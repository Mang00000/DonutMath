#include "Settings.h"

#include <iostream>
#include <ostream>
#include <string>


int     Settings::Height = 20;
int     Settings::Width = 100;
int     Settings::Resolution = 32;

char    Settings::ScreenMeshProjection = 'X';
char    Settings::ScreenBackground = ' ';

int     Settings::ScreenPosition = 9;
int     Settings::ViewerPosition = 10;

float   Settings::RotationX = 0.02f;
int     Settings::FrameDuration = 30;

float   Settings::LightDirectionX = 0.f;
float   Settings::LightDirectionY = 1.f;
float   Settings::LightDirectionZ = 0.f;


void Settings::ParseArguments(int argc, char* argv[])
{

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-w") == 0)
        {
            i++;
            Width = std::stoi(argv[i]);
        }
        else if (strcmp(argv[i], "-h") == 0)
        {
            i++;
            Height = std::stoi(argv[i ]);
        }
        else if (strcmp(argv[i], "-r") == 0)
        {
            i++;
            Resolution = std::stoi(argv[i]);
        }
        else if (strcmp(argv[i], "-b") == 0)
        {
            i++;
            ScreenBackground = argv[i][0];
        }
        else if (strcmp(argv[i], "-p") == 0)
        {
            i++;
            ScreenMeshProjection = argv[i][0];
        }
        else if (strcmp(argv[i], "-s") == 0)
        {
            i++;
            ScreenPosition = std::stoi(argv[i]);
        }
        else if (strcmp(argv[i], "-v") == 0)
        {
            i++;
            ViewerPosition = std::stoi(argv[i]);
        }
        else if (strcmp(argv[i], "-x") == 0)
        {
            i++;
            RotationX = std::stof(argv[i]);
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            i++;
            FrameDuration = std::stoi(argv[i]);
        }
        else if (strcmp(argv[i], "-lx") == 0)
        {
            i++;
            LightDirectionX = std::stof(argv[i]);
        }
        else if (strcmp(argv[i], "-ly") == 0)
        {
            i++;
            LightDirectionY = std::stof(argv[i]);
        }
        else if (strcmp(argv[i], "-lz") == 0)
        {
            i++;
            LightDirectionZ = std::stof(argv[i]);
        }
        
    }
}

