//-----------------------------------------------------------------------------
// Module name: screen_app.c
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
#include <screen/screen_app.h>
#include <gui.h>
#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------
//	Variable definition
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Internal function declaration
//------------------------------------------------------------------------------
static void _screen_app_init(void);

//------------------------------------------------------------------------------
//	External function definition
//------------------------------------------------------------------------------
GUI_SCREEN_t screen_app_process(GUI_SCREEN_HANDLE_t *screen_handle)
{
  GUI_SCREEN_t ret_screen = eGUI_SCREEN_APP;

  if(screen_handle->tick == 0){
    _screen_app_init();
    screen_handle->previous_screen = eGUI_SCREEN_APP;
  }

  return ret_screen;
}

//------------------------------------------------------------------------------
//	Internal function definition
//------------------------------------------------------------------------------
void _screen_app_init(void)
{
  gui_clear();
  gui_draw_string("APP", eGUI_ALIGNMENT_X_MIDDLE | eGUI_ALIGNMENT_Y_MIDDLE, 0);
}
