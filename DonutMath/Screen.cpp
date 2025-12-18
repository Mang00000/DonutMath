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

Screen::Screen()
{
    ConfigConsole();

    m_Pixels = new Pixel[Settings::Width * Settings::Height];

    for (int i = 0; i < Settings::Width * Settings::Height; i++)
    {
        m_Pixels[i].Char = Settings::ScreenBackground;
        m_Pixels[i].Depth = 0;
    }
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
    HideCursor();
    SetCursorHome();
    for (int i = 0; i < Settings::Height; ++i)
    {
        for (int j = 0; j < Settings::Width; ++j)
        {
            std::cout << m_Pixels[i * Settings::Width + j].Char;
        }
        std::cout << '\n';
    }
    ShowCursor();
}

void Screen::DisplayMesh(Mesh& mesh, float x, float y, float z)
{
    std::vector<VERTEX>& vertices = mesh.GetVertices();

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

        worldX += Settings::Width / 2;
        worldY += Settings::Height / 2;


        SetPixel(worldX, worldY, worldZ, CurrentVertex.nx, CurrentVertex.ny, CurrentVertex.nz);
    }
   
}

void Screen::SetPixel(float x, float y, float z, float nx, float ny, float nz)
{
    if (x < 0 || y < 0 || x > Settings::Width || y > Settings::Height)
    {
        //std::cout << "PIXEL OUT OF BOUND" << std::endl;
        return;
    }

    Pixel& CurrentPixel = m_Pixels[(int)y * Settings::Width + (int)x];
    
    if (CurrentPixel.Depth < 1 / z)
    {
        CurrentPixel.Depth =  1 / z;
        CurrentPixel.Char = ComputeChar(ComputeLight(nx,ny,nz));
    }
}

void Screen::ResetScreen()
{
    for (int i = 0; i < Settings::Height; ++i)
    {
        for (int j = 0; j < Settings::Width; ++j)
        {
            m_Pixels[i * Settings::Width + j].Char = Settings::ScreenBackground;
            m_Pixels[i * Settings::Width + j].Depth = -2147483647;
        }
    }
}

float Screen::ComputeLight(float _nx, float _ny, float _nz)
{
    VERTEX light = {Settings::LightDirectionX, Settings::LightDirectionY, Settings::LightDirectionZ};
    
    return _nx * light.x + _ny * light.y + _nz * light.z;
}

char Screen::ComputeChar(float dotProd)
{
    dotProd = (-dotProd + 1) * 0.5f;

    int index = dotProd * 12;
    if (index == 12)
        index = 11;
    
    return LIGHTCHAR[index]; 
}
