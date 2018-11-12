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

#ifndef LIBEXPLAIN_PATHNAME_IS_A_DIRECTORY_H
#define LIBEXPLAIN_PATHNAME_IS_A_DIRECTORY_H

/**
  * The explain_pathname_is_a_directory function may be used to
  * determine whether or not a given pathname refers to a directory.
  *
  * @param pathname
  *    The path of interest
  * @returns
  *    int; non-zero (true) if the path exists and is a directory, zero
  *    (false) if the file does not exists, or does exist but is not a
  *    directory.
  */
int explain_pathname_is_a_directory(const char *pathname);

#endif /* LIBEXPLAIN_PATHNAME_IS_A_DIRECTORY_H */
/* vim: set ts=8 sw=4 et : */
