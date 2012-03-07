#include "EasyBMP.h"
#include <string>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

struct pixel{
    int x;
    int y;
};

class identifier
{
        //identifiziert den stack auf dem bild
        BMP init_center, init_fold;
        BMP Background;
        pixel SchwimmerPositon;
        int screen_nr;
    public:
        void makeScreenshot();
        void findeSchwimmer();
        void werfeAngel();
        void SchwimmerPositonAusgeben();
        int getCenterx();
        int getCentery();
};
