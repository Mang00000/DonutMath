#include "Mesh.h"
#include <iostream>
# define M_PI           3.14159265358979323846

void VERTEX::Debug() const
{
    std::cout << "X = " << x << "; Y = " << y << "; Z = " << z << '\n';
}

void VERTEX::Rotate(float angle, Axis axis)
{
    VERTEX tmp = *this;
    float radAngle = angle * M_PI / 180;
    
    switch (axis)
    {
        case Axis::X:
            {
                tmp.x = x * 1 + y * 0 + z * 0;
                tmp.y = x * 0 + y * cos(radAngle) - z * sin(radAngle);
                tmp.z = x * 0 + y * sin(radAngle) - z * cos(radAngle);
                break;
            }
        case Axis::Y:
            {
                tmp.x = x * cos(radAngle)    + y * 0 + z * sin(radAngle);
                tmp.y = x * 0             + y * 1 + z * 0;
                tmp.z = x * (-sin(radAngle)) + y * 0 + z * cos(radAngle);
                break;
            }
        case Axis::Z:
            {
                tmp.x = x * cos(radAngle) - y * sin(radAngle) + z * 0;
                tmp.y = x * sin(radAngle) + y * cos(radAngle) + z * 0;
                tmp.z = x * 0 + y * 0 + z * 1;
                break;
            }
    }

    *this = tmp;
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

void Mesh::Rotate(float angle, Axis axis)
{
    for (int i = 0; i < m_Vertices.size(); ++i)
    {
        m_Vertices[i].Rotate(angle, axis);
    }
}


std::vector<VERTEX>& Mesh::GetVertices()
{
    return m_Vertices;
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

void Mesh::GenerateRectangle(float width, float height)
{
    VERTEX v;
    for (int i = 0; i < m_Resolution; ++i)
    {
        for (int j = 0; j < m_Resolution; ++j)
        {
            v.x = (width * i) / (m_Resolution - 1) - (width / 2);
            v.y = (height * j) / (m_Resolution - 1) - (height / 2);
            v.z = 0;
            m_Vertices.push_back(v);
        }
    }
}

void Mesh::GenerateCircle(float radius)
{
    GenerateCirclePart(radius, static_cast<float>(2 * M_PI));
}

void Mesh::GenerateHalfCircle(float radius)
{
    GenerateCirclePart(radius, static_cast<float>(M_PI));
}




void Mesh::GenerateCirclePart(float radius, float angle)
{
    VERTEX v;
    for (int i = 0; i < m_Resolution; ++i)
    {
        for (int j = 0; j < m_Resolution; ++j)
        {
            v.x = ( radius * i) / (m_Resolution - 1)  * cos(angle * j  / m_Resolution);
            v.y =   (radius * i) / (m_Resolution - 1)  * sin(angle * j  / m_Resolution);
            v.z = 0;
            m_Vertices.push_back(v);
        }
    }
}
