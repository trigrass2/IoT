/*******************************************************************************
* File Name: solinst_power_pin.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "solinst_power_pin.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 solinst_power_pin__PORT == 15 && ((solinst_power_pin__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: solinst_power_pin_Write
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
void solinst_power_pin_Write(uint8 value) 
{
    uint8 staticBits = (solinst_power_pin_DR & (uint8)(~solinst_power_pin_MASK));
    solinst_power_pin_DR = staticBits | ((uint8)(value << solinst_power_pin_SHIFT) & solinst_power_pin_MASK);
}


/*******************************************************************************
* Function Name: solinst_power_pin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void solinst_power_pin_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(solinst_power_pin_0, mode);
}


/*******************************************************************************
* Function Name: solinst_power_pin_Read
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
*  Macro solinst_power_pin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 solinst_power_pin_Read(void) 
{
    return (solinst_power_pin_PS & solinst_power_pin_MASK) >> solinst_power_pin_SHIFT;
}


/*******************************************************************************
* Function Name: solinst_power_pin_ReadDataReg
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
uint8 solinst_power_pin_ReadDataReg(void) 
{
    return (solinst_power_pin_DR & solinst_power_pin_MASK) >> solinst_power_pin_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(solinst_power_pin_INTSTAT) 

    /*******************************************************************************
    * Function Name: solinst_power_pin_ClearInterrupt
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
    uint8 solinst_power_pin_ClearInterrupt(void) 
    {
        return (solinst_power_pin_INTSTAT & solinst_power_pin_MASK) >> solinst_power_pin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
