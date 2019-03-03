# Topmost

Very simple program to toggle if a window is topmost on Windows

# Compiling

You can use MSVC or MINGW
(g++ main.cpp -mwindows -o topmost with MINGW)

# How to use

1. Focus the desired window
2. Pressed Ctrl + Enter
3. To remove the topmost, pressed Ctrl + Enter again

# What I learned

## Win32 Api

-   Running a programming without a console window.
-   Getting keyboard keystates (GetKeyState)
-   Getting the current focused window (GetForegroundWindow)
-   Changing if a window is topmost (SetWindowPos)
