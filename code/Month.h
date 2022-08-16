//

// Created by hello on 11/22/2021.
//

#ifndef CALENDAR_GUI_MONTH_H
#define CALENDAR_GUI_MONTH_H

#include "GUIComponent.h"
#include "Fonts.h"
#include "Date.h"
//Month changes based on Dropdown, thus a GUI Component
class Month : public GUIComponent{
private:

    sf::RectangleShape daysOfWeek[7];
    sf::Text titles[7];

    std::string monthName="month";

    //Maximum of 31 days --> index = day-1 and 1 extra spot at the end.
    Date dates[31];

    //Pointer to date whose FileTree is showing
    Date* showingDate= nullptr;

    //12 months --> index of nth month is (n-1). Thus, Jan is 0 and Dec is 11.
    int months[12];

    //number of days in a month
    int numDays=0;

    //Screen having all days
    sf::RectangleShape monthScreen;

    void getDOW();

    //position of the monthScreen on the window
    sf::Vector2f position = {0,0};
public:
    Month();

    Month(int m, int y, float w, float h);

    void initDaysOfWeek();

    void repositionDates();

    std::string getMonthName();

    void setLightView();
    void setNightView();

    void highlightTasks();
    void highlightBirthdays();
    void higlightBoth();

    void setMonthName(std::string name);

    void updateMonth(int n, int yr);


    sf::FloatRect getGlobalBounds() const;

    void setPosition(float x, float y);

    void setMonthScreenSize(float w, float h);

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //CALENDAR_GUI_MONTH_H
