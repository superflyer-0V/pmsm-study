#include "justfloat.h"
#include "usbd_cdc_if.h"
#include "usbd_def.h"
#include "usbd_cdc.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

static uint8_t tx_buf_a[VOFA_BUF_SIZE];
static uint8_t tx_buf_b[VOFA_BUF_SIZE];
static volatile uint8_t buf_sel = 0;

void vofa_send(float *data, uint8_t ch_count)
{
  if (ch_count > VOFA_MAX_CHANNELS) return;

  USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;
  if (hcdc->TxState != 0) return;

  uint8_t *buf = (buf_sel == 0) ? tx_buf_a : tx_buf_b;
  buf_sel = 1 - buf_sel;

  uint8_t idx = 0;
  for (uint8_t i = 0; i < ch_count; i++)
  {
    buf[idx++] = ((uint8_t*)&data[i])[0];
    buf[idx++] = ((uint8_t*)&data[i])[1];
    buf[idx++] = ((uint8_t*)&data[i])[2];
    buf[idx++] = ((uint8_t*)&data[i])[3];
  }

  buf[idx++] = 0x00;
  buf[idx++] = 0x00;
  buf[idx++] = 0x80;
  buf[idx++] = 0x7f;

  CDC_Transmit_FS(buf, idx);
}
