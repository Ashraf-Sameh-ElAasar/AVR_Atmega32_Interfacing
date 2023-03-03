/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Global Interrupt Enable Interface.h	*/
/****************************************************************/


#ifndef GIE_INT_H_
#define GIE_INT_H_

/******************************************************************************
* \Syntax          : GIE_voidENABLE()       
* \Description     : this service for Enabling Global Interrupt                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : none
* \Return value:   : None                            
*******************************************************************************/

void GIE_voidENABLE();

/******************************************************************************
* \Syntax          : GIE_voidENABLE()       
* \Description     : this service for Disabling Global Interrupt                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : none
* \Return value:   : None                            
*******************************************************************************/

void GIE_voidDISABLE();


#endif /* GIE_INT_H_ */
