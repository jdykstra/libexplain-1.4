#!/bin/sh
#
# libexplain - Explain errno values returned by libc functions
# Copyright (C) 2008, 2010, 2011 Peter Miller
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

TEST_SUBJECT="write vs EINVAL"
. test_prelude

fmt > test.ok.1 << 'fubar'
write(fildes = 0, data = 0x00000010, data_size = 20) failed, Invalid
argument (EINVAL) because the file descriptor is attached to an object
which is unsuitable for writing (O_RDONLY | O_LARGEFILE)
fubar
test $? -eq 0 || no_result

fmt > test.ok.2 << 'fubar'
write(fildes = 0, data = 0x00000010, data_size = 20) failed, Invalid
argument (EINVAL) because the file descriptor is attached to an object
which is unsuitable for writing (O_RDONLY)
fubar
test $? -eq 0 || no_result

touch bogus
test $? -eq 0 || no_result

explain -e EINVAL -o test.out1 write 0 0x10 0x14 < bogus
test $? -eq 0 || fail

fmt -w 500 test.out1 > test.out2
test $? -eq 0 || no_result

sed 's| "[^"]*",|,|' test.out2 > test.out3
test $? -eq 0 || no_result

fmt test.out3 > test.out
test $? -eq 0 || no_result

diff test.ok.2 test.out > /dev/null 2> /dev/null && pass

diff test.ok.1 test.out
test $? -eq 0 || fail

#
# Only definite negatives are possible.
# The functionality exercised by this test appears to work,
# no other guarantees are made.
#
pass

# vim:ts=8:sw=4:et
