/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2009, 2010, 2012, 2013 Peter Miller
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libexplain/ac/errno.h>
#include <libexplain/ac/unistd.h>

#include <libexplain/pathconf.h>
#include <libexplain/output.h>


long
explain_pathconf_on_error(const char *pathname, int name)
{
    long            result;
    int             hold_errno;

    hold_errno = errno;
#ifdef IRIX
    errno = EINVAL; /* IRIX fails to set EINVAL ever */
#else
    errno = 0;
#endif
    result = pathconf(pathname, name);
    if (result == -1 && errno != 0)
    {
        hold_errno = errno;
        explain_output_message
        (
            explain_errno_pathconf(hold_errno, pathname, name)
        );
    }
    errno = hold_errno;
    return result;
}


/* vim: set ts=8 sw=4 et : */
