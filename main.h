#ifndef MAIN_H
#define MAIN_H

#include <Windows.h>

#define IDC_BUTTON_OKAY 101

HINSTANCE hInst;

int WINAPI WinMain
(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow
);

LRESULT CALLBACK PeterProc
(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
);

#endif