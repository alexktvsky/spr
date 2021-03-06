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

#ifndef INCLUDED_SPR_ARRAY_H
#define INCLUDED_SPR_ARRAY_H

#include "spr_pool.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct spr_array_s spr_array_t;

struct spr_array_s {
    void *data;
    size_t size;
    size_t n_total;
    size_t n_current;
};

spr_array_t *spr_array_create(spr_pool_t *pool, size_t size, size_t n);
spr_err_t spr_array_push(spr_array_t *array, void *data);
void spr_array_clear(spr_array_t *array);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDED_SPR_ARRAY_H */
