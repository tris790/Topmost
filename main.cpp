#include <Windows.h>
#include <stdio.h>

int WinMain(HINSTANCE hInstance,
            HINSTANCE hPrevInstance, 
            LPTSTR    lpCmdLine, 
            int       cmdShow)
{
    bool wasPressed = false;
    while(true) {
        // Check if ctrl+enter is pressed
        bool keybindPressed = GetKeyState(VK_CONTROL) & 0x8000 && GetKeyState(VK_RETURN) & 0x8000;
        if(keybindPressed && !wasPressed) {
            wasPressed = true;

            // Get the Foreground window handle
            HWND handle = GetForegroundWindow();

            // Toggle the window topmost state
            if(GetWindowLong(handle, GWL_EXSTYLE) & WS_EX_TOPMOST) {
                SetWindowPos(handle, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            }
            else {
                SetWindowPos(handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);      
            }
        } else if(!keybindPressed && wasPressed) {
            wasPressed = false;
        }
        
        Sleep(100);
    }
    return 0;
}

