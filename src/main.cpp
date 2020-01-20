#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "vector.h"
#include "vertex.h"
#include "ray.h"
#include "colour.h"
#include "file_maker_bmp.h"

int thisone;

int main(int argc, char *argv[]){
    std::cout <<"rendering..."<< std::endl;

    int dpi = 72;

    int image_width = 512;
    int image_height = 512;
    int n = image_height *image_width;
    std::vector<Colour> pixels;

    File_Maker_BMP writer = File_Maker_BMP();

    for(int x = 0; x < image_width; x++){
        for(int y = 0; y < image_height; y++){
            thisone = y *image_width + x;


        }
    }
    
    writer.savebmp("out/scene.bmp", image_width, image_height, dpi, pixels);

    return 0;
}