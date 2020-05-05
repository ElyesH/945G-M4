/* This file is part of the coreboot project. */
/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _SOC_QUALCOMM_SDM845_GPIO_H_
#define _SOC_QUALCOMM_SDM845_GPIO_H_

#include <types.h>
#include <soc/addressmap.h>

typedef struct {
	u32 addr;
} gpio_t;

#define TLMM_TILE_SIZE		0x00400000
#define TLMM_GPIO_OFF_DELTA	0x00001000
#define TLMM_GPIO_TILE_NUM	3

#define TLMM_GPIO_IN_OUT_OFF	0x4
#define TLMM_GPIO_ID_STATUS_OFF	0x10

#define GPIO_FUNC_ENABLE	1
#define GPIO_FUNC_DISABLE	0

/* GPIO TLMM: Direction */
#define GPIO_INPUT	0
#define GPIO_OUTPUT	1

/* GPIO TLMM: Pullup/Pulldown */
#define GPIO_NO_PULL	0
#define GPIO_PULL_DOWN	1
#define GPIO_KEEPER	2
#define GPIO_PULL_UP	3

/* GPIO TLMM: Drive Strength */
#define GPIO_2MA	0
#define GPIO_4MA	1
#define GPIO_6MA	2
#define GPIO_8MA	3
#define GPIO_10MA	4
#define GPIO_12MA	5
#define GPIO_14MA	6
#define GPIO_16MA	7

/* GPIO TLMM: Status */
#define GPIO_DISABLE	0
#define GPIO_ENABLE	1

/* GPIO TLMM: Mask */
#define GPIO_CFG_PULL_BMSK	0x3
#define GPIO_CFG_FUNC_BMSK	0xF
#define GPIO_CFG_DRV_BMSK	0x7
#define GPIO_CFG_OE_BMSK	0x1

/* GPIO TLMM: Shift */
#define GPIO_CFG_PULL_SHFT	0
#define GPIO_CFG_FUNC_SHFT	2
#define GPIO_CFG_DRV_SHFT	6
#define GPIO_CFG_OE_SHFT	9

/* GPIO IO: Mask */
#define GPIO_IO_IN_BMSK		0x1
#define GPIO_IO_OUT_BMSK	0x1

/* GPIO IO: Shift */
#define GPIO_IO_IN_SHFT		0
#define GPIO_IO_OUT_SHFT	1

/* GPIO ID STATUS: Mask */
#define GPIO_ID_STATUS_BMSK	0x1

/* GPIO MAX Valid # */
#define GPIO_NUM_MAX		149

#define GPIO_FUNC_GPIO 0

#define GPIO(num) ((gpio_t){.addr = GPIO##num##_ADDR})

#define PIN(index, tlmm, func1, func2, func3, func4, func5, func6, func7) \
GPIO##index##_ADDR = TLMM_##tlmm##_TILE_BASE + index * TLMM_GPIO_OFF_DELTA, \
GPIO##index##_FUNC_##func1 = 1,	\
GPIO##index##_FUNC_##func2 = 2, \
GPIO##index##_FUNC_##func3 = 3, \
GPIO##index##_FUNC_##func4 = 4, \
GPIO##index##_FUNC_##func5 = 5, \
GPIO##index##_FUNC_##func6 = 6, \
GPIO##index##_FUNC_##func7 = 7

enum {
	PIN(0, EAST,	QUP_L0, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(1, EAST,	QUP_L1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(2, EAST,	QUP_L2, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(3, EAST,	QUP_L3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(4, NORTH,	QUP_L2, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(5, NORTH,	QUP_L3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(6, NORTH,	QUP_L0, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(7, NORTH,	QUP_L1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(8, EAST,	QUP_L4_0_CS, GP_PDM_MIRB, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(9, EAST,	QUP_L5_0_CS, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(10, EAST,	MDP_VSYNC_P_MIRA, QUP_L6_0_CS, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(11, EAST,	MDP_VSYNC_S_MIRA, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(12, SOUTH,	MDP_VSYNC_E, RES_2, TSIF1_SYNC, RES_4, RES_5,
		RES_6, RES_7),
	PIN(13, SOUTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(14, SOUTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(15, SOUTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(16, SOUTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(17, SOUTH,	CCI_I2C_SDA0, QUP_L0, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(18, SOUTH,	CCI_I2C_SCL0, QUP_L1, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(19, SOUTH,	CCI_I2C_SDA1, QUP_L2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(20, SOUTH,	CCI_I2C_SCL1, QUP_L3, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(21, SOUTH,	CCI_TIMER0, GCC_GP2_CLK_MIRB, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(22, SOUTH,	CCI_TIMER1, GCC_GP3_CLK_MIRB, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(23, SOUTH,	CCI_TIMER2, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(24, SOUTH,	CCI_TIMER3, CCI_ASYNC_IN1, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(25, SOUTH,	CCI_TIMER4, CCI_ASYNC_IN2, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(26, SOUTH,	CCI_ASYNC_IN0, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(27, EAST,	QUP_L0, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(28, EAST,	QUP_L1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(29, EAST,	QUP_L2, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(30, EAST,	QUP_L3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(31, NORTH,	QUP_L0, QUP_L2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(32, NORTH,	QUP_L1, QUP_L3, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(33, NORTH,	QUP_L2, QUP_L0, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(34, NORTH,	QUP_L3, QUP_L1, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(35, SOUTH,	PCI_E0_RST_N, QUP_L4_1_CS, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(36, SOUTH,	PCI_E0_CLKREQN, QUP_L5_1_CS, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(37, SOUTH,	QUP_L6_1_CS, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(38, NORTH,	USB_PHY_PS, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(39, EAST,	LPASS_SLIMBUS_DATA2, RES_2, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(40, SOUTH,	SD_WRITE_PROTECT, TSIF1_ERROR, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(41, EAST,	QUP_L0, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(42, EAST,	QUP_L1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(43, EAST,	QUP_L2, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(44, EAST,	QUP_L3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(45, EAST,	QUP_L0, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(46, EAST,	QUP_L1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(47, EAST,	QUP_L2, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(48, EAST,	QUP_L3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(49, NORTH,	QUP_L0, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(50, NORTH,	QUP_L1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(51, NORTH,	QUP_L2, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(52, NORTH,	QUP_L3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(53, NORTH,	QUP_L2, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(54, NORTH,	QUP_L3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(55, NORTH,	QUP_L0, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(56, NORTH,	QUP_L1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(57, NORTH,	QUA_MI2S_MCLK, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(58, NORTH,	QUA_MI2S_SCK, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(59, NORTH,	QUA_MI2S_WS, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(60, NORTH,	QUA_MI2S_DATA0, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(61, NORTH,	QUA_MI2S_DATA1, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(62, NORTH,	QUA_MI2S_DATA2, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(63, NORTH,	QUA_MI2S_DATA3, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(64, NORTH,	PRI_MI2S_MCLK, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(65, NORTH,	PRI_MI2S_SCK, QUP_L0, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(66, NORTH,	PRI_MI2S_WS, QUP_L1, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(67, NORTH,	PRI_MI2S_DATA0, QUP_L2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(68, NORTH,	PRI_MI2S_DATA1, QUP_L3, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(69, EAST,	SPKR_I2S_MCLK, AUDIO_REF_CLK, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(70, EAST,	LPASS_SLIMBUS_CLK, SPKR_I2S_SCK, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(71, EAST,	LPASS_SLIMBUS_DATA0, SPKR_I2S_DATA_OUT, RES_3,
		RES_4, RES_5, RES_6, RES_7),
	PIN(72, EAST,	LPASS_SLIMBUS_DATA1, SPKR_I2S_WS, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(73, EAST,	BTFM_SLIMBUS_DATA, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(74, EAST,	BTFM_SLIMBUS_CLK, TER_MI2S_MCLK, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(75, EAST,	TER_MI2S_SCK, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(76, EAST,	TER_MI2S_WS, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(77, EAST,	TER_MI2S_DATA0, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(78, EAST,	TER_MI2S_DATA1, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(79, NORTH,	SEC_MI2S_MCLK, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(80, NORTH,	SEC_MI2S_SCK, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(81, NORTH,	SEC_MI2S_WS, QUP_L0, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(82, NORTH,	SEC_MI2S_DATA0, QUP_L1, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(83, NORTH,	SEC_MI2S_DATA1, QUP_L2, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(84, NORTH,	QUP_L3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(85, EAST,	QUP_L0, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(86, EAST,	QUP_L1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(87, EAST,	QUP_L2, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(88, EAST,	QUP_L3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(89, SOUTH,	TSIF1_CLK, QUP_L0, QSPI_CS_N_1, RES_4, RES_5,
		RES_6, RES_7),
	PIN(90, SOUTH,	TSIF1_EN, MDP_VSYNC0_OUT, QUP_L1, QSPI_CS_N_0,
		MDP_VSYNC1_OUT, MDP_VSYNC2_OUT, MDP_VSYNC3_OUT),
	PIN(91, SOUTH,	TSIF1_DATA, SDC4_CMD, QUP_L2, QSPI_DATA,
		RES_5, RES_6, RES_7),
	PIN(92, SOUTH,	TSIF2_ERROR, SDC4_DATA, QUP_L3, QSPI_DATA,
		RES_5, RES_6, RES_7),
	PIN(93, SOUTH,	TSIF2_CLK, SDC4_CLK, QUP_L0, QSPI_DATA,
		RES_5, RES_6, RES_7),
	PIN(94, SOUTH,	TSIF2_EN, SDC4_DATA, QUP_L1, QSPI_DATA,
		RES_5, RES_6, RES_7),
	PIN(95, SOUTH,	TSIF2_DATA, SDC4_DATA, QUP_L2, QSPI_CLK,
		RES_5, RES_6, RES_7),
	PIN(96, SOUTH,	TSIF2_SYNC, SDC4_DATA, QUP_L3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(97, NORTH,	RFFE6_CLK, GRFC37, MDP_VSYNC_P_MIRB,
		RES_4, RES_5, RES_6, RES_7),
	PIN(98, NORTH,	RFFE6_DATA, MDP_VSYNC_S_MIRB, RES_3,
		RES_4, RES_5, RES_6, RES_7),
	PIN(99, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(100, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(101, NORTH,	GRFC4, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(102, NORTH,	PCI_E1_RST_N, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(103, NORTH,	PCI_E1_CLKREQN, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(104, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(105, NORTH,	UIM2_DATA, QUP_L0, QUP_L4_8_CS, RES_4, RES_5,
		RES_6, RES_7),
	PIN(106, NORTH,	UIM2_CLK, QUP_L1, QUP_L5_8_CS, RES_4, RES_5,
		RES_6, RES_7),
	PIN(107, NORTH,	UIM2_RESET, QUP_L2, QUP_L6_8_CS, RES_4, RES_5,
		RES_6, RES_7),
	PIN(108, NORTH,	UIM2_PRESENT, QUP_L3, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(109, NORTH,	UIM1_DATA, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(110, NORTH,	UIM1_CLK, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(111, NORTH,	UIM1_RESET, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(112, NORTH,	UIM1_PRESENT, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(113, NORTH,	UIM_BATT_ALARM, EDP_HOT_PLUG_DETECT, RES_3,
		RES_4, RES_5, RES_6, RES_7),
	PIN(114, NORTH,	GRFC8, RES_2, RES_3, GPS_TX_AGGRESSOR_MIRE,
		RES_5, RES_6, RES_7),
	PIN(115, NORTH,	GRFC9, RES_2, RES_3, GPS_TX_AGGRESSOR_MIRF,
		RES_5, RES_6, RES_7),
	PIN(116, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(117, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(118, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(119, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(120, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(121, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(122, EAST,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(123, EAST,	QUP_L4_9_CS, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(124, EAST,	QUP_L5_9_CS, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(125, EAST,	QUP_L6_9_CS, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(126, EAST,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(127, NORTH,	GRFC3, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(128, NORTH,	RES_1, RES_2, GPS_TX_AGGRESSOR_MIRB, RES_4,
		RES_5, RES_6, RES_7),
	PIN(129, NORTH,	RES_1, RES_2, GPS_TX_AGGRESSOR_MIRC, RES_4,
		RES_5, RES_6, RES_7),
	PIN(130, NORTH,	QLINK_REQUEST, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(131, NORTH,	QLINK_ENABLE, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(132, NORTH,	GRFC2, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(133, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(134, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(135, NORTH,	GRFC0, PA_INDICATOR_1_OR_2, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(136, NORTH,	GRFC1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(137, NORTH,	RFFE3_DATA, GRFC35, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(138, NORTH,	RFFE3_CLK, GRFC32, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(139, NORTH,	RFFE4_DATA, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(140, NORTH,	RFFE4_CLK, GRFC36, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(141, NORTH,	RFFE5_DATA, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(142, NORTH,	RFFE5_CLK, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(143, NORTH,	GRFC5, RES_2, RES_3, GPS_TX_AGGRESSOR_MIRD,
		RES_5, RES_6, RES_7),
	PIN(144, NORTH,	RES_1, RES_2, RES_3, RES_4, RES_5, RES_6, RES_7),
	PIN(145, NORTH,	RES_1, GPS_TX_AGGRESSOR_MIRA, RES_3, RES_4,
		RES_5, RES_6, RES_7),
	PIN(146, NORTH,	RFFE2_DATA, GRFC34, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(147, NORTH,	RFFE2_CLK, GRFC33, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(148, NORTH,	RFFE1_DATA, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
	PIN(149, NORTH,	RFFE1_CLK, RES_2, RES_3, RES_4, RES_5,
		RES_6, RES_7),
};

struct tlmm_gpio {
	uint32_t cfg;
	uint32_t in_out;
};

void gpio_configure(gpio_t gpio, uint32_t func, uint32_t pull,
				uint32_t drive_str, uint32_t enable);

#endif // _SOC_QUALCOMM_SDM845_GPIO_H_
