//
// Created by hello on 11/22/2021.
//

#ifndef CALENDAR_GUI_DATE_H
#define CALENDAR_GUI_DATE_H

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include "Fonts.h"
#include "GUIComponent.h"
#include "FileTree.h"



class Date : public GUIComponent{
private:
    sf::Text operationsHead;
    //Value of day
    //dayValue of -1 indicates the date isn't a part of the month. eg. 30 for Feb = -1 at the end of program.
    int dayValue=-1;

    //day of the week as index (0 is Sunday, 1 is Monday,..6 is Saturday, thus 6 is max value and 0 is min)
    int dayOfWeek;

    //Box wrapper of Date
    sf::RectangleShape dateBox;

    //Text or the Date inside the dateBox
    sf::Text sfDayValue;

    float screenX=100;
    float screenY=200;

    //Private members defining a Date are below the public declarations.
    void initOperationsHeader();
public:

    enum eventType {TASK, BIRTHDAY};
    //maps an event with the appropriate eventType (TASK or BIRTHDAY)
    std::map<Date::eventType, std::vector<std::string>> events;

    Date();

    Date(int dayVal, int m, int y, sf::Vector2f pos, float sX, float sY);

    //void add
    //void add

    sf::FloatRect getGlobalBounds() const;

    void acceptScreensize(float x, float y);

    void setPosition(float x, float y);

    bool contains(float x, float y);

    void setFillColor(sf::Color c);

    void setLightView();

    void setNightView();

    int numTasks();
    int numBirthdays();

    std::vector<std::string> getTasks();
    std::vector<std::string> getBirthdays();


    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    int getDayValue() const;
    int getDayOfTheWeek() const;

    void setDayOfTheWeek(int month, int year);
    void setDayValue(int val);
    void lightViewConfig();
    void nightViewConfig();

    void setTreePosition(sf::Vector2f pos);

    void initTree();

private:
    //operations: (are FileNodes)
    // -- task - add, remove, and view
    // --birthday - add, remove, and view
    //FileTree operations;
    FileTree* operations=new FileTree();

    std::vector<std::string> tasks;
    std::vector<std::string> birthdays;

    void updateEvents();


};


#endif //CALENDAR_GUI_DATE_H
