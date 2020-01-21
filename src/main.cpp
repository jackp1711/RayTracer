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
#include "camera.h"
#include "light.h"
#include "scene.h"

int thisone;

void savebmp(const char *filename, int w, int h, int dpi, Colour *data);

int main(int argc, char *argv[]){
    std::cout <<"rendering..."<< std::endl;

    int dpi = 72;

    int image_width = 512;
    int image_height = 512;
    int n = image_height *image_width;
    Colour *pixels = new Colour[n];

    // File_Maker_BMP writer = File_Maker_BMP();

    Vector X = Vector(1, 0, 0);
    Vector Y = Vector(0, 1, 0);
    Vector Z = Vector(0, 0, 1);

    Scene scene;

    Camera camera = Camera();
    camera.position = Vertex(0.0f, 0.0f, -3.5f);

    Vector look_at = Vector(0,0,0);
    Vector diff = Vector(camera.position.x - look_at.x, camera.position.y - look_at.y, camera.position.z - look_at.z);
    diff.negate();
    diff.normalize();
    camera.direction = diff;

    camera.camera_right = Y.cross(camera.direction); camera.camera_right.normalize();
    camera.camera_down = camera.camera_right.cross(camera.direction);

    Light light = Light(Vertex(0, 10, 10), Vector(0, 0, -1), Colour(1, 1, 1));

    scene.add_light_to_list(light);

    for(int x = 0; x < image_width; x++){
        for(int y = 0; y < image_height; y++){
            thisone = y *image_width + x;
            Ray ray;
            Hit hit;

            Colour colour = scene.trace(ray, hit);
            
        }
    }
    
    savebmp("out/scene.bmp", image_width, image_height, dpi, pixels);

    return 0;
}


void savebmp(const char *filename, int w, int h, int dpi, Colour *data){
    FILE *f;
    int k = w * h;
    int s = 4*k;
    int file_size = 54 + s;

    double factor = 39.375;
    int m = static_cast<int>(factor);

    int ppm = dpi*m;

    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

    bmpfileheader[ 2] = (unsigned char)(file_size);
    bmpfileheader[ 3] = (unsigned char)(file_size>>8);
    bmpfileheader[ 4] = (unsigned char)(file_size>>16);
    bmpfileheader[ 5] = (unsigned char)(file_size>>24);

    bmpinfoheader[ 4] = (unsigned char)(w);
    bmpinfoheader[ 5] = (unsigned char)(w>>8);
    bmpinfoheader[ 6] = (unsigned char)(w>>16);
    bmpinfoheader[ 7] = (unsigned char)(w>>24);

    bmpinfoheader[ 8] = (unsigned char)(h);
    bmpinfoheader[ 9] = (unsigned char)(h>>8);
    bmpinfoheader[10] = (unsigned char)(h>>16);
    bmpinfoheader[11] = (unsigned char)(h>>24);

    bmpinfoheader[21] = (unsigned char)(s);
    bmpinfoheader[22] = (unsigned char)(s>>8);
    bmpinfoheader[23] = (unsigned char)(s>>16);
    bmpinfoheader[24] = (unsigned char)(s>>24);

    bmpinfoheader[25] = (unsigned char)(ppm);
    bmpinfoheader[26] = (unsigned char)(ppm>>8);
    bmpinfoheader[27] = (unsigned char)(ppm>>16);
    bmpinfoheader[28] = (unsigned char)(ppm>>24);

    bmpinfoheader[29] = (unsigned char)(ppm);
    bmpinfoheader[30] = (unsigned char)(ppm>>8);
    bmpinfoheader[31] = (unsigned char)(ppm>>16);
    bmpinfoheader[32] = (unsigned char)(ppm>>24);

    f = fopen(filename,"wb");

    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for(int i = 0; i < k; i++){
        Colour rgb = data[i];

        double red = (rgb.r)*255;
        double green = (rgb.g)*255;
        double blue = (rgb.b)*255;

        unsigned char colour[3] = {(int)floor(blue), (int)floor(green), (int)floor(red)};

        fwrite(colour, 1, 3, f);
    }

    fclose(f);
}