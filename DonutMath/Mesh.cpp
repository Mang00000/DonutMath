#include "Mesh.h"

#include <iostream>

void VERTEX::Debug() const
{
    std::cout << "X = " << x << "; Y = " << y << "; Z = " << z << '\n';
}

void Mesh::Debug() const
{
    for (int i = 0; i < m_Resolution; ++i)
    {
        m_Vertices[i].Debug();
    }
}
