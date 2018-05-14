#ifndef PRINTTESTIMAGE_H
#define PRINTTESTIMAGE_H

#include "scene.h"

class PrintTestImage : public Scene
{
public:
    PrintTestImage() : Scene("PrintTestImage") {}
    void render(std::ostream& out);
};

#endif // PRINTTESTIMAGE_H
