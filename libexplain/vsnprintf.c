/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2010, 2011, 2013 Peter Miller
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
#include <libexplain/ac/stdarg.h>
#include <libexplain/ac/stdio.h>

#include <libexplain/buffer/errno/vsnprintf.h>
#include <libexplain/common_message_buffer.h>
#include <libexplain/vsnprintf.h>


const char *
explain_vsnprintf(char *data, size_t data_size, const char *format, va_list ap)
{
    return explain_errno_vsnprintf(errno, data, data_size, format, ap);
}


const char *
explain_errno_vsnprintf(int errnum, char *data, size_t data_size, const char
    *format, va_list ap)
{
    explain_message_errno_vsnprintf(explain_common_message_buffer,
        explain_common_message_buffer_size, errnum, data, data_size, format,
        ap);
    return explain_common_message_buffer;
}


void
explain_message_vsnprintf(char *message, int message_size, char *data, size_t
    data_size, const char *format, va_list ap)
{
    explain_message_errno_vsnprintf(message, message_size, errno, data,
        data_size, format, ap);
}


void
explain_message_errno_vsnprintf(char *message, int message_size, int errnum,
    char *data, size_t data_size, const char *format, va_list ap)
{
    explain_string_buffer_t sb;

    explain_string_buffer_init(&sb, message, message_size);
    explain_buffer_errno_vsnprintf(&sb, errnum, data, data_size, format, ap);
}


/* vim: set ts=8 sw=4 et : */
