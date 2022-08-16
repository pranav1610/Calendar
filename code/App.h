//
// Created by hello on 12/1/2021.
//

#ifndef CALENDAR_GUI_APP_H
#define CALENDAR_GUI_APP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Stacks/Stack.h"
#include "MultiText.h"
#include "TextInput.h"
#include "DropdownMenu.h"
#include "History.h"
//remove this include
//#include "MouseEvents.h"
//#include "TextBox.h"
#include "InputBox.h"
#include "Menu.h"
#include "MenuBar.h"
#include "Image.h"
#include "FileItem.h"
#include "FileTree.h"
#include "Date.h"
#include "Calendar.h"
#include "Month.h"
class App {
    private:
        sf::Color background= sf::Color::Black;
        sf::Color getBackground(Calendar& cal);
public:
    void run();
};


#endif //CALENDAR_GUI_APP_H
