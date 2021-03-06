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

#ifndef INCLUDED_SPR_SOCKADDR_H
#define INCLUDED_SPR_SOCKADDR_H

#ifdef __cplusplus
extern "C" {
#endif

#define SPR_ADDR_INVALID            -1
#define SPR_ADDR_IPV4                0
#define SPR_ADDR_IPV6                1

#define SPR_NI_MAXHOST               NI_MAXHOST
#define SPR_NI_MAXSERV               NI_MAXSERV

#define spr_sockaddr_is_ipv4(sockaddr) \
    (sockaddr->ss_family == AF_INET)
#define spr_sockaddr_is_ipv6(sockaddr) \
    (sockaddr->ss_family == AF_INET6)


const char * spr_sockaddr_get_addr_text(const struct sockaddr *sockaddr,
    char *buf, size_t bufsize);
const char *spr_sockaddr_get_port_text(const struct sockaddr *sockaddr,
    char *buf, size_t bufsize);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDED_SPR_SOCKADDR_H */
