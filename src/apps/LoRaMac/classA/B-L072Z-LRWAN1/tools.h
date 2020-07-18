/*!
 * \file      tools.h
 *
 * \brief     parameters and sensor functions
 *
 * \author    Alexandro Vanderley dos Santos
 */

#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdio.h>
#include "gpio.h"

//Registradores do Sensor LSM303AGR (Magnetômetro e acelerômetro)
#define LSM303AGR_ADDRESS_A         0x19
#define LSM303AGR_ADDRESS_M         0x1E
#define LSM303AGR_DEVICE_ID_A       0x33
#define LSM303AGR_DEVICE_ID_M       0x40
#define LSM303AGR_STATUS_REG_AUX_A 	0x07
#define LSM303AGR_OUT_TEMP_L_A 		0x0C
#define LSM303AGR_OUT_TEMP_H_A 		0x0D
#define LSM303AGR_INT_COUNTER_REG_A 0x0E
#define LSM303AGR_WHO_AM_I_A 		0x0F
#define LSM303AGR_TEMP_CFG_REG_A 	0x1F
#define LSM303AGR_CTRL_REG1_A 		0x20
#define LSM303AGR_CTRL_REG2_A 		0x21
#define LSM303AGR_CTRL_REG3_A 		0x22
#define LSM303AGR_CTRL_REG4_A 		0x23
#define LSM303AGR_CTRL_REG5_A 		0x24
#define LSM303AGR_CTRL_REG6_A 		0x25
#define LSM303AGR_REF_DATACAP_A 	0x26
#define LSM303AGR_STATUS_REG_A 		0x27
#define LSM303AGR_OUT_X_L_A 		0x28
#define LSM303AGR_OUT_X_H_A 		0x29
#define LSM303AGR_OUT_Y_L_A 		0x2A
#define LSM303AGR_OUT_Y_H_A 		0x2B
#define LSM303AGR_OUT_Z_L_A 		0x2C
#define LSM303AGR_OUT_Z_H_A 		0x2D
#define LSM303AGR_FIFO_CTRL_REG_A 	0x2E
#define LSM303AGR_FIFO_SRC_REG_A 	0x2F
#define LSM303AGR_INT1_CFG_A 		0x30
#define LSM303AGR_INT1_SRC_A 		0x31
#define LSM303AGR_INT1_THS_A 		0x32
#define LSM303AGR_INT1_DURATION_A 	0x33
#define LSM303AGR_INT2_CFG_A 		0x34
#define LSM303AGR_INT2_SRC_A 		0x35
#define LSM303AGR_INT2_THS_A 		0x36
#define LSM303AGR_INT2_DURATION_A 	0x37
#define LSM303AGR_CLICK_CFG_A 		0x38
#define LSM303AGR_CLICK_SRC_A 		0x39
#define LSM303AGR_CLICK_THS_A 		0x3A
#define LSM303AGR_TIME_LIMIT_A 		0x3B
#define LSM303AGR_TIME_LATENCY_A 	0x3C
#define LSM303AGR_TIME_WINDOW_A 	0x3D
#define LSM303AGR_Act_THS_A 		0x3E
#define LSM303AGR_Act_DUR_A 		0x3F
#define LSM303AGR_OFFSET_X_REG_L_M 	0x45
#define LSM303AGR_OFFSET_X_REG_H_M 	0x46
#define LSM303AGR_OFFSET_Y_REG_L_M 	0x47
#define LSM303AGR_OFFSET_Y_REG_H_M 	0x48
#define LSM303AGR_OFFSET_Z_REG_L_M 	0x49
#define LSM303AGR_OFFSET_Z_REG_H_M 	0x4A
#define LSM303AGR_WHO_AM_I_M 		0x4F
#define LSM303AGR_CFG_REG_A_M 		0x60
#define LSM303AGR_CFG_REG_B_M 		0x61
#define LSM303AGR_CFG_REG_C_M 		0x62
#define LSM303AGR_INT_CTRL_REG_M 	0x63
#define LSM303AGR_INT_SOURCE_REG_M 	0x64
#define LSM303AGR_INT_THS_L_REG_M 	0x65
#define LSM303AGR_INT_THS_H_REG_M 	0x66
#define LSM303AGR_STATUS_REG_M 		0x67
#define LSM303AGR_OUTX_L_REG_M		0x68 
#define LSM303AGR_OUTX_H_REG_M 		0x69
#define LSM303AGR_OUTY_L_REG_M		0x6A 
#define LSM303AGR_OUTY_H_REG_M 		0x6B
#define LSM303AGR_OUTZ_L_REG_M		0x6C 
#define LSM303AGR_OUTZ_H_REG_M 		0x6D

//Registradores do Sensor LSM6DSL (Giroscópio e acelerômetro)
#define LSM6DSL_ADDRESS             0x6B
#define LSM6DSL_DEVICE_ID           0x6A
#define LSM6DSL_FUNC_CFG_ACCESS     0x01 
#define LSM6DSL_SENSOR_SYNC_TIME_FRAME  0x04
#define LSM6DSL_SENSOR_SYNC_RES_RATIO   0x05
#define LSM6DSL_FIFO_CTRL1          0x06
#define LSM6DSL_FIFO_CTRL2          0x07
#define LSM6DSL_FIFO_CTRL3          0x08
#define LSM6DSL_FIFO_CTRL4          0x09
#define LSM6DSL_FIFO_CTRL5          0x0A
#define LSM6DSL_DRDY_PULSE_CFG_G    0x0B
#define LSM6DSL_INT1_CTRL           0x0D
#define LSM6DSL_INT2_CTRL           0x0E
#define LSM6DSL_WHO_AM_I            0x0F
#define LSM6DSL_CTRL1_XL            0x10
#define LSM6DSL_CTRL2_G             0x11
#define LSM6DSL_CTRL3_C             0x12
#define LSM6DSL_CTRL4_C             0x13
#define LSM6DSL_CTRL5_C             0x14
#define LSM6DSL_CTRL6_C             0x15
#define LSM6DSL_CTRL7_G             0x16
#define LSM6DSL_CTRL8_XL            0x17
#define LSM6DSL_CTRL9_XL            0x18
#define LSM6DSL_CTRL10_C            0x19
#define LSM6DSL_MASTER_CONFIG       0x1A
#define LSM6DSL_WAKE_UP_SRC         0x1B
#define LSM6DSL_TAP_SRC             0x1C
#define LSM6DSL_D6D_SRC             0x1D
#define LSM6DSL_STATUS_REG          0x1E
#define LSM6DSL_OUT_TEMP_L          0x20
#define LSM6DSL_OUT_TEMP_H          0x21
#define LSM6DSL_OUTX_L_G            0x22
#define LSM6DSL_OUTX_H_G            0x23
#define LSM6DSL_OUTY_L_G            0x24
#define LSM6DSL_OUTY_H_G            0x25
#define LSM6DSL_OUTZ_L_G            0x26
#define LSM6DSL_OUTZ_H_G            0x27
#define LSM6DSL_OUTX_L_XL           0x28
#define LSM6DSL_OUTX_H_XL           0x29
#define LSM6DSL_OUTY_L_XL           0x2A
#define LSM6DSL_OUTY_H_XL           0x2B
#define LSM6DSL_OUTZ_L_XL           0x2C
#define LSM6DSL_OUTZ_H_XL           0x2D
#define LSM6DSL_SENSORHUB1_REG      0x2E
#define LSM6DSL_SENSORHUB2_REG      0x2F
#define LSM6DSL_SENSORHUB3_REG      0x30
#define LSM6DSL_SENSORHUB4_REG      0x31
#define LSM6DSL_SENSORHUB5_REG      0x32
#define LSM6DSL_SENSORHUB6_REG      0x33
#define LSM6DSL_SENSORHUB7_REG      0x34
#define LSM6DSL_SENSORHUB8_REG      0x35
#define LSM6DSL_SENSORHUB9_REG      0x36
#define LSM6DSL_SENSORHUB10_REG     0x37
#define LSM6DSL_SENSORHUB11_REG     0x38
#define LSM6DSL_SENSORHUB12_REG     0x39
#define LSM6DSL_FIFO_STATUS1        0x3A
#define LSM6DSL_FIFO_STATUS2        0x3B
#define LSM6DSL_FIFO_STATUS3        0x3C
#define LSM6DSL_FIFO_STATUS4        0x3D
#define LSM6DSL_FIFO_DATA_OUT_L     0x3E
#define LSM6DSL_FIFO_DATA_OUT_H     0x3F
#define LSM6DSL_TIMESTAMP0_REG      0x40
#define LSM6DSL_TIMESTAMP1_REG      0x41
#define LSM6DSL_TIMESTAMP2_REG      0x42
#define LSM6DSL_STEP_TIMESTAMP_L    0x49
#define LSM6DSL_STEP_TIMESTAMP_H    0x4A
#define LSM6DSL_STEP_COUNTER_L      0x4B
#define LSM6DSL_STEP_COUNTER_H      0x4C
#define LSM6DSL_SENSORHUB13_REG     0x4D
#define LSM6DSL_SENSORHUB14_REG     0x4E
#define LSM6DSL_SENSORHUB15_REG     0x4F
#define LSM6DSL_SENSORHUB16_REG     0x50
#define LSM6DSL_SENSORHUB17_REG     0x51
#define LSM6DSL_SENSORHUB18_REG     0x52
#define LSM6DSL_FUNC_SRC1           0x53
#define LSM6DSL_FUNC_SRC2           0x54
#define LSM6DSL_WRIST_TILT_IA       0x55
#define LSM6DSL_TAP_CFG             0x58
#define LSM6DSL_TAP_THS_6D          0x59
#define LSM6DSL_INT_DUR2            0x5A
#define LSM6DSL_WAKE_UP_THS         0x5B
#define LSM6DSL_WAKE_UP_DUR         0x5C
#define LSM6DSL_FREE_FALL           0x5D
#define LSM6DSL_MD1_CFG             0x5E
#define LSM6DSL_MD2_CFG             0x5F
#define LSM6DSL_MASTER_CMD_CODE     0x60
#define LSM6DSL_SENS_SYNC_SPI_ERROR_CODE    0x61
#define LSM6DSL_OUT_MAG_RAW_X_L     0x66
#define LSM6DSL_OUT_MAG_RAW_X_H     0x67
#define LSM6DSL_OUT_MAG_RAW_Y_L     0x68
#define LSM6DSL_OUT_MAG_RAW_Y_H     0x69
#define LSM6DSL_OUT_MAG_RAW_Z_L     0x6A
#define LSM6DSL_OUT_MAG_RAW_Z_H     0x6B
#define LSM6DSL_X_OFS_USR           0x73
#define LSM6DSL_Y_OFS_USR           0x74
#define LSM6DSL_Z_OFS_USR           0x75
#define LSM6DSL_SLV0_ADD            0x02
#define LSM6DSL_SLV0_SUBADD         0x03
#define LSM6DSL_SLAVE0_CONFIG       0x04
#define LSM6DSL_SLV1_ADD            0x05
#define LSM6DSL_SLV1_SUBADD         0x06
#define LSM6DSL_SLAVE1_CONFIG       0x07
#define LSM6DSL_SLV2_ADD            0x08
#define LSM6DSL_SLV2_SUBADD         0x09
#define LSM6DSL_SLAVE2_CONFIG       0x0A
#define LSM6DSL_SLV3_ADD            0x0B
#define LSM6DSL_SLV3_SUBADD         0x0C
#define LSM6DSL_SLAVE3_CONFIG       0x0D
#define LSM6DSL_DATAWRITE_SRC_MODE_SUB_SLV0 0x0E
#define LSM6DSL_CONFIG_PEDO_THS_MIN 0x0F
#define LSM6DSL_SM_THS              0x13
#define LSM6DSL_PEDO_DEB_REG        0x14
#define LSM6DSL_STEP_COUNT_DELTA    0x15
#define LSM6DSL_MAG_SI_XX           0x24
#define LSM6DSL_MAG_SI_XY           0x25
#define LSM6DSL_MAG_SI_XZ           0x26
#define LSM6DSL_MAG_SI_YX           0x27
#define LSM6DSL_MAG_SI_YY           0x28
#define LSM6DSL_MAG_SI_YZ           0x29
#define LSM6DSL_MAG_SI_ZX           0x2A
#define LSM6DSL_MAG_SI_ZY           0x2B
#define LSM6DSL_MAG_SI_ZZ           0x2C
#define LSM6DSL_MAG_OFFX_L          0x2D
#define LSM6DSL_MAG_OFFX_H          0x2E
#define LSM6DSL_MAG_OFFY_L          0x2F
#define LSM6DSL_MAG_OFFY_H          0x30
#define LSM6DSL_MAG_OFFZ_L          0x31
#define LSM6DSL_MAG_OFFZ_H          0x32
#define LSM6DSL_A_WRIST_TILT_LAT    0x50
#define LSM6DSL_A_WRIST_TILT_THS    0x54
#define LSM6DSL_A_WRIST_TILT_Mask   0x59

//Registradores do Sensor HTS221 (Temperatura e umidade)
#define HTS221_ADDRESS   			0x5F
#define HTS221_WHO_AM_I          	0x0F
#define HTS221_DEVICE_ID			0xBC
#define HTS221_AV_CONF				0x10
#define HTS221_CTRL1             	0x20
#define HTS221_CTRL2             	0x21
#define HTS221_STATUS            	0x27
#define HTS221_HUMIDITY_OUT_L    	0x28
#define HTS221_TEMP_OUT_L        	0x2A
#define HTS221_TEMP_OUT_H        	0x2B
#define HTS221_H0_rH_x2          	0x30
#define HTS221_H1_rH_x2          	0x31
#define HTS221_T0_degC_x8        	0x32
#define HTS221_T1_degC_x8        	0x33
#define HTS221_T1_T0_MSB         	0x35
#define HTS221_H0_T0_OUT         	0x36
#define HTS221_H1_T0_OUT         	0x3A
#define HTS221_T0_OUT            	0x3C
#define HTS221_T1_OUT            	0x3E

//Registradores do Sensor LPS22HB (Pressão atmosférica)
#define	LPS22HB_ADDRESS				0x5D
#define LPS22HB_DEVICE_ID			0xB1
#define	LPS22HB_INTERRUPT_CFG 	 	0x0B
#define	LPS22HB_THS_P_L 	 		0x0C
#define	LPS22HB_THS_P_H  			0x0D
#define	LPS22HB_WHO_AM_I 			0x0F
#define	LPS22HB_CTRL_REG1  			0x10
#define	LPS22HB_CTRL_REG2  			0x11
#define	LPS22HB_CTRL_REG3  			0x12
#define	LPS22HB_FIFO_CTRL  			0x14
#define	LPS22HB_REF_P_XL  			0x15
#define	LPS22HB_REF_P_L  			0x16
#define	LPS22HB_REF_P_H  			0x17
#define	LPS22HB_RPDS_L  			0x18
#define	LPS22HB_RPDS_H  			0x19
#define	LPS22HB_RES_CONF  			0x1A
#define	LPS22HB_INT_SOURCE  		0x25
#define	LPS22HB_FIFO_STATUS  		0x26
#define	LPS22HB_STATUS  			0x27 
#define	LPS22HB_PRESS_OUT_XL  		0x28
#define	LPS22HB_PRESS_OUT_L  		0x29
#define	LPS22HB_PRESS_OUT_H  		0x2A
#define	LPS22HB_TEMP_OUT_L  		0x2B
#define	LPS22HB_TEMP_OUT_H  		0x2C
#define	LPS22HB_LPFP_RES			0x33

//Cria os objetos referentes aos pinos de comunicacao i2c
Gpio_t SCL;
Gpio_t SDA;

//Variaveis de calibracao do sensor HTS221
float _hts221HumiditySlope;
float _hts221HumidityZero;
float _hts221TemperatureSlope;
float _hts221TemperatureZero;

enum {
  FAHRENHEIT,
  CELSIUS
};


//Funcao para imprimir double e float
void printDouble(double v, int decimalDigits);

//Protocolo i2c via software
void WriteI2cSW_8bits(uint8_t addr, uint8_t reg, uint8_t data);
uint8_t ReadI2cSW_8bits(uint8_t addr, uint8_t reg);
uint16_t ReadI2cSW_16bits(uint8_t addr, uint8_t reg);

// Funcoes para o sensor HTS221
uint8_t HTS221_begin();
void HTS221_Read_Calibration();
float HTS221_Temperature(int units);
float HTS221_Humidity();
uint16_t HTS221_Temperature_Hex();
uint16_t HTS221_Humidity_Hex();

// Funcoes para o sensor LPS22HB
uint8_t LPS22HB_begin();
float LPS22HB_Pressure();
uint32_t LPS22HB_Pressure_Hex();
uint16_t LPS22HB_Temperature_Hex();

// Funcoes para o sensor LSM303AGR
uint8_t LSM303AGR_begin();

// Funcoes para o sensor LSM6DSL
uint8_t LSM6DSL_begin();

#endif // __TOOLS_H__
