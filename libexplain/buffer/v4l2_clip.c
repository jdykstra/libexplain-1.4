/*
 * libexplain - a library of system-call-specific strerror replacements
 * Copyright (C) 2011, 2013 Peter Miller
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

#include <libexplain/ac/linux/videodev2.h>

#include <libexplain/buffer/v4l2_clip.h>
#include <libexplain/buffer/v4l2_rect.h>
#include <libexplain/buffer/pointer.h>
#include <libexplain/is_efault.h>


#ifdef HAVE_LINUX_VIDEODEV2_H

void
explain_buffer_v4l2_clip(explain_string_buffer_t *sb,
    const struct v4l2_clip *data)
{
    if (explain_is_efault_pointer(data, sizeof(*data)))
    {
        explain_buffer_pointer(sb, data);
        return;
    }

    explain_string_buffer_puts(sb, "{ c = ");
    explain_buffer_v4l2_rect(sb, &data->c);
    explain_string_buffer_puts(sb, ", next = ");
    explain_buffer_pointer(sb, data->next);
    explain_string_buffer_puts(sb, " }");
}


void
explain_buffer_v4l2_clip_list(explain_string_buffer_t *sb,
    const struct v4l2_clip *data, size_t data_size)
{
    int             first;

    if (explain_is_efault_pointer(data, sizeof(*data)) || !data_size)
    {
        explain_buffer_pointer(sb, data);
        return;
    }

    first = 1;
    explain_string_buffer_puts(sb, "{");
    while (data && data_size > 0)
    {
        if (!first)
        {
            explain_string_buffer_puts(sb, ", ");
            first = 0;
        }
        explain_buffer_v4l2_rect(sb, &data->c);
        data = data->next;
        if (!data)
            break;
        --data_size;
        if (!data_size)
            break;
        if (explain_is_efault_pointer(data, sizeof(*data)))
        {
            explain_string_buffer_puts(sb, ", ");
            explain_buffer_pointer(sb, data);
            break;
        }
    }
    explain_string_buffer_puts(sb, " }");
}

#endif

/* vim: set ts=8 sw=4 et : */
