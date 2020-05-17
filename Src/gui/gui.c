//-----------------------------------------------------------------------------
// Module name: lcd.c
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
#include <gui.h>
#include <ssd1306.h>
#include <ssd1306_fonts.h>
// #include <screen/screen_init.h>
// #include <screen/screen_logo.h>
// #include <screen/screen_app.h>
#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------
//	Variable definition
//------------------------------------------------------------------------------
static GUI_SCREEN_HANDLE_t _screen_handle;
static GUI_SCREEN_t _screen;

//------------------------------------------------------------------------------
//	Internal function declaration
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	EXternal function definition
//------------------------------------------------------------------------------
void gui_init(void)
{
  _screen_handle.tick = 0;
  _screen_handle.previous_screen = eGUI_SCREEN_INIT;
  _screen = eGUI_SCREEN_INIT;

  ssd1306_Init();
  HAL_Delay(1000);
}

void gui_process(void)
{
  if(_screen != _screen_handle.previous_screen){
    _screen_handle.tick = 0;
  }

  // switch (_screen) {
  //   case eGUI_SCREEN_INIT:
  //     _screen = screen_init_process(&_screen_handle);
  //     break;
  //   case eGUI_SCREEN_LOGO:
  //     _screen = screen_logo_process(&_screen_handle);
  //     break;
  //   case eGUI_SCREEN_TEST:
  //       _screen = screen_app_process(&_screen_handle);
  //     break;
  // }

  _screen_handle.tick++;
}

void gui_draw_string(const char *str, GUI_ALIGNMENT_t alignment, GUI_ZONE_t zone)
{
  uint8_t x, y;
  uint8_t str_size = strlen(str);
  uint8_t zone_x0, zone_y0, zone_x1, zone_y1;
  uint8_t zone_margin;
  uint8_t font_width;
  uint8_t font_height;

  zone_x0 = 0;
  zone_y0 = 0;
  zone_x1 = (128 - 1);
  zone_y1 = ( 64 - 1);

  zone_margin = 2;

  font_width = 6;
  font_height = 8;

  if (str_size > ((zone_x1 - zone_x0)/font_width)){
     str_size = ((zone_x1 - zone_x0)/font_width);
  }

  switch (alignment & 0x0F) {
    case 0x01: //LEFT
      x = zone_x0 + zone_margin;
      break;
    case 0x02: //MIDDLE
      x = zone_x0 + (((zone_x1 - zone_x0) - (str_size * font_width))/2);
      break;
    case 0x04: //RIGHT
      x = zone_x1 - zone_margin - (str_size * font_width);
      break;
    default:
      return;
  }

  switch (alignment & 0xF0) {
    case 0x10: //UP
      y = zone_y0 + zone_margin;
      break;
    case 0x20: //MIDDLE
      y = zone_y0 + (((zone_y1 - zone_y0) - font_height)/2);
      break;
    case 0x40: //BOTTOM
      y = zone_y1 - zone_margin - font_height;
      break;
    default:
      return;
  }

  ssd1306_SetCursor(x, y);
  ssd1306_WriteString(str, Font_6x8, White);
  ssd1306_UpdateScreen();
}

void gui_clear(GUI_ZONE_t zone)
{

}
