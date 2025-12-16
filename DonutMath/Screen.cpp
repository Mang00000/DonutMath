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

void Screen::DisplayMesh(Mesh& mesh, float x, float y, float z)
{
    std::vector<VERTEX>& vertices = mesh.GetVertices();

    float ScreenPos = m_Settings.GetScreenPos();
    float ViewerPos = m_Settings.GetViewerPos();

    for (int i = 0; i < vertices.size(); ++i)
    {
        VERTEX CurrentVertex = vertices.at(i);

        float worldX = CurrentVertex.x + x;
        float worldY = CurrentVertex.y + y;
        float worldZ = CurrentVertex.z + z;
        
        // worldZ += ViewerPos;
        // worldX = ScreenPos * worldX / worldZ;
        // worldY = ScreenPos * worldY / worldZ / 2.f;

        worldY *= 0.50f;

        worldX += m_Settings.GetWidth() / 2;
        worldY += m_Settings.GetHeight() / 2;


        SetPixel(worldX, worldY, worldZ, m_Settings.GetScreenMeshProjection(), CurrentVertex.nx, CurrentVertex.ny, CurrentVertex.nz);
    }
   
}

void Screen::SetPixel(float x, float y, float z, char newChar, float nx, float ny, float nz)
{
    if (x < 0 || y < 0 || x > m_Settings.GetWidth() || y > m_Settings.GetHeight())
    {
        //std::cout << "PIXEL OUT OF BOUND" << std::endl;
        return;
    }

    Pixel& CurrentPixel = m_Settings.GetPixels()[(int)y * m_Settings.GetWidth() + (int)x];
    
    if (CurrentPixel.Depth < 1 / z)
    {
        CurrentPixel.Depth =  1 / z;
        CurrentPixel.Char = ComputeLight(ny);
    }
}

void Screen::ResetScreen()
{
    for (int i = 0; i < m_Settings.GetHeight(); ++i)
    {
        for (int j = 0; j < m_Settings.GetWidth(); ++j)
        {
            m_Settings.GetPixels()[i * m_Settings.GetWidth() + j].Char = m_Settings.GetScreenBackground();
            m_Settings.GetPixels()[i * m_Settings.GetWidth() + j].Depth = -2147483647;
        }
    }
}

char Screen::ComputeLight(float _ny)
{
    _ny = (-_ny + 1) * 0.5f;

    int index = _ny * 12;
    if (index == 12)
        index = 11;
    
    return LIGHTCHAR[index]; 
}
