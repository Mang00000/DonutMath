#include "Mesh.h"
#include "Screen.h"




int main(int argc, char* argv[])
{
    Screen screen(argc, argv);

    screen.Display();

    Mesh mesh(screen.GetSettings().GetResolution());

    mesh.GenerateCircle(1);

    mesh.Debug();
    
    return 0;
}
