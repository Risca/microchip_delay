#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <ostream>

class Scene
{
public:
    Scene(const std::string &name) : _name(name) {}

    virtual void render(std::ostream& out) = 0;

protected:
    const std::string _name;
};

#endif // SCENE_H
