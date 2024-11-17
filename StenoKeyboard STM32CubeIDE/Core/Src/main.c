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
#define KEY_GRAVE 0x35 // ` and ~
#define KEY_COMM 0x36 // , and <
#define KEY_DOT 0x37 // . and >
#define KEY_SLASH 0x38 // / and ?
#define KEY_CAPSLOCK 0x39 // Caps Lock

#define MAX_KEY_SIZE 2000
#define MAX_VALUE_SIZE 2000
#define TABLE_SIZE 2000

#define TIME_LIMIT 2
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
					keyBoardHIDsub.MODIFIER=0x02;
					keyBoardHIDsub.KEYCODE2=KEY_3;
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
			default:
					keyBoardHIDsub.MODIFIER=0x00;
					keyBoardHIDsub.KEYCODE2=0x00;
				break;
	  	  }
  }
  void Test_Send(){
	  char str[] = "hello";
	  int l = strlen(str);
	  for(int i = 0; i < l; i++){
		  Set_Character(str[i]);
		  Send_Character();
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

      HashEntry *entry = (HashEntry *)malloc(sizeof(HashEntry));
      strcpy(entry->key, key);
      strcpy(entry->value, value);

      hashTable[index] = entry;
  }

  const char *search(const char *key) {
      unsigned int index = hashFunction(key);

      if (hashTable[index] != NULL && strcmp(hashTable[index]->key, key) == 0) {
          return hashTable[index]->value;
      }
      return NULL;
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
  		  }

  		  previousChar = n;
  		  if(n == 24){
			  previousChar = 0;
			  activeTimeLimit = activeTimeLimit + TIME_LIMIT;
		  }
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

  		Set_Character(' ');
		Send_Gate(1, ' ');
		lastPress = 1;
  	}
  	switch (pressed_key) {
  	    case 1:
  	    	/*


			Read_File_Test();
			Test_Send();
#############################################


##############################################



  	    	*/

  	    case 2:
		  counter2 += 1;
		  if (counter2 >= 3) {
			Set_Character('S');
			Send_Gate(2, 'S');
			lastPress = 2;
			  counter2 = 0;
		  }
  	        break;
  	    case 3:
  		  counter3 += 1;
  		  if (counter3 >= 3) {
  			Set_Character('T');
  			Send_Gate(3, 'T');
  			lastPress = 3;
  			  counter3 = 0;
  		  }
  	        break;
  	    case 4:
		  counter4 += 1;
		  if (counter4 >= 3) {
			  Set_Character('K');
			Send_Gate(4, 'K');
			lastPress = 4;
			  counter4 = 0;
		  }
  	        break;
  	    case 5:
		  counter5 += 1;
		  if (counter5 >= 3) {
			  Set_Character('P');
			Send_Gate(5, 'P');
			lastPress = 5;
			  counter5 = 0;
    		  }
  	        break;
  	    case 6:
		  counter6 += 1;
		if (counter6 >= 3) {
			  Set_Character('W');
			Send_Gate(6, 'W');
			lastPress = 6;
			  counter6 = 0;
    		  }
  	        break;
  	    case 7:
		  counter7 += 1;
		  if (counter7 >= 3) {
			  Set_Character('H');
			Send_Gate(7, 'H');
			lastPress = 7;
			  counter7 = 0;
    		  }
  	        break;
  	    case 8:
		  counter8 += 1;
		  if (counter8 >= 3) {
			  Set_Character('R');
			Send_Gate(8, 'R');
			lastPress = 8;
			  counter8 = 0;
    		  }
  	        break;
  	    case 9:
		  counter9 += 1;
		  if (counter9 >= 3) {
			  Set_Character('A');
			Send_Gate(9, 'A');
			lastPress = 9;
			  counter9 = 0;
    		  }
  	        break;
  	    case 10:
		  counter10 += 1;
		  if (counter10 >= 3) {
			  Set_Character('O');
			Send_Gate(10, 'O');
			lastPress = 10;
			  counter10 = 0;
    		  }
  	        break;
  	    case 11:
		  counter11 += 1;
		  if (counter11 >= 3) {
			  Set_Character('*');
			Send_Gate(11, '*');
			lastPress = 11;
			  counter11 = 0;
    		  }
  	        break;
  	    case 12:
		  counter12 += 1;
		  if (counter12 >= 3) {
			  Set_Character('E');
			Send_Gate(12, 'E');
			lastPress = 12;
			  counter12 = 0;
    		  }
  	        break;
  	    case 13:
		  counter13 += 1;
		  if (counter13 >= 3) {
			  Set_Character('U');
			Send_Gate(13, 'U');
			lastPress = 13;
			  counter13 = 0;
		  }
  	        break;
  	    case 14:
		  counter14 += 1;
		  if (counter14 >= 3) {
			  Set_Character('F');
			Send_Gate(14, 'F');
			lastPress = 14;
			  counter14 = 0;
		  }
  	        break;
  	    case 15:
		  counter15 += 1;
		  if (counter15 >= 3) {
			  Set_Character('R');
			Send_Gate(15, 'R');
			lastPress = 15;
			  counter15 = 0;
		  }
  	        break;
  	    case 16:
		  counter16 += 1;
		  if (counter16 >= 3) {
			  Set_Character('P');
			Send_Gate(16, 'P');
			lastPress = 16;
			  counter16 = 0;
		  }
  	        break;
  	    case 17:
		  counter17 += 1;
		  if (counter17 >= 3) {
			  Set_Character('B');
			Send_Gate(17, 'B');
			lastPress = 17;
			  counter17 = 0;
		  }
  	        break;
  	    case 18:
		  counter18 += 1;
		  if (counter18 >= 3) {
			  Set_Character('L');
			Send_Gate(18, 'L');
			lastPress = 18;
			  counter18 = 0;
		  }
  	        break;
  	    case 19:
		  counter19 += 1;
		  if (counter19 >= 3) {
			  Set_Character('G');
			Send_Gate(19, 'G');
			lastPress = 19;
			  counter19 = 0;
		  }
  	        break;
  	    case 20:
		  counter20 += 1;
		  if (counter20 >= 3) {
			  Set_Character('T');
			Send_Gate(20, 'T');
			lastPress = 20;
			  counter20 = 0;
		  }
  	        break;
  	    case 21:
		  counter21 += 1;
		  if (counter21 >= 3) {
			  Set_Character('S');
			Send_Gate(21, 'S');
			lastPress = 21;
			  counter21 = 0;
		  }
  	        break;
  	    case 22:
		  counter22 += 1;
		  if (counter22 >= 3) {
			  Set_Character('D');
			Send_Gate(22, 'D');
			lastPress = 22;
			  counter22 = 0;
		  }
  	        break;
  	    case 23:
		  counter23 += 1;
		  if (counter23 >= 3) {
			  Set_Character('Z');
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
  htim10.Init.Period = 10000 - 1;
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
