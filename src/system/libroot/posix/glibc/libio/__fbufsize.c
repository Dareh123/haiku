/* Copyright (C) 2000-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <stdio_ext.h>

size_t
__fbufsize (FILE *fp)
{
#ifdef __HAIKU__
  if (fp->_flags & _IO_UNBUFFERED)
    return 0;
#endif

  if (fp->_mode > 0)
    return fp->_wide_data->_IO_buf_end - fp->_wide_data->_IO_buf_base;
  else
    return fp->_IO_buf_end - fp->_IO_buf_base;
}
