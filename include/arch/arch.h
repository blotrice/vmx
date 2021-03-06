/******************************************************************************
 *   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.
 *
 *   This file is part of Real VMX.
 *   Copyright (C) 2013 Surplus Users Ham Society
 *
 *   Real VMX is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Real VMX is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Real VMX.  If not, see <http://www.gnu.org/licenses/>.
 */

/* arch.h - Architecutre specific stuff */

#ifndef _arch_h_
#define _arch_h_

#define _BIG_ENDIAN                     1234
#define _LITTLE_ENDIAN                  4321
#define _STACK_GROWS_DOWN               (-1)
#define _STACK_GROWS_UP                 ( 1)

#include <types/vmxCpu.h>

#if	 CPU_FAMILY==I386
#include <arch/i386/archI386.h>
#endif

#endif

