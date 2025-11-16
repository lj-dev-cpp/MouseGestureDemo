#include "hook.h"

// Global variables
BOOL g_bMouseDraw = FALSE;
BOOL g_bRPressed = FALSE;
BOOL g_bFirstRecord = FALSE;
std::vector<POINT> g_MousePoints;
POINT g_ptPressed = {0};
POINT g_LastPt = {0};
tGestureRecog g_GestureRecog;

// Simplified gesture action handler
void ActionByMouseGesture()
{
    // Ensure enough data to form a gesture
    if (g_MousePoints.size() < 4)
        return;

    // Recognize gesture path
    g_GestureRecog.m_path.clear();
    for(int i=0;i<g_MousePoints.size();++i)
    {
  	g_GestureRecog.m_path.push_back(g_MousePoints.at(i));
    }
    g_GestureRecog.TransfromPath();

    // Display or execute recognized command
    if (!result.IsEmpty())
    {
        // Example: print result (in real system would trigger command)
        OutputDebugString(_T("Recognized gesture: "));
        OutputDebugString(result);
        OutputDebugString(_T("\n"));
    }

    // Reset state
    g_MousePoints.clear();
    g_bMouseDraw = FALSE;
    g_bRPressed = FALSE;
}

// Message hook for mouse events
#ifdef ARX_2020
bool MouseSignalHook(MSG *pMsg)
#else
BOOL MouseSignalHook(MSG *pMsg)
#endif
{
    if (!pMsg) 
#ifdef ARX_2020
        return false;
#else
        return FALSE;
#endif

    // Right button down → start recording gesture
    if (pMsg->message == WM_RBUTTONDOWN)
    {
        g_MousePoints.clear();
        g_ptPressed = pMsg->pt;
        g_LastPt = g_ptPressed;
        g_bRPressed = TRUE;
        g_bFirstRecord = TRUE;
        g_bMouseDraw = TRUE;
    }
    // Mouse move → collect gesture points
    else if (g_bRPressed && pMsg->message == WM_MOUSEMOVE)
    {
        POINT pt = pMsg->pt;
        g_MousePoints.push_back(pt);
        g_LastPt = pt;
    }
    // Right button up → gesture complete
    else if (pMsg->message == WM_RBUTTONUP)
    {
        if (g_bRPressed)
        {
            ActionByMouseGesture();
        }
    }

#ifdef ARX_2020
    return true;
#else
    return TRUE;
#endif
}
