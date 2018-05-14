#ifndef BIRDIE_H
#define BIRDIE_H

#include "scene.h"

class Birdie : public Scene
{
public:
    Birdie() : Scene("BirdieText") {}

    void render(std::ostream& out);
};

#endif // BIRDIE_H
