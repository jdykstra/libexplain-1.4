/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2009, 2013 Peter Miller
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful,but
 * WITHOUT ANY WARRANTY; without even the implied warranty
 * ofMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNULesser
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libexplain/ac/stdio.h>
#include <libexplain/ac/stdlib.h>

#include <libexplain/buffer/fildes.h>
#include <libexplain/string_to_thing.h>
#include <libexplain/tcdrain.h>
#include <libexplain/wrap_and_print.h>

#include <explain/syscall/tcdrain.h>


void
explain_syscall_tcdrain(int errnum, int argc, char **argv)
{
    int             fildes;

    if (argc != 1)
    {
        fprintf(stderr, "tcdrain: requires 1 argument, not %d\n", argc);
        exit(EXIT_FAILURE);
    }
    fildes = explain_parse_fildes_or_die(argv[0], "arg one");

    explain_wrap_and_print(stdout, explain_errno_tcdrain(errnum, fildes));
}


/* vim: set ts=8 sw=4 et : */
