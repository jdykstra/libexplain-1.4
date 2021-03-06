/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2008, 2009 Peter Miller
 * Written by Peter Miller <pmiller@opensource.org.au>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CODEGEN_GENERATE_H
#define CODEGEN_GENERATE_H

#include <codegen/catalogue.h>
#include <codegen/node.h>

/**
  * The generate function is used to generate the content, give the
  * function declaration.
  *
  * @param np
  *    The complete function declaration.
  * @param cp
  *    The system call catalogue entry.
  */
void generate(node_t *np, catalogue_t *cp);

/**
  * The generate_specific function is used to limit the file generation
  * to the named file(s).  May be called more than once.
  */
void generate_specific(const char *filename);

#endif /* CODEGEN_GENERATE_H */
