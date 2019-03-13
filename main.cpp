#include <Windows.h>
#include <stdio.h>

int WinMain(HINSTANCE hInstance,
            HINSTANCE hPrevInstance,
            LPTSTR lpCmdLine,
            int cmdShow)
{
    if (!RegisterHotKey(
            NULL,
            1,
            MOD_CONTROL | 0x4000,
            VK_RETURN))
    {
        return 1;
    }

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            HWND handle = GetForegroundWindow();

            // Toggle the window topmost state
            if (GetWindowLong(handle, GWL_EXSTYLE) & WS_EX_TOPMOST)
            {
                SetWindowPos(handle, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            }
            else
            {
                SetWindowPos(handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            }
        }
    }
    return 0;
}
