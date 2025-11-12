#include "Mesh.h"
#include "Screen.h"




int main(int argc, char* argv[])
{
    Screen screen(argc, argv);

    screen.Display();

    std::vector<VERTEX> vertices;
    VERTEX v1(-1, -1, 0);
    VERTEX v2(-1, 1, 0);
    VERTEX v3(1, -1, 0);
    VERTEX v4(1, 1, 0);

    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);


    Mesh mesh(vertices, screen.GetSettings().GetResolution());


    mesh.Debug();
    
    return 0;
}
