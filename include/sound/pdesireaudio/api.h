/* Copyright (C) 2017 Tristan Marsell (tristan.marsell@t-online.de). All rights reserved.
 * Copyright (C) 2017 Team DevElite. All rights reserved.
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
 
#ifndef __SOUND_PDESIREAUDIO_API
#define __SOUND_PDESIREAUDIO_API

extern int pdesireaudio_is_enabled(void);

extern int pdesireaudio_api_print(const char *message, int error_code); 

extern int reinit_pdesireaudio(void);

extern int disable_pdesireaudio(void);

extern int enable_pdesireaudio(void);

extern void pdesireaudio_api_static_mode_control(bool enable);

#endif
