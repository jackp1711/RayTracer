#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

#include "colour.h"
#include "file_maker_bmp.h"

void File_Maker_BMP::savebmp(const char *filename, int w, int h, int dpi, std::vector<Colour> &data){
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
        Colour rgb = data.at(i);

        double red = (rgb.r)*255;
        double green = (rgb.g)*255;
        double blue = (rgb.b)*255;

        unsigned char colour[3] = {(int)floor(blue), (int)floor(green), (int)floor(red)};

        fwrite(colour, 1, 3, f);
    }

    fclose(f);
}