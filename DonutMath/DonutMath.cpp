#include "Mesh.h"
#include "Screen.h"

int main(int argc, char* argv[])
{
    Screen screen(argc, argv);

    Mesh mesh(screen.GetSettings().GetResolution());

    mesh.GenerateRectangle(5,4);

    screen.DisplayMesh(mesh, 0,0, 5);
    

    screen.Display();
    
    return 0;
}
