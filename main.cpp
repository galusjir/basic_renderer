#include "tgaimage.h"
#include "operations.h"
#include "model.h"
#include<iostream>


void draw_african_head(TGAImage& image)
{
    Model model("obj/african_head.obj");
	for (int i = 0; i < model.nfaces(); i++)
	{
        std::vector face = model.face(i);
		if (face.size() == 3)
		{
			for (int j = 0; j < 3; j++)
			{
              	Vec3f v0 = model.vert(face[j]);
				Vec3f v1 = model.vert(face[(j + 1) % 3]);
				int x0 = (v0.x + 1.) * image.get_width()  / 2.;
				int y0 = (v0.y + 1.) * image.get_height() / 2.;
				int x1 = (v1.x + 1.) * image.get_width()  / 2.;
				int y1 = (v1.y + 1.) * image.get_height() / 2.;
				line(x0, y0, x1, y1, image, white);
				std::cout << "Priting: v0:" << x0 << ", " << y0
				          << " v1: " << x1 << ", " << y1 << " \n";
			}
		}
		
	}
}

int main(int argc, char** argv) {
	TGAImage image(800, 800, TGAImage::RGB);
	

	Vec2i t0[3] = {Vec2i(10, 70),   Vec2i(50, 160),  Vec2i(70, 80)}; 
	Vec2i t1[3] = {Vec2i(180, 50),  Vec2i(150, 1),   Vec2i(70, 180)}; 
	Vec2i t2[3] = {Vec2i(180, 150), Vec2i(120, 160), Vec2i(130, 180)}; 
	triangle(t0[0], t0[1], t0[2], image, red); 
	triangle(t1[0], t1[1], t1[2], image, white); 
	triangle(t2[0], t2[1], t2[2], image, blue);

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

