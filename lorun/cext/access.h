/**
 * Loco program runner core
 * Copyright (C) 2011  Lodevil(Du Jiong)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LO_ACCESS_HEADER
#define __LO_ACCESS_HEADER

#include "lorun.h"
#include <sys/user.h>

#define ACCESS_CALL_ERR 1
#define ACCESS_FILE_ERR 2
#define ACCESS_OK 0

#if __WORDSIZE == 64
    #define REG_SYS_CALL(x) ((x)->orig_rax)
    #define REG_ARG_1(x) ((x)->rdi)
    #define REG_ARG_2(x) ((x)->rsi)
    #define REG_ARG_3(x) ((x)->rdx)
#else
    #define REG_SYS_CALL(x) ((x)->orig_eax)
    #define REG_ARG_1(x) ((x)->ebx)
    #define REG_ARG_2(x) ((x)->ecx)
    #define REG_ARG_3(x) ((x)->edx)
#endif

int checkAccess(struct Runobj *runobj, int pid, struct user_regs_struct *regs);
const char* lastFileAccess(void);

#endif
