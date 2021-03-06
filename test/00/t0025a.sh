#!/bin/sh
#
# libexplain - Explain errno values returned by libc functions
# Copyright (C) 2008, 2011 Peter Miller
# Written by Peter Miller <pmiller@opensource.org.au>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or (at
# your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <http://www.gnu.org/licenses/>.
#

TEST_SUBJECT="open vs ENOENT"
. test_prelude

fmt > test.ok.1 << 'fubar'
open(pathname = "foo/bar/baz", flags = O_WRONLY | O_CREAT | O_TRUNC, mode =
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) failed, No such
file or directory (ENOENT) because there is no "bar" directory in the
pathname "foo" directory
fubar
test $? -eq 0 || no_result

fmt > test.ok.2 << fubar
open(pathname = "foo/bar/baz", flags = O_WRONLY | O_CREAT | O_TRUNC, mode =
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) failed, No such
file or directory (ENOENT) because there is no "bar" directory in the
pathname "$testdir/foo" directory
fubar
test $? -eq 0 || no_result

mkdir foo
test $? -eq 0 || no_result

test_open -f O_WRONLY+O_CREAT+O_TRUNC foo/bar/baz > test.out.2 2>&1
if test $? -ne 1
then
    echo it must fail
    cat test.out
    fail
fi

fmt test.out.2 > test.out
test $? -eq 0 || no_result

diff test.ok.2 test.out > /dev/null 2>&1 && pass

diff test.ok.1 test.out
test $? -eq 0 || fail

#
# Only definite negatives are possible.
# The functionality exercised by this test appears to work,
# no other guarantees are made.
#
pass

# vim:ts=8:sw=4:et
