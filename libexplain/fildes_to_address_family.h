/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2008, 2009, 2013 Peter Miller
 * Written by Peter Miller <pmiller@opensource.org.au>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBEXPLAIN_FILDES_TO_ADDRESS_FAMILY_H
#define LIBEXPLAIN_FILDES_TO_ADDRESS_FAMILY_H

/**
  * The explain_fildes_to_address_family function may be used to
  * obtain the address family of a file descriptor that refers to a
  * network socket.
  *
  * @param fildes
  *    The file descriptor of interest
  * @returns
  *    the address family,
  *    or -1 on error (including not open and not a socket)
  */
int explain_fildes_to_address_family(int fildes);

#endif /* LIBEXPLAIN_FILDES_TO_ADDRESS_FAMILY_H */
/* vim: set ts=8 sw=4 et : */
