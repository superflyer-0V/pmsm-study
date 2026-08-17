#ifndef __JUSTFLOAT_H__
#define __JUSTFLOAT_H__

#include "main.h"

#define VOFA_MAX_CHANNELS    8
#define VOFA_BUF_SIZE        (VOFA_MAX_CHANNELS * 4 + 4)

void vofa_send(float *data, uint8_t ch_count);

#endif
