/* Copyright (c) 2010, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Code Aurora Forum nor
 *       the names of its contributors may be used to endorse or promote
 *       products derived from this software without specific prior written
 *       permission.
 *
 * Alternatively, provided that this notice is retained in full, this software
 * may be relicensed by the recipient under the terms of the GNU General Public
 * License version 2 ("GPL") and only version 2, in which case the provisions of
 * the GPL apply INSTEAD OF those given above.  If the recipient relicenses the
 * software under the GPL, then the identification text in the MODULE_LICENSE
 * macro must be changed to reflect "GPLv2" instead of "Dual BSD/GPL".  Once a
 * recipient changes the license terms to the GPL, subsequent recipients shall
 * not relicense under alternate licensing terms, including the BSD or dual
 * BSD/GPL terms.  In addition, the following license statement immediately
 * below and between the words START and END shall also then apply when this
 * software is relicensed under the GPL:
 *
 * START
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 2 and only version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * END
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "mt9p015.h"
#include <linux/kernel.h>
/*Micron settings from Applications for lower power consumption.*/
struct reg_struct const mt9p015_reg_pat[2] = {
	{ /* Preview */
		/* vt_pix_clk_div          REG=0x0300 */
		0x5,

		/* vt_sys_clk_div          REG=0x0302 */
		0x1,

		/* pre_pll_clk_div         REG=0x0304 */
		0x3,

		/* pll_multiplier          REG=0x0306 */
		0x44,

		/* op_pix_clk_div          REG=0x0308 */
		0xA,

		/* op_sys_clk_div          REG=0x030A */
		0x1,

		/* scale_m                 REG=0x0404 */
		0x10,

		/* row_speed               REG=0x3016 */
		0x0111,

		/* x_addr_start            REG=0x3004 */
		8,

		/* x_addr_end              REG=0x3008 */
		2597,

		/* y_addr_start            REG=0x3002 */
		8,

		/* y_addr_end              REG=0x3006 */
		1949,

		/* read_mode               REG=0x3040
		 * Preview 2x2 skipping */
		0x14C3,

		/* x_output_size           REG=0x034C */
		1296,

		/* y_output_size           REG=0x034E */
		972,

		/* line_length_pck         REG=0x300C */
		3430,

		/* frame_length_lines      REG=0x300A */
		1055,

		/* coarse_integration_time REG=0x3012 */
		800,

		/* fine_integration_time   REG=0x3014 */
		1794,
		0x15c
	},
	{ /*Snapshot*/
		/* vt_pix_clk_div          REG=0x0300 */
		0x5,

		/* vt_sys_clk_div          REG=0x0302 */
		0x1,

		/* pre_pll_clk_div         REG=0x0304 */
		0x3,

		/* pll_multiplier          REG=0x0306 */
		0x4A,

		/* op_pix_clk_div          REG=0x0308 */
		0xA,

		/* op_sys_clk_div          REG=0x030A */
		0x1,

		/* scale_m                 REG=0x0404 */
		0x10,

		/* row_speed               REG=0x3016 */
		0x0111,

		/* x_addr_start            REG=0x3004 */
		0,

		/* x_addr_end              REG=0x3008 */
		2607,

		/* y_addr_start            REG=0x3002 */
		0,

		/* y_addr_end              REG=0x3006 */
		1959,

		/* read_mode               REG=0x3040 */
		0x0041,

		/* x_output_size           REG=0x034C */
		2608,

		/* y_output_size           REG=0x034E */
		1960,

		/* line_length_pck         REG=0x300C */
		3854,

		/* frame_length_lines      REG=0x300A */
		2046,

		/* coarse_integration_time REG=0x3012 */
		800,

		/* fine_integration_time   REG=0x3014 */
		882,
		0x9c
	}
};


struct mt9p015_i2c_reg_conf const mt9p015_test_tbl[] = {
	{0x3044, 0x0544 & 0xFBFF},
	{0x30CA, 0x0004 | 0x0001},
	{0x30D4, 0x9020 & 0x7FFF},
	{0x31E0, 0x0003 & 0xFFFE},
	{0x3180, 0x91FF & 0x7FFF},
	{0x301A, (0x10CC | 0x8000) & 0xFFF7},
	{0x301E, 0x0000},
	{0x3780, 0x0000},
};


struct mt9p015_i2c_reg_conf const mt9p015_lc_tbl[] = {

{0x360A, 0x01B0},
{0x360C, 0xA24B},
{0x360E, 0x04F1},
{0x3610, 0x248C},
{0x3612, 0xCBD1},
{0x364A, 0x980C},
{0x364C, 0x20EB},
{0x364E, 0xD3EE},
{0x3650, 0xBB6B},
{0x3652, 0x0D90},
{0x368A, 0x2331},
{0x368C, 0x71CB},
{0x368E, 0xACF2},
{0x3690, 0xCB8E},
{0x3692, 0xB56F},
{0x36CA, 0x2BAB},
{0x36CC, 0x80AD},
{0x36CE, 0x676F},
{0x36D0, 0x0C4E},
{0x36D2, 0x9670},
{0x370A, 0x88F2},
{0x370C, 0x66AC},
{0x370E, 0xBCF2},
{0x3710, 0x7D0D},
{0x3712, 0x5034},
{0x3600, 0x00D0},
{0x3602, 0x1908},
{0x3604, 0x7770},
{0x3606, 0x200C},
{0x3608, 0xBAB1},
{0x3640, 0xDEAC},
{0x3642, 0xC62C},
{0x3644, 0xA88F},
{0x3646, 0xC0AD},
{0x3648, 0x4330},
{0x3680, 0x1FD1},
{0x3682, 0x596E},
{0x3684, 0x81B2},
{0x3686, 0xF08F},
{0x3688, 0x8D52},
{0x36C0, 0xED2B},
{0x36C2, 0xE02B},
{0x36C4, 0x0CD1},
{0x36C6, 0x5850},
{0x36C8, 0xEFF0},
{0x3700, 0x8812},
{0x3702, 0x82D0},
{0x3704, 0xD373},
{0x3706, 0x2610},
{0x3708, 0x3475},
{0x3614, 0x0150},
{0x3616, 0x0345},
{0x3618, 0x2550},
{0x361A, 0x0149},
{0x361C, 0x8B71},
{0x3654, 0x870B},
{0x3656, 0x1F8A},
{0x3658, 0x65CA},
{0x365A, 0xDF09},
{0x365C, 0x7BAD},
{0x3694, 0x7330},
{0x3696, 0x704D},
{0x3698, 0x8A52},
{0x369A, 0xEDEE},
{0x369C, 0xB9B0},
{0x36D4, 0xB14A},
{0x36D6, 0xE2CD},
{0x36D8, 0x716F},
{0x36DA, 0x1B6F},
{0x36DC, 0xBAF1},
{0x3714, 0xE771},
{0x3716, 0xB40F},
{0x3718, 0xC832},
{0x371A, 0x72EF},
{0x371C, 0x0575},
{0x361E, 0x00D0},
{0x3620, 0xFAAB},
{0x3622, 0x08B1},
{0x3624, 0xF30A},
{0x3626, 0xD1D1},
{0x365E, 0xA5CA},
{0x3660, 0xA62B},
{0x3662, 0x26CD},
{0x3664, 0x996E},
{0x3666, 0x6E2C},
{0x369E, 0x1E11},
{0x36A0, 0xD10B},
{0x36A2, 0x91B2},
{0x36A4, 0xA228},
{0x36A6, 0xD6F1},
{0x36DE, 0x634C},
{0x36E0, 0x85CE},
{0x36E2, 0x486F},
{0x36E4, 0x0431},
{0x36E6, 0x8412},
{0x371E, 0x8472},
{0x3720, 0x472B},
{0x3722, 0xBF13},
{0x3724, 0x0851},
{0x3726, 0x2595},
{0x3782, 0x051C},
{0x3784, 0x03C8},
{0x3780, 0x8000},

};
#if 0
/* rolloff table for illuminant A */
struct mt9p015_i2c_reg_conf const mt9p015_rolloff_tbl[] = {
	/* P_RD_P0Q0 */
	{0x360A, 0x7FEF},
	/* P_RD_P0Q1 */
	{0x360C, 0x232C},
	/* P_RD_P0Q2 */
	{0x360E, 0x7050},
	/* P_RD_P0Q3 */
	{0x3610, 0xF3CC},
	/* P_RD_P0Q4 */
	{0x3612, 0x89D1},
	/* P_RD_P1Q0 */
	{0x364A, 0xBE0D},
	/* P_RD_P1Q1 */
	{0x364C, 0x9ACB},
	/* P_RD_P1Q2 */
	{0x364E, 0x2150},
	/* P_RD_P1Q3 */
	{0x3650, 0xB26B},
	/* P_RD_P1Q4 */
	{0x3652, 0x9511},
	/* P_RD_P2Q0 */
	{0x368A, 0x2151},
	/* P_RD_P2Q1 */
	{0x368C, 0x00AD},
	/* P_RD_P2Q2 */
	{0x368E, 0x8334},
	/* P_RD_P2Q3 */
	{0x3690, 0x478E},
	/* P_RD_P2Q4 */
	{0x3692, 0x0515},
	/* P_RD_P3Q0 */
	{0x36CA, 0x0710},
	/* P_RD_P3Q1 */
	{0x36CC, 0x452D},
	/* P_RD_P3Q2 */
	{0x36CE, 0xF352},
	/* P_RD_P3Q3 */
	{0x36D0, 0x190F},
	/* P_RD_P3Q4 */
	{0x36D2, 0x4413},
	/* P_RD_P4Q0 */
	{0x370A, 0xD112},
	/* P_RD_P4Q1 */
	{0x370C, 0xF50F},
	/* P_RD_P4Q2 */
	{0x370E, 0x6375},
	/* P_RD_P4Q3 */
	{0x3710, 0xDC11},
	/* P_RD_P4Q4 */
	{0x3712, 0xD776},
	/* P_GR_P0Q0 */
	{0x3600, 0x1750},
	/* P_GR_P0Q1 */
	{0x3602, 0xF0AC},
	/* P_GR_P0Q2 */
	{0x3604, 0x4711},
	/* P_GR_P0Q3 */
	{0x3606, 0x07CE},
	/* P_GR_P0Q4 */
	{0x3608, 0x96B2},
	/* P_GR_P1Q0 */
	{0x3640, 0xA9AE},
	/* P_GR_P1Q1 */
	{0x3642, 0xF9AC},
	/* P_GR_P1Q2 */
	{0x3644, 0x39F1},
	/* P_GR_P1Q3 */
	{0x3646, 0x016F},
	/* P_GR_P1Q4 */
	{0x3648, 0x8AB2},
	/* P_GR_P2Q0 */
	{0x3680, 0x1752},
	/* P_GR_P2Q1 */
	{0x3682, 0x70F0},
	/* P_GR_P2Q2 */
	{0x3684, 0x83F5},
	/* P_GR_P2Q3 */
	{0x3686, 0x8392},
	/* P_GR_P2Q4 */
	{0x3688, 0x1FD6},
	/* P_GR_P3Q0 */
	{0x36C0, 0x1131},
	/* P_GR_P3Q1 */
	{0x36C2, 0x3DAF},
	/* P_GR_P3Q2 */
	{0x36C4, 0x89B4},
	/* P_GR_P3Q3 */
	{0x36C6, 0xA391},
	/* P_GR_P3Q4 */
	{0x36C8, 0x1334},
	/* P_GR_P4Q0 */
	{0x3700, 0xDC13},
	/* P_GR_P4Q1 */
	{0x3702, 0xD052},
	/* P_GR_P4Q2 */
	{0x3704, 0x5156},
	/* P_GR_P4Q3 */
	{0x3706, 0x1F13},
	/* P_GR_P4Q4 */
	{0x3708, 0x8C38},
	/* P_BL_P0Q0 */
	{0x3614, 0x0050},
	/* P_BL_P0Q1 */
	{0x3616, 0xBD4C},
	/* P_BL_P0Q2 */
	{0x3618, 0x41B0},
	/* P_BL_P0Q3 */
	{0x361A, 0x660D},
	/* P_BL_P0Q4 */
	{0x361C, 0xC590},
	/* P_BL_P1Q0 */
	{0x3654, 0x87EC},
	/* P_BL_P1Q1 */
	{0x3656, 0xE44C},
	/* P_BL_P1Q2 */
	{0x3658, 0x302E},
	/* P_BL_P1Q3 */
	{0x365A, 0x106E},
	/* P_BL_P1Q4 */
	{0x365C, 0xB58E},
	/* P_BL_P2Q0 */
	{0x3694, 0x0DD1},
	/* P_BL_P2Q1 */
	{0x3696, 0x2A50},
	/* P_BL_P2Q2 */
	{0x3698, 0xC793},
	/* P_BL_P2Q3 */
	{0x369A, 0xE8F1},
	/* P_BL_P2Q4 */
	{0x369C, 0x4174},
	/* P_BL_P3Q0 */
	{0x36D4, 0x01EF},
	/* P_BL_P3Q1 */
	{0x36D6, 0x06CF},
	/* P_BL_P3Q2 */
	{0x36D8, 0x8D91},
	/* P_BL_P3Q3 */
	{0x36DA, 0x91F0},
	/* P_BL_P3Q4 */
	{0x36DC, 0x52EF},
	/* P_BL_P4Q0 */
	{0x3714, 0xA6D2},
	/* P_BL_P4Q1 */
	{0x3716, 0xA312},
	/* P_BL_P4Q2 */
	{0x3718, 0x2695},
	/* P_BL_P4Q3 */
	{0x371A, 0x3953},
	/* P_BL_P4Q4 */
	{0x371C, 0x9356},
	/* P_GB_P0Q0 */
	{0x361E, 0x7EAF},
	/* P_GB_P0Q1 */
	{0x3620, 0x2A4C},
	/* P_GB_P0Q2 */
	{0x3622, 0x49F0},
	{0x3624, 0xF1EC},
	/* P_GB_P0Q4 */
	{0x3626, 0xC670},
	/* P_GB_P1Q0 */
	{0x365E, 0x8E0C},
	/* P_GB_P1Q1 */
	{0x3660, 0xC2A9},
	/* P_GB_P1Q2 */
	{0x3662, 0x274F},
	/* P_GB_P1Q3 */
	{0x3664, 0xADAB},
	/* P_GB_P1Q4 */
	{0x3666, 0x8EF0},
	/* P_GB_P2Q0 */
	{0x369E, 0x09B1},
	/* P_GB_P2Q1 */
	{0x36A0, 0xAA2E},
	/* P_GB_P2Q2 */
	{0x36A2, 0xC3D3},
	/* P_GB_P2Q3 */
	{0x36A4, 0x7FAF},
	/* P_GB_P2Q4 */
	{0x36A6, 0x3F34},
	/* P_GB_P3Q0 */
	{0x36DE, 0x4C8F},
	/* P_GB_P3Q1 */
	{0x36E0, 0x886E},
	/* P_GB_P3Q2 */
	{0x36E2, 0xE831},
	/* P_GB_P3Q3 */
	{0x36E4, 0x1FD0},
	/* P_GB_P3Q4 */
	{0x36E6, 0x1192},
	/* P_GB_P4Q0 */
	{0x371E, 0xB952},
	/* P_GB_P4Q1 */
	{0x3720, 0x6DCF},
	/* P_GB_P4Q2 */
	{0x3722, 0x1B55},
	/* P_GB_P4Q3 */
	{0x3724, 0xA112},
	/* P_GB_P4Q4 */
	{0x3726, 0x82F6},
	/* POLY_ORIGIN_C */
	{0x3782, 0x0510},
	/* POLY_ORIGIN_R  */
	{0x3784, 0x0390},
	/* POLY_SC_ENABLE */
	{0x3780, 0x8000},
};

#endif

struct mt9p015_reg mt9p015_regs = {
	.reg_pat = &mt9p015_reg_pat[0],
	.reg_pat_size = ARRAY_SIZE(mt9p015_reg_pat),
	.ttbl = &mt9p015_test_tbl[0],
	.ttbl_size = ARRAY_SIZE(mt9p015_test_tbl),
	.lctbl = &mt9p015_lc_tbl[0],
	.lctbl_size = ARRAY_SIZE(mt9p015_lc_tbl),
	//.rftbl = &mt9p015_rolloff_tbl[0],
	//.rftbl_size = ARRAY_SIZE(mt9p015_rolloff_tbl)
};


