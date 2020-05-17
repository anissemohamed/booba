//-----------------------------------------------------------------------------
// Module name: sync.h
//
// (c) Copyright 2018 Notilo PLus, unpublished work.
// All Rights Reserved.
//
// The information contained herein is confidential
// property of Company. The user, copying, transfer or
// disclosure of such information is prohibited except
// by express written agreement with Company.
//
// Module Description: TODO
//-----------------------------------------------------------------------------
#include <sched.h>
#include "stm32l4xx_hal.h"

//------------------------------------------------------------------------------
//	Variable definition
//------------------------------------------------------------------------------
static struct
{
	uint32_t ts;
	uint8_t *flag;
} _sched_timers[SCHED_MAX_TIMERS];

//------------------------------------------------------------------------------
//	EXternal function definition
//------------------------------------------------------------------------------
void sched_init(void)
{
	uint8_t index = 0;

	for(index=0; index<SCHED_MAX_TIMERS; index++) {
		_sched_timers[index].ts = 0;
		_sched_timers[index].flag = 0;
	}
}

uint32_t sched_gettick(void)
{
	return HAL_GetTick();
}


void sched_process(void)
{
  uint8_t index = 0;
	uint64_t now  = sched_gettick();

	for(index=0; index<SCHED_MAX_TIMERS; index++) {
		if ((_sched_timers[index].ts != 0) && (_sched_timers[index].flag != 0)) {
			if (now >= _sched_timers[index].ts)	{
				*_sched_timers[index].flag = 1;

				_sched_timers[index].ts = 0;
				_sched_timers[index].flag = 0;
			}
		}
	}
}

void sched_schedule(uint32_t timeout, uint8_t *flag)
{
	uint8_t index;

	sched_remove(flag);
	*flag = 0;

	for(index=0; index<SCHED_MAX_TIMERS; index++)
	{
		if ((_sched_timers[index].ts == 0) && (_sched_timers[index].flag == 0))
		{
			_sched_timers[index].ts = sched_gettick() + timeout;
			_sched_timers[index].flag = flag;
			return;
		}
	}
}

void sched_remove(uint8_t *flag)
{
	uint8_t index;

	for(index=0; index<SCHED_MAX_TIMERS; index++)
	{
		if (flag == _sched_timers[index].flag)
		{
			_sched_timers[index].ts = 0;
			_sched_timers[index].flag = 0;
		}
	}
}
