/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "frequency.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
unsigned long NoteStartTime = 0;

/* USER CODE BEGIN PV */


int bpm = 120;
int SongID =1;
struct ton song1[] = {
// Bar 1
{NOTE_C4, 8},
{NOTE_D4, 8},
{NOTE_E4, 8},
{NOTE_F4, 8},
{NOTE_G4, 4},
{NOTE_G4, 4},
{NOTE_A4, 8},
{NOTE_A4, 8},
{NOTE_A4, 8},
{NOTE_A4, 8},
{NOTE_G4, 2},
/*// Bar 2
{NOTE_A4, 8},
{NOTE_A4, 8},
{NOTE_A4, 8},
{NOTE_A4, 8},
{NOTE_G4, 2},
{NOTE_F4, 8},
{NOTE_F4, 8},
{NOTE_F4, 8},
{NOTE_F4, 8},
{NOTE_E4, 4},
{NOTE_E4, 4},
// Bar 3
{NOTE_G4, 8},
{NOTE_G4, 8},
{NOTE_G4, 8},
{NOTE_G4, 8},
{NOTE_C4, 4},*/
{0, 4}
};


struct ton song2[] ={
  //Bar 1
  {NOTE_D4_SHARP, 4},
  {1, 4},
  {NOTE_D4_SHARP, 4},
  {1, 4},

  {NOTE_D4_SHARP, 4},
  {1, 4},
  {NOTE_D4_SHARP, 4},
  {NOTE_D4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_B4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 4},

  //Bar 2

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_C5_SHARP, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_B4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_B4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_F4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_B4, 4},

  // Bar 3

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_B4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_C5, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_C5_SHARP, 4},

  {NOTE_D5_SHARP, 2},
  {NOTE_D4_SHARP, 2},

  {NOTE_E5, 2},
  {NOTE_E5, 4},
  {NOTE_A4_SHARP, 16},
  {NOTE_B4, 16},
  {NOTE_C5, 16},
  {NOTE_C5_SHARP, 16},

  //Bar 4

  {NOTE_D5_SHARP, 4},
  {NOTE_D5_SHARP, 8},
  {NOTE_A5_SHARP, 4},
  {NOTE_A5_SHARP, 8},
  {NOTE_D5_SHARP, 8},
  {NOTE_D5, 8},

  {NOTE_C5_SHARP, 4},
  {NOTE_C5, 4},
  {NOTE_B4, 4},
  {NOTE_A4_SHARP, 4},

  {NOTE_B4, 2},
  {NOTE_E5, 2},

  {NOTE_G4_SHARP, 16},
  {1, 16},
  {NOTE_G4_SHARP, 16},
  {1, 16},
  {NOTE_B4, 4},
  {NOTE_G4_SHARP, 16},
  {1, 16},
  {NOTE_G4_SHARP, 16},
  {NOTE_C5_SHARP, 4},

  //Bar 5

  {NOTE_D5_SHARP, 4},
  {NOTE_D5_SHARP, 8},
  {NOTE_A4_SHARP, 4},
  {NOTE_A4_SHARP, 8},
  {NOTE_D5_SHARP, 8},
  {NOTE_D5, 8},

  {NOTE_C5_SHARP, 4},
  {NOTE_C5, 4},
  {NOTE_B4, 4},
  {NOTE_A4_SHARP,8},
  {NOTE_B4, 8},

  {NOTE_E5, 2},
  {NOTE_G5_SHARP, 2},

  {NOTE_E5, 2},
  {NOTE_B5, 2},

  {NOTE_D5_SHARP, 16},
  {1, 16},
  {NOTE_D5_SHARP, 16},
  {1, 16},
  {1, 8},
  {NOTE_D5_SHARP, 8},
  {1, 8},
  {NOTE_D5_SHARP, 8},
  {1, 8},
  {NOTE_D5_SHARP, 8},

  //Bar 6

  {1, 8},
  {NOTE_D5_SHARP, 8},
  {1, 8},
  {NOTE_D5_SHARP, 8},
  {NOTE_E5, 8},
  {1, 8},
  {NOTE_E5, 8},
  {1, 8},

  {NOTE_D5_SHARP, 16},
  {1, 16},
  {NOTE_D5_SHARP, 16},
  {1, 16},
  {1, 8},
  {NOTE_D5_SHARP, 8},
  {1, 8},
  {NOTE_D5_SHARP, 8},
  {1, 8},
  {NOTE_D5_SHARP, 8},

  {1, 8},
  {NOTE_D5_SHARP, 8},
  {1, 8},
  {NOTE_D5_SHARP, 8},
  {NOTE_F5_SHARP, 8},
  {1, 8},
  {NOTE_F5_SHARP, 8},
  {1, 8},

  {NOTE_D5_SHARP, 2},
  {NOTE_D4_SHARP, 2},

  {NOTE_A4_SHARP, 2},
  {1, 2},

  //Bar 7

  {NOTE_D4_SHARP, 1},

  {NOTE_D4_SHARP, 1},

  {NOTE_F4, 1},

  {NOTE_F4_SHARP, 1},

  {NOTE_D6_SHARP, 4},
  {NOTE_D6, 4},
  {NOTE_C6_SHARP, 4},
  {NOTE_C6, 4},

  //Bar 8

  {NOTE_D6_SHARP, 8},
  {NOTE_D6, 8},
  {NOTE_C6_SHARP, 8},
  {NOTE_C6, 8},
  {NOTE_B5, 8},
  {1, 8},
  {NOTE_B5, 8},
  {1, 8},

  {NOTE_D6_SHARP, 4},
  {NOTE_D6, 4},
  {NOTE_C6_SHARP, 4},
  {NOTE_C6, 4},

  {NOTE_D6_SHARP, 8},
  {NOTE_D6, 8},
  {NOTE_C6_SHARP, 8},
  {NOTE_C6, 8},
  {NOTE_B5, 8},
  {1, 8},
  {NOTE_B5, 8},
  {1, 8},

  {NOTE_D4_SHARP, 1},

  // Bar 9

  {NOTE_B4, 1},

  {NOTE_A4_SHARP, 1},

  {NOTE_G4_SHARP, 1},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_B4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4, 16},
  {1, 16},
  {NOTE_D4, 4},

  // Bar 10

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_A4_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_B4, 4},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_C5_SHARP, 4},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D5, 4},

  {NOTE_D5_SHARP, 2},
  {NOTE_E5, 2},

  {NOTE_F5_SHARP, 2},
  {NOTE_E5, 2},

  //Bar 11

  {NOTE_D5_SHARP, 2},
  {NOTE_E5, 2},

  {NOTE_F5_SHARP, 2},
  {NOTE_G5_SHARP, 2},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 8},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 8},

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 8},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {1, 8},

  //Bar 12

  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_D4_SHARP, 16},
  {1, 16},
  {NOTE_B4, 4},
  {NOTE_D4_SHARP, 8},
  {NOTE_D4_SHARP, 4},
  {NOTE_D4_SHARP, 8},

  {NOTE_D4_SHARP, 1},

  {NOTE_D4_SHARP, 1},
  {0, 1},
};


struct ton song3[] ={
  {NOTE_G5, 8},
  {NOTE_G5, 8},
  {NOTE_G5, 8},
  {NOTE_G5, 8},
  {NOTE_C5, 4},
  {0, 4}
  };

struct ton song4[] ={
  {NOTE_G3, 8},
  {NOTE_G3, 8},
  {NOTE_G3, 8},
  {NOTE_G3, 8},
  {NOTE_C3, 4},
  {0, 4}
  };


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/**
  * changes frequency of the timer signal.
  *
  * @param tone is defined as an int value to adjust the timer parameters
  */
void tone_set(int tone){
  __HAL_TIM_SET_AUTORELOAD(&htim2, tone);
  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, tone/2);
  __HAL_TIM_SET_COUNTER(&htim2, 0);
}

/**
  * switches the Output Pins for the LEDs to create an alternating blinking effect.
  */
void leds(){
  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);
}

/**
  * is the main function that plays the notes using a loop.
  *
  * This function starts a while loop for the duration of the playing note
  * during the loop the button is checked and ends the whole play_song function
  * It also checks for 1/4 Notes of time to trigger the LEDs
  *
  * @param  song is a whole music piece in form of a struct array {note, length}
  *         is required to have an element {0,x} as its last element
  *         as otherwise the function won't terminate
  *
  */
  void play_song(struct ton song[]){
  unsigned long ledtick = HAL_GetTick();
  for(int i = 0; song[i].note!= 0;i++){
    int interval = note_duration(song[i],bpm);

    tone_set(song[i].note);
    tone_start();

    unsigned long NoteStartTime = HAL_GetTick();
    while(HAL_GetTick() - NoteStartTime <= interval){
      if(HAL_GetTick() - ledtick >= 60000/bpm){
        ledtick = HAL_GetTick();
        leds();
      }
      if(Status==1){
        tone_stop();
        SongID++;
        Status=0;
        return;
      }
    }
    tone_stop();
  }

}

/**
  * just starts the timer to create a tone.
  */
void tone_start(){

  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

}

/**
  * ends the timer to stop the sound.
  */
void tone_stop(){

  HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);

}

/**
  * a function to calculate the duration of a note
  *
  * @param  note is one struct of the type ton
  * @param  bpm is the beats per minute
  * @return the length the note is suppost to be played, calculatet from bpm and
            the length of the note e.g 1/4, 1/2
  */
int note_duration(struct ton note,int bpm){
    return 60/(bpm/4)*1000 / note.len;
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    while(SongID == 1){
      bpm = 120;
      play_song(song1);
      HAL_Delay(1000);
    }

    while(SongID == 2){
      bpm = 190;
      play_song(song2);
      HAL_Delay(1000);
    }

    while(SongID == 3){
      bpm = 120;
      play_song(song3);
      HAL_Delay(1000);
    }

    while(SongID == 4){
      bpm = 120;
      play_song(song4);
      HAL_Delay(1000);
    }
    if (SongID > 4)
      SongID = 1;

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable MSI Auto calibration
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
