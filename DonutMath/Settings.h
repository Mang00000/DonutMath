#pragma once

struct Pixel
{
    char Char;
    float Depth;
};

class Settings
{
    int m_Height;
    int m_Width;
    int m_Resolution;
    
    char m_ScreenMeshProjection;
    char m_ScreenBackground;

    int m_ScreenPosition;
    int m_ViewerPosition;

    float m_RotationX;
    int m_FrameDuration;

    float m_LightDirectionX;
    float m_LightDirectionY;
    float m_LightDirectionZ;
public:
    Settings() = default;
    Settings(int argc, char* argv[]);
    
    int GetHeight();
    int GetWidth();
    int GetResolution();

    char GetScreenMeshProjection();
    char GetScreenBackground();
    int GetScreenPos();
    int GetViewerPos();
    
    float GetRotationXPerFrame();
    float GetFrameDuration();

    float GetLightDirectionX();
    float GetLightDirectionY();
    float GetLightDirectionZ();
};
