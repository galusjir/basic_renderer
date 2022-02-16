
#ifndef __WIREFRAME_H
#define __WIREFRAME_H

#include<string>
#include<vector>
#include<tgaimage.h>

class Wireframe
{
public:
    Wireframe(std::string& filepath);
    void Draw(TGAImage& image, TGAColor& color);

private:
    class Face
    {
    public:
        Face(int v1, int v2, int v3) :
          m_v1(v1), m_v2(v2), m_v3(v3){}
        int m_v1;
        int m_v2;
        int m_v3;
    };

    std::vector<float> m_vertices;
    std::vector<Face> m_face;
    bool m_initialized;

};


#endif //__WIREFRAME_H