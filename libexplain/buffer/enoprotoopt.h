/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2009, 2013 Peter Miller
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
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBEXPLAIN_BUFFER_ENOPROTOOPT_H
#define LIBEXPLAIN_BUFFER_ENOPROTOOPT_H

#include <libexplain/string_buffer.h>

struct enoprotoopt; /* forward */

/**
  * The explain_buffer_enoprotoopt function may be used to print
  * an explanation for an ENOPROTOOPT error, reported by some socket
  * functions.
  *
  * @param sb
  *     The string buffer to print into.
  * @param caption
  *     The name of the offending system call argument.
  */
void explain_buffer_enoprotoopt(explain_string_buffer_t *sb,
    const char *caption);

#endif /* LIBEXPLAIN_BUFFER_ENOPROTOOPT_H */
/* vim: set ts=8 sw=4 et : */
