#include "Mesh.h"

#include <iostream>

void VERTEX::Debug() const
{
    std::cout << "X = " << x << "; Y = " << y << "; Z = " << z << '\n';
}

Mesh::Mesh(std::vector<VERTEX> vertices, int resolution)
: m_Vertices(vertices), m_Resolution(resolution)
{
}

void Mesh::Debug() const
{
    for (int i = 0; i < m_Vertices.size(); ++i)
    {
        m_Vertices[i].Debug();
    }
}
