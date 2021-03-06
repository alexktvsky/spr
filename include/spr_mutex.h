/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2020 Alex Kotovsky <alexktvsky@gmail.com>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef INCLUDED_SPR_MUTEX_H
#define INCLUDED_SPR_MUTEX_H

#include "spr_portable.h"
#include "spr_bitfield.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Mutex specific parameters */
#define SPR_MUTEX_SHARED             0x00000001
#define SPR_MUTEX_PRIVATE            0x00000002
#define SPR_MUTEX_RECURSIVE          0x00000004
#define SPR_MUTEX_NONRECURSIVE       0x00000008
#define SPR_MUTEX_DEFAULT            0x00000010


#if (SPR_POSIX)

struct spr_mutex_s {
    pthread_mutex_t handle;
};

#elif (SPR_WIN32)

typedef enum {
    spr_mutex_mutex,
    spr_mutex_critical_section
} spr_mutex_type_t;

struct spr_mutex_s {
    HANDLE handle;
    spr_mutex_type_t type;
    CRITICAL_SECTION section;
};

#endif

spr_err_t spr_mutex_init(spr_mutex_t *mutex, spr_bitfield_t params);
spr_err_t spr_mutex_lock(spr_mutex_t *mutex);
spr_err_t spr_mutex_trylock(spr_mutex_t *mutex);
spr_err_t spr_mutex_unlock(spr_mutex_t *mutex);
void spr_mutex_fini(spr_mutex_t *mutex);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDED_SPR_MUTEX_H */
