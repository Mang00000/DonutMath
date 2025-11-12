#include "Mesh.h"
#include <iostream>

void VERTEX::Debug() const
{
    std::cout << "X = " << x << "; Y = " << y << "; Z = " << z << '\n';
}

Mesh::Mesh(int resolution) : m_Resolution(resolution)
{
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

void Mesh::GenerateSquare(float size)
{
    VERTEX v;
    for (int i = 0; i < m_Resolution; ++i)
    {
        for (int j = 0; j < m_Resolution; ++j)
        {
            v.x = (size * i) / (m_Resolution - 1 ) - (size / 2); // i= 0 => -size   i = 1 -> size
            v.y = (size * j) / (m_Resolution - 1 ) - (size / 2); // 
            v.z = 0;
            m_Vertices.push_back(v);
        }
    }
}
