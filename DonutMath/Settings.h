#pragma once


struct Settings
{
    static int Height;
    static int Width;
    static int Resolution;
    
    static char ScreenBackground;

    static float RotationX;
    static int FrameDuration;

    static float LightDirectionX;
    static float LightDirectionY;
    static float LightDirectionZ;

    static void ParseArguments(int argc, char *argv[]);
};
