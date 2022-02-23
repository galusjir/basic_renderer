#ifndef __OPERATIONS_H
#define __OPERATIONS_H

#include "tgaimage.h"
#include "geometry.h"

/**
 * @brief Basic Brensenrs line algorithms
 * 
 * @param x0 
 * @param y0 
 * @param x1 
 * @param y1 
 * @param color 
 */
void line(int x0, int y0, int x1, int y1, TGAImage& image, const TGAColor color);

void line(Vec2i v0, Vec2i v1, TGAImage& image, const TGAColor color);

void sweep_triangle(Vec2i v0, Vec2i v1, Vec2i v2, TGAImage& image, const TGAColor color);

void triangle(const Vec2i t0, const Vec2i t1,const Vec2i t2, TGAImage &image, const TGAColor& color);



#endif // I_OPERATIONS_H