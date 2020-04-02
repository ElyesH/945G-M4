/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <baseboard/variants.h>
#include <bootblock_common.h>
#include <soc/gpio.h>

void bootblock_mainboard_init(void)
{
	const struct pad_config *pads;
	size_t num;

	pads = variant_early_gpio_table(&num);
	gpio_configure_pads(pads, num);
}
