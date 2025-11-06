#include "Settings.h"

#include <iostream>
#include <ostream>
#include <string>



Settings::Settings(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h"))
        {
            i++;
            m_Height = std::stoi(argv[i ]);
        }
        else if (strcmp(argv[i], "-w"))
        {
            i++;
            m_Width = std::stoi(argv[i]);
        }
    }

    if (m_Height == 0 || m_Width == 0)
    {
        std::cout << "No Width or Height specified, using default size" << std::endl;
        m_Width = 100;
        m_Height = 20;
    }
    
    m_Pixels = new char[m_Width * m_Height];

    for (int i = 0; i < m_Width * m_Height; i++)
    {
        m_Pixels[i] = '.';
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

char* Settings::GetPixels()
{
    return m_Pixels;
}
