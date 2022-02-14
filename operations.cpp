#include "operations.h"
#include<algorithm>


void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
    // I have to iterate through the longer edge, otherwiese there will be holes in the line
    bool steep = false;
    if (x0 == x1 && y0 == y1)
    {
        return;
    }
    if (abs(y0 - y1) > abs(x0 - x1) ){
       std::swap(x0,y0);
       std::swap(x1,y1);
       steep = true;
    }
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    float slope = (y1 - y0) / (float) (x1 - x0);
    int y;
    for (int x = x0; x <= x1; x++){
        y = slope * (x - x0) + y0;
        if (steep)
        {
            image.set(y, x, color);
        }
        else
        {
            image.set(x, y, color);
        }
        
    }
}
