#include "operations.h"
#include<algorithm>


void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
    // I have to iterate through the longer edge, otherwiese there will be holes in the line
    float slope = (y1 - y0) / (x1 - x0);
    int y;
    for (int x = x0; x <= x1; x++){
        y = slope * (x - x0) + y0;
        image.set(x, y, color);
    }
}
