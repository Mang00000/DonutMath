#include "Mesh.h"
#include "Screen.h"
#include <Windows.h>


int main(int argc, char* argv[])
{
    bool running = true;
    Screen screen(argc, argv);

    Mesh mesh(screen.GetSettings().GetResolution());

    //mesh.GenerateRectangle(5,2);
    mesh.GenerateTorus(4.0f,0.9f);
    //mesh.Rotate(45, Axis::Z);
    //mesh.GenerateHalfCircle(2);
    //mesh.GenerateSquare(3);

    while (running)
    {
        screen.ResetScreen();
        screen.SetCursorHome();
        mesh.Rotate(screen.GetSettings().GetRotationXPerFrame(), Axis::X);

        screen.DisplayMesh(mesh, 10,8, 15);

        screen.Display();
        Sleep(100);
    }

    
    return 0;
}
