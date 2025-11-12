#pragma once
#include <vector>

struct VERTEX
{
    float x;
    float y;
    float z;
    VERTEX() = default;
    VERTEX(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    void Debug() const;
};

class Mesh
{
    std::vector<VERTEX> m_Vertices;
    int m_Resolution;
public:

    Mesh() = default;
    Mesh(int resolution);
    Mesh(std::vector<VERTEX> vertices, int resolution);
    void Debug() const;

    void GenerateSquare(float size);

    
};
