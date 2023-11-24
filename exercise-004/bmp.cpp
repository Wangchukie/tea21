#include "bmp.h"
#include <fstream>
#include <vector>
#include <iostream>

template<typename T>
static void read_value(std::fstream& file,T* value )
{
    file.read(reinterpret_cast<char*>(value), sizeof(T));
}

// Funktion zur Darstellung des Graustufenvektors als ASCII-Bild
void displayAsciiImage(const std::vector<uint8_t>& grey_buffer, int width, int height) 
{
    // Zeichen zur Darstellung der Graustufen (hier einfach gehalten)
    const std::string ascii_chars = " .:-=+*#%@";//"@%#*+=-:. ";
   
    // Schleife über den Graustufenvektor
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; ++i) 
        {
            // Bestimme den entsprechenden ASCII-Charakter basierend auf dem Grauwert
            int index = grey_buffer[i+(height-j)*width] * (ascii_chars.size() - 1) / 255;
            char ascii_char = ascii_chars[index];

            // Ausgabe des ASCII-Zeichens
            std::cout << ascii_char;
        }
        // Zeilenumbruch nach jeder Zeile entsprechend der Bildbreite
        std::cout  << "|"<< std::endl;
    }
}


bool BMP::read(const std::string&  filename)
{
    auto ret = false;
    std::fstream infile; 
    infile.open(filename, std::ios::binary | std::ios::in);

    if (!infile.is_open()) {
        return ret;
    }

    
    read_value(infile, &m_file_header.bfType);
    read_value(infile, &m_file_header.bfSize);
    read_value(infile, &m_file_header.bfReserved);
    read_value(infile, &m_file_header.bfOffBits);

    read_value(infile, &m_info_header.biSize);
    read_value(infile, &m_info_header.biWidth);
    read_value(infile, &m_info_header.biHeight);
    read_value(infile, &m_info_header.biPlanes);
    read_value(infile, &m_info_header.biBitCount);
    read_value(infile, &m_info_header.biCompression);
    read_value(infile, &m_info_header.biSizeImage);
    read_value(infile, &m_info_header.biXPelsPerMeter);
    read_value(infile, &m_info_header.biYPelsPerMeter);
    read_value(infile, &m_info_header.biClrUsed);
    read_value(infile, &m_info_header.biClrImportant);

    fmt::println("Type: {}", m_file_header.bfType);
    fmt::println("Size Header: {}", m_file_header.bfSize);
    fmt::println("Bits: {}", m_file_header.bfOffBits);
    fmt::println("Reserved: {}", m_file_header.bfReserved);
    fmt::println("Width: {}", m_info_header.biWidth);
    fmt::println("Height: {}", m_info_header.biHeight);
    fmt::println("BitCount: {}", m_info_header.biBitCount);
    fmt::println("ClrImportant: {}", m_info_header.biClrImportant);
    fmt::println("ClrUsed: {}", m_info_header.biClrUsed);
    fmt::println("Compression: {}", m_info_header.biCompression);
    fmt::println("Planes: {}", m_info_header.biPlanes);
    fmt::println("Size Info: {}", m_info_header.biSize);
    fmt::println("SizeImage: {}", m_info_header.biSizeImage);
    fmt::println("XPelsPerMeter: {}", m_info_header.biXPelsPerMeter);
    fmt::println("YPelsPerMeter: {}", m_info_header.biYPelsPerMeter);
    
    int buffer_size = m_info_header.biWidth*m_info_header.biHeight;
    std::vector<Pixel> pixel_buffer(buffer_size);
    int width_len = m_info_header.biWidth * 3;
    int padding_len = 4 - width_len%4;
    fmt::print("Padding: {}\n",padding_len);

    for (int i = 0; i < m_info_header.biHeight; i++)
    {
        for(int j = 0; j < m_info_header.biWidth; j++)  // Korrektur: Verwenden Sie 'j' als Bedingung
        {
            read_value(infile, &pixel_buffer[j+i*(m_info_header.biWidth)].red);
            read_value(infile, &pixel_buffer[j+i*(m_info_header.biWidth)].green);
            read_value(infile, &pixel_buffer[j+i*(m_info_header.biWidth)].blue); 
        }
        for(int x = 0; x < padding_len; x++)
        {
            infile >> pixel_buffer[i].alpha;
        }
    }

    std::vector<uint8_t> grey_buffer(buffer_size);

    for (int i = 0; i < buffer_size; i++)
    {
        grey_buffer[i] = pixel_buffer[i].grey();
    }

    displayAsciiImage(grey_buffer, m_info_header.biWidth, m_info_header.biHeight);

    /*
    char asciiList[] = {'@','%','+','*','+','=','-',':','.',' '};    //@%#*+=-:.

    for (int i = 0; i < m_info_header.biHeight; i++)
    {
        for(int j = 0; j < m_info_header.biWidth; j++)  // Korrektur: Verwenden Sie 'j' als Bedingung
        {
            char mappedChar = asciiList[grey_buffer[i * m_info_header.biWidth + j]];
            fmt::print("{}", mappedChar);   
        }
    fmt::print("{}\n");
}
*/
    return ret;
}

bool BMP::write(const std::string&  filename)
{
    auto ret = false;
    //insert your code here
    //auf info-> pixels-> grey-> ascii->print
    return ret;
}