#!/bin/sh
#
# libexplain - a library of system-call-specific strerror replacements
# Copyright (C) 2010, 2011 Peter Miller
# Written by Peter Miller <pmiller@opensource.org.au>
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 3 of the License, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License along with
# this program. If not, see <http://www.gnu.org/licenses/>.
#

TEST_SUBJECT="ptrace EIO"
. test_prelude

cat > test.ok << 'fubar'
ptrace(request = PT_CONTINUE, pid = 0, addr = NULL, data = 666) failed,
Input/output error (EIO) because an invalid signal was specified during a
restart request
fubar
test $? -eq 0 || no_result

explain -eEIO ptrace PT_CONTINUE 0 0 666 > test.out
test $? -eq 0 || fail

diff test.ok test.out
test $? -eq 0 || fail

#
# Only definite negatives are possible.
# The functionality exercised by this test appears to work,
# no other guarantees are made.
#
pass

# vim:ts=8:sw=4:et