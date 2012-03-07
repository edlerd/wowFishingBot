#include "mouse_action.h"


mouse_action::mouse_action(int x, int y)
{
    centerx=x+10;
    centery=y+2;
}

void mouse_action::perform(std::string myAction)
{
    if (myAction == "goToPosition")
    {
        SetCursorPos(centerx,centery);
    }
    if (myAction == "rechtsklick")
    {
        mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
    }
}
