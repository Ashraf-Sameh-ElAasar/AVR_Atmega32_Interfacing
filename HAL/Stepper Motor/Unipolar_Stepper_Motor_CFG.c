/**************************************************************************************
		 Includes
**************************************************************************************/
#include "Unipolar_Stepper_Motor_CFG.h"


/*****************************************************************/
/* !comment : Please Fill the Configuration for Stepper Motor    */
/*****************************************************************/


StepperMotor CONFIG_Stepper_Motor[NUMBER_OF_STEPPER_MOTORS] = {
	
	{
		.Mode = Full  ,
		.Port = PORTB      ,
		.Pin1 = PIN0       ,
		.Pin2 = PIN1       ,
		.Pin3 = PIN2       ,
		.Pin4 = PIN3
	}
};
