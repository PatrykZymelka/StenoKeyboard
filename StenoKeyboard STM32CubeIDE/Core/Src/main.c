/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

	/* Modifiers: */
#define KEY_CTRL 0x01 // Ctrl
#define KEY_SHIFT 0x02 // Shift
#define KEY_ALT 0x04 // Alt

	/* Character Keys: */
#define KEY_A 0x04 // A
#define KEY_B 0x05 // B
#define KEY_C 0x06 // C
#define KEY_D 0x07 // D
#define KEY_E 0x08 // E
#define KEY_F 0x09 // F
#define KEY_G 0x0a // G
#define KEY_H 0x0b // H
#define KEY_I 0x0c // I
#define KEY_J 0x0d // J
#define KEY_K 0x0e // K
#define KEY_L 0x0f // L
#define KEY_M 0x10 // M
#define KEY_N 0x11 // N
#define KEY_O 0x12 // O
#define KEY_P 0x13 // P
#define KEY_Q 0x14 // Q
#define KEY_R 0x15 // R
#define KEY_S 0x16 // S
#define KEY_T 0x17 // T
#define KEY_U 0x18 // U
#define KEY_V 0x19 // V
#define KEY_W 0x1a // W
#define KEY_X 0x1b // X
#define KEY_Y 0x1c // Y
#define KEY_Z 0x1d // Z

	/* Number Keys:*/
#define KEY_1 0x1e // 1 and !
#define KEY_2 0x1f // 2 and @
#define KEY_3 0x20 // 3 and #
#define KEY_4 0x21 // 4 and $
#define KEY_5 0x22 // 5 and %
#define KEY_6 0x23 // 6 and ^
#define KEY_7 0x24 // 7 and &
#define KEY_8 0x25 // 8 and *
#define KEY_9 0x26 // 9 and (
#define KEY_0 0x27 // 0 and )

	/* Function keys: */
#define KEY_ENTER 0x28 // enter
#define KEY_ESC 0x29 // esc
#define KEY_BACKSPACE 0x2a // backspace
#define KEY_TAB 0x2b // Tab
#define KEY_SPACE 0x2c // Space
#define KEY_MINUS 0x2d // - and _
#define KEY_EQUAL 0x2e // = and +
#define KEY_LEFTBRACE 0x2f // [ and {
#define KEY_RIGHTBRACE 0x30 // ] and }
#define KEY_BACKSLASH 0x31 // \ and |
#define KEY_HASHTILDE 0x32 // # and ~
#define KEY_SEMICOLON 0x33 // ; and :
#define KEY_APOSTROPHE 0x34 // ' and "
#define KEY_COMMA 0x36 // , and <
#define KEY_DOT 0x37 // . and >
#define KEY_SLASH 0x38 // / and ?
#define KEY_CAPSLOCK 0x39 // Caps Lock

#define MAX_KEY_SIZE 20
#define MAX_VALUE_SIZE 30
#define TABLE_SIZE 1129

#define TIME_LIMIT 5


#define __HAL_TIM_SET_COUNTER(__HANDLE__, __COUNTER__) ((__HANDLE__)->Instance->CNT = (__COUNTER__))
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim10;

/* USER CODE BEGIN PV */
	extern USBD_HandleTypeDef hUsbDeviceFS;

	typedef struct
	{
		uint8_t MODIFIER;
		uint8_t RESERVED;
		uint8_t KEYCODE1;
		uint8_t KEYCODE2;
		uint8_t KEYCODE3;
		uint8_t KEYCODE4;
		uint8_t KEYCODE5;
		uint8_t KEYCODE6;
	}subKeyBoard;

	subKeyBoard keyBoardHIDsub = {0,0,0,0,0,0,0,0};

	typedef struct {
	    char key[MAX_KEY_SIZE];
	    char value[MAX_VALUE_SIZE];
	} HashEntry;

	HashEntry *hashTable[TABLE_SIZE];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM10_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
volatile uint32_t elapsedTime = 0;
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
  MX_USB_DEVICE_Init();
  MX_TIM10_Init();
  /* USER CODE BEGIN 2 */

  int counter1 = 0;
  int counter2 = 0;
  int counter3 = 0;
  int counter4 = 0;
  int counter5 = 0;
  int counter6 = 0;
  int counter7 = 0;
  int counter8 = 0;
  int counter9 = 0;
  int counter10 = 0;
  int counter11 = 0;
  int counter12 = 0;
  int counter13 = 0;
  int counter14 = 0;
  int counter15 = 0;
  int counter16 = 0;
  int counter17 = 0;
  int counter18 = 0;
  int counter19 = 0;
  int counter20 = 0;
  int counter21 = 0;
  int counter22 = 0;
  int counter23 = 0;
  int counter24 = 0;

  int lastPress = 0;
  int timeout = 0;
  int timeoutB = 0;
  int previousChar = 0;
  char charbuffer[22] = {};
  int bufferItemsNumber = 0;
  char result[22] = {};
  int activeTimeLimit = TIME_LIMIT;
  int activeTimer = 0;


  uint8_t Scan_KeyMatrix(void) {
        uint8_t key = 0;

  		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 1);
  		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
  		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
  		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
  		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
  		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
  		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
  		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
  		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
  		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
  		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


        if (HAL_GPIO_ReadPin(Row1_GPIO_Port, Row1_Pin) == 1) {
            key = 1;
        }
        if (HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) == 1) {
            key = 2;
        }
        if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 24;
        }

  		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
  		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 1);
  		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
  		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
  		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
  		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
  		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
  		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
  		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
  		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
  		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


        if (HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) == 1) {
            key = 3;
        }
        if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 4;
        }

		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 1);
		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


		if (HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) == 1) {
			key = 5;
		}
		if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 6;
		}
		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 1);
		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


		if (HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) == 1) {
			key = 7;
		}
		if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 8;
		}
		if (HAL_GPIO_ReadPin(Row4_GPIO_Port, Row4_Pin) == 1) {
			key = 9;
		}

		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 1);
		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


		if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 11;
		}
		if (HAL_GPIO_ReadPin(Row4_GPIO_Port, Row4_Pin) == 1) {
			key = 10;
		}

		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 1);
		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


		if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 11;
		}
		if (HAL_GPIO_ReadPin(Row4_GPIO_Port, Row4_Pin) == 1) {
			key = 12;
		}

		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 1);
		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


		if (HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) == 1) {
			key = 14;
		}
		if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 15;
		}
		if (HAL_GPIO_ReadPin(Row4_GPIO_Port, Row4_Pin) == 1) {
			key = 13;
		}

		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 1);
		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


		if (HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) == 1) {
			key = 16;
		}
		if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 17;
		}

		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 1);
		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


		if (HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) == 1) {
			key = 18;
		}
		if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 19;
		}

		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 1);
		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 0);


		if (HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) == 1) {
			key = 20;
		}
		if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 21;
		}

		HAL_GPIO_WritePin(Column1_GPIO_Port, Column1_Pin, 0);
		HAL_GPIO_WritePin(Column2_GPIO_Port, Column2_Pin, 0);
		HAL_GPIO_WritePin(Column3_GPIO_Port, Column3_Pin, 0);
		HAL_GPIO_WritePin(Column4_GPIO_Port, Column4_Pin, 0);
		HAL_GPIO_WritePin(Column5_GPIO_Port, Column5_Pin, 0);
		HAL_GPIO_WritePin(Column6_GPIO_Port, Column6_Pin, 0);
		HAL_GPIO_WritePin(Column7_GPIO_Port, Column7_Pin, 0);
		HAL_GPIO_WritePin(Column8_GPIO_Port, Column8_Pin, 0);
		HAL_GPIO_WritePin(Column9_GPIO_Port, Column9_Pin, 0);
		HAL_GPIO_WritePin(Column10_GPIO_Port, Column10_Pin, 0);
		HAL_GPIO_WritePin(Column11_GPIO_Port, Column11_Pin, 1);



        if (HAL_GPIO_ReadPin(Row1_GPIO_Port, Row1_Pin) == 1) {
            key = 1;
        }
		if (HAL_GPIO_ReadPin(Row2_GPIO_Port, Row2_Pin) == 1) {
			key = 22;
		}
		if (HAL_GPIO_ReadPin(Row3_GPIO_Port, Row3_Pin) == 1) {
			key = 23;
		}

        return key;
    }
  void Clear_Buffer(){
  	  for (int i = 0; i < 22; i++) {
  	  		          charbuffer[i] = '\0';
  	   }
    }
  void Send_Character(){
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
	  HAL_Delay(20);
	  keyBoardHIDsub.MODIFIER=0x00;
	  keyBoardHIDsub.KEYCODE2=0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
	  HAL_Delay(20);

	  }






  void Set_Character(char i){
	  switch(i){
	  	  	  case 'a':
					keyBoardHIDsub.MODIFIER=0x00;
	  			    keyBoardHIDsub.KEYCODE2=KEY_A;
	  			    break;
	  	  	  case 'b':
					keyBoardHIDsub.MODIFIER=0x00;
	  	  		  	keyBoardHIDsub.KEYCODE2=KEY_B;
	  	  		  	break;
	  	  	case 'c':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_C;
	    			break;
	  	  	case 'd':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_D;
	  			break;
	  	  	case 'e':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_E;
	  			break;
	  	  	case 'f':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_F;
	  			break;
	  	  	case 'g':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_G;
	  			break;
	  	  	case 'h':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_H;
	  			break;
	  	  	case 'i':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_I;
	  			break;
	  	  	case 'j':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_J;
					break;
	  	  	case 'k':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_K;
	  			break;
	  	  	case 'l':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_L;
	  			break;
	  	  	case 'm':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_M;
	  			break;
	  	  	case 'n':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_N;
	  			break;
	  	  	case 'o':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_O;
	  			break;
	  	  	case 'p':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_P;
	  			break;
	  	  	case 'q':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_Q;
	  			break;
	  	  	case 'r':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_R;
	  			break;
	  	  	case 's':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_S;
	  			break;
	  	  	case 't':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_T;
	  			break;
	  	  	case 'u':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_U;
	  			break;
	  	  	case 'v':
				keyBoardHIDsub.MODIFIER=0x00;
	    			keyBoardHIDsub.KEYCODE2=KEY_V;
	  			break;
			case 'w':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_W;
				break;
			case 'x':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_X;
				break;
			case 'y':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_Y;
				break;
			case 'z':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_Z;
				break;
			case '1':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_1;
				break;
			case '2':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_2;
				break;
			case '3':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_3;
				break;
			case '4':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_4;
				break;
			case '5':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_5;
				break;
			case '6':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_6;
				break;
			case '7':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_7;
				break;
			case '8':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_8;
				break;
			case '9':
				keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_9;
				break;
			case '0':
					keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_0;
				break;
			case '!':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_1;
				break;
			case '@':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_2;
				break;
			case '#':
					keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_BACKSPACE;
				break;
			case '$':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_4;
				break;
			case '%':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_5;
				break;
			case '^':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_6;
				break;
			case '&':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_7;
				break;
			case '*':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_8;
				break;
			case '(':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_9;
				break;
			case ')':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_0;
				break;
			case '+':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_SPACE;
				break;
			case ' ':
					keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_SPACE;
				break;
			case '\'':
					keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_APOSTROPHE;
				break;
			case '.':
					keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_DOT;
				break;
			case ',':
					keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=KEY_COMMA;
				break;
			case '?':
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_SLASH;
				break;
			default:
					keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=0x00;
				break;
	  	  }
  }
  unsigned int hashFunction(const char *key) {
      unsigned int hash = 0;
      while (*key) {
          hash = (hash << 5) + *key++;
      }
      return hash % TABLE_SIZE;
  }

  void insert(const char *key, const char *value) {
      unsigned int index = hashFunction(key);
      while (hashTable[index] != NULL) {
          if (strcmp(hashTable[index]->key, key) == 0) {
              strncpy(hashTable[index]->value, value, MAX_VALUE_SIZE - 1);
              hashTable[index]->value[MAX_VALUE_SIZE - 1] = '\0';
              return;
          }
          index = (index + 1) % TABLE_SIZE;
      }

      HashEntry *newEntry = (HashEntry *)malloc(sizeof(HashEntry));
      if (newEntry == NULL) {
          fprintf(stderr, "Memory allocation failed\n");
          exit(EXIT_FAILURE);
      }
      strncpy(newEntry->key, key, MAX_KEY_SIZE - 1);
      newEntry->key[MAX_KEY_SIZE - 1] = '\0';
      strncpy(newEntry->value, value, MAX_VALUE_SIZE - 1);
      newEntry->value[MAX_VALUE_SIZE - 1] = '\0';
      hashTable[index] = newEntry;
  }

  const char *search(const char *key) {
      unsigned int index = hashFunction(key);
      while (hashTable[index] != NULL) {
          if (strcmp(hashTable[index]->key, key) == 0) {
              return hashTable[index]->value;
          }
          index = (index + 1) % TABLE_SIZE; // Linear probing
      }
      return NULL; // Key not found
  }

  void hashInit(){
	    for (int i = 0; i < TABLE_SIZE; i++) {
	        hashTable[i] = NULL;
	    }

	    insert("S", "is");
	    insert("ST", "is it");
	    insert("STK", "and");
	    insert("SAOU", "sue");
	    insert("SAOPB", "soon");
	    insert("P", "about");
	    insert("KOD", "cod");
	    insert("TAO*E", "ty");
	    insert("STRA/TA", "strata");
	    insert("STA/TAOU/KWOE", "status quo");
	    insert("STA/TAOU", "statue");
	    insert("STAT/WET", "statuette");
		insert("TKO*FG", "doing");
		insert("TKO", "do");
		insert("TKAUS", "cause");
		insert("TKAET", "data");
		insert("TKAEUPBT", "didn't"),
		insert("TKAEU", "day");
		insert("TKAOS", "does");
		insert("TKAOUT", "duty");
		insert("TKAOU", "due");
		insert("TKAOE/TPAULT", "default");
		insert("LT", "#ing");
		insert("LG", "#n't");
		insert("*F", "#.");
		insert("*FP", "#,");
		insert("HFP", "#?");
		insert("HFPL", "#!");
		insert("TPHROETS", "floats");
		insert("TPHROES", "flows");
		insert("TPHROED", "flowed");
		insert("-T", "the");
		insert("-F", "of");
		insert("SKP", "and");
		insert("TO", "to");
		insert("TPH", "in");
		insert("EU", "I");
		insert("THA", "that");
		insert("WAS", "was");
		insert("HEUS", "his");
		insert("HE", "he");
		insert("T", "it");
		insert("W", "with");
		insert("S", "is");
		insert("TPOR", "for");
		insert("AS", "as");
		insert("H", "had");
		insert("U", "you");
		insert("TPHOT", "not");
		insert("-B", "be");
		insert("HER", "her");
		insert("OPB", "on");
		insert("AT", "at");
		insert("PWEU", "by");
		insert("WEU", "which");
		insert("SR", "have");
		insert("OR", "or");
		insert("TPR", "from");
		insert("TH", "this");
		insert("HEUPL", "him");
		insert("PWUT", "but");
		insert("AUL", "all");
		insert("SHE", "she");
		insert("THE", "they");
		insert("WR", "were");
		insert("PHEU", "my");
		insert("R", "are");
		insert("PHE", "me");
		insert("WUPB", "one");
		insert("THAEUR", "their");
		insert("SO", "so");
		insert("APB", "an");
		insert("SED", "said");
		insert("THEPL", "them");
		insert("WE", "we");
		insert("WHO", "who");
		insert("WO", "would");
		insert("PW-PB", "been");
		insert("HR", "will");
		insert("TPHO", "no");
		insert("WHEPB", "when");
		insert("THR", "there");
		insert("TP", "if");
		insert("PHOR", "more");
		insert("OUT", "out");
		insert("UP", "up");
		insert("TPHAO", "into");
		insert("TKO", "do");
		insert("TPHEU", "any");
		insert("KWROUR", "your");
		insert("WHA", "what");
		insert("HAS", "has");
		insert("PHAPB", "man");
		insert("KO", "could");
		insert("OER", "other");
		insert("THAPB", "than");
		insert("OUR", "our");
		insert("SOPL", "some");
		insert("SRE", "very");
		insert("TAOEUPL", "time");
		insert("POPB", "upon");
		insert("PW", "about");
		insert("PHAE", "may");
		insert("EUTS", "its");
		insert("OEPBL", "only");
		insert("TPHOU", "now");
		insert("HRAOEUBG", "like");
		insert("HREUL", "little");
		insert("THEPB", "then");
		insert("K", "can");
		insert("SHO", "should");
		insert("PHAED", "made");
		insert("TK", "did");
		insert("US", "us");
		insert("SUFP", "such");
		insert("AEU", "a");
		insert("TKPWRAET", "great");
		insert("PW-FR", "before");
		insert("PHUFT", "must");
		insert("TWO", "two");
		insert("THEZ", "these");
		insert("SAOE", "see");
		insert("TPHOE", "know");
		insert("OEFR", "over");
		insert("PHUFP", "much");
		insert("TKOUPB", "down");
		insert("AF", "after");
		insert("TPEUFRT", "first");
		insert("PHR-FPLT", "Mr.");
		insert("TKPWAOD", "good");
		insert("PHEPB", "men");
		insert("OEPB", "own");
		insert("TPHEFR", "never");
		insert("PHOFT", "most");
		insert("OLD", "old");
		insert("SHAL", "shall");
		insert("TKAEU", "day");
		insert("W-R", "where");
		insert("THOZ", "those");
		insert("KAEUPL", "came");
		insert("KOPL", "come");
		insert("HEUPLS", "himself");
		insert("WAEU", "way");
		insert("WORBG", "work");
		insert("HRAOEUF", "life");
		insert("WOUT", "without");
		insert("TKPW", "go");
		insert("PHAEUBG", "make");
		insert("WEL", "well");
		insert("THRU", "through");
		insert("-BG", "being");
		insert("HROPBG", "long");
		insert("SAEU", "say");
		insert("PHAOEUT", "might");
		insert("HOU", "how");
		insert("APL", "am");
		insert("TAO", "too");
		insert("AOEPB", "even");
		insert("TK-F", "def");
		insert("TKPWEPB", "again");
		insert("PHAEPB", "many");
		insert("PWABG", "back");
		insert("HAOER", "here");
		insert("THEU", "think");
		insert("EF", "every");
		insert("PAOEPL", "people");
		insert("WEPBT", "went");
		insert("SAEUPL", "same");
		insert("HRAFT", "last");
		insert("THAUT", "thought");
		insert("A/WAEU", "away");
		insert("TPH-PB", "under");
		insert("TAEUBG", "take");
		insert("TPOUPBD", "found");
		insert("HAPBD", "hand");
		insert("AO*EUS", "eyes");
		insert("STEUL", "still");
		insert("PHRAEUS", "place");
		insert("WHAOEUL", "while");
		insert("SKWRUFT", "just");
		insert("HR-S", "also");
		insert("KWRUPBG", "young");
		insert("KWRET", "yet");
		insert("THOE", "though");
		insert("TKPWEPBS", "against");
		insert("THEUPBGS", "things");
		insert("TKPWET", "get");
		insert("-FR", "ever");
		insert("TKPWEUF", "give");
		insert("TKPWOD", "god");
		insert("KWRAOERS", "years");
		insert("OF", "off");
		insert("TPAEUS", "face");
		insert("TPHOG", "nothing");
		insert("RAOEUT", "right");
		insert("WUPBS", "once");
		insert("TPHOER", "another");
		insert("HREFT", "left");
		insert("PART", "part");
		insert("SAU", "saw");
		insert("HOUS", "house");
		insert("WORLD", "world");
		insert("HED", "head");
		insert("THRAOE", "three");
		insert("TAOBG", "took");
		insert("TPHU", "new");
		insert("HRUF", "love");
		insert("AULS", "always");
		insert("PHR-S", "Mrs.");
		insert("PUT", "put");
		insert("TPHAOEUT", "night");
		insert("AOEFP", "each");
		insert("KEUPBG", "king");
		insert("TWAOEPB", "between");
		insert("TEL", "tell");
		insert("PHAOEUPBD", "mind");
		insert("HART", "heart");
		insert("TPAOU", "few");
		insert("PWAU", "because");
		insert("THEUPBG", "thing");
		insert("WHOPL", "whom");
		insert("TPAR", "far");
		insert("SAOEPLD", "seemed");
		insert("HRAOBGD", "looked");
		insert("KAULD", "called");
		insert("WHOEL", "whole");
		insert("TK*E", "de");
		insert("SET", "set");
		insert("PWO*T", "both");
		insert("TKPWOT", "got");
		insert("TPAOEUPBD", "find");
		insert("TKOPB", "done");
		insert("HAERD", "heard");
		insert("HRAOBG", "look");
		insert("TPHAEUPL", "name");
		insert("TKAEUS", "days");
		insert("TOLD", "told");
		insert("HRET", "let");
		insert("HRORD", "lord");
		insert("KREU", "country");
		insert("SK-D", "asked");
		insert("TKPW-G", "going");
		insert("SAOEPB", "seen");
		insert("PWOERT", "better");
		insert("P*", "p");
		insert("SR-G", "having");
		insert("HOEPL", "home");
		insert("TPHAOU", "knew");
		insert("SAOEUD", "side");
		insert("S-G", "something");
		insert("PHOEPLT", "moment");
		insert("TPAER", "father");
		insert("PHOPBG", "among");
		insert("KORS", "course");
		insert("HAPBDZ", "hands");
		insert("WOPL", "woman");
		insert("TPHUF", "enough");
		insert("WORDZ", "words");
		insert("PHOER", "mother");
		insert("SAOPB", "soon");
		insert("TPUL", "full");
		insert("EPBD", "end");
		insert("TKPWAEUF", "gave");
		insert("RAOPL", "room");
		insert("HR-PL", "almost");
		insert("SPHAL", "small");
		insert("THO*U", "thou");
		insert("SK-PBT", "cannot");
		insert("WAUR", "water");
		insert("WAPBT", "want");
		insert("HOUF", "however");
		insert("HRAOEUT", "light");
		insert("KWAOEUT", "quite");
		insert("PWRAUT", "brought");
		insert("TPH-R", "nor");
		insert("WORD", "word");
		insert("WHOZ", "whose");
		insert("TKPWEUFPB", "given");
		insert("TKAOR", "door");
		insert("PWEFT", "best");
		insert("TURPBD", "turned");
		insert("TAEPB", "taken");
		insert("TKOS", "does");
		insert("AOUS", "use");
		insert("PHORPBG", "morning");
		insert("PHAO*EUS", "myself");
		insert("TKPWUT/*EPB/PWERG", "Gutenberg");
		insert("TPELT", "felt");
		insert("TPH-L", "until");
		insert("SEUPBS", "since");
		insert("POUR", "power");
		insert("TH*EPLS", "themselves");
		insert("AOUFD", "used");
		insert("RAER", "rather");
		insert("TKPWAPB", "began");
		insert("PREPBT", "present");
		insert("SROEUS", "voice");
		insert("OERS", "others");
		insert("WHAOEUT", "white");
		insert("WORBGS", "works");
		insert("HRES", "less");
		insert("PHUPB", "money");
		insert("TPHEGT", "next");
		insert("PAOR", "poor");
		insert("TK*T", "death");
		insert("STAOD", "stood");
		insert("TPORPL", "form");
		insert("W-PB", "within");
		insert("TOGT", "together");
		insert("TEUL", "till");
		insert("THAO*EU", "thy");
		insert("HRARPBLG", "large");
		insert("PHAERT", "matter");
		insert("KEUPBD", "kind");
		insert("OFPB", "often");
		insert("SERPB", "certain");
		insert("H*ERS", "herself");
		insert("KWRAOER", "year");
		insert("TPREPBD", "friend");
		insert("HAF", "half");
		insert("ORD", "order");
		insert("ROUPBD", "round");
		insert("TRAOU", "true");
		insert("TPHEUG", "anything");
		insert("KAOEP", "keep");
		insert("SEPBT", "sent");
		insert("WAOEUF", "wife");
		insert("PHAOEPBS", "means");
		insert("PWHREF", "believe");
		insert("PAFD", "passed");
		insert("TPAOET", "feet");
		insert("TPHAOER", "near");
		insert("PHREUBG", "public");
		insert("STAEUT", "state");
		insert("SOPB", "son");
		insert("HUPBD", "hundred");
		insert("KHEURPB", "children");
		insert("THUS", "thus");
		insert("HOEP", "hope");
		insert("A/HROEPB", "alone");
		insert("PWOF", "above");
		insert("KAEUS", "case");
		insert("TKAER", "dear");
		insert("THAOE", "thee");
		insert("SEZ", "says");
		insert("PERPB", "person");
		insert("HAOEU", "high");
		insert("RAED", "read");
		insert("STEU", "city");
		insert("HR-R", "already");
		insert("SAOEFD", "received");
		insert("TPABGT", "fact");
		insert("TKPWOPB", "gone");
		insert("TKPWEURL", "girl");
		insert("TPHOEPB", "known");
		insert("HAER", "hear");
		insert("TAOEUPLS", "times");
		insert("HRAOEFT", "least");
		insert("PRAPS", "perhaps");
		insert("SHUR", "sure");
		insert("TPHAOEPBD", "indeed");
		insert("TKPWHREURB", "English");
		insert("OEP", "open");
		insert("PWO*ED", "body");
		insert("T/SEFL", "itself");
		insert("A/HROPBG", "along");
		insert("HRAPBD", "land");
		insert("RURPB", "return");
		insert("HREF", "leave");
		insert("AEUR", "air");
		insert("TPHAEURT", "nature");
		insert("AEPBS/-D", "answered");
		insert("AOERT", "either");
		insert("HRAU", "law");
		insert("HEP", "help");
		insert("HRAEU", "lay");
		insert("POEUPBT", "point");
		insert("KHAOEULD", "child");
		insert("HRERT", "letter");
		insert("TPOUR", "four");
		insert("WEURB", "wish");
		insert("TPAOEUR", "fire");
		insert("KRAOEUD", "cried");
		insert("TWO/TWO*", "2");
		insert("WEUPL", "women");
		insert("SPAOEBG", "speak");
		insert("TPHUPL", "number");
		insert("TH-FR", "therefore");
		insert("HOUR", "hour");
		insert("TPREPBDZ", "friends");
		insert("HELD", "held");
		insert("TPRAOE", "free");
		insert("WAR", "war");
		insert("TKURG", "during");
		insert("SEFRL", "several");
		insert("PWEUS", "business");
		insert("WHR", "whether");
		insert("*E/R*", "er");
		insert("PHAERPB", "manner");
		insert("SEBGD", "second");
		insert("R-PB", "reason");
		insert("RE/PHRAOEUD", "replied");
		insert("AOUPBTD", "united");
		insert("KAUL", "call");
		insert("SKWREPBL", "general");
		insert("KWR", "why");
		insert("HEUPBD", "behind");
		insert("PWAEUPL", "became");
		insert("SKWROPB", "John");
		insert("PW-BG", "become");
		insert("TKED", "dead");
		insert("*ERT", "earth");
		insert("PWOEU", "boy");
		insert("HRO*S", "lost");
		insert("TPO*RT", "forth");
		insert("THOUD", "thousand");
		insert("HRAOG", "looking");
		insert("AOEUL", "I'll");
		insert("TPAEPL", "family");
		insert("SOUL", "soul");
		insert("TPAOEL", "feel");
		insert("KO*G", "coming");
		insert("TKPWHRAEPBD", "England");
		insert("SPEURT", "spirit");
		insert("KWE", "question");
		insert("KAEUR", "care");
		insert("TRAO*UT", "truth");
		insert("TKPWROUPBD", "ground");
		insert("R-L", "really");
		insert("REFT", "rest");
		insert("PHAOEPB", "mean");
		insert("TKEUFRT", "different");
		insert("PHAEUG", "making");
		insert("POB", "possible");
		insert("TPEL", "fell");
		insert("TORDZ", "towards");
		insert("HAOUPL", "human");
		insert("KEPT", "kept");
		insert("SHORT", "short");
		insert("TOUPB", "town");
		insert("TPOLG", "following");
		insert("TPHAOED", "need");
		insert("KAUS", "cause");
		insert("PHET", "met");
		insert("AOEPBG", "evening");
		insert("RURPBD", "returned");
		insert("TPAOEUF", "five");
		insert("STROPBG", "strong");
		insert("ABL", "able");
		insert("TPREFRPB", "French");
		insert("HREUF", "live");
		insert("HRA*ED", "lady");
		insert("SUBT", "subject");
		insert("S*P/TPH*", "Sn");
		insert("AEPBS", "answer");
		insert("SAE", "sea");
		insert("TPAOER", "fear");
		insert("URPBD", "understand");
		insert("HARD", "hard");
		insert("TERPLS", "terms");
		insert("TKOUT", "doubt");
		insert("ARPBD", "around");
		insert("SK", "ask");
		insert("ARPLS", "arms");
		insert("TURPB", "turn");
		insert("SEPBS", "sense");
		insert("SAOEPLS", "seems");
		insert("PWHRABG", "black");
		insert("PWREU", "bring");
		insert("TPOLD", "followed");
		insert("PWAOUFL", "beautiful");
		insert("KHROES", "close");
		insert("TKARBG", "dark");
		insert("HOLD", "hold");
		insert("KRAR", "character");
		insert("SORT", "sort");
		insert("SAOEUT", "sight");
		insert("TEPB", "ten");
		insert("SHOE", "show");
		insert("PAERT", "party");
		insert("TPAOEUPB", "fine");
		insert("KWR*/*E", "ye");
		insert("R-D", "ready");
		insert("STOER", "story");
		insert("KPHOPB", "common");
		insert("PWAOBG", "book");
		insert("TRO*PBG", "electronic");
		insert("TAUBG", "talk");
		insert("K-T", "account");
		insert("PHARBG", "mark");
		insert("TR", "interest");
		insert("WREUPB", "written");
		insert("K-PBT", "can't");
		insert("PWED", "bed");
		insert("TPHES", "necessary");
		insert("AEUPBLG", "age");
		insert("ELS", "else");
		insert("TPORS", "force");
		insert("KWR-D", "idea");
		insert("HRORPBG", "longer");
		insert("ART", "art");
		insert("SPOEBG", "spoke");
		insert("KRAOS", "across");
		insert("PWROER", "brother");
		insert("ERL", "early");
		insert("OT", "ought");
		insert("STAOEUPLS", "sometimes");
		insert("HRAOEUPB", "line");
		insert("SAEUG", "saying");
		insert("TAEUBL", "table");
		insert("A/PAOERD", "appeared");
		insert("REUFR", "river");
		insert("T-PBD", "continued");
		insert("AOEU", "eye");
		insert("*E/T*/KWR*", "ety");
		insert("SUPB", "sun");
		insert("TPH-FGS", "information");
		insert("HRAEURT", "later");
		insert("EFRG", "everything");
		insert("RAOEFPD", "reached");
		insert("SULD", "suddenly");
		insert("PAFT", "past");
		insert("HOURS", "hours");
		insert("STRAEUPBG", "strange");
		insert("TKAOEP", "deep");
		insert("KHAEUPBG", "change");
		insert("PHAOEULS", "miles");
		insert("TPAOELG", "feeling");
		insert("ABGT", "act");
		insert("PHAOET", "meet");
		insert("PAEUD", "paid");
		insert("TPURT", "further");
		insert("PURP", "purpose");
		insert("HAEP", "happy");
		insert("AD/-D", "added");
		insert("SAOEPL", "seem");
		insert("TAEUG", "taking");
		insert("PWHRAOD", "blood");
		insert("ROEZ", "rose");
		insert("SOUT", "south");
		insert("KWROPBD", "beyond");
		insert("KOELD", "cold");
		insert("TPHAOERT", "neither");
		insert("TPAORD", "forward");
		insert("SRAOU", "view");
		insert("AOEUF", "I've");
		insert("POGS", "position");
		insert("SOUPBD", "sound");
		insert("TPHOPB", "none");
		insert("SPWR-D", "entered");
		insert("KHRAOER", "clear");
		insert("RAOD", "road");
		insert("HRAEUT", "late");
		insert("STAPBD", "stand");
		insert("SPOS", "suppose");
		insert("HRA", "la");
		insert("TKAUR", "daughter");
		insert("RAEL", "real");
		insert("TPHAOERL", "nearly");
		insert("PHAOEUPB", "mine");
		insert("HRAUS", "laws");
		insert("TPHOPBLG", "knowledge");
		insert("KOPLS", "comes");
		insert("TORD", "toward");
		insert("PWAD", "bad");
		insert("KUT", "cut");
		insert("KO*EP", "copy");
		insert("HUS", "husband");
		insert("SEUBGS", "six");
		insert("TPRAPBS", "France");
		insert("HREUFG", "living");
		insert("PAES", "peace");
		insert("TK-PBT", "didn't");
		insert("HROE", "low");
		insert("TPHORT", "north");
		insert("RER", "remember");
		insert("EFBGT", "effect");
		insert("TPHARL", "natural");
		insert("PREUT", "pretty");
		insert("TPAUL", "fall");
		insert("TPAEUR", "fair");
		insert("S-FS", "service");
		insert("PWHRO", "below");
		insert("KPEPT", "except");
		insert("PHERPB", "American");
		insert("HAEUR", "hair");
		insert("HROPBD/OPB", "London");
		insert("HRAEUD", "laid");
		insert("PAS", "pass");
		insert("HRED", "led");
		insert("KO*EP/RAOEUT", "copyright");
		insert("TK*G", "doing");
		insert("AERPL", "army");
		insert("RUPB", "run");
		insert("HORS", "horse");
		insert("TPAOURT", "future");
		insert("OEPD", "opened");
		insert("PHRERB", "pleasure");
		insert("HEUFRT", "history");
		insert("WEFT", "west");
		insert("PAEU", "pay");
		insert("RED", "red");
		insert("APB/AE", "an'");
		insert("TPOUR/TPO*UR", "4");
		insert("HA*T", "hath");
		insert("TPHOET", "note");
		insert("HR*T", "although");
		insert("WAPBTD", "wanted");
		insert("TKPWOELD", "gold");
		insert("PHAEUBGS", "makes");
		insert("STKAOEUR", "desire");
		insert("PHRAEU", "play");
		insert("PHAFRT", "master");
		insert("OFS", "office");
		insert("TRAOEUD", "tried");
		insert("TPROPBT", "front");
		insert("PWEUG", "big");
		insert("TKR-FPLT", "Dr.");
		insert("HREUFD", "lived");
		insert("SERPBL", "certainly");
		insert("WEUPBD", "wind");
		insert("SAOEF", "receive");
		insert("TAEPBGS", "attention");
		insert("TKPWOFT", "government");
		insert("UPB/TO", "unto");
		insert("KHUFRPB", "church");
		insert("STREPBG", "strength");
		insert("HREPBG", "length");
		insert("K-P", "company");
		insert("PHRAEUFD", "placed");
		insert("PAEUP", "paper");
		insert("HRERTS", "letters");
		insert("PROBL", "probably");
		insert("TKPWHRAD", "glad");
		insert("PORPB", "important");
		insert("EPS", "especially");
		insert("TKPWRAERT", "greater");
		insert("KWRO*URS", "yourself");
		insert("TP*EL", "fellow");
		insert("PWAER", "bear");
		insert("P-PB", "opinion");
		insert("WOEUPBD", "window");
		insert("RAPB", "ran");
		insert("TPA*EUT", "faith");
		insert("AG", "ago");
		insert("TKPWRAOEPLT", "agreement");
		insert("KHARPBLG", "charge");
		insert("PWAOUT", "beauty");
		insert("HREUPS", "lips");
		insert("RE/PHAEUPBD", "remained");
		insert("ARPL", "arm");
		insert("HRART", "latter");
		insert("TKAOUT", "duty");
		insert("SEPBD", "send");
		insert("STKAPBS", "distance");
		insert("SHREPBS", "silence");
		insert("TPAOT", "foot");
		insert("WAOEULD", "wild");
		insert("OBT", "object");
		insert("TKAOEU", "die");
		insert("SAF", "save");
		insert("SKWRA*PL", "gentleman");
		insert("TRAOES", "trees");
		insert("TKPWRAOEPB", "green");
		insert("TRUBL", "trouble");
		insert("SPHAOEUL", "smile");
		insert("PWAOBGS", "books");
		insert("WROPBG", "wrong");
		insert("SRAEURS", "various");
		insert("SHRAOEP", "sleep");
		insert("PERPBS", "persons");
		insert("PWHROBG/TK-LS/KWOET", "blockquote");
		insert("HAPD", "happened");
		insert("PHRAR", "particular");
		insert("TKRAOU", "drew");
		insert("PHEUPBS", "minutes");
		insert("HA*RLD", "hardly");
		insert("WAUBGD", "walked");
		insert("KHAOEF", "chief");
		insert("KHAPBS", "chance");
		insert("KORG", "according");
		insert("TKPWEUPB/-G", "beginning");
		insert("*BGS", "action");
		insert("TKAOEL", "deal");
		insert("HROFD", "loved");
		insert("SREUFT", "visit");
		insert("THEUG", "thinking");
		insert("TPOL", "follow");
		insert("STAPBG", "standing");
		insert("TPHOEZ", "knows");
		insert("TREU", "try");
		insert("PREPBS", "presence");
		insert("HOEUF", "heavy");
		insert("SWAOET", "sweet");
		insert("PHRAEUPB", "plain");
		insert("TKOEPBGS/-S", "donations");
		insert("PHAOELD", "immediately");
		insert("WRO", "wrote");
		insert("PHO*UT", "mouth");
		insert("REUFP", "rich");
		insert("THAUTS", "thoughts");
		insert("PHO*PBTS", "months");
		insert("*U", "u");
		insert("WOEPBT", "won't");
		insert("A/TPRAEUD", "afraid");
		insert("PA*EURS", "Paris");
		insert("SEUPBLG", "single");
		insert("SKWROEU", "joy");
		insert("TPHAEPL", "enemy");
		insert("PWROEPB", "broken");
		insert("TPH-LS", "unless");
		insert("STAEUTS", "states");
		insert("SHEUP", "ship");
		insert("K-PB", "condition");
		insert("KAER", "carry");
		insert("SKHRAEUPLD", "exclaimed");
		insert("KHRUG", "including");
		insert("TPEULD", "filled");
		insert("SAOEG", "seeing");
		insert("WEPBS", "influence");
		insert("WREU", "write");
		insert("PWOEUS", "boys");
		insert("A/PAOER", "appear");
		insert("OUDZ", "outside");
		insert("SKRET", "secret");
		insert("PARTS", "parts");
		insert("PHRES", "please");
		insert("PAOERPBS", "appearance");
		insert("AOEFL", "evil");
		insert("PHAFRPB", "march");
		insert("SKWRORPBLG", "George");
		insert("WHAF", "whatever");
		insert("SHROEL", "slowly");
		insert("TAERS", "tears");
		insert("HORS/-S", "horses");
		insert("PHRAEUFS", "places");
		insert("KAUT", "caught");
		insert("STAEU", "stay");
		insert("STPHED", "instead");
		insert("STRUBG", "struck");
		insert("PWHRU", "blue");
		insert("KWRORBG", "York");
		insert("EUPL/POB", "impossible");
		insert("PAOERD", "period");
		insert("ST-R", "sister");
		insert("PWA*LT", "battle");
		insert("SKAOL", "school");
		insert("PHA*ER", "Mary");
		insert("RA*EUFD", "raised");
		insert("KWAEUGS", "occasion");
		insert("PHAERD", "married");
		insert("PHAPB/AES", "man's");
		insert("TPRORPL", "former");
		insert("TPAOD", "food");
		insert("KWRAO*UT", "youth");
		insert("HRERPBD", "learned");
		insert("PHAOERL", "merely");
		insert("RAOEFP", "reach");
		insert("S-PL", "system");
		insert("TWEPBT", "twenty");
		insert("TKEURPB", "dinner");
		insert("KWAO*EUT", "quiet");
		insert("AOELS", "easily");
		insert("PHOFD", "moved");
		insert("A*FRDZ", "afterwards");
		insert("TKPWEUFG", "giving");
		insert("WAUBG", "walk");
		insert("STOPD", "stopped");
		insert("HRAFD", "laughed");
		insert("HRAPBL", "language");
		insert("EBGS/PREGS", "expression");
		insert("WAOEBG", "week");
		insert("HAUL", "hall");
		insert("TKAEUPBLG", "danger");
		insert("PROT", "property");
		insert("WOPBD", "wonder");
		insert("AOURB", "usual");
		insert("TPEUG", "figure");
		insert("PWORPB", "born");
		insert("KORT", "court");
		insert("SKWRERPBL", "generally");
		insert("TKPWRAOU", "grew");
		insert("SHOED", "showed");
		insert("TKPWEGT", "getting");
		insert("AEURBT", "ancient");
		insert("R-PT", "respect");
		insert("THEURD", "third");
		insert("WO*RT", "worth");
		insert("S*EUPL", "simple");
		insert("TRAOE", "tree");
		insert("HREFG", "leaving");
		insert("RAEUPL", "remain");
		insert("SOET", "society");
		insert("TPAOEUT", "fight");
		insert("WAUL", "wall");
		insert("RULT", "result");
		insert("HEFPB", "heaven");
		insert("WOEUPL", "William");
		insert("STARTD", "started");
		insert("KPHAPBD", "command");
		insert("TOEPB", "tone");
		insert("RARD", "regard");
		insert("KP-PTD", "expected");
		insert("PHAOER", "mere");
		insert("PHO*PBT", "month");
		insert("PWE/SAOEUD", "beside");
		insert("SHREPBT", "silent");
		insert("P-F", "perfect");
		insert("SPAOERPBS", "experience");
		insert("STRAOET", "street");
		insert("WREUG", "writing");
		insert("TKPW-S", "goes");
		insert("SEURBGS", "circumstances");
		insert("SPWAOEURL", "entirely");
		insert("TPRERB", "fresh");
		insert("TKAOUBG", "duke");
		insert("KOFRD", "covered");
		insert("PWOUPBD", "bound");
		insert("AOEFT", "east");
		insert("WAOD", "wood");
		insert("STOEPB", "stone");
		insert("KWEULG", "quickly");
		insert("TPH-TS", "notice");
		insert("PWRAOEUT", "bright");
		insert("KRAOEUFT", "Christ");
		insert("PWOET", "boat");
		insert("TPHOEBL", "noble");
		insert("PHEPBT", "meant");
		insert("SWHA", "somewhat");
		insert("SUD", "sudden");
		insert("SRAOUL", "value");
		insert("KR*/TP-PL", "c.");
		insert("TKREBGS", "direction");
		insert("KHAEUR", "chair");
		insert("TKAOU", "due");
		insert("SPOR", "support");
		insert("TOPL", "Tom");
		insert("TKAEUT", "date");
		insert("WAEUGT", "waiting");
		insert("KREUGS", "Christian");
		insert("SREULG", "village");
		insert("HREUFS", "lives");
		insert("RAEGD", "reading");
		insert("TKPWRAE", "agree");
		insert("HRAOEUPBS", "lines");
		insert("KR-D", "considered");
		insert("TPAOELD", "field");
		insert("OEBD", "observed");
		insert("SKAEURS/HREU", "scarcely");
		insert("WEURBD", "wished");
		insert("WAEUT", "wait");
		insert("TKPWRAET/EFT", "greatest");
		insert("PERPLGS", "permission");
		insert("SKES", "success");
		insert("PAOES", "piece");
		insert("PWREURB", "British");
		insert("EBGS", "ex");
		insert("KHARLS", "Charles");
		insert("TPORPLD", "formed");
		insert("SPAOEG", "speaking");
		insert("TRAOEUG", "trying");
		insert("K-FRGS", "conversation");
		insert("PROR", "proper");
		insert("HEUL", "hill");
		insert("PHAOUFBG", "music");
		insert("TAOUPBT", "opportunity");
		insert("TH-TS", "that's");
		insert("SKWR*ERPB", "German");
		insert("AFPB", "afternoon");
		insert("KRAOEU", "cry");
		insert("KOFT", "cost");
		insert("HRO*UD", "allowed");
		insert("TKPWEURLS", "girls");
		insert("KR-BL", "considerable");
		insert("KR*", "c");
		insert("PWROEBG", "broke");
		insert("HO*RPB/A*U", "honour");
		insert("SEFPB", "seven");
		insert("PRAOEUFT", "private");
		insert("SEUT", "sit");
		insert("TPHUS", "news");
		insert("TOP", "top");
		insert("SAEPB", "scene");
		insert("SKOFD", "discovered");
		insert("PHAERPBLG", "marriage");
		insert("STEP", "step");
		insert("TKPWA*RPB", "garden");
		insert("RAEUS", "race");
		insert("TKPWEUPB", "begin");
		insert("PER", "per");
		insert("SREUD", "individual");
		insert("SEUGT", "sitting");
		insert("HRERPB", "learn");
		insert("PHREU/K-L", "political");
		insert("TKEUFL", "difficult");
		insert("PWEUT", "bit");
		insert("SPAOEFP", "speech");
		insert("HEPB/REU", "Henry");
		insert("HRAOEU", "lie");
		insert("KAFT", "cast");
		insert("AOET", "eat");
		insert("THORT", "authority");
		insert("*ETS", "etc.");
		insert("TPHRAOR", "floor");
		insert("EUL", "ill");
		insert("WAEUS", "ways");
		insert("OEUFRS", "officers");
		insert("OFRD", "offered");
		insert("ORPBLG", "original");
		insert("HAEP/-PBS", "happiness");
		insert("TPHRO*URS", "flowers");
		insert("PRO*UD", "produced");
		insert("SAOURPL", "summer");
		insert("PROEFD", "provide");
		insert("STOEU", "study");
		insert("RE/HREUGS", "religion");
		insert("P*EUFP", "picture");
		insert("WAULS", "walls");
		insert("PERPBL", "personal");
		insert("PHERBG", "America");
		insert("WAFP", "watch");
		insert("PHREFD", "pleased");
		insert("HREFS", "leaves");
		insert("TKE/KHRAEURD", "declared");
		insert("HOT", "hot");
		insert("*URPBD", "understood");
		insert("EFRT", "effort");
		insert("PRAOEPD", "prepared");
		insert("SKA*EUP", "escape");
		insert("A/TEPLT", "attempt");
		insert("SPOED", "supposed");
		insert("KEULD", "killed");
		insert("TPAFT", "fast");
		insert("THOER", "author");
		insert("EUPBD/KWRAPB", "Indian");
		insert("PWROUPB", "brown");
		insert("TKERPLD", "determined");
		insert("PAEUPB", "pain");
		insert("SPREUPBG", "spring");
		insert("TAEUBGS", "takes");
		insert("TKRAUPB", "drawn");
		insert("SHRERPBLGS", "soldiers");
		insert("HO*UFS", "houses");
		insert("TPHAO*ET", "beneath");
		insert("TAUG", "talking");
		insert("TURPBG", "turning");
		insert("KROEURPBT", "century");
		insert("STEPS", "steps");
		insert("SPWEPBD/-D", "intended");
		insert("SOFT", "soft");
		insert("STRAEUT", "straight");
		insert("PHAERTS", "matters");
		insert("HRAOEULG", "likely");
		insert("KRORPB", "corner");
		insert("TRAEUD/PHARBG", "trademark");
		insert("SKWRUFS", "justice");
		insert("SAO*EPL", "simply");
		insert("PROU", "produce");
		insert("TRUFT", "trust");
		insert("A/PAOERS", "appears");
		insert("RO*EPL", "Rome");
		insert("HRAF", "laugh");
		insert("TPORGT", "forget");
		insert("AO*URP", "Europe");
		insert("PAFPBLG", "passage");
		insert("AET", "eight");
		insert("KHROEFD", "closed");
		insert("OUR/SEFS", "ourselves");
		insert("TKPWEUFS", "gives");
		insert("TKRES", "dress");
		insert("PAFG", "passing");
		insert("TERBL", "terrible");
		insert("RAOEURD", "required");
		insert("PHAOEPLD", "medium");
		insert("EFRTS", "efforts");
		insert("SAEUBG", "sake");
		insert("PWR*ET", "breath");
		insert("WAOEUS", "wise");
		insert("HRAEUDZ", "ladies");
		insert("PEFGS", "possession");
		insert("PHREFPBT", "pleasant");
		insert("P-FRL", "perfectly");
		insert("O*/TK-LS/AE", "o'");
		insert("PHOEURPL", "memory");
		insert("AOURBL", "usually");
		insert("TKPWRAEUF", "grave");
		insert("TPEUFD", "fixed");
		insert("PHOERPB", "modern");
		insert("SPOT", "spot");
		insert("TRAOPS", "troops");
		insert("RAOEUZ", "rise");
		insert("PWRAEBG", "break");
		insert("TPAEFT", "fifty");
		insert("AOEULD", "island");
		insert("PHAOEGT", "meeting");
		insert("KAFRP", "camp");
		insert("TPH-GS", "nation");
		insert("KPEUFS", "existence");
		insert("RE/PHRAOEU", "reply");
		insert("AOEUD", "I'd");
		insert("KO*EPS", "copies");
		insert("SKAOEU", "sky");
		insert("TUFP", "touch");
		insert("KWAL", "equal");
		insert("TP-RPB", "fortune");
		insert("SR*/TP-PL", "v.");
		insert("SHOR", "shore");
		insert("TKPHAEUPB", "domain");
		insert("TPHAEUPLD", "named");
		insert("SEUFP", "situation");
		insert("HRAOBGS", "looks");
		insert("PROPLS", "promise");
		insert("ORDZ", "orders");
		insert("TKEG", "degree");
		insert("PH*EULD", "middle");
		insert("WEURPBT", "winter");
		insert("PHRAPB", "plan");
		insert("SPEPBT", "spent");
		insert("HROU", "allow");
		insert("PAEL", "pale");
		insert("KUBGT", "conduct");
		insert("R*UPBG", "running");
		insert("RE/HREURBS", "religious");
		insert("SPRAOEUS", "surprise");
		insert("PHEUPB", "minute");
		insert("RO*EPB", "Roman");
		insert("KAEUSZ", "cases");
		insert("SHOT", "shot");
		insert("HRAED", "lead");
		insert("PHOF", "move");
		insert("TPHAEUPLS", "names");


  }
  void sendBuffer(){
	  for(int n = 0; n < bufferItemsNumber; n++){
			strcpy(result, (search(charbuffer)));
		  }

		  for(int n = 0; n < strlen(result); n++){
		  Set_Character(result[n]);
		  Send_Character();
		  }
		  Set_Character(' ');
		  Send_Character();
		  bufferItemsNumber = 0;
		  Clear_Buffer();
  }
  void translation(int n, char c){
  	  if(n == 1){
  		  sendBuffer();
  	  }
  	  else{
  		  charbuffer[bufferItemsNumber] = c;
  		  bufferItemsNumber += 1;
  	  }
    }
  void CounterRestart(){
	  HAL_TIM_Base_Stop_IT(&htim10);
	  __HAL_TIM_SET_COUNTER(&htim10, 0);
	  elapsedTime = 0;
	  HAL_TIM_Base_Start_IT(&htim10);
  }

  void Send_Gate(int n, char c) {
	  if(previousChar == 0 && n == 24){
		  return;
	  }
  	  if(previousChar < n || n == 1 || n == 24){
  		  if(n != lastPress){
  			  timeout = 0;
  		  }
  		  else{
  			  timeout +=1;
  			  }

  		  if(timeout >= 1200 || timeout == 0){
  			  translation(n, c);
  			  CounterRestart();


  		  }

  		  previousChar = n;
  		  if(n == 24){
			  previousChar = 0;
		  }
  		 }
    }
  void BackSpace(){
	  if(lastPress != 1){
		  timeoutB = 0;
	  }
	  else{
		  timeoutB +=1;
	  }
	  if(timeoutB == 0 || timeoutB >= 1500){
		  Set_Character('#');
		  Send_Character();
		  timeoutB = 1;
	  }

  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    uint8_t pressed_key;
    hashInit();
    while (1)
    {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  	  // Initialize GPIOs for keyboard matrix
    pressed_key = Scan_KeyMatrix();

  	if(pressed_key != 0 && activeTimer == 0){
  		HAL_TIM_Base_Start_IT(&htim10);
  		activeTimer = 1;
  	}
  	if(elapsedTime >= activeTimeLimit){
  		HAL_TIM_Base_Stop_IT(&htim10);
  		activeTimer = 0;
  		elapsedTime = 0;

		Send_Gate(1, ' ');
		lastPress = 1;
  	}
  	switch (pressed_key) {
  	    case 1:
  	    	BackSpace();
			break;
  	    case 2:
		  counter2 += 1;
		  if (counter2 >= 3) {
			Send_Gate(2, 'S');
			lastPress = 2;
			  counter2 = 0;
		  }
  	        break;
  	    case 3:
  		  counter3 += 1;
  		  if (counter3 >= 3) {
  			Send_Gate(3, 'T');
  			lastPress = 3;
  			  counter3 = 0;
  		  }
  	        break;
  	    case 4:
		  counter4 += 1;
		  if (counter4 >= 3) {
			Send_Gate(4, 'K');
			lastPress = 4;
			  counter4 = 0;
		  }
  	        break;
  	    case 5:
		  counter5 += 1;
		  if (counter5 >= 3) {
			Send_Gate(5, 'P');
			lastPress = 5;
			  counter5 = 0;
    		  }
  	        break;
  	    case 6:
		  counter6 += 1;
		if (counter6 >= 3) {
			Send_Gate(6, 'W');
			lastPress = 6;
			  counter6 = 0;
    		  }
  	        break;
  	    case 7:
		  counter7 += 1;
		  if (counter7 >= 3) {
			Send_Gate(7, 'H');
			lastPress = 7;
			  counter7 = 0;
    		  }
  	        break;
  	    case 8:
		  counter8 += 1;
		  if (counter8 >= 3) {
			Send_Gate(8, 'R');
			lastPress = 8;
			  counter8 = 0;
    		  }
  	        break;
  	    case 9:
		  counter9 += 1;
		  if (counter9 >= 3) {
			Send_Gate(9, 'A');
			lastPress = 9;
			  counter9 = 0;
    		  }
  	        break;
  	    case 10:
		  counter10 += 1;
		  if (counter10 >= 3) {
			Send_Gate(10, 'O');
			lastPress = 10;
			  counter10 = 0;
    		  }
  	        break;
  	    case 11:
		  counter11 += 1;
		  if (counter11 >= 3) {
			Send_Gate(11, '*');
			lastPress = 11;
			  counter11 = 0;
    		  }
  	        break;
  	    case 12:
		  counter12 += 1;
		  if (counter12 >= 3) {
			Send_Gate(12, 'E');
			lastPress = 12;
			  counter12 = 0;
    		  }
  	        break;
  	    case 13:
		  counter13 += 1;
		  if (counter13 >= 3) {
			Send_Gate(13, 'U');
			lastPress = 13;
			  counter13 = 0;
		  }
  	        break;
  	    case 14:
		  counter14 += 1;
		  if (counter14 >= 3) {
			Send_Gate(14, 'F');
			lastPress = 14;
			  counter14 = 0;
		  }
  	        break;
  	    case 15:
		  counter15 += 1;
		  if (counter15 >= 3) {
			Send_Gate(15, 'R');
			lastPress = 15;
			  counter15 = 0;
		  }
  	        break;
  	    case 16:
		  counter16 += 1;
		  if (counter16 >= 3) {
			Send_Gate(16, 'P');
			lastPress = 16;
			  counter16 = 0;
		  }
  	        break;
  	    case 17:
		  counter17 += 1;
		  if (counter17 >= 3) {
			Send_Gate(17, 'B');
			lastPress = 17;
			  counter17 = 0;
		  }
  	        break;
  	    case 18:
		  counter18 += 1;
		  if (counter18 >= 3) {
			Send_Gate(18, 'L');
			lastPress = 18;
			  counter18 = 0;
		  }
  	        break;
  	    case 19:
		  counter19 += 1;
		  if (counter19 >= 3) {
			Send_Gate(19, 'G');
			lastPress = 19;
			  counter19 = 0;
		  }
  	        break;
  	    case 20:
		  counter20 += 1;
		  if (counter20 >= 3) {
			Send_Gate(20, 'T');
			lastPress = 20;
			  counter20 = 0;
		  }
  	        break;
  	    case 21:
		  counter21 += 1;
		  if (counter21 >= 3) {
			Send_Gate(21, 'S');
			lastPress = 21;
			  counter21 = 0;
		  }
  	        break;
  	    case 22:
		  counter22 += 1;
		  if (counter22 >= 3) {
			Send_Gate(22, 'D');
			lastPress = 22;
			  counter22 = 0;
		  }
  	        break;
  	    case 23:
		  counter23 += 1;
		  if (counter23 >= 3) {
			Send_Gate(23, 'Z');
			lastPress = 23;
			  counter23 = 0;
		  }
  	        break;
  	    case 24:
		  counter24 += 1;
		  if (counter24 >= 3) {
			Send_Gate(24, '/');
			lastPress = 24;
			  counter24 = 0;
		  }
				break;
  	    default:
  	        break;
  		}
  	}

  }

  /* USER CODE END 3 */

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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM10 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM10_Init(void)
{

  /* USER CODE BEGIN TIM10_Init 0 */

  /* USER CODE END TIM10_Init 0 */

  /* USER CODE BEGIN TIM10_Init 1 */

  /* USER CODE END TIM10_Init 1 */
  htim10.Instance = TIM10;
  htim10.Init.Prescaler = 10000 - 1;
  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim10.Init.Period = 1000 - 1;
  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim10) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM10_Init 2 */

  /* USER CODE END TIM10_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Column1_Pin|Column2_Pin|Column3_Pin|Column4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Column5_Pin|Column6_Pin|Column7_Pin|Column8_Pin
                          |Column11_Pin|Column10_Pin|Column9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Row1_Pin Row2_Pin Row3_Pin Row4_Pin */
  GPIO_InitStruct.Pin = Row1_Pin|Row2_Pin|Row3_Pin|Row4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Column1_Pin Column2_Pin Column3_Pin Column4_Pin */
  GPIO_InitStruct.Pin = Column1_Pin|Column2_Pin|Column3_Pin|Column4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Column5_Pin Column6_Pin Column7_Pin Column8_Pin
                           Column11_Pin Column10_Pin Column9_Pin */
  GPIO_InitStruct.Pin = Column5_Pin|Column6_Pin|Column7_Pin|Column8_Pin
                          |Column11_Pin|Column10_Pin|Column9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    		if(htim == &htim10){
    			elapsedTime++;
    		}
    	}
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
