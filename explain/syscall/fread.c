/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2008, 2009 Peter Miller
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libexplain/ac/stdio.h>
#include <libexplain/ac/stdlib.h>

#include <libexplain/fread.h>
#include <libexplain/strtol.h>
#include <libexplain/wrap_and_print.h>

#include <explain/syscall/fread.h>


void
explain_syscall_fread(int errnum, int argc, char **argv)
{
    void            *ptr;
    long            size;
    long            nmemb;
    FILE            *fp;

    if (argc != 4 && argc != 3)
    {
        fprintf(stderr, "fread: requires 4 arguments, not %d\n", argc);
        exit(EXIT_FAILURE);
    }
    ptr = (void *)explain_strtol_or_die(argv[0], 0, 0);
    size = explain_strtol_or_die(argv[1], 0, 0);
    nmemb = explain_strtol_or_die(argv[2], 0, 0);
    fp = argc < 4 ? stdin : (FILE *)explain_strtol_or_die(argv[3], 0, 0);

    explain_wrap_and_print
    (
        stdout,
        explain_errno_fread(errnum, ptr, size, nmemb, fp)
    );
}
