#pragma once

class Light
{
public:
    Light(float x, float y, float z);
    Light() = default;


    float directionX;
    float directionY;
    float directionZ;
};
