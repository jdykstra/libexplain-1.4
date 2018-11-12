#!/bin/sh
#
# libexplain - Explain errno values returned by libc functions
# Copyright (C) 2008, 2012 Peter Miller
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

TEST_SUBJECT="link EACCES"
. test_prelude

# this test doesn't work for root (or fakeroot)
test_config not-root || pass

cat > test.ok << 'fubar'
link(oldpath = "a/b/foo", newpath = "c/d/bar") failed, Permission denied
(EACCES) because the process does not have write permission to the newpath
"c/d" directory, this is needed to create the directory entry for the "bar"
regular file
fubar
test $? -eq 0 || no_result

mkdir -p a/b c/d
test $? -eq 0 || no_result

touch a/b/foo
test $? -eq 0 || no_result

# we are trying for EACCES
chmod a-w c/d
test $? -eq 0 || no_result

test_link a/b/foo c/d/bar > test.out 2>&1
if test $? -ne 1
then
    chmod -R u+w .
    echo expected to fail
    test -f test.out && cat test.out
    fail
fi

chmod -R u+w .

diff test.ok test.out
test $? -eq 0 || fail

#
# Only definite negatives are possible.
# The functionality exercised by this test appears to work,
# no other guarantees are made.
#
pass

# vim: set ts=8 sw=4 et :
