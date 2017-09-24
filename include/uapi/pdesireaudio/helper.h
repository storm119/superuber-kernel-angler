/* 
 * Copyright (C) 2017 Tristan Marsell <tristan.marsell@t-online.de>. All rights reserved.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
#ifndef __LINUX_PDESIREAUDIO
#define __LINUX_PDESIREAUDIO

extern void pdesireaudio_initialization(void);

extern int pdesireaudio_enable(void);

extern int pdesireaudio_disable(void);

extern int pdesireaudio_get_pdesireaudio_value(void);

extern void pdesireaudio_set_pdesireaudio_value(void);

extern int pdesireaudio_get_pdesireaudio_static_value(void);

extern void pdesireaudio_set_pdesireaudio_static_value(void);

extern void pdesireaudio_log_fatal_error(const char *message);

extern void pdesireaudio_log_warning(const char *message);

extern void pdesireaudio_log_debug(const char *message);

#endif
