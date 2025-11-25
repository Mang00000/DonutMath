#include "Mesh.h"
#include "Screen.h"

int main(int argc, char* argv[])
{
    Screen screen(argc, argv);

    Mesh mesh(screen.GetSettings().GetResolution());

    //mesh.GenerateRectangle(5,2);
    mesh.GenerateCircle(4);
    //mesh.GenerateHalfCircle(2);
    //mesh.GenerateSquare(3);
    
    screen.DisplayMesh(mesh, 10,5, 5);
    

    screen.Display();
    
    return 0;
}
