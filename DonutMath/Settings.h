#pragma once


struct Settings
{
public:

    static int Height;
    static int Width;
    static int Resolution;

    static char ScreenMeshProjection;
    static char ScreenBackground;

    static int ScreenPosition;
    static int ViewerPosition;

    static float RotationX;
    static int FrameDuration;

    static float LightDirectionX;
    static float LightDirectionY;
    static float LightDirectionZ;

    static void ParseArguments(int argc, char *argv[]);
};
