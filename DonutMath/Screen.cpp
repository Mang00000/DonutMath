#include "Screen.h"
#include <iostream>
#include <Windows.h>


void Screen::ConfigConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    return;
}

Screen::Screen(int argc, char* argv[])
{
    ConfigConsole();
    m_Settings = Settings(argc, argv);
}

void Screen::Clear()
{
    std::cout << CLEAR << std::endl;
    return;
}

void Screen::HideCursor()
{
    std::cout << INVISIBLE << std::endl;
    return;
}

void Screen::ShowCursor()
{
    std::cout << VISIBLE << std::endl;
    return;
}

void Screen::SetCursorHome()
{
    std::cout << HOME << std::endl;
    return;
}

Settings Screen::GetSettings()
{
    return m_Settings;
}

void Screen::Display()
{
    Clear();
    HideCursor();
    SetCursorHome();
    for (int i = 0; i < m_Settings.GetWidth(); ++i)
    {
        for (int j = 0; j < m_Settings.GetHeight(); ++j)
        {
            std::cout << m_Settings.GetPixels()[i * m_Settings.GetWidth() + j];
        }
        std::cout << '\n';
    }
    ShowCursor();
}
