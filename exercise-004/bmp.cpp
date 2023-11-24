#include "bmp.h"
#include <fstream>
#include <vector>

bool BMP::read(const std::string&  filename)
{
    auto ret = false;
    std::ifstream infile; 
    infile.open(filename);

    if (!infile.is_open()) {
        return ret;
    }

    BITMAPFILEHEADER file_header;
    
    infile >> file_header.bfType;
    infile >> file_header.bfSize;
    infile >> file_header.bfReserved;
    infile >> file_header.bfOffBits;

    BITMAPINFOHEADER info_header;

    infile >> info_header.biSize;
    infile >> info_header.biWidth;
    infile >> info_header.biHeight;
    infile >> info_header.biPlanes;
    infile >> info_header.biBitCount;
    infile >> info_header.biCompression;
    infile >> info_header.biSizeImage;
    infile >> info_header.biXPelsPerMeter;
    infile >> info_header.biYPelsPerMeter;
    infile >> info_header.biClrUsed;
    infile >> info_header.biClrImportant;

    auto buffer_size = info_header.biWidth*info_header.biHeight;
    std::vector<Pixel> pixel_buffer(buffer_size);
    
    for (int i = 0; i < buffer_size; i++)
    {
        auto muell = 0;
        infile >> pixel_buffer[i].red;
        infile >> pixel_buffer[i].green;
        infile >> pixel_buffer[i].blue;
        infile >> muell;
    }
    return ret;
}

bool BMP::write(const std::string&  filename)
{
    auto ret = false;
    //insert your code here
    //auf info-> pixels-> grey-> ascii->print
    return ret;
}