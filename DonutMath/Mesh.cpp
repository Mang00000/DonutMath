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
    
    switch (axis)
    {
        case Axis::X:
            {
                y =  tmp.y * cos(angle) - tmp.z * sin(angle);
                z =  tmp.y * sin(angle) - tmp.z * cos(angle);
                break;
            }
        case Axis::Y:
            {
                x = tmp.x * cos(angle) + tmp.z * sin(angle);
                z = tmp.x * -sin(angle) + tmp.z * cos(angle);
                break;
            }
        case Axis::Z:
            {
                x = tmp.x * cos(angle) - tmp.y * sin(angle);
                y = tmp.x * sin(angle) +tmp.y * cos(angle);
                break;
            }
    }
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
    for (VERTEX& v : m_Vertices)
    {
        v.Rotate(angle, axis);
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

void Mesh::GenerateTorus(float majorRadius, float minorRadius)
{
    VERTEX v;
    for (int i = 0; i < m_Resolution; ++i)
    {
        for (int j = 0; j < m_Resolution; ++j)
        {
            float angleY = 2.0f * M_PI * i / (m_Resolution - 1);
            
            v.x = minorRadius * cos(2 * M_PI * j  / m_Resolution);
            v.x += majorRadius;
            
            v.y = minorRadius * sin(2 * M_PI * j  / m_Resolution) ;
            v.z = 0;


            v.Rotate(angleY, Axis::Z);
            m_Vertices.push_back(v);
        }
    }
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
