/*
 * uc_delay.h
 *
 *  Created on: 15 ���. 2022 �.
 *      Author: DubininRE
 */

#ifndef UC_DELAY_H_
#define UC_DELAY_H_

#include "stm32g0xx_ll_bus.h"
#include "stm32g0xx_ll_rcc.h"
#include "stm32g0xx_ll_tim.h"

void delay_us_init();
void delay_us(uint32_t us);

#endif /* UC_DELAY_H_ */
