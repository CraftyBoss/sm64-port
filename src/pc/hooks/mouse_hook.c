#include "mouse_hook.h"

PPOINT p;
int mousePosX;
int mousePosY;

void updateMouseHook(HWND * gWindow){    
    ScreenToClient(gWindow,&p);
}

void setMousePoint(){
    mousePosX = p[0].x;
    mousePosY = p[0].y;
}

int getMousePosX() {
    setMousePoint();
    return mousePosX;
}

int getMousePosY() {
    setMousePoint();
    return mousePosY;
}