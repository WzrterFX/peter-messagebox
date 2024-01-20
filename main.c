#include "main.h"
#include "resource.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc = { 0 };

    wc.lpfnWndProc = PeterProc;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hIcon = NULL;
    wc.lpszClassName = L"PeterClass";

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, L"PeterClass", L"Peter Alert", WS_OVERLAPPED | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 256, 186, 0, 0, hInstance, 0);

    ShowWindow(hwnd, nCmdShow);
    
    BITMAP bmp;
    HBITMAP hBitmap = (HBITMAP)LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1));

    HDC hdc = GetDC(hwnd);
    HDC hdcMem = CreateCompatibleDC(hdc);

    SelectObject(hdcMem, hBitmap);
    GetObject(hBitmap, sizeof(BITMAP), &bmp);

    StretchBlt(hdc, 94, 16, bmp.bmWidth, bmp.bmHeight, hdcMem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK PeterProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        HWND buttonOkay = CreateWindow(L"BUTTON", L"OK", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 90, 100, 72, 24, hwnd, (HMENU)IDC_BUTTON_OKAY, hInst, 0);

        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDC_BUTTON_OKAY)
            PostMessage(hwnd, WM_CLOSE, 0, 0);

        break;

    case WM_DESTROY:
        PostQuitMessage(0);

        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}