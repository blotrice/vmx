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

/* strncpy.c - Copy string up to a maximum size */

#include <sys/types.h>
#include <vmx.h>

/******************************************************************************
 * strncpy - Safe string copy
 *
 * RETURNS: Pointer to destination
 */

char* strncpy(
    char *s1,
    const char *s2,
    size_t size
    )
{
    char *dest = s1;

    if (size != 0)
    {
        while ((*dest++ = *s2++) != EOS)
        {
            if (--size == 0)
            {
                return s1;
            }
        }

        while (--size > 0)
        {
            *dest++ = EOS;
        }
    }

    return s1;
}

