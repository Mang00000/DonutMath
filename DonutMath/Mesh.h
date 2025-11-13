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

    void GenerateCirclePart(float radius, float angle);
public:

    Mesh() = default;
    Mesh(int resolution);
    Mesh(std::vector<VERTEX> vertices, int resolution);
    void Debug() const;

    void Display(Mesh const& mesh);

    void GenerateSquare(float size);
    void GenerateRectangle(float width, float height);
    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius);
};
