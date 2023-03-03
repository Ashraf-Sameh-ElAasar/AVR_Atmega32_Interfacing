/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Unipolar_Stepper_Motor_CFG.h		*/
/****************************************************************/


#ifndef UNIPOLAR_STEPPER_MOTOR_CFG_H_
#define UNIPOLAR_STEPPER_MOTOR_CFG_H_

#define NUMBER_OF_STEPPER_MOTORS	1

typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD
}PORTx;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	PIN16,
	PIN17,
	PIN18,
	PIN19,
	PIN20,
	PIN21,
	PIN22,
	PIN23,
	PIN24,
	PIN25,
	PIN26,
	PIN27,
	PIN28,
	PIN29,
	PIN30,
	PIN31,
	PIN32
}PINx;

typedef enum {
	Full  ,
	Half
}Step_Mode;



typedef struct{
	
	PORTx      Port ;
	PINx       Pin1 ;
	PINx       Pin2 ;
	PINx       Pin3 ;
	PINx       Pin4 ;
	Step_Mode  Mode ;
}StepperMotor;

StepperMotor CONFIG_Stepper_Motor[NUMBER_OF_STEPPER_MOTORS] ;



#endif /* UNIPOLAR_STEPPER_MOTOR_CFG_H_ */
