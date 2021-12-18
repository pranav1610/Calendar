//
// Created by hello on 10/6/2021.
//

#ifndef SFML_PROJECT_1_TEXTINPUT_H
#define SFML_PROJECT_1_TEXTINPUT_H

#include "GUIComponent.h"
#include "TextBox.h"
#include "Label.h"
#include "Cursor.h"
#include "MultiText.h"
#include "MouseEvents.h"
#include "ColorCode.h"

class TextInput : public GUIComponent{

private:
    //input box
    TextBox box;

    //Label for input box
    Label label;

    //Cursor
    Cursor cursor;

    //text input stored as multitext
    MultiText text;

    //Color Coding the input
    ColorCode colorCode;

    void colorCodeWord();

public:
    TextInput();
    void setPosition(float x, float y);
    void setLabelSize(float s);
    void setLabelMargin(float t, float b, float l, float r);
    void setLabel(std::string l);
    std::string tostring();
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    //The Node's global bounds, including those changed by its children based on its state
    sf::FloatRect getGlobalBounds() const;

};


#endif //SFML_PROJECT_1_TEXTINPUT_H
