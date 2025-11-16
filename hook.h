#ifndef _HOOK_H_
#define _HOOK_H_

#include <windows.h>
#include <vector>
#include "GestureRecog.h"

// Global state flags
extern BOOL g_bMouseDraw;
extern BOOL g_bRPressed;
extern BOOL g_bFirstRecord;

// Mouse data
extern std::vector<POINT> g_MousePoints;
extern POINT g_ptPressed;
extern POINT g_LastPt;

// Gesture recognizer
extern tGestureRecog g_GestureRecog;

// Hook function for message interception
#ifdef ARX_2020
bool MouseSignalHook(MSG *pMsg);
#else
BOOL MouseSignalHook(MSG *pMsg);
#endif

// Main entry: process gesture after right button release
void ActionByMouseGesture();

#endif
