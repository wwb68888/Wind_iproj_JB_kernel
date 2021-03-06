/* Copyright (c) 2008-2010, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef TVENC_H
#define TVENC_H

#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/fb.h>

#include <mach/hardware.h>
#include <linux/io.h>

#include <asm/system.h>
#include <asm/mach-types.h>

#include "msm_fb_panel.h"

#define NTSC_M		0 /* North America, Korea */
#define NTSC_J		1 /* Japan */
#define PAL_BDGHIN	2 /* Non-argentina PAL-N */
#define PAL_M		3 /* PAL-M */
#define PAL_N		4 /* Argentina PAL-N */

#define CLOCK_OFF	0
#define CLOCK_ON	1

/* 3.57954545 Mhz */
#define TVENC_CTL_TV_MODE_NTSC_M_PAL60  0
/* 3.57961149 Mhz */
#define TVENC_CTL_TV_MODE_PAL_M			BIT(0)
/*non-Argintina = 4.3361875 Mhz */
#define TVENC_CTL_TV_MODE_PAL_BDGHIN		BIT(1)
/*Argentina = 3.582055625 Mhz */
#define TVENC_CTL_TV_MODE_PAL_N			(BIT(1)|BIT(0))

#define TVENC_CTL_ENC_EN			BIT(2)
#define TVENC_CTL_CC_EN				BIT(3)
#define TVENC_CTL_CGMS_EN			BIT(4)
#define TVENC_CTL_MACRO_EN			BIT(5)
#define TVENC_CTL_Y_FILTER_W_NOTCH		BIT(6)
#define TVENC_CTL_Y_FILTER_WO_NOTCH		0
#define TVENC_CTL_Y_FILTER_EN			BIT(7)
#define TVENC_CTL_CR_FILTER_EN			BIT(8)
#define TVENC_CTL_CB_FILTER_EN			BIT(9)
#define TVENC_CTL_SINX_FILTER_EN		BIT(10)
#define TVENC_CTL_TEST_PATT_EN			BIT(11)
#define TVENC_CTL_OUTPUT_INV			BIT(12)
#define TVENC_CTL_PAL60_MODE			BIT(13)
#define TVENC_CTL_NTSCJ_MODE			BIT(14)
#define TVENC_CTL_S_VIDEO_EN			BIT(19)


#define TVENC_CTL_TPG_CLRBAR			0
#define TVENC_CTL_TPG_MODRAMP			BIT(15)
#define TVENC_CTL_TPG_REDCLR			BIT(16)
#define TVENC_CTL_TPG_NTSC_CBAR			(BIT(16)|BIT(15))
#define TVENC_CTL_TPG_BLACK			BIT(17)
#define TVENC_CTL_TPG_WHITE100			(BIT(17)|BIT(15))
#define TVENC_CTL_TPG_YELLOW75			(BIT(17)|BIT(16))
#define TVENC_CTL_TPG_CYAN75			(BIT(17)|BIT(16)|BIT(15))
#define TVENC_CTL_TPG_GREEN75			BIT(18)
#define TVENC_CTL_TPG_MAGENTA75			(BIT(18)|BIT(15))
#define TVENC_CTL_TPG_RED75			(BIT(18)|BIT(16))
#define TVENC_CTL_TPG_BLUE75			(BIT(18)|BIT(16)|BIT(15))
#define TVENC_CTL_TPG_WHITE75			(BIT(18)|BIT(17))
#define TVENC_CTL_TPG_WHITE_TRSTN		(BIT(18)|BIT(17)|BIT(15))

#define TVENC_LOAD_DETECT_EN			BIT(8)

#ifdef TVENC_C
void *tvenc_base;
struct tvenc_platform_data *tvenc_pdata;
#else
extern void *tvenc_base;
extern struct tvenc_platform_data *tvenc_pdata;
#endif

#define TV_OUT(reg, v)		writel(v, tvenc_base + MSM_##reg)
#define TV_IN(reg)		readl(tvenc_base + MSM_##reg)

#define MSM_TV_ENC_CTL				0x00
#define MSM_TV_LEVEL				0x04
#define MSM_TV_GAIN				0x08
#define MSM_TV_OFFSET				0x0c
#define MSM_TV_CGMS				0x10
#define MSM_TV_SYNC_1				0x14
#define MSM_TV_SYNC_2				0x18
#define MSM_TV_SYNC_3				0x1c
#define MSM_TV_SYNC_4				0x20
#define MSM_TV_SYNC_5				0x24
#define MSM_TV_SYNC_6				0x28
#define MSM_TV_SYNC_7				0x2c
#define MSM_TV_BURST_V1				0x30
#define MSM_TV_BURST_V2				0x34
#define MSM_TV_BURST_V3				0x38
#define MSM_TV_BURST_V4				0x3c
#define MSM_TV_BURST_H				0x40
#define MSM_TV_SOL_REQ_ODD			0x44
#define MSM_TV_SOL_REQ_EVEN			0x48
#define MSM_TV_DAC_CTL				0x4c
#define MSM_TV_TEST_MUX				0x50
#define MSM_TV_TEST_MODE			0x54
#define MSM_TV_TEST_MISR_RESET			0x58
#define MSM_TV_TEST_EXPORT_MISR			0x5c
#define MSM_TV_TEST_MISR_CURR_VAL		0x60
#define MSM_TV_TEST_SOF_CFG			0x64
#define MSM_TV_DAC_INTF				0x100

#define MSM_TV_INTR_ENABLE			0x200
#define MSM_TV_INTR_STATUS			0x204
#define MSM_TV_INTR_CLEAR			0x208

int tvenc_set_encoder_clock(boolean clock_on);
int tvenc_set_clock(boolean clock_on);
#endif /* TVENC_H */
