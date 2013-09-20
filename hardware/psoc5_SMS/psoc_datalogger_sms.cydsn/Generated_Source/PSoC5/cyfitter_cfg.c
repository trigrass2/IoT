/*******************************************************************************
* FILENAME: cyfitter_cfg.c
* PSoC Creator 2.2 Component Pack 6
*
* Description:
* This file is automatically generated by PSoC Creator with device 
* initialization code.  Except for the user defined sections in
* CyClockStartupError(), this file should not be modified.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include <string.h>
#include <cytypes.h>
#include <cydevice_trm.h>
#include <cyfitter.h>
#include <CyLib.h>
#include <cyfitter_cfg.h>

/* Clock startup error codes                                                   */
#define CYCLOCKSTART_NO_ERROR    0u
#define CYCLOCKSTART_XTAL_ERROR  1u
#define CYCLOCKSTART_32KHZ_ERROR 2u
#define CYCLOCKSTART_PLL_ERROR   3u

#ifdef CY_NEED_CYCLOCKSTARTUPERROR
/*******************************************************************************
* Function Name: CyClockStartupError
********************************************************************************
* Summary:
*  If an error is encountered during clock configuration (crystal startup error,
*  PLL lock error, etc.), the system will end up here.  Unless reimplemented by
*  the customer, this function will stop in an infinite loop.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
__attribute__ ((unused))
#endif
static void CyClockStartupError(uint8 errorCode);
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
__attribute__ ((unused))
#endif
static void CyClockStartupError(uint8 errorCode)
{
    /* To remove the compiler warning if errorCode not used.                */
    errorCode = errorCode;

    /* `#START CyClockStartupError` */

    /* If we have a clock startup error (bad MHz crystal, PLL lock, etc.),  */
    /* we will end up here to allow the customer to implement something to  */
    /* deal with the clock condition.                                       */

    /* `#END` */

    /* If nothing else, stop here since the clocks have not started         */
    /* correctly.                                                           */
    while(1) {}
}
#endif


#if defined(__GNUC__) || defined(__ARMCC_VERSION)
	#define CYPACKED __attribute__ ((packed))
	#define CYALIGNED __attribute__ ((aligned))
	
	#if defined(__ARMCC_VERSION)
		#define CY_CFG_MEMORY_BARRIER() __memory_changed()
	#else
		#define CY_CFG_MEMORY_BARRIER() __sync_synchronize()
	#endif
	
	/*******************************************************************************
	* Function Name: CYMEMZERO8
	********************************************************************************
	* Summary:
	*  This function is provided as a way to initialize a block of memory to zero
	*  one byte at a time.  While this is a 32bit processor, some of the 
	*  configuration registers are only 8bits wide.  This allows us to initialize
	*  just the registers we care about.
	*
	* Parameters:  
	*   addr  - The first address to start writing zero to.
	*   count - The number of bytes to write 0 to.
	*
	* Return:
	*   void
	*
	*******************************************************************************/
	__attribute__ ((unused))
	static void CYMEMZERO8(void *addr, uint32 count);
	__attribute__ ((unused))
	static void CYMEMZERO8(void *addr, uint32 count)
	{
		volatile uint8 * const addr8 = (volatile uint8 *)addr;
		uint32 i;
		for (i = 0u; i < count; i++)
		{
			addr8[i] = 0u;
		}
	}

	/*******************************************************************************
	* Function Name: CYCONFIGCPY8
	********************************************************************************
	* Summary:
	*  This function is provided as a way to copy data from one location to another
	*  one byte at a time.  While this is a 32bit processor, some of the 
	*  configuration registers are only 8bits wide.  This allows us to initialize
	*  just the registers we care about.
	*
	* Parameters:  
	*   dest  - The destination address to copy data to.
	*   src   - The source address to copy data from.
	*   count - The number of bytes to copy from 'src' to 'dest'.
	*
	* Return:
	*   void
	*
	*******************************************************************************/
	__attribute__ ((unused))
	static void CYCONFIGCPY8(void *dest, const void *src, uint32 count);
	__attribute__ ((unused))
	static void CYCONFIGCPY8(void *dest, const void *src, uint32 count)
	{
		volatile uint8 * const dest8 = (volatile uint8 *)dest;
		const uint8 * const src8 = (const uint8 *)src;
		uint32 i;
		for (i = 0u; i < count; i++)
		{
			dest8[i] = src8[i];
		}
	}

	/*******************************************************************************
	* Function Name: CYCONFIGCPYCODE8
	********************************************************************************
	* Summary:
	*  This function is provided as a way to copy data from one location to another
	*  one byte at a time.  While this is a 32bit processor, some of the 
	*  configuration registers are only 8bits wide.  This allows us to initialize
	*  just the registers we care about.
	*
	* Parameters:  
	*   dest  - The destination address to copy data to.
	*   src   - The source address to copy data from.
	*   count - The number of bytes to copy from 'src' to 'dest'.
	*
	* Return:
	*   void
	*
	*******************************************************************************/
	__attribute__ ((unused))
	static void CYCONFIGCPYCODE8(void *dest, const void *src, uint32 count);
	__attribute__ ((unused))
	static void CYCONFIGCPYCODE8(void *dest, const void *src, uint32 count)
	{
		CYCONFIGCPY8(dest, src, count);
	}

	__attribute__ ((unused))
	static void CYMEMZERO(void *s, size_t n);
	__attribute__ ((unused))
	static void CYMEMZERO(void *s, size_t n)
	{
		(void)memset(s, 0, n);
	}
	__attribute__ ((unused))
	static void CYCONFIGCPY(void *dest, const void *src, size_t n);
	__attribute__ ((unused))
	static void CYCONFIGCPY(void *dest, const void *src, size_t n)
	{
		(void)memcpy(dest, src, n);
	}
	__attribute__ ((unused))
	static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n);
	__attribute__ ((unused))
	static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n)
	{
		(void)memcpy(dest, src, n);
	}
#else
	#error Unsupported toolchain
#endif

#define CY_CFG_BASE_ADDR_COUNT 31u
typedef struct
{
	uint8 offset;
	uint8 value;
} CYPACKED cy_cfg_addrvalue_t;

#define cy_cfg_addr_table ((const uint32 CYFAR *)0x48000000u)
#define cy_cfg_data_table ((const cy_cfg_addrvalue_t CYFAR *)0x4800007Cu)

/* IOPINS0_0 Address: CYREG_PRT0_DR Size (bytes): 10 */
#define BS_IOPINS0_0_VAL ((const uint8 CYFAR *)0x48000724u)

/* IOPINS0_7 Address: CYREG_PRT12_DR Size (bytes): 10 */
#define BS_IOPINS0_7_VAL ((const uint8 CYFAR *)0x48000730u)

/* IOPINS0_4 Address: CYREG_PRT4_DR Size (bytes): 10 */
#define BS_IOPINS0_4_VAL ((const uint8 CYFAR *)0x4800073Cu)

/* IOPINS0_6 Address: CYREG_PRT6_DR Size (bytes): 10 */
#define BS_IOPINS0_6_VAL ((const uint8 CYFAR *)0x48000748u)

/* IOPORT_0 Address: CYDEV_PRTDSI_PRT0_BASE Size (bytes): 7 */
#define BS_IOPORT_0_VAL ((const uint8 CYFAR *)0x48000754u)

/* IOPORT_6 Address: CYDEV_PRTDSI_PRT6_BASE Size (bytes): 7 */
#define BS_IOPORT_6_VAL ((const uint8 CYFAR *)0x4800075Cu)


/*******************************************************************************
* Function Name: cfg_write_bytes32
********************************************************************************
* Summary:
*  This function is used for setting up the chip configuration areas that
*  contain relatively sparse data.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
static void cfg_write_bytes32(const uint32 addr_table[], const cy_cfg_addrvalue_t data_table[]);
static void cfg_write_bytes32(const uint32 addr_table[], const cy_cfg_addrvalue_t data_table[])
{
	/* For 32-bit little-endian architectures */
	uint32 i, j = 0u;
	for (i = 0u; i < CY_CFG_BASE_ADDR_COUNT; i++)
	{
		uint32 baseAddr = addr_table[i];
		uint8 count = (uint8)baseAddr;
		baseAddr &= 0xFFFFFF00u;
		while (count != 0u)
		{
			CY_SET_XTND_REG8((void CYFAR *)(baseAddr + data_table[j].offset), data_table[j].value);
			j++;
			count--;
		}
	}
}

/*******************************************************************************
* Function Name: ClockSetup
********************************************************************************
*
* Summary:
*  Performs the initialization of all of the clocks in the device based on the
*  settings in the Clock tab of the DWR.  This includes enabling the requested
*  clocks and setting the necessary dividers to produce the desired frequency. 
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void ClockSetup(void);
static void ClockSetup(void)
{


	/* Configure Digital Clocks based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0), 0x0019u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_DCFG0_CFG0 + 0x2u), 0x18u);
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_CLKDIST_DCFG1_CFG0), 0x0138u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_DCFG1_CFG0 + 0x2u), 0x18u);

	/* Configure ILO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_SLOWCLK_ILO_CR0), 0x02u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_CR), 0x08u);

	/* Configure IMO based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_FASTCLK_IMO_CR), 0x03u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_IMO_TR1), (CY_GET_XTND_REG8((void CYFAR *)CYREG_FLSHID_CUST_TABLES_IMO_3MHZ)));

	/* Configure PLL based on settings from Clock DWR */
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_P), 0x0008u);
	CY_SET_XTND_REG16((void CYFAR *)(CYREG_FASTCLK_PLL_CFG0), 0x1051u);
	/* Wait 250us for the PLL to lock */
	CyDelayCycles(250u * 12u); /* Delay 250us based on 12MHz clock */

	/* Configure Bus/Master Clock based on settings from Clock DWR */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x03u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR1), 0x01u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x07u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG0), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_BCFG2), 0x48u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_MSTR0), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CLKDIST_LD), 0x02u);

	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PM_ACT_CFG2), ((CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG2) | 0x03u)));
}


/* Analog API Functions */


/*******************************************************************************
* Function Name: AnalogSetDefault
********************************************************************************
*
* Summary:
*  Sets up the analog portions of the chip to default values based on chip
*  configuration options from the project.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void AnalogSetDefault(void);
static void AnalogSetDefault(void)
{
	CY_SET_XTND_REG16((void CYFAR *)CYREG_PM_ACT_CFG10, 0x0310u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_DAC0_CR0, 0x1Eu);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_DAC1_CR0, 0x1Eu);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_DAC2_CR0, 0x1Eu);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_DAC3_CR0, 0x1Eu);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_SAR0_CSR0, 0xC0u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_SAR0_CSR3, 0x0Cu);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_SAR1_CSR0, 0xC0u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_SAR1_CSR3, 0x0Cu);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0, 0x44u);
}


/*******************************************************************************
* Function Name: SetAnalogRoutingPumps
********************************************************************************
*
* Summary:
* Enables or disables the analog pumps feeding analog routing switches.
* Intended to be called at startup, based on the Vdda system configuration;
* may be called during operation when the user informs us that the Vdda voltage
* crossed the pump threshold.
*
* Parameters:
*  enabled - 1 to enable the pumps, 0 to disable the pumps
*
* Return:
*  void
*
*******************************************************************************/
void SetAnalogRoutingPumps(uint8 enabled)
{
	uint8 regValue = CY_GET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0);
	if (enabled != 0u)
	{
		regValue |= 0x00u;
	}
	else
	{
		regValue &= (uint8)~0x00u;
	}
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PUMP_CR0, regValue);
}

#define CY_AMUX_UNUSED CYREG_BOOST_SR


/*******************************************************************************
* Function Name: cyfitter_cfg
********************************************************************************
* Summary:
*  This function is called by the start-up code for the selected device. It
*  performs all of the necessary device configuration based on the design
*  settings.  This includes settings from the Design Wide Resources (DWR) such
*  as Clocks and Pins as well as any component configuration that is necessary.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/

void cyfitter_cfg(void)
{
#ifdef CYGlobalIntDisable
	/* Disable interrupts by default. Let user enable if/when they want. */
	CYGlobalIntDisable
#endif


	/* Set Flash Cycles based on max possible frequency in case a glitch occurs during ClockSetup(). */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), (((CYDEV_INSTRUCT_CACHE_ENABLED) != 0) ? 0x00u : 0x01u));
	/* Setup clocks based on selections from Clock DWR */
	ClockSetup();
	/* Set Flash Cycles based on newly configured 24.00MHz Bus Clock. */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_CACHE_CC_CTL), (((CYDEV_INSTRUCT_CACHE_ENABLED) != 0) ? 0x80u : 0x81u));

	/* Disable DMA channels so they can be configured for chip initialization */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PHUB_CH0_BASIC_CFG), 0x00u);
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_PHUB_CH1_BASIC_CFG), 0x00u);

	/* Enable analog pulldown switches */
	CY_SET_XTND_REG8((void CYFAR *)(CYREG_ANAIF_CFG_MISC_CR0), 0x01u);

	/* Enable/Disable Debug functionality based on settings from System DWR */
	CY_SET_XTND_REG8((void CYFAR *)CYREG_MLOGIC_DBG_DBE, (CY_GET_XTND_REG8((void CYFAR *)CYREG_MLOGIC_DBG_DBE) | 0x01u));

	{

		typedef struct {
			void CYFAR *address;
			uint16 size;
		} CYPACKED cfg_memset_t;

		static const cfg_memset_t CYCODE cfg_memset_list [] = {
			/* address, size */
			{(void CYFAR *)(CYREG_PRT1_DR), 48u},
			{(void CYFAR *)(CYREG_PRT5_DR), 16u},
			{(void CYFAR *)(CYREG_PRT15_DR), 16u},
			{(void CYFAR *)(CYDEV_UCFG_B0_P0_U0_BASE), 4096u},
			{(void CYFAR *)(CYDEV_UCFG_B1_P2_U0_BASE), 2048u},
			{(void CYFAR *)(CYDEV_UCFG_DSI0_BASE), 2560u},
			{(void CYFAR *)(CYDEV_UCFG_DSI12_BASE), 512u},
		};

		uint8 CYDATA i;

		/* Zero out critical memory blocks before beginning configuration */
		for (i = 0u; i < (sizeof(cfg_memset_list)/sizeof(cfg_memset_list[0])); i++)
		{
			const cfg_memset_t CYCODE * CYDATA ms = &cfg_memset_list[i];
			CYMEMZERO(ms->address, (uint32)(ms->size));
		}

		cfg_write_bytes32(cy_cfg_addr_table, cy_cfg_data_table);

		/* Perform normal device configuration. Order is not critical for these items. */
		CYCONFIGCPY8((void CYFAR *)(CYDEV_PRTDSI_PRT0_BASE), (const void CYFAR *)(BS_IOPORT_0_VAL), 7u);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT1_BASE), 7u);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT2_BASE), 7u);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT3_BASE), 7u);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT4_BASE), 7u);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT5_BASE), 7u);
		CYCONFIGCPY8((void CYFAR *)(CYDEV_PRTDSI_PRT6_BASE), (const void CYFAR *)(BS_IOPORT_6_VAL), 7u);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT12_BASE), 6u);
		CYMEMZERO8((void CYFAR *)(CYDEV_PRTDSI_PRT15_BASE), 7u);

		/* Enable digital routing */
		CY_SET_XTND_REG8((void CYFAR *)CYREG_BCTL0_BANK_CTL, CY_GET_XTND_REG8((void CYFAR *)CYREG_BCTL0_BANK_CTL) | 0x02u);
		CY_SET_XTND_REG8((void CYFAR *)CYREG_BCTL1_BANK_CTL, CY_GET_XTND_REG8((void CYFAR *)CYREG_BCTL1_BANK_CTL) | 0x02u);

		/* Enable UDB array */
		CY_SET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG0, CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_ACT_CFG0) | 0x40u);
		CY_SET_XTND_REG8((void CYFAR *)CYREG_PM_AVAIL_CR2, CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_AVAIL_CR2) | 0x10u);
	}

	/* Perform second pass device configuration. These items must be configured in specific order after the regular configuration is done. */
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT0_DR), (const void CYFAR *)(BS_IOPINS0_0_VAL), 10u);
	CYCONFIGCPY8((void CYFAR *)(CYREG_PRT12_DR), (const void CYFAR *)(BS_IOPINS0_7_VAL), 10u);
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT4_DR), (const void CYFAR *)(BS_IOPINS0_4_VAL), 10u);
	CYCONFIGCPY((void CYFAR *)(CYREG_PRT6_DR), (const void CYFAR *)(BS_IOPINS0_6_VAL), 10u);


	/* Perform basic analog initialization to defaults */
	AnalogSetDefault();

	/* Configure alternate active mode */
	CYCONFIGCPY((void CYFAR *)CYDEV_PM_STBY_BASE, (const void CYFAR *)CYDEV_PM_ACT_BASE, 12u);
	CY_SET_XTND_REG8((void CYFAR *)CYREG_PM_STBY_CFG0, CY_GET_XTND_REG8((void CYFAR *)CYREG_PM_STBY_CFG0) & (uint8)~0x02u);	/* Disable CPU */
}
