//
// Created by hello on 11/6/2021.
//

#include "Image.h"

std::map<Image::imageOf, sf::Texture> Image::images;
std::map<Image::imageOf, bool> Image::loaded;

sf::Texture& Image::getImage(Image::imageOf im)
{
    if(!loaded[im])
    {
        loadImage(im);
    }
    return images[im];
}

void Image::loadImage(Image::imageOf im)
{
    if(!images[im].loadFromFile(getImagePath(im)))
    {
        std::cout << "Load Failed!\n";
        loaded[im] = false;
        exit(1);
    }
    //images[im] = texture;
    loaded[im] = true;
}

std::string Image::getImagePath(Image::imageOf im) {
    if(im==FOLDER)
    {
        return "Images/green_plus.png";
    }
    else if(im==FILE)
    {
        return "Images/red_arrow.png";
    }
}

