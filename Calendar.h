//
// Created by hello on 11/22/2021.
//

#ifndef CALENDAR_GUI_CALENDAR_H
#define CALENDAR_GUI_CALENDAR_H

#include <string>
#include <map>
#include "GUIComponent.h"
#include "DropdownMenu.h"
#include "MenuBar.h"
#include "Month.h"


//Calendar is a GUI Component
class Calendar: public GUIComponent{
private:
    sf::Color* background = nullptr;
    std::string title;
    sf::Text sfTitle;
    sf::RenderTexture texture;
    sf::Sprite sprite;
    static int imgCount;
    DropdownMenu dropdownMonth;
    MenuBar menuBar;
    Month month;
    std::string monthChoice;
    std::map<std::string, Month*> months;

    std::string menuBarClicked = "";

    void setSpriteView();

    float windowWidth=1;
    float windowHeight=1;

    std::map<std::string, int> monthNIndex;
    void initMonthNIndex();

    void initMenubar();
    void initializeDropdown();

public:
    //Default Styling
    Calendar();

    Calendar(sf::Color& c, float windowWidth, float windowHeight);

    void setMonthPosition(float windowWidth, float windowHeight);

    void performMenuBarAction(sf::RenderTarget& window, std::string action);

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //CALENDAR_GUI_CALENDAR_H
