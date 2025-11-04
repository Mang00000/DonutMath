#include <iostream>
#include <Windows.h>

static const char HOME[] = "\033[H";
static const char CLEAR[] = "\033[2J";
static const char INVISIBLE[] = "\033[?25l";
static const char VISIBLE[] = "\033[?25h";

void ConfigConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    return;
}

void ClearConsole()
{
    std::cout << CLEAR << std::endl;
    return;
}

void SetCursorVisible(bool value)
{
    if(value)
        std::cout << VISIBLE << std::endl;
    else
        std::cout << INVISIBLE << std::endl;
    return;
}

void SetCursorHome()
{
    std::cout << HOME << std::endl;
    return;
}


int main(int argc, char** argv)
{
    ConfigConsole();

    ClearConsole();
    SetCursorVisible(false);
    SetCursorHome();

    std::cout << "Hello World" << std::endl;

    SetCursorVisible(true);
    
    return 0;
}
