#ifndef MYCONSOLE_H
#define MYCONSOLE_H

void PlaceCursor(int x,int y);
int CheckKeyPressed(int waitTime = 20);
bool SetColorAtPoint(int x,int y,int color);

#endif