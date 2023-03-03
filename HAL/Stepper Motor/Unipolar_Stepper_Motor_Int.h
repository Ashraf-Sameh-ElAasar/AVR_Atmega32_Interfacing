/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Unipolar_Stepper_Motor_Int.h			*/
/****************************************************************/



#ifndef UNIPOLAR_STEPPER_MOTOR_INT_H_
#define UNIPOLAR_STEPPER_MOTOR_INT_H_

void uStep_Motor_voidInit(void);

void uStep_Motor_voidRotate_Clock(u8 Stepper_Motor_Num, u16 StepCount);

void uStep_Motor_voidRotate_Anti_Clock(u8 Stepper_Motor_Num, u16 StepCount);



#endif /* UNIPOLAR_STEPPER_MOTOR_INT_H_ */
