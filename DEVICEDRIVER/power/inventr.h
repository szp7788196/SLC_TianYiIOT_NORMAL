#ifndef __INVENTR_H
#define __INVENTR_H	 
#include "sys.h"


#define INVENTR_MAX_CURRENT_ADC_VAL	1058			//ʵ��ֵ1058  0x0422
#define INVENTR_MAX_VOLTAGE_ADC_VAL	90				//ʵ��ֵ90  0x005A

#define INVENTR_MAX_CURRENT_MA		1050			//����������1050ma
#define INVENTR_MAX_VOLTAGE_V		272.108844f		//��������ѹ272.108844v,VMAX =Power/(Iomax*70%)=200w/(1.05A*70%)= 204.1v(����70%�ǹ̶�ֵ������)


#define RELAY_ON	GPIO_SetBits(GPIOC,GPIO_Pin_7);
#define RELAY_OFF	GPIO_ResetBits(GPIOC,GPIO_Pin_7);


extern u8 InventrBusy;
extern u8 InventrDisable;

extern float InventrInPutCurrent;
extern float InventrInPutVoltage;
extern float InventrOutPutCurrent;
extern float InventrOutPutVoltage;


void RELAY_Init(void);

u8 InventrSetMaxPowerCurrent(u8 percent); 
u8 InventrSetLightLevel(u8 level);
float InventrGetOutPutCurrent(void);
float InventrGetOutPutVoltage(void);
u8 InventrGetDeviceInfo(void);

void SetLightLevel(u8 intfc_type, u8 level);





































#endif
