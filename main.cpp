#include "printtestimage.h"
#include "birdie.h"
#include "scene.h"

#include <fstream>
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<Scene> scene(new Birdie);
    scene->render(std::cout);
//    std::ofstream ofs("/home/risca/Projects/microchip_vga/src/birdie.asm", std::ios::out | std::ios::trunc);
//    scene->render(ofs);
    return 0;
}
