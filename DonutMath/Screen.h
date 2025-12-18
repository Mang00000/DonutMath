#pragma once
#include "Settings.h"

static const char HOME[] = "\033[H";
static const char CLEAR[] = "\033[2J";
static const char INVISIBLE[] = "\033[?25l";
static const char VISIBLE[] = "\033[?25h";


static const char LIGHTCHAR[13] = ".,-~:;=!*#$@";

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

    void DisplayMesh(Mesh& mesh, float x, float y, float z);

    void SetPixel(float x, float y, float z, char newChar, float nx, float ny, float nz);

    void ResetScreen();

    float ComputeLight(float _nx, float _ny ,float _nz);

    char ComputeChar(float dotProd);
};
