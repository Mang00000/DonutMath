#pragma once
#include "Settings.h"

static const char HOME[] = "\033[H";
static const char CLEAR[] = "\033[2J";
static const char INVISIBLE[] = "\033[?25l";
static const char VISIBLE[] = "\033[?25h";


class Mesh;

class Screen
{
    void ConfigConsole();
    Settings m_Settings;
public:
    Screen() = default;
    Screen(int argc, char* argv[]);
    void Clear();
    void HideCursor();
    void ShowCursor();
    void SetCursorHome();

    Settings GetSettings();
    
    void Display();

    void DisplayMesh(Mesh& mesh);

    void SetPixel(float x, float y, float z, char newChar);

    void ResetScreen();
};
