#ifndef MY_BMP
#define MY_BMP

#include <cstdint>
#include <fmt/format.h>
#include <string>


struct Pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
    uint8_t grey()
    {
        return (Pixel::red + Pixel::green + Pixel::blue)/3;
    };
    void print(){
        fmt::print("R: {}, G: {}, B:{}\n",Pixel::red, Pixel::green, Pixel::blue);
    }
};

struct BITMAPFILEHEADER 
{
    uint16_t bfType;
    uint32_t bfSize;
    uint32_t bfReserved;
    uint32_t bfOffBits;
};

struct BITMAPINFOHEADER 
{
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};


class BMP
{
    public:
    //BMP();
    //~BMP();
    bool read(const std::string&  filename);
    bool write(const std::string&  filename);
    
    
    
    
    
    private:
    BITMAPFILEHEADER m_file_header;
    BITMAPINFOHEADER m_info_header;
    
};

#endif