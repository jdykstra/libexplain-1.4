/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2009, 2010, 2013 Peter Miller
 * Written by Peter Miller <pmiller@opensource.org.au>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBEXPLAIN_AC_SYS_MMAN_H
#define LIBEXPLAIN_AC_SYS_MMAN_H

/**
  * @file
  * @brief Insulate <sys/mman.h> differences
  */

#include <libexplain/config.h>

#ifdef HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif

#endif /* LIBEXPLAIN_AC_SYS_MMAN_H */
/* vim: set ts=8 sw=4 et : */
