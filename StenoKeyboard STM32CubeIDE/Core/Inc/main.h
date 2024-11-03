/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define Row1_Pin GPIO_PIN_0
#define Row1_GPIO_Port GPIOA
#define Row2_Pin GPIO_PIN_1
#define Row2_GPIO_Port GPIOA
#define Row3_Pin GPIO_PIN_2
#define Row3_GPIO_Port GPIOA
#define Row4_Pin GPIO_PIN_3
#define Row4_GPIO_Port GPIOA
#define Column1_Pin GPIO_PIN_4
#define Column1_GPIO_Port GPIOA
#define Column2_Pin GPIO_PIN_5
#define Column2_GPIO_Port GPIOA
#define Column3_Pin GPIO_PIN_6
#define Column3_GPIO_Port GPIOA
#define Column4_Pin GPIO_PIN_7
#define Column4_GPIO_Port GPIOA
#define Column5_Pin GPIO_PIN_0
#define Column5_GPIO_Port GPIOB
#define Column6_Pin GPIO_PIN_1
#define Column6_GPIO_Port GPIOB
#define Column7_Pin GPIO_PIN_2
#define Column7_GPIO_Port GPIOB
#define Column8_Pin GPIO_PIN_10
#define Column8_GPIO_Port GPIOB
#define Column11_Pin GPIO_PIN_12
#define Column11_GPIO_Port GPIOB
#define Column10_Pin GPIO_PIN_13
#define Column10_GPIO_Port GPIOB
#define Column9_Pin GPIO_PIN_14
#define Column9_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
