#include "Screen.h"
#include <iostream>
#include <Windows.h>
#include "Mesh.h"


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
    //Clear();
    HideCursor();
    SetCursorHome();
    for (int i = 0; i < m_Settings.GetHeight(); ++i)
    {
        for (int j = 0; j < m_Settings.GetWidth(); ++j)
        {
            std::cout << m_Settings.GetPixels()[i * m_Settings.GetWidth() + j].Char;
        }
        std::cout << '\n';
    }
    ShowCursor();
}

void Screen::DisplayMesh(Mesh& mesh)
{
    std::vector<VERTEX>& vertices = mesh.GetVertices();
    
    float ScreenPos = m_Settings.GetScreenPos();
    float ViewerPos = 3.3333f;

    for (int i = 0; i < vertices.size(); ++i)
    {
        VERTEX& CurrentVertex = vertices.at(i);

        
        CurrentVertex.z += ViewerPos;
        CurrentVertex.x = ScreenPos * CurrentVertex.x / CurrentVertex.z;
        CurrentVertex.y = ScreenPos * CurrentVertex.y / CurrentVertex.z / 2.f;

        CurrentVertex.x += m_Settings.GetWidth() / 2;
        CurrentVertex.y += m_Settings.GetHeight() / 2;



        int u = std::round(CurrentVertex.x);
        int v = std::round(CurrentVertex.y);
        float ooz = 1.f / CurrentVertex.z;
        
        
        if(ooz < m_Settings.GetPixels()[v * m_Settings.GetWidth() + u].Depth)
        {
            if (u < 0 || v < 0 || u > m_Settings.GetWidth() || v > m_Settings.GetHeight())
            {
                std::cout << "PIXEL OUT OF BOUND" << std::endl;
                return;
            }
            m_Settings.GetPixels()[v * m_Settings.GetWidth() + u].Depth = ooz;
            m_Settings.GetPixels()[v * m_Settings.GetWidth() + u].Char = m_Settings.GetScreenMeshProjection();
        }

        
        // float worldX = (CurrentVertex.x + x) * 2;
        // float  worldY = CurrentVertex.y + y;
        // float worldZ = CurrentVertex.z + z;
        //
        // float x = worldX  * ScreenPos / worldZ;
        // float y = worldY  * ScreenPos / worldZ;
        // float z = worldZ;
        

        //SetPixel(CurrentVertex.x, CurrentVertex.y, CurrentVertex.z, m_Settings.GetScreenMeshProjection());
    }
   
}

void Screen::SetPixel(float x, float y, float z, char newChar)
{
    if (x < 0 || y < 0 || x > m_Settings.GetWidth() || y > m_Settings.GetHeight())
    {
        std::cout << "PIXEL OUT OF BOUND" << std::endl;
        return;
    }

    Pixel& CurrentPixel = m_Settings.GetPixels()[(int)y * m_Settings.GetWidth() + (int)x];
    
    if (CurrentPixel.Depth > 1/z)
    {
        CurrentPixel.Depth =  1 / z;
        CurrentPixel.Char = newChar;
    }
}

void Screen::ResetScreen()
{
    for (int i = 0; i < m_Settings.GetHeight(); ++i)
    {
        for (int j = 0; j < m_Settings.GetWidth(); ++j)
        {
            m_Settings.GetPixels()[i * m_Settings.GetWidth() + j].Char = m_Settings.GetScreenBackground();
            m_Settings.GetPixels()[i * m_Settings.GetWidth() + j].Depth =  INFINITE;
        }
    }
}
