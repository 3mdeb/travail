/*
 * Copyright (c) 2018 Daniel P. Smith, Apertus Solutions, LLC
 *
 * The definitions in this header are extracted from:
 *  - Trusted Computing Group's "TPM Main Specification", Parts 1-3.
 *  - Trusted Computing Group's TPM 2.0 Library Specification Parts 1&2.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include <linux/types.h>
#include <linux/init.h>
#include <linux/linkage.h>
#include <asm/io.h>
#include <asm/segment.h>
#include <linux/tpm_command.h>
#include <asm/tpm.h>

#include "early_tpm.h"

/*
 * Use a static environment since memory management is not ready in the
 * early uncompressed kernel.
 */
#define CONF_STATIC_ENV

