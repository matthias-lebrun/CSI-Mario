////
////  mario.hpp
////  SDL_Practice
////
////  Created by Andrew Kliewer on 11/30/18.
////  Copyright © 2018 Andrew Kliewer. All rights reserved.
////


#ifndef mario_hpp
#define mario_hpp

#include "mario.hpp"
#include "SDL_Plotter.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

const int windowHeight = 500;
const int windowWidth = 500;

SDL_Plotter g(windowHeight, windowWidth);

class Mario
{
    
    int X = 250;
    int Y = 250;
    int w = 10;
    int h = 10;
    
private:
    void move();
    void draw();
    void background();
    void NPC();
    
public:
    
    // Move mario function
    void move(int xoffset, int yoffset)
    {
        X = min (max (X + xoffset, 0), windowWidth - w);
        Y = min (max (Y + yoffset, 0), windowHeight - h);
        X = X + xoffset;
        
        if (X < 0)
        {
            X = 0;
        }
        else if (X > windowWidth)
        {
            X = windowWidth;
        }
        
        
        
        if (g.getKey() == UP_ARROW)
        {
            Y = max(Y - 1, 0);
        }
        else if (g.getKey() == DOWN_ARROW)
        {
            Y = min(Y + 1, windowHeight - h);
        }
        else if (g.getKey() == LEFT_ARROW)
        {
            X = max(X - 1, 0);
            
        }
        else if (g.getKey() == RIGHT_ARROW)
        {
            X = min(X + 1, windowWidth - w);
        }
        
        //UP
        Y = max(Y - 1, 0);
        
        // Down
        Y = min(Y + 1, windowHeight - h);
        
        // Left
        X = max(X - 1, 0);
        
        // Right
        X = min(X + 1, windowWidth - w);
        
    }
    
    // Draw mario function
    void draw(SDL_Plotter & g)
    {
        for (int col = X; col < w + X; ++col)
        {
            for (int row = Y; row < h + Y; ++row)
            {
                g.plotPixel (col, row, 0, 0, 255);
            }
        }
    }
    
    
    // Platform function
    void platform(SDL_Plotter & g)
    {
        // Platform variables
        int middle = 250;
        int tMiddle = 220;
        int top = 100;
        int NearBottom = 400;
        int bottom = 530;
        //int base = 560;
        
        // Y position variables
        int nMY = 226;
        int nTM = 196;
        int nT = 76;
        int nNB = 376;
        int B = 506;
        
        
        
        for (int col = 0; col < w + 1000; ++ col)
        {
            for (int row = bottom; row < windowHeight; ++row)
            {
                g.plotPixel(col, row, 0, 0, 255);
            }
            
        }
        
        
        if (Y == bottom)
        {
            if (X >= 0 && X <= 1000)
            {
                Y = B;
            }
        }
        
        
        
        // For the platforms on the row 300
        for (int col = 800; col < w + 1000; ++col)
        {
            for (int row = middle; row < h + middle; ++row)
            {
                g.plotPixel (col, row, 0, 0, 255);
                
            }
        }
        if (Y == middle)
        {
            if (X >= 800 && X <= 1000)
            {
                Y = nMY;
            }
        }
        
        
        for (int col = 0; col < w + 200; ++col)
        {
            for (int row = middle; row < h + middle ; ++row)
            {
                g.plotPixel (col, row, 0, 0, 255);
                
            }
        }
        
        if (Y == middle)
        {
            if (X <= 200 && X >= 0)
            {
                Y = nMY;
            }
        }
        
        
        // For the platform directly in the middle
        for (int col = 300; col < w + 700; ++col)
        {
            for (int row = tMiddle; row < h + tMiddle; ++row)
            {
                g.plotPixel (col, row, 0, 0, 255);
                
            }
        }
        
        if (Y == tMiddle)
        {
            if (X <= 700 && X >= 300)
            {
                Y = nTM;
            }
        }
        
        
        
        //For the platforms on the row 450
        
        // for the row on the right
        for (int col = 600; col < w + 1000; ++col)
        {
            for (int row = NearBottom; row < h + NearBottom; ++row)
            {
                g.plotPixel (col, row, 0, 0, 255);
                
            }
        }
        
        if (Y == NearBottom)
        {
            if(X <= 1000 && X >= 600)
            {
                Y = nNB;
            }
        }
        
        // Row on the left
        for (int col = 0; col < w + 400; ++col)
        {
            for (int row = NearBottom; row < h + NearBottom; ++row)
            {
                g.plotPixel (col, row, 0, 0, 255);
                
            }
        }
        
        if (Y == NearBottom)
        {
            if (X <= 400 && X >= 0)
            {
                Y = nNB;
            }
        }
        
        
        // Dot in the middle for the pow box
        for (int col = 480; col < w + 510; ++col)
        {
            for (int row = NearBottom; row < h + NearBottom; ++row)
            {
                g.plotPixel (col, row, 0, 0, 255);
            }
        }
        if (Y == NearBottom)
        {
            if(X >= 480 && X <= 510)
            {
                Y = nNB;
            }
        }
        
        
        
        // For the top platforms (i.e row 150)
        for (int col = 0; col < w + 400; ++col)
        {
            for (int row = top; row < h + top; ++row)
            {
                g.plotPixel (col, row, 0, 0, 255);
                
            }
        }
        
        if (Y == top)
        {
            if(X <= 400 && X >= 0)
            {
                Y = nT;
            }
        }
        
        
        // For the row on the right
        for (int col = 600; col < w + 1000; ++col)
        {
            for (int row = top; row < h + top; ++row)
            {
                g.plotPixel (col, row, 0, 0, 255);
                
                
            }
        }
        
        if (Y == top)
        {
            if (X <= 1000 && X >= 600)
            {
                Y = nT;
            }
        }
        
        
    }
    
    void background(SDL_Plotter & g)
    {
        for (int col = 0; col < windowWidth; ++col)
        {
            for (int row = 0; row < windowHeight; ++row)
            {
                g.plotPixel (col, row, 0, 0, 0);
            }
        }
    }
    
    void NPC(SDL_Plotter & g)
    {
        
        
    }
    
};


#endif /* mario_hpp */
