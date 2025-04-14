#include <iostream>
#include <cmath>

struct Image { 
    int *pixels; 
    int width; 
    int height;

    void printImage(const Image& img);
    Image halve(const Image& img);
};

void printImage(const Image& img) {
    for (int i=0; i<img.height; i++) {
        for (int j=0; j<img.width; j++) {
            std::cout << img.pixels[i*img.width + j] << " ";
        }
        std::cout << std::endl;
    }
}

Image halve(const Image& img) { // ignore odd rowIndex and columnnIndex
    int nWidth = ceil(float(img.width)/2.0);
    int nHeight = ceil(float(img.height)/2.0);

    int* newPixels = new int[nWidth * nHeight]; // 2 * 3
 
    for (int i=0; i<img.height; i+=2) {
        for (int j=0; j<img.width; j+=2) {
            newPixels[i/2 * nWidth + j/2] = img.pixels[i*img.width + j];
        }
    }

    Image newImg = {
        newPixels, 
        nWidth,
        nHeight
    };

    return newImg;
}

int main() {
    int pixels[] = {
        1, 3, 0, 5, 2,
        4, 1, 8, 3, 1,
        3, 3, 1, 3, 2
    };
    Image img = {pixels, 5, 3};
    printImage(img);
    printImage(halve(img));
}