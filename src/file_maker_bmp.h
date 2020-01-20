#include "colour.h"
#include <vector>

#pragma once

class File_Maker_BMP{
    public:

    File_Maker_BMP(){}

    void savebmp(const char *, int, int, int, std::vector<Colour>&);
};