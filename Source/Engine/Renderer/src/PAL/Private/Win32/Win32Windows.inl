#include "Win32Include.h"
#include "CorePCH.h"

#undef CreateWindow

namespace Private
{
	namespace Platform
	{
        LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) 
        { 
            switch (msg)
            {
            case WM_CLOSE:
                ::DestroyWindow(hWnd);
                break;

            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
            }

            return DefWindowProc(hWnd, msg, wParam, lParam);
        }

		void* CreateWindow(const String& title, const int32 width, const int32 height)
		{
            HINSTANCE hInstance = GetModuleHandle(nullptr);
            Char* winTitle = Encoding::ConvertUTF16(title.ToArray(), title.GetLength());
            DWORD style = WS_OVERLAPPEDWINDOW;

            WNDCLASSEX wcex;
            ZeroMemory(&wcex, sizeof(WNDCLASSEX));

            wcex.cbSize = sizeof(WNDCLASSEX);
            wcex.cbClsExtra = 0;
            wcex.cbWndExtra = 0;
            wcex.lpfnWndProc = WindowProc;
            wcex.hInstance = hInstance;
            wcex.lpszClassName = winTitle;

            RegisterClassEx(&wcex);

            HWND hWnd = CreateWindowEx(
                0,                              // Optional window styles.
                winTitle,                       // Window class
                winTitle,                       // Window text
                style,                          // Window style

                // Size and position
                CW_USEDEFAULT, CW_USEDEFAULT, 
                width, 
                height,

                0,          // Parent window    
                0,          // Menu
                hInstance,  // Instance handle
                0           // Additional application data
            );

            if (hWnd == nullptr)
            {
                return 0;
            }

            Memory::Free(winTitle);

            ShowWindow(hWnd, SW_SHOW);

            return hWnd;
		}
        
        void UpdateWindow()
        {
            MSG msg = { };
            ZeroMemory(&msg, sizeof(MSG));

            while (PeekMessage(&msg, nullptr, 0, 0, 0))
            {
                GetMessage(&msg, nullptr, 0, 0);

                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        void DestroyWindow(const String& windowClass)
        {
            HINSTANCE hInstance = GetModuleHandle(nullptr);
            Char* cls = Encoding::ConvertUTF16(windowClass.ToArray(), windowClass.GetLength());

            UnregisterClass(cls, hInstance);
        }
	}
}