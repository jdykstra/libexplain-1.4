/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2008-2010, 2013 Peter Miller
 * Written by Peter Miller <pmiller@opensource.org.au>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
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

#include <libexplain/string_buffer.h>


void
explain_string_buffer_init(explain_string_buffer_t *sb, char *message,
    int message_size)
{
    if (!message || message_size <= 0)
    {
        static char dummy[1];
        message = dummy;
        message_size = 1;
    }

    sb->message = message;
    sb->position = 0;
    sb->maximum = message_size;
    sb->message[0] = '\0';
    sb->footnotes = sb;
}


/* vim: set ts=8 sw=4 et : */
