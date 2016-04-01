/*******************************************************************************
* File Name: PWR_Telit.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PWR_Telit.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PWR_Telit__PORT == 15 && ((PWR_Telit__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PWR_Telit_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void PWR_Telit_Write(uint8 value) 
{
    uint8 staticBits = (PWR_Telit_DR & (uint8)(~PWR_Telit_MASK));
    PWR_Telit_DR = staticBits | ((uint8)(value << PWR_Telit_SHIFT) & PWR_Telit_MASK);
}


/*******************************************************************************
* Function Name: PWR_Telit_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWR_Telit_DM_STRONG     Strong Drive 
*  PWR_Telit_DM_OD_HI      Open Drain, Drives High 
*  PWR_Telit_DM_OD_LO      Open Drain, Drives Low 
*  PWR_Telit_DM_RES_UP     Resistive Pull Up 
*  PWR_Telit_DM_RES_DWN    Resistive Pull Down 
*  PWR_Telit_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWR_Telit_DM_DIG_HIZ    High Impedance Digital 
*  PWR_Telit_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWR_Telit_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PWR_Telit_0, mode);
}


/*******************************************************************************
* Function Name: PWR_Telit_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro PWR_Telit_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWR_Telit_Read(void) 
{
    return (PWR_Telit_PS & PWR_Telit_MASK) >> PWR_Telit_SHIFT;
}


/*******************************************************************************
* Function Name: PWR_Telit_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 PWR_Telit_ReadDataReg(void) 
{
    return (PWR_Telit_DR & PWR_Telit_MASK) >> PWR_Telit_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWR_Telit_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWR_Telit_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 PWR_Telit_ClearInterrupt(void) 
    {
        return (PWR_Telit_INTSTAT & PWR_Telit_MASK) >> PWR_Telit_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
