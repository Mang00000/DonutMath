#pragma once

class Settings
{
    int m_Height;
    int m_Width;
    int m_Resolution;
        
    char* m_Pixels;

    char m_ScreenMeshProjection;
    char m_ScreenBackground;
    int m_ScreenPosition;
    int m_ViewerPosition;
public:
    Settings() = default;
    Settings(int argc, char* argv[]);

    
    int GetHeight();
    int GetWidth();
    int GetResolution();

    char* GetPixels();
};
