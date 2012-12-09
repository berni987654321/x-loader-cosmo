#include <common.h>
#include <asm/arch/cpu.h>
#include <asm/io.h>
#include <asm/arch/bits.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/sys_info.h>
#include <asm/arch/clocks.h>
#include <asm/arch/mem.h>
#include <i2c.h>
#include <asm/mach-types.h>
#if (CONFIG_COMMANDS & CFG_CMD_NAND) && defined(CFG_NAND_LEGACY)
#include <linux/mtd/nand_legacy.h>
#endif

#define CONFIG_OMAP4_SDC		1

int board_init(void)
{
	return 0;
}

#define		OMAP44XX_WKUP_CTRL_BASE		0x4A31E000 
#if 1
#define M0_SAFE M0
#define M1_SAFE M1
#define M2_SAFE M2
#define M4_SAFE M4
#define M7_SAFE M7
#define M3_SAFE M3
#define M5_SAFE M5
#define M6_SAFE M6
#else
#define M0_SAFE M7
#define M1_SAFE M7
#define M2_SAFE M7
#define M4_SAFE M7
#define M7_SAFE M7
#define M3_SAFE M7
#define M5_SAFE M7
#define M6_SAFE M7
#endif

#if	0
#define		MV(OFFSET, VALUE)\
			__raw_writew((VALUE), OMAP44XX_CTRL_BASE + (OFFSET));
#define		MV1(OFFSET, VALUE)\
			__raw_writew((VALUE), OMAP44XX_WKUP_CTRL_BASE + (OFFSET));

#define		CP(x)	(CONTROL_PADCONF_##x)
#define		WK(x)	(CONTROL_WKUP_##x)
#endif

#if	0	

#define MUX_DEFAULT_OMAP4() \
	MV(CP(GPMC_AD0) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_AD1) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_AD2) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_AD3) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_AD4) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_AD5) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_AD6) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_AD7) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_AD8) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M3))   \
	MV(CP(GPMC_AD9) , ( PTU | IEN | M3))   \
	MV(CP(GPMC_AD10) , ( PTU | IEN | M3))   \
	MV(CP(GPMC_AD11) , ( PTU | IEN | M3))   \
	MV(CP(GPMC_AD12) , ( PTU | IEN | M3))   \
	MV(CP(GPMC_AD13) , ( PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3))   \
	MV(CP(GPMC_AD14) , ( PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3))   \
	MV(CP(GPMC_AD15) , ( PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3))   \
	MV(CP(GPMC_A16) , ( M3))   \
	MV(CP(GPMC_A17) , ( PTD | M3))   \
	MV(CP(GPMC_A18) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
MV(CP(GPMC_A19),	PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)		 \
	MV(CP(GPMC_A20) , ( IEN | M3))   \
	MV(CP(GPMC_A21) , ( M3))   \
MV(CP(GPMC_A22) , ( PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3))   \
	MV(CP(GPMC_A23) , ( OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_A24) , ( PTD | M3))   \
	MV(CP(GPMC_A25) , ( PTD | M3))   \
	MV(CP(GPMC_NCS0) , ( M3))   \
	MV(CP(GPMC_NCS1) , ( IEN | M3))   \
MV(CP(GPMC_NCS2),		PTU | IEN | M3)					\
	MV(CP(GPMC_NCS3) , ( IEN | M3))   \
	MV(CP(GPMC_NWP) , ( M3))   \
	MV(CP(GPMC_CLK) , ( PTD | M3))   \
	MV(CP(GPMC_NADV_ALE) , ( M3))   \
	MV(CP(GPMC_NOE) , ( PTU | IEN | OFF_EN | OFF_OUT_PTD | M1))   \
	MV(CP(GPMC_NWE) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(GPMC_NBE0_CLE) , ( M3))   \
	MV(CP(GPMC_NBE1) , ( PTD | M3))   \
	MV(CP(GPMC_WAIT0) , ( PTU | IEN | M3))   \
	MV(CP(GPMC_WAIT1) , ( IEN | M3))   \
	MV(CP(C2C_DATA11) , ( PTD | M3))   \
	MV(CP(C2C_DATA12) , ( M1))   \
	MV(CP(C2C_DATA13) , ( PTD | M3))   \
	MV(CP(C2C_DATA14) , ( M1))   \
MV(CP(C2C_DATA15),		(PTD | M3))			 \
	MV(CP(HDMI_HPD) , ( M0))   \
	MV(CP(HDMI_CEC) , ( M0))   \
	MV(CP(HDMI_DDC_SCL) , ( PTU | M0))   \
	MV(CP(HDMI_DDC_SDA) , ( PTU | IEN | M0))   \
	MV(CP(CSI21_DX0) , ( IEN | M0))   \
	MV(CP(CSI21_DY0) , ( IEN | M0))   \
	MV(CP(CSI21_DX1) , ( IEN | M0))   \
	MV(CP(CSI21_DY1) , ( IEN | M0))   \
	MV(CP(CSI21_DX2) , ( IEN | M0))   \
	MV(CP(CSI21_DY2) , ( IEN | M0))   \
	MV(CP(CSI21_DX3) , ( PTD | M7))   \
	MV(CP(CSI21_DY3) , ( PTD | M7))   \
	MV(CP(CSI21_DX4) , ( PTD | OFF_EN | OFF_PD | OFF_IN | M7))   \
	MV(CP(CSI21_DY4) , ( PTD | OFF_EN | OFF_PD | OFF_IN | M7))   \
	MV(CP(CSI22_DX0) , ( IEN | M0))   \
	MV(CP(CSI22_DY0) , ( IEN | M0))   \
	MV(CP(CSI22_DX1) , ( IEN | M0))   \
	MV(CP(CSI22_DY1) , ( IEN | M0))   \
	MV(CP(CAM_SHUTTER) , ( OFF_EN | OFF_PD | OFF_OUT_PTD | M0))   \
	MV(CP(CAM_STROBE) , ( OFF_EN | OFF_PD | OFF_OUT_PTD | M0))   \
	MV(CP(CAM_GLOBALRESET) , ( PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3))   \
	MV(CP(USBB1_ULPITLL_CLK) , ( PTD | IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_STP) , ( OFF_EN | OFF_OUT_PTD | M4))   \
	MV(CP(USBB1_ULPITLL_DIR) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_NXT) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_DAT0) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_DAT1) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_DAT2) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_DAT3) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_DAT4) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_DAT5) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_DAT6) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_ULPITLL_DAT7) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M4))   \
	MV(CP(USBB1_HSIC_DATA) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(USBB1_HSIC_STROBE) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
MV(CP(USBC1_ICUSB_DP),	PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
MV(CP(USBC1_ICUSB_DM),	PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
	MV(CP(SDMMC1_CLK) , ( PTU | OFF_EN | OFF_OUT_PTD | M0))   \
	MV(CP(SDMMC1_CMD) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
MV(CP(SDMMC1_DAT0) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))  	\
MV(CP(SDMMC1_DAT1) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))  	\
MV(CP(SDMMC1_DAT2) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))  	\
MV(CP(SDMMC1_DAT3) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))  	\
MV(CP(SDMMC1_DAT4),		PTU | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)  	\
	MV(CP(SDMMC1_DAT5) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(SDMMC1_DAT6) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(SDMMC1_DAT7) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(ABE_MCBSP2_CLKX) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(ABE_MCBSP2_DR) , ( IEN | OFF_EN | OFF_OUT_PTD | M0))   \
	MV(CP(ABE_MCBSP2_DX) , ( OFF_EN | OFF_OUT_PTD | M0))   \
	MV(CP(ABE_MCBSP2_FSX) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(ABE_MCBSP1_CLKX) , ( IEN | M1))   \
	MV(CP(ABE_MCBSP1_DR) , ( IEN | M1))   \
	MV(CP(ABE_MCBSP1_DX) , ( OFF_EN | OFF_OUT_PTD | M0))   \
	MV(CP(ABE_MCBSP1_FSX) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(ABE_PDM_UL_DATA) , ( PTD | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(ABE_PDM_DL_DATA) , ( PTD | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(ABE_PDM_FRAME) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(ABE_PDM_LB_CLK) , ( PTD | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(ABE_CLKS) , ( PTD | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(ABE_DMIC_CLK1) , ( M0))   \
	MV(CP(ABE_DMIC_DIN1) , ( IEN | M0))   \
	MV(CP(ABE_DMIC_DIN2) , ( IEN | M0))   \
	MV(CP(ABE_DMIC_DIN3) , ( IEN | M0))   \
	MV(CP(UART2_CTS) , ( PTU | IEN | M0))   \
	MV(CP(UART2_RTS) , ( M0))   \
	MV(CP(UART2_RX) , ( PTU | IEN | M0))   \
	MV(CP(UART2_TX) , ( M0))   \
	MV(CP(HDQ_SIO) , ( M3))   \
	MV(CP(I2C1_SCL) , ( PTU | IEN | EN| M0))   \
	MV(CP(I2C1_SDA) , ( PTU | IEN | EN| M0))   \
	MV(CP(I2C2_SCL) , ( PTU | IEN | EN| M0))   \
	MV(CP(I2C2_SDA) , ( PTU | IEN | EN| M0))   \
	MV(CP(I2C3_SCL) , ( PTU | IEN | EN| M0))   \
	MV(CP(I2C3_SDA) , ( PTU | IEN | EN| M0))   \
	MV(CP(I2C4_SCL) , ( PTU | IEN | EN| M0))   \
	MV(CP(I2C4_SDA) , ( PTU | IEN | EN| M0))   \
	MV(CP(MCSPI1_CLK) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(MCSPI1_SOMI) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(MCSPI1_SIMO) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(MCSPI1_CS0) , ( PTD | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
MV(CP(MCSPI1_CS1),		PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)			\
MV(CP(MCSPI1_CS2),		PTU | OFF_EN | OFF_PD | OFF_OUT_PTU |	M3)			\
MV(CP(MCSPI1_CS3),		PTD | 									M3)			\
MV(CP(UART3_CTS_RCTX) , PTU | IEN | M1)										\
MV(CP(UART3_RTS_SD),	M7)													\
MV(CP(UART3_RX_IRRX),	M7)													\
MV(CP(UART3_TX_IRTX),	PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
	MV(CP(SDMMC5_CLK) , ( PTU | IEN | OFF_EN | OFF_OUT_PTD | M0))   \
	MV(CP(SDMMC5_CMD) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(SDMMC5_DAT0) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(SDMMC5_DAT1) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(SDMMC5_DAT2) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(SDMMC5_DAT3) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(MCSPI4_CLK) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(MCSPI4_SIMO) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(MCSPI4_SOMI) , ( IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
	MV(CP(MCSPI4_CS0) , ( PTD | IEN | OFF_EN | OFF_PD | OFF_IN | M0))   \
MV(CP(UART4_RX),	(IEN | M0))		\
MV(CP(UART4_TX),	(M0))			\
	MV(CP(USBB2_ULPITLL_CLK) , ( IEN | M3))   \
	MV(CP(USBB2_ULPITLL_STP) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_DIR) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_NXT) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_DAT0) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_DAT1) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_DAT2) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_DAT3) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_DAT4) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_DAT5) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_DAT6) , ( IEN | M5))   \
	MV(CP(USBB2_ULPITLL_DAT7) , ( IEN | M5))   \
	MV(CP(USBB2_HSIC_DATA) , ( PTD | OFF_EN | OFF_OUT_PTU | M3))   \
	MV(CP(USBB2_HSIC_STROBE) , ( PTD | OFF_EN | OFF_OUT_PTU | M3))   \
MV(CP(UNIPRO_TX0),		OFF_EN | OFF_PD | OFF_IN | M1)   \
MV(CP(UNIPRO_TY0),		OFF_EN | OFF_PD | OFF_IN | M1)   \
	MV(CP(UNIPRO_TX1) , ( OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(UNIPRO_TY1) , ( OFF_EN | OFF_PD | OFF_IN | M1))   \
MV(CP(UNIPRO_TX2),		(PTD	|	OFF_EN	|	OFF_PD	| OFF_OUT_PTD				| M3))	 \
MV(CP(UNIPRO_TY2),		(PTD	|	OFF_EN	|	OFF_PD	| OFF_OUT_PTD				| M3))	 \
MV(CP(UNIPRO_RX0),		(PTU	|	IEN		|	OFF_EN	| OFF_PD		| OFF_IN	| M1))	 \
MV(CP(UNIPRO_RY0),		(PTU	|	IEN		|	OFF_EN	| OFF_PD		| OFF_IN	| M1))	 \
	MV(CP(UNIPRO_RX1) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(UNIPRO_RY1) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(UNIPRO_RX2) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(UNIPRO_RY2) , ( PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1))   \
	MV(CP(USBA0_OTG_CE) , ( PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M0))   \
MV(CP(USBA0_OTG_DP),	IEN | OFF_EN | OFF_PD | OFF_IN | M0)			\
MV(CP(USBA0_OTG_DM),	IEN | OFF_EN | OFF_PD | OFF_IN | M0)			\
	MV(CP(FREF_CLK1_OUT) , ( M0))   \
	MV(CP(FREF_CLK2_OUT) , ( M0))   \
	MV(CP(SYS_NIRQ1) , ( PTU | IEN | M0))   \
	MV(CP(SYS_NIRQ2) , ( PTU | IEN | M0))   \
	MV(CP(SYS_BOOT0) , ( PTU | IEN | M3))   \
	MV(CP(SYS_BOOT1) , ( M3))   \
	MV(CP(SYS_BOOT2) , ( PTD | IEN | M3))   \
	MV(CP(SYS_BOOT3) , ( M3))   \
	MV(CP(SYS_BOOT4) , ( M3))   \
	MV(CP(SYS_BOOT5) , ( PTD | IEN | M3))   \
MV(CP(DPM_EMU0),	PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
MV(CP(DPM_EMU1),	PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
MV(CP(DPM_EMU2),	PTU | IEN	| M3	)			\
MV(CP(DPM_EMU3),	PTU | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
MV(CP(DPM_EMU4),	PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
MV(CP(DPM_EMU5),	PTU | IEN	| M3	)			\
MV(CP(DPM_EMU6),		(PTU | M2)) 				\
MV(CP(DPM_EMU7),		(PTU | IEN | M2))			\
MV(CP(DPM_EMU8),		(PTD | M2))  				\
MV(CP(DPM_EMU9),		(PTD | IEN | M2))			\
MV(CP(DPM_EMU10),		PTD | IEN | OFF_EN | OFF_PD | OFF_IN | M3)			\
MV(CP(DPM_EMU11),		PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
MV(CP(DPM_EMU12),		PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
MV(CP(DPM_EMU13),		PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)		 \
	MV(CP(DPM_EMU14) , ( IEN | M5))   \
	MV(CP(DPM_EMU15) , ( IEN | M5))   \
MV(CP(DPM_EMU16),		PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\	
MV(CP(DPM_EMU17),		PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
MV(CP(DPM_EMU18),		PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
MV(CP(DPM_EMU19),		PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)			\
	MV1(WK(PAD0_SIM_IO) , ( IEN | M0))   \
MV1(WK(PAD1_SIM_CLK),		PTU | IEN | M3)						\
MV1(WK(PAD0_SIM_RESET),		PTU | IEN | M3)						\
MV1(WK(PAD1_SIM_CD),		PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)		\
MV1(WK(PAD0_SIM_PWRCTRL),	PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)		\
	MV1(WK(PAD1_SR_SCL) , ( PTU | IEN | M0))   \
	MV1(WK(PAD0_SR_SDA) , ( PTU | IEN | M0))   \
	MV1(WK(PAD1_FREF_XTAL_IN) , ( M0))   \
	MV1(WK(PAD0_FREF_SLICER_IN) , ( M0))   \
	MV1(WK(PAD1_FREF_CLK_IOREQ) , ( M0))   \
	MV1(WK(PAD0_FREF_CLK0_OUT) , ( M2))   \
MV1(WK(PAD1_FREF_CLK3_REQ),		PTD | OFF_EN | OFF_PD | OFF_OUT_PTD | M3)   \
	MV1(WK(PAD0_FREF_CLK3_OUT) , ( M0))   \
	MV1(WK(PAD1_FREF_CLK4_REQ) , ( PTU | IEN | M0))   \
	MV1(WK(PAD0_FREF_CLK4_OUT) , ( M0))   \
	MV1(WK(PAD1_SYS_32K) , ( IEN | M0))   \
	MV1(WK(PAD0_SYS_NRESPWRON) , ( M0))   \
	MV1(WK(PAD1_SYS_NRESWARM) , ( M0))   \
	MV1(WK(PAD0_SYS_PWR_REQ) , ( PTU | M0))   \
MV1(WK(PAD1_SYS_PWRON_RESET), PTU | IEN | M3)		 \
	MV1(WK(PAD0_SYS_BOOT6) , ( IEN | M3))   \
	MV1(WK(PAD1_SYS_BOOT7) , ( IEN | M3))   \

	MV1(WK(PAD1_JTAG_TCK) , ( IEN | M0))   \
	MV1(WK(PAD0_JTAG_RTCK) , ( M0))   \
	MV1(WK(PAD1_JTAG_TMS_TMSC) , ( IEN | M0))   \
	MV1(WK(PAD0_JTAG_TDI) , ( IEN | M0))   \
	MV1(WK(PAD1_JTAG_TDO) , ( M0))   
#endif
 

void set_muxconf_regs(void)
{
#if	0	
	MUX_DEFAULT_OMAP4();
	delay(100);
#endif
	MV(CP(UART4_RX),	(IEN | M0));	
	MV(CP(UART4_TX),	(M0));			
	return;
}

void board_hang (void)
{ while (0) {};}

#if defined (CONFIG_LGE_CX2)

const struct ddr_regs ddr_regs_400mhz_2cs = {

	.tim1			= 0x10eb0661,
	.tim2			= 0x20370dd2,
	.tim3			= 0x00b1c33f,
	.phy_ctrl_1 	= 0x049FF409,
	.ref_ctrl		= 0x00000618,
#if defined(CONFIG_DDR_512MB)
	.config_init	= 0x80000eb1,
	.config_final	= 0x80001ab1,
#elif defined(CONFIG_DDR_1GB)
	.config_init	= 0x80000eb2,
	.config_final	= 0x80001ab2,
#else
#error "There is no DDR configuration"
#endif
	.zq_config		= 0x500b3214,
	.mr1			= 0x83,
	.mr2			= 0x4
};

void ddr_init(void)
{
	__raw_writel(0x80640300, DMM_BASE + DMM_LISA_MAP_0);

	do_ddr_init(&ddr_regs_400mhz_2cs, &ddr_regs_400mhz_2cs);
}
#endif
