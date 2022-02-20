#include "tgaimage.h"
#include "operations.h"
#include "model.h"
#include<iostream>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

int main(int argc, char** argv) {
	TGAImage image(800, 800, TGAImage::RGB);
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

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

