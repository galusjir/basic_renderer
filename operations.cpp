#include "operations.h"
#include<algorithm>

void line(Vec2i v0, Vec2i v1, TGAImage& image, const TGAColor color)
{
    line(v0.x, v0.y, v1.x, v1.y, image, color);
}

void line(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor color)
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
    int dx = x1 - x0;
    int dy = y1 - y0;
    float derror = std::abs( float(dy) / float(dx));
    float error = 0.;
    int y = y0;
    for (int x = x0; x <= x1; x++){
        if (steep)
        {
            image.set(y, x, color);
        }
        else
        {
            image.set(x, y, color);
        }
        error += derror;
        if (error > 0.5)
        {
            y += y1 > y0 ? 1 : -1;
            error -= 1;
        }
    }
}



void sweep_triangle(Vec2i v0, Vec2i v1, Vec2i v2, TGAImage& image, const TGAColor color)
{
    std::vector v = {v0, v1, v2};
    std::sort(v.begin(), v.end(), [](const Vec2i& a, const Vec2i& b) {
        return a.y > b.y;
    });
    
    Vec2i start;
    Vec2i end;
    std::vector<Vec2i> line1;
    std::vector<Vec2i> line2;
    get_boundary_vectors_1(line1, v[0], v[1]);
    get_boundary_vectors_1(line2, v[0], v[2]); // That is the longer
    bool line1_on_left = v[1].x < v[2].x ? true : false;
    auto line1_iter = line1.begin();
    auto line2_iter = line2.begin();
    while (line1_iter != line1.end() &&
           line2_iter != line2.end())
    {
        if (line1_on_left)
        {
            line1_iter
        }
    }
    
}


void get_boundary_vectors_1(std::vector<Vec2i>& out_vect, Vec2i v0, Vec2i v1)
{
    int x0, x1, y0, y1;
    x0 = v0.x;
    y0 = v0.y;
    x1 = v1.x;
    y1 = v1.y;
    
    bool steep = false;
    if (x0 == x1 && y0 == y1)
    {
        return;
    }
    if (abs(y0 - y1) > abs(x0 - x1) ){   // mirror according 1st and 3rd quadrant
       std::swap(x0,y0);
       std::swap(x1,y1);
       steep = true;
    }
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1 - x0;
    int dy = y1 - y0;
    float derror = std::abs( float(dy) / float(dx));
    float error = 0.;
    int y = y0;
    if (x0 <= x1)
    {
        for (int x = x0; x <= x1; x++){
            if (steep)
            {
                out_vect.push_back(Vec2i(y, x));
            }
            else
            {
                out_vect.push_back(Vec2i(x, y));
            }
            error += derror;
            if (error > 0.5)
            {
                y += y1 > y0 ? 1 : -1;
                error -= 1;
            }
        }
    }
    else
    {
        for (int x = x0; x >= x1; x--){
            if (steep)
            {
                out_vect.push_back(Vec2i(y, x));
            }
            else
            {
                out_vect.push_back(Vec2i(x, y));
            }
            error += derror;
            if (error > 0.5)
            {
                y += y1 > y0 ? 1 : -1;
                error -= 1;
            }
        }
    }
    
}

void triangle(const Vec2i t0, const Vec2i t1,const Vec2i t2, TGAImage &image, const TGAColor& color) { 
    line(t0, t1, image, color); 
    line(t1, t2, image, color); 
    line(t2, t0, image, color); 
} 
