//
// Created by Andrew Kliewer on 11/12/18.
//

#ifndef GROUPPROJECT_PLAYER_H
#define GROUPPROJECT_PLAYER_H

#include "SDL_Plotter.h"

using namespace std;


class Player
{
private:

    const int windowWidth = 600;
    const int windowHeight = 1000;

    int posX = 200;
    int posY = 100;
    int width = 100;
    int height = 100;

public:
    void move(int xoffset, int yoffset)
    {
        posX = min (max (posX + xoffset, 0), windowWidth - width);
        posY = min (max (posY + yoffset, 0), windowHeight - height);
            posX = posX + xoffset;
            if (posX < 0)
            {
                posX = 0;
            }
            else if (posX > windowWidth)
            {
                posX = windowWidth;
            }


            void draw(SDL_Plotter & g)
            {
               for (int col = posX; col < width + posX; ++col)
               {
                   for (int row = posY; row < height + posY; ++row)
                   {
                       g.plotPixel (col, row, 0, 0, 255);
                   }
               }
            }
//
//
//            UP
//            rectPosY = max(rectPosY - 1, 0);
//
//            // Down
//            rectPosY = min(rectPosY + 1, windowHeight - height);
//
//            // Left
//            rectPosX = max(rectPosX - 1, 0);
//
//            // Right
//            rectPosY = min(rectPosX + 1, windowWidth - width);
    }
};

#endif //GROUPPROJECT_PLAYER_H
