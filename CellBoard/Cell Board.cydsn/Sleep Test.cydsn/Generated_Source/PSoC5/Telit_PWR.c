/*******************************************************************************
* File Name: Telit_PWR.c  
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
#include "Telit_PWR.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Telit_PWR__PORT == 15 && ((Telit_PWR__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Telit_PWR_Write
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
void Telit_PWR_Write(uint8 value) 
{
    uint8 staticBits = (Telit_PWR_DR & (uint8)(~Telit_PWR_MASK));
    Telit_PWR_DR = staticBits | ((uint8)(value << Telit_PWR_SHIFT) & Telit_PWR_MASK);
}


/*******************************************************************************
* Function Name: Telit_PWR_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Telit_PWR_DM_STRONG     Strong Drive 
*  Telit_PWR_DM_OD_HI      Open Drain, Drives High 
*  Telit_PWR_DM_OD_LO      Open Drain, Drives Low 
*  Telit_PWR_DM_RES_UP     Resistive Pull Up 
*  Telit_PWR_DM_RES_DWN    Resistive Pull Down 
*  Telit_PWR_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Telit_PWR_DM_DIG_HIZ    High Impedance Digital 
*  Telit_PWR_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Telit_PWR_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Telit_PWR_0, mode);
}


/*******************************************************************************
* Function Name: Telit_PWR_Read
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
*  Macro Telit_PWR_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Telit_PWR_Read(void) 
{
    return (Telit_PWR_PS & Telit_PWR_MASK) >> Telit_PWR_SHIFT;
}


/*******************************************************************************
* Function Name: Telit_PWR_ReadDataReg
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
uint8 Telit_PWR_ReadDataReg(void) 
{
    return (Telit_PWR_DR & Telit_PWR_MASK) >> Telit_PWR_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Telit_PWR_INTSTAT) 

    /*******************************************************************************
    * Function Name: Telit_PWR_ClearInterrupt
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
    uint8 Telit_PWR_ClearInterrupt(void) 
    {
        return (Telit_PWR_INTSTAT & Telit_PWR_MASK) >> Telit_PWR_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
