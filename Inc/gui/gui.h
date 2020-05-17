/******************************************************************************
* Module name: gui.h
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
#ifndef __GUI_H__
#define __GUI_H__

#include <stdint.h>
#include <ssd1306.h>

//------------------------------------------------------------------------------
//	Macros definition
//------------------------------------------------------------------------------
#define GUI_PROCESS_PERIOD_MS             100
#if (GUI_PROCESS_PERIOD_MS == 0)
# error "GUI_PROCESS_PERIOD_MS = 0 is not allowed"
#endif

//------------------------------------------------------------------------------
//	Data types definition
//------------------------------------------------------------------------------
typedef enum{
  eGUI_SCREEN_INIT = 0,
  eGUI_SCREEN_LOGO,
  eGUI_SCREEN_APP
}GUI_SCREEN_t;

typedef enum
{
  eGUI_ALIGNMENT_X_LEFT   = 0x01,
  eGUI_ALIGNMENT_X_MIDDLE = 0x02,
  eGUI_ALIGNMENT_X_RIGHT  = 0x04,
  eGUI_ALIGNMENT_Y_UP     = 0x10,
  eGUI_ALIGNMENT_Y_MIDDLE = 0x20,
  eGUI_ALIGNMENT_Y_DOWN   = 0x40,
} GUI_ALIGNMENT_t;

typedef enum
{
  eGUI_ZONE_HEADER = 0,
  eGUI_ZONE_BODY,
  eGUI_ZONE_FOOTER,
  eGUI_ZONE_FULL
}GUI_ZONE_t;

typedef struct {
  GUI_SCREEN_t previous_screen;
  uint32_t     tick;
} GUI_SCREEN_HANDLE_t;

//------------------------------------------------------------------------------
//	External variable declaration
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	External function declaration
//------------------------------------------------------------------------------

//==============================================================================
//	void gui_init(void)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	: Initializes the GUI
//------------------------------------------------------------------------------
void gui_init(void);

//==============================================================================
//	void gui_process(void)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	: Refresh GUI
//------------------------------------------------------------------------------
void gui_process(void);

//==============================================================================
//	void gui_draw_string(const char *str, GUI_ALIGNMENT_t alignment, GUI_ZONE_t zone)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	: Draws string on the body of the GUI with the specified
//                alignment
//  Function Input : str is the string to draw
//  Function Input : alignment
//  Function Input : zone
//------------------------------------------------------------------------------
void gui_draw_string(const char *str, GUI_ALIGNMENT_t alignment, GUI_ZONE_t zone);

//==============================================================================
//	void gui_draw_sprite(void)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	: 
//  Function Input : x
//  Function Input : y
//  Function Input : width
//  Function Input : height
//  Function Input : sprite
//------------------------------------------------------------------------------
void gui_draw_sprite(uint8_t x, uint8_t y, uint8_t width, uint8_t height, const uint8_t *sprite);

//==============================================================================
//	void gui_clear(void)
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Description	: Clear zone (Draws a black filled rectangle)
//------------------------------------------------------------------------------
void gui_clear(void);



#endif // __GUI_H__
