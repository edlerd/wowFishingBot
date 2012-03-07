#include <string>
#include <windows.h>
#include <stdio.h>

class mouse_action
{
        int centerx;
        int centery;
    public:
        mouse_action(int x, int y);
        void perform(std::string myAction);
};