// WOWAB2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "identifier.hpp"
#include "mouse_action.h"

int _tmain(int argc, _TCHAR* argv[])
{
    
    identifier myIdentifier;
    int iSecret;

    bool goon=true;
    while (goon)
    {
        iSecret = rand() % 1000 + 1;
        Sleep(3000+iSecret);
        
        myIdentifier.werfeAngel();
        iSecret = rand() % 500 + 1;
        Sleep(3000+iSecret);
        
        
        myIdentifier.makeScreenshot();
        myIdentifier.findeSchwimmer();
        mouse_action myMouse(myIdentifier.getCentery(),myIdentifier.getCenterx());
        myMouse.perform("goToPosition");
        iSecret = rand() % 1500 + 1;

        Sleep(8000+iSecret);
        myMouse.perform("rechtsklick");
    }

	return 0;
}

