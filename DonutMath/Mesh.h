#pragma once


struct VERTEX
{
    float x;
    float y;
    float z;
    VERTEX(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    void Debug() const;
};

class Mesh
{
    VERTEX* m_Vertices;
    int m_Resolution;
public:
    void Debug() const;

    
};
