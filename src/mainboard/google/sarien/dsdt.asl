/*
 * This file is part of the coreboot project.
 *
 * Copyright 2018 Google LLC
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <variant/ec.h>

#include <arch/acpi.h>
DefinitionBlock(
	"dsdt.aml",
	"DSDT",
	0x02,		/* DSDT revision: ACPI v2.0 and up */
	OEM_ID,
	ACPI_TABLE_CREATOR,
	0x20110725	/* OEM revision */
)
{
	/* Some generic macros */
	#include <soc/intel/cannonlake/acpi/platform.asl>

	/* global NVS and variables */
	#include <soc/intel/cannonlake/acpi/globalnvs.asl>

	/* CPU */
	#include <cpu/intel/common/acpi/cpu.asl>

	Scope (\_SB) {
		Device (PWRB)
		{
			Name (_HID, EisaId ("PNP0C0C"))
		}
		Device (PCI0)
		{
			#include <soc/intel/cannonlake/acpi/northbridge.asl>
			#include <soc/intel/cannonlake/acpi/southbridge.asl>
		}
	}

#if IS_ENABLED(CONFIG_CHROMEOS)
	/* Chrome OS specific */
	#include <vendorcode/google/chromeos/acpi/chromeos.asl>
#endif

	/* Chipset specific sleep states */
	#include <soc/intel/cannonlake/acpi/sleepstates.asl>

#if IS_ENABLED(CONFIG_EC_GOOGLE_WILCO)
	/* Chrome OS Embedded Controller */
	Scope (\_SB.PCI0.LPCB)
	{
		/* ACPI code for EC SuperIO functions */
		#include <ec/google/wilco/acpi/superio.asl>
		/* ACPI code for EC functions */
		#include <ec/google/wilco/acpi/ec.asl>
	}
#endif

	/* Dynamic Platform Thermal Framework */
	Scope (\_SB)
	{
		/* Per board variant specific definitions. */
		#include <variant/acpi/dptf.asl>
		/* Include soc specific DPTF changes */
		#include <soc/intel/cannonlake/acpi/dptf.asl>
		/* Include common dptf ASL files */
		#include <soc/intel/common/acpi/dptf/dptf.asl>
	}
}
