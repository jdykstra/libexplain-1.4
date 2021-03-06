/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2013 Peter Miller
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libexplain/ac/errno.h>
#include <libexplain/ac/grp.h>

#include <libexplain/output.h>
#include <libexplain/setgrent.h>


void
explain_setgrent_or_die(void)
{
    int             hold_errno;

    hold_errno = errno;
    errno = 0;
    explain_setgrent_on_error();
    if (errno)
    {
        hold_errno = errno;
        explain_output_exit_failure();
    }
    errno = hold_errno;
}


void
explain_setgrent_on_error(void)
{
    int             hold_errno;

    hold_errno = errno;
    errno = 0;
#ifdef HAVE_SETGRENT
    setgrent();
#else
    errno = ENOSYS;
#endif
    if (errno != 0)
    {
        hold_errno = errno;
        explain_output_error("%s", explain_errno_setgrent(hold_errno));
    }
    errno = hold_errno;
}


/* vim: set ts=8 sw=4 et : */
