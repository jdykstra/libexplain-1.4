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

#include <libexplain/buffer/int32_t.h>
#include <libexplain/buffer/pointer.h>
#include <libexplain/buffer/v4l2_pixel_format.h>
#include <libexplain/buffer/v4l2_vbi_flags.h>
#include <libexplain/buffer/v4l2_vbi_format.h>
#include <libexplain/is_efault.h>
#include <libexplain/sizeof.h>


#ifdef HAVE_LINUX_VIDEODEV2_H

void
explain_buffer_v4l2_vbi_format(explain_string_buffer_t *sb,
    const struct v4l2_vbi_format *data)
{
    if (explain_is_efault_pointer(data, sizeof(*data)))
    {
        explain_buffer_pointer(sb, data);
        return;
    }

    explain_string_buffer_puts(sb, "{ sampling_rate = ");
    explain_buffer_uint32_t(sb, data->sampling_rate);
    explain_string_buffer_puts(sb, ", offset = ");
    explain_buffer_uint32_t(sb, data->offset);
    explain_string_buffer_puts(sb, ", samples_per_line = ");
    explain_buffer_uint32_t(sb, data->samples_per_line);
    explain_string_buffer_puts(sb, ", sample_format = ");
    explain_buffer_v4l2_pixel_format(sb, data->sample_format);
    explain_string_buffer_puts(sb, ", start = ");
    explain_buffer_int32_array(sb, data->start, SIZEOF(data->start));
    explain_string_buffer_puts(sb, ", count = ");
    explain_buffer_uint32_array(sb, data->count, SIZEOF(data->count));
    explain_string_buffer_puts(sb, ", flags = ");
    explain_buffer_v4l2_vbi_flags(sb, data->flags);
    if (!explain_uint32_array_all_zero(data->reserved, SIZEOF(data->reserved)))
    {
        explain_string_buffer_puts(sb, ", reserved = ");
        explain_buffer_uint32_array(sb, data->reserved, SIZEOF(data->reserved));
    }
    explain_string_buffer_puts(sb, " }");
}

#endif

/* vim: set ts=8 sw=4 et : */
