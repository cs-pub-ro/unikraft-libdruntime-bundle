// GNU D Compiler configure constants.
// Copyright (C) 2015-2018 Free Software Foundation, Inc.

// GCC is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3, or (at your option) any later
// version.

// GCC is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

module gcc.config;

// Does platform define __ARM_EABI_UNWINDER__
enum GNU_ARM_EABI_Unwinder = false;

// Map from thread model to thread interface.
enum ThreadModel
{
    Single,
    Posix,
    Win32,
}

enum ThreadModel GNU_Thread_Model = ThreadModel.Posix;

// Whether struct dl_phdr_info has dlpi_tls_modid member.
enum OS_Have_Dlpi_Tls_Modid = true;

// Whether the linker provides __start_minfo and __stop_minfo symbols
enum Minfo_Bracketing = true;

// Whether target has support for builtin atomics.
enum GNU_Have_Atomics = true;

// Whether target has support for 64-bit builtin atomics.
enum GNU_Have_64Bit_Atomics = true;

// Do we have libatomic available
enum GNU_Have_LibAtomic = true;

// Do we have qsort_r function
enum Have_Qsort_R = true;