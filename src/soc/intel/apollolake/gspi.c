/* This file is part of the coreboot project. */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <intelblocks/gspi.h>
#include <soc/pci_devs.h>

int gspi_soc_bus_to_devfn(unsigned int gspi_bus)
{
	switch (gspi_bus) {
	case 0:
		return PCH_DEVFN_SPI0;
	case 1:
		return PCH_DEVFN_SPI1;
	case 2:
		return PCH_DEVFN_SPI2;
	}
	return -1;
}
