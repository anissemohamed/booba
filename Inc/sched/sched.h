/******************************************************************************
* Module name: sync.h
*
* (c) Copyright 2018 Notilo PLus, unpublished work.
* All Rights Reserved.
*
* The information contained herein is confidential
* property of Company. The user, copying, transfer or
* disclosure of such information is prohibited except
* by express written agreement with Company.
*
* Module Description: TODO
******************************************************************************/
#ifndef _SCHED_H_
#define _SCHED_H_

#include <stdint.h>
#include <stddef.h>

//------------------------------------------------------------------------------
//	Macros definition
//------------------------------------------------------------------------------
#define SCHED_MAX_TIMERS 8

//==============================================================================
//	void sched_init(void)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	: Initialize TIMER interrupt and "_sched_timer" tab
//------------------------------------------------------------------------------
void sched_init(void);

//==============================================================================
//	uint64_t sched_gettick(void)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	    : Return the current tick
//  Function Output : tick in ms
//------------------------------------------------------------------------------
uint32_t sched_gettick(void);

//==============================================================================
//	void sched_process(void)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	    : Set to 1 the flag when time's out
//------------------------------------------------------------------------------
void sched_process(void);

//==============================================================================
//	void sched_schedule(uint32_t timeout, uint8_t *flag)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	    : Set the timeout value
// Function input   : timeout in ms
// Function output  : flag (Set to 1 when time's out else 0)
//------------------------------------------------------------------------------
void sched_schedule(uint32_t timeout, uint8_t *flag);

//==============================================================================
//	void sched_remove(uint8_t *flag)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	    : Remove flag
// Function input   : flag to remove (on "_sched_timer" tab)
//------------------------------------------------------------------------------
void sched_remove(uint8_t *flag);

#endif//_SCHED_H_
