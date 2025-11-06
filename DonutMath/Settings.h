#pragma once

class Settings
{
    int m_Height;
    int m_Width;

    char* m_Pixels;
public:
    Settings() = default;
    Settings(int argc, char* argv[]);

    
    int GetHeight();
    int GetWidth();
};
