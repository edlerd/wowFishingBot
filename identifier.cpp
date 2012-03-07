#include "identifier.hpp"
#include <iostream>

void identifier::makeScreenshot()
{
    int     nWidth  = GetSystemMetrics(SM_CXSCREEN);
    int     nHeight = GetSystemMetrics(SM_CYSCREEN);

    HWND    hWnd    = ::GetDesktopWindow();
    HDC     hdc     = ::GetDC(hWnd);
    HDC     memDC   = ::CreateCompatibleDC(hdc);
    HBITMAP hbm     = ::CreateCompatibleBitmap(hdc, nWidth, nHeight);
    HBITMAP hbmOld  = (HBITMAP)::SelectObject(memDC, hbm);

    ::BitBlt(memDC, 0, 0, nWidth, nHeight, hdc, 0, 0, SRCCOPY);
                                     
    BITMAPINFO bmi;

    ZeroMemory(&bmi, sizeof(bmi));

    bmi.bmiHeader.biSize         = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth        = nWidth;
    bmi.bmiHeader.biHeight       = nHeight;
    bmi.bmiHeader.biBitCount     = 24;
    bmi.bmiHeader.biPlanes       = 1;
    bmi.bmiHeader.biCompression  = BI_RGB;
    bmi.bmiHeader.biSizeImage    = 32 * nWidth * nHeight / 8;

    BYTE *pbBits = new BYTE[bmi.bmiHeader.biSizeImage];

    ::GetDIBits( memDC, 
                 hbm,
                 0,
                 bmi.bmiHeader.biHeight,
                 pbBits,
                 &bmi,
                 DIB_RGB_COLORS );

    BITMAPFILEHEADER bfh;

    bfh.bfType      = ('M' << 8) + 'B';
    bfh.bfSize      = sizeof(BITMAPFILEHEADER)  +
                      bmi.bmiHeader.biSizeImage +
                      sizeof(BITMAPINFOHEADER); 
    bfh.bfReserved1 = 0;
    bfh.bfReserved2 = 0;
    bfh.bfOffBits   = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    HANDLE hfile = CreateFile( _T("screen.bmp"),
                               GENERIC_WRITE,
                               0,
                               0,
                               OPEN_ALWAYS,
                               0,
                               0 ); 

    DWORD dwWritten;
     
    WriteFile(hfile,&bfh,           sizeof(bfh),               &dwWritten, NULL); 
    WriteFile(hfile,&bmi.bmiHeader, sizeof(BITMAPINFOHEADER),  &dwWritten, NULL); 
    WriteFile(hfile,pbBits,         bmi.bmiHeader.biSizeImage, &dwWritten, NULL); 

    CloseHandle(hfile); 

    ::SelectObject(memDC, hbmOld);
    ::DeleteDC(memDC);
    ::ReleaseDC(hWnd,hdc); 
    ::DeleteObject(hbm);

    delete[] pbBits;



    Background.ReadFromFile("screen.bmp");
}

void identifier::werfeAngel()
{
    //drücke die taste 3
    byte keyToPress = 0x33;
    keybd_event(keyToPress, 0, 0L, 0L);
    keybd_event(keyToPress, 0, KEYEVENTF_KEYUP, 0L);
}

void identifier::findeSchwimmer()
{
    for (int zeile=1; zeile<Background.TellHeight(); zeile++)
    {
        for (int spalte=1; spalte<Background.TellWidth(); spalte++)
        {
            /* Die eine Farbe (blauer bg)
            if (Background.GetPixel(spalte,zeile).Blue>=52 &&  Background.GetPixel(spalte,zeile).Blue<=56 &&
                Background.GetPixel(spalte,zeile).Green>=73 && Background.GetPixel(spalte,zeile).Green<=78 &&
                Background.GetPixel(spalte,zeile).Red>=52 &&   Background.GetPixel(spalte,zeile).Red<=56)
            */
            /* Die andere Farbe (roter bg) */
            if (Background.GetPixel(spalte,zeile).Blue>=90 &&  Background.GetPixel(spalte,zeile).Blue<=95 &&
                Background.GetPixel(spalte,zeile).Green>=85 && Background.GetPixel(spalte,zeile).Green<=90 &&
                Background.GetPixel(spalte,zeile).Red>=130 &&   Background.GetPixel(spalte,zeile).Red<=135)
            {
                SchwimmerPositon.x = zeile;
                SchwimmerPositon.y = spalte;
                return;
            }
        }
    }

}

void identifier::SchwimmerPositonAusgeben()
{
    std::cout << SchwimmerPositon.x << " " << SchwimmerPositon.y;
}

int identifier::getCenterx()
{
    return SchwimmerPositon.x;
}

int identifier::getCentery()
{
    return SchwimmerPositon.y;
}