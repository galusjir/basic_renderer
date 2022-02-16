#include"wireframe.h"
#include<fstream>
#include<iostream>
Wireframe::Wireframe(std::string& filepath)
{
    m_initialized = false;
    std::fstream file(filepath, file.in);
    if(!file.is_open())
    {
        std::cout << "Not possible to open the file";
    }
    else
    {
        char * buffer = new char(256);
        while (file.getline(buffer, 256))
        {
            std::string line(buffer);
            line[0];
            
        }
        
    }
}

void Wireframe::Draw(TGAImage& image, TGAColor& color)
{

}