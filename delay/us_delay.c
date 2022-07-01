/*
 * us_delay.c
 *
 *  Created on: 20 апр. 2022 г.
 *      Author: DubininRE
 */

#include "us_delay.h"

#include "stm32g0xx_ll_rcc.h"
#include "stm32g0xx_ll_tim.h"

static uint32_t arr;

void delay_us_init() {
  LL_RCC_ClocksTypeDef tmp;
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM16);
  LL_RCC_GetSystemClocksFreq(&tmp);
  arr = tmp.PCLK1_Frequency / 1000000;

  LL_TIM_InitTypeDef cfgTim = {.Prescaler = 0,
                               .CounterMode = LL_TIM_COUNTERMODE_UP,
                               .Autoreload = 0,
                               .ClockDivision = LL_TIM_CLOCKDIVISION_DIV1,
                               .RepetitionCounter = 0};

  LL_TIM_Init(TIM16, &cfgTim);

  LL_TIM_SetOnePulseMode(TIM16, LL_TIM_ONEPULSEMODE_SINGLE);
  LL_TIM_ClearFlag_UPDATE(TIM16);
}

void delay_us(uint32_t us) {
  LL_TIM_SetAutoReload(TIM16, arr * us);
  LL_TIM_EnableCounter(TIM16);
  while (!LL_TIM_IsActiveFlag_UPDATE(TIM16));
  LL_TIM_ClearFlag_UPDATE(TIM16);
}
