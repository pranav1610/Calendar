//
// Created by hello on 11/6/2021.
//

#ifndef FILETREE_IMAGE_H
#define FILETREE_IMAGE_H

#include <iostream>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>

class Image{
public:

    enum imageOf{FOLDER, FILE};

    //map of images --> map image or photo with enum to make access and change of properties easier
    static std::map<imageOf, sf::Texture> images;
    static sf::Texture& getImage(imageOf im);

    //state of image
    static std::map<imageOf, bool> loaded;
    static void loadImage(imageOf im);


    static std::string getImagePath(imageOf im);

};


#endif //FILETREE_IMAGE_H
