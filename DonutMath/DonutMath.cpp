#include "Mesh.h"
#include "Screen.h"
#include <Windows.h>


int main(int argc, char* argv[])
{
    Settings::ParseArguments(argc, argv);
    bool running = true;
    Screen screen;

    Mesh mesh(Settings::Resolution);

    //mesh.GenerateRectangle(5,2);
    mesh.GenerateTorus(15.f,4.f);
    //mesh.Rotate(45, Axis::Z);
    //mesh.GenerateHalfCircle(2);
    //mesh.GenerateSquare(17);

    while (running)
    {
        screen.ResetScreen();
        screen.SetCursorHome();
        
        mesh.Rotate(Settings::RotationX, Axis::X);

        screen.DisplayMesh(mesh, 0, 0,0);

        screen.Display();
        //Sleep(10);
    }

    
    return 0;
}
