/*
 * Copyright (C) 2017, Tristan Marsell <tristan.marsell@t-online.de>. All rights reserved.
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

#include <linux/module.h> 
#include <linux/init.h>
#include <sound/pdesireaudio/api.h>
#include <uapi/pdesireaudio/helper.h>

inline void pdesireaudio_initialization(void)
{
	reinit_pdesireaudio();
}
EXPORT_SYMBOL(pdesireaudio_initialization);

int pdesireaudio_enable(void)
{
	return enable_pdesireaudio();
}
EXPORT_SYMBOL(pdesireaudio_enable);

int pdesireaudio_disable(void)
{
	return disable_pdesireaudio();
}
EXPORT_SYMBOL(pdesireaudio_disable);

int pdesireaudio_get_pdesireaudio_value(void)
{
	return PDesireAudio;
}
EXPORT_SYMBOL(pdesireaudio_get_pdesireaudio_value);

void pdesireaudio_set_pdesireaudio_value(void)
{
	PDesireAudio = 1;
}
EXPORT_SYMBOL(pdesireaudio_set_pdesireaudio_value);

int pdesireaudio_get_pdesireaudio_static_value(void)
{
	return pdesireaudio_static_mode;
}
EXPORT_SYMBOL(pdesireaudio_get_pdesireaudio_static_value);

void pdesireaudio_set_pdesireaudio_static_value(void)
{
	pdesireaudio_static_mode = 1;
}
EXPORT_SYMBOL(pdesireaudio_set_pdesireaudio_static_value);

void pdesireaudio_log_fatal_error(const char *message)
{
	pdesireaudio_api_print(message, 0); 
}
EXPORT_SYMBOL(pdesireaudio_log_fatal_error);

void pdesireaudio_log_warning(const char *message)
{
	pdesireaudio_api_print(message, 1); 
}
EXPORT_SYMBOL(pdesireaudio_log_warning);

void pdesireaudio_log_debug(const char *message)
{
	pdesireaudio_api_print(message, 2); 
}
EXPORT_SYMBOL(pdesireaudio_log_debug);
