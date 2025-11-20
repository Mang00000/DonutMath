#include "Settings.h"

#include <iostream>
#include <ostream>
#include <string>



Settings::Settings(int argc, char* argv[])
    : m_Height(20), m_Width(100), m_Resolution(32), m_ScreenBackground(' '), m_ScreenMeshProjection('X'),
    m_ScreenPosition(9), m_ViewerPosition(10)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-w") == 0)
        {
            i++;
            m_Width = std::stoi(argv[i]);
        }
        else if (strcmp(argv[i], "-h") == 0)
        {
            i++;
            m_Height = std::stoi(argv[i ]);
        }
        else if (strcmp(argv[i], "-r") == 0)
        {
            i++;
            m_Resolution = std::stoi(argv[i]);
        }
        else if (strcmp(argv[i], "-b") == 0)
        {
            i++;
            m_ScreenBackground = argv[i][0];
        }
        else if (strcmp(argv[i], "-p") == 0)
        {
            i++;
            m_ScreenMeshProjection = argv[i][0];
        }
        else if (strcmp(argv[i], "-s") == 0)
        {
            i++;
            m_ScreenPosition = std::stoi(argv[i]);
        }
        else if (strcmp(argv[i], "-v") == 0)
        {
            i++;
            m_ViewerPosition = std::stoi(argv[i]);
        }
    }
    
    m_Pixels = new Pixel[m_Width * m_Height];

    for (int i = 0; i < m_Width * m_Height; i++)
    {
        m_Pixels[i].Char = '.';
        m_Pixels[i].Depth = 0;
    }
}

int Settings::GetHeight()
{
    return m_Height;
}

int Settings::GetWidth()
{
    return m_Width;
}

int Settings::GetResolution()
{
    return m_Resolution;
}

char Settings::GetScreenMeshProjection()
{
    return m_ScreenMeshProjection;
}

int Settings::GetScreenPos()
{
    return m_ScreenPosition;
}

int Settings::GetViewerPos()
{
    return m_ViewerPosition;
}

Pixel* Settings::GetPixels()
{
    return m_Pixels;
}
