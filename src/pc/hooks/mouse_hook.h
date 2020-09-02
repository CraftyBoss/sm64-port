#ifndef MOUSE_HOOK_H
#define MOUSE_HOOK_H
#include <stdbool.h>
#include <dxgi1_3.h>
#include "types.h"
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Updates LPPOINT variable with current mouse coordinates relative to the window
*/
void updateMouseHook(HWND * gWindow);

#ifdef __cplusplus
}
#endif

/**
 * converts LPPOINT to mousePosX and mousePosY
*/
void setMousePoint();
/**
 * returns mousePosX
*/
int getMousePosX();

/**
 * returns mousePosY
*/
int getMousePosY();

#endif
