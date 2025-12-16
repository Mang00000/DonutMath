#pragma once
#include <vector>

enum class Axis
{
    X,
    Y,
    Z
};


struct VERTEX
{
    float x;
    float y;
    float z;

    float nx;
    float ny;
    float nz;
    
    VERTEX() = default;
    VERTEX(float _x, float _y, float _z) : x(_x), y(_y), z(_z), nx(0), ny(0), nz(0) {}
    void Debug() const;
    void Rotate(float angle, Axis axis);
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
    void Rotate(float angle, Axis axis);
    
    std::vector<VERTEX>& GetVertices();

    void GenerateSquare(float size);
    void GenerateRectangle(float width, float height);
    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius);

    void GenerateTorus(float majorRadius, float minorRadius);

};
