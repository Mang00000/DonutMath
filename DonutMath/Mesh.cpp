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

    float c = cos(angle);
    float s = sin(angle);
    
    switch (axis)
    {
        case Axis::X:
            {
                y =  tmp.y * c - tmp.z * s;
                z =  tmp.y * s + tmp.z * c;

                ny =  tmp.ny * c - tmp.nz * s;
                nz =  tmp.ny * s + tmp.nz * c;
                break;
            }
        case Axis::Y:
            {
                x = tmp.x * c - tmp.z * s;
                z = tmp.x * s + tmp.z * c;

                nx = tmp.nx * c - tmp.nz * s;
                nz = tmp.nx * s + tmp.nz * c;
                break;
            }
        case Axis::Z:
            {
                x = tmp.x * c - tmp.y * s;
                y = tmp.x * s + tmp.y * c;

                nx = tmp.nx * c - tmp.ny * s;
                ny = tmp.ny * s + tmp.ny * c;
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
        float theta = 2.0f * M_PI * i / ((float)m_Resolution - 1);
        for (int j = 0; j < m_Resolution; ++j)
        {
            float phi = 2.0f * M_PI * j  / ((float)m_Resolution - 1);

            v.x = (majorRadius + minorRadius * cos(phi)) * cos(theta);
            v.y = (majorRadius + minorRadius * cos(phi)) * sin(theta);
            v.z = minorRadius * sin(phi);

            v.nx = v.x - (cos(theta) * majorRadius);
            v.ny = v.y - (sin(theta) * majorRadius);
            v.nz = v.z;

            float lenght = 1 / sqrt(v.nx * v.nx + v.ny * v.ny + v.nz * v.nz);

            v.nx *= lenght;
            v.ny *= lenght;
            v.nz *= lenght;
            
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
