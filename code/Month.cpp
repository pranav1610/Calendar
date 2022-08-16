//
// Created by hello on 11/22/2021.
//

#include "Month.h"

Month::Month()
{
    monthScreen.setFillColor(sf::Color(196, 196, 196));

    setPosition(0,0);

    updateMonth(3,2022);

}

Month::Month(int m, int y, float w, float h)
{
    if(m==1)
    {
        monthName = "January";
    }
    else if (m==2)
    {
        monthName = "February";
    }
    monthScreen.setFillColor(sf::Color(196, 196, 196));

    float x1 = 0.026*w;
    float y1 = 0.26*h;

    setPosition(x1,y1);
    setMonthScreenSize((w-2*x1),0.71*h);
    updateMonth(m,y);

    setNightView();

}


//1. Always draw monthscreen
//   -- if date tree is showing(month in HIDDEN state), draw that Date
//   --otherwise draw all Dates in the Month(this, month not HIDDEN)
void Month::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    //draw month screen
    window.draw(monthScreen);

    if(this->isEnabled(HIDDEN))
    {
        window.draw(*showingDate);
    }
    else
    {
        //draw the days of week on month screen
        for(int i=0;i<7;i++)
        {
            window.draw(daysOfWeek[i]);
            window.draw(titles[i]);
        }

        //draw the dates on the month screen
        for(int i=0;i<31;i++)
        {
            if(dates[i].getDayValue()==-1)
            {
                // std::cout << "here " << i+1 << "\n";
                break;
            }
            window.draw(dates[i]);
        }
    }
}

void Month::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    //1. add Event haldnler on each date to determine if a its SHOWTREE is enabled.
    //2. only one date's tree can be visible on month screen, thus clear the month screen
    //   and dont allow event handler on other dates

    if(!this->isEnabled(HIDDEN))    // HIDDEN month means all dates are hidden and a date's tree is showing/operating
    {
        for (int i = 0; i < numDays; i++) {
            dates[i].addEventHandler(window, event);
//            if (dates[i].isEnabled(SHOWTREE))
//            {
//               // std::cout << "in month, hide\n";
//                showingDate = &dates[i];
//                this->enableState(HIDDEN);
//                return;
//            }
//            else
//            {
//                std::cout << "in month, show\n";
//                this->disableState(HIDDEN);
//            }
        }
        for (int i = 0; i < numDays; i++) {
            if (dates[i].isEnabled(SHOWTREE))
            {
                // std::cout << "in month, hide\n";
                showingDate = &dates[i];
                this->enableState(HIDDEN);
                return;
            }
//            else
//            {
//                //std::cout << "in month, show\n";
//                this->disableState(HIDDEN);
//            }
        }
    }
    else
    {
        showingDate->addEventHandler(window,event);
        //std::cout << "go to date\n";
        if(!showingDate->isEnabled(SHOWTREE))
        {
            this->disableState(HIDDEN);
        }
    }


//    for(int i=0;i<numDays;i++)
//    {
//
//        //if date is clicked, hide the dates and show the operations tree for the date clicked
//        if(MouseEvents<Date>::mouseClicked(dates[i], window))
//        {
//            dates[i].setFillColor(sf::Color::Black);
//            dates[i].enableState(SHOWTREE);
//            //add event handler for the tree in a date object
//            dates[i].addEventHandler(window,event);
//        }
//        else if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
//        {
//            dates[i].setFillColor(sf::Color::Red);
//            dates[i].disableState(SHOWTREE);
//        }
//    }

}

//TODO update the dates[30] positions.
void Month::update() {
    //if(this->isEnabled(HIDDEN))
//    {
//        showingDate->update();
//    }
//    else
//    {
//        repositionDates();
//    }
    if(this->isEnabled(HIDDEN))
    {
        for (int i = 0; i < numDays; i++)
        {
            if(dates[i].isEnabled(SHOWTREE))
                dates[i].update();
        }
    }
    else
    {
        repositionDates();
        for(int i=0;i<numDays;i++)
        {
            if(dates[i].isEnabled(TASK) && dates[i].isEnabled(BIRTHDAY))
            {
                sf::Color c(222,56,232);
                dates[i].setFillColor(c);
            }
            else if(dates[i].isEnabled(BIRTHDAY))
            {
                sf::Color c(43,213,155);
                dates[i].setFillColor(c);
            }
            else if(dates[i].isEnabled(TASK))
            {
                sf::Color c(236,176,71);
                dates[i].setFillColor(c);
            }
            else
            {
                if(dates[i].isEnabled(LIGHTVIEW))
                {
                    dates[i].lightViewConfig();
                }
                else
                {
                    dates[i].nightViewConfig();
                }
            }
        }
    }
}

Snapshot &Month::getSnapshot() {
    //return <#initializer#>;
}

void Month::applySnapshot(const Snapshot &snapshot) {

}

void Month::setPosition(float x, float y)
{
    monthScreen.setPosition(x,y);
}

void Month::setMonthScreenSize(float w, float h)
{
    monthScreen.setSize({w,h});
    //as initDaysOfWeek does positioning relative to the month screen's size
    initDaysOfWeek();

    //repositionDates();
}

//nth month 1<=n<=12
// n = 1 3 5 7 8 10 12 --> 31 days
// n = 4 6 9 11 --> 30 days
// n= 2 --> 28 days
void Month::updateMonth(int n, int yr) {
    // 31 days
    if(n==2)
        numDays = 28;
    else if ((n <= 7 && n % 2 == 1) || (n >= 8 && n % 2 == 0)) {
        numDays = 31;
    } else if (n == 4 || n == 6 || n == 9 || n == 11) {
        numDays = 30;
    }

    for (int i = 0; i < numDays; i++)
    {
        dates[i] = Date(i+1, n, yr, {0,0}, monthScreen.getGlobalBounds().left, monthScreen.getGlobalBounds().top);
        //dates[i].setDayValue(i+1);
        //dates[i].setDayOfTheWeek(n, yr);

        //initialize tree for each day and hide it(in Date class)
        //dates[i].initTree();
    }
    //std::cout << n << "/1/2022 falls on " << dates[0].getDayOfTheWeek() << "\n";
}

std::string Month::getMonthName() {
    return monthName;
}

void Month::setMonthName(std::string name)
{
    monthName = name;
}

sf::FloatRect Month::getGlobalBounds() const {
    return monthScreen.getGlobalBounds();
}

void Month::initDaysOfWeek()
{
    std::string t[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    //float padding = ;

    for(int i=0;i<7;i++)
    {
        titles[i].setFont(Fonts::getFont());
        titles[i].setCharacterSize(10);
        titles[i].setFillColor(sf::Color::Black);
        titles[i].setString(t[i]);
        sf::Color c(218,186,74);
        daysOfWeek[i].setFillColor(c);
        daysOfWeek[i].setSize({30,20});
        if(i==0)
        {
            daysOfWeek[i].setPosition(monthScreen.getGlobalBounds().left+0.09*monthScreen.getGlobalBounds().width,
                                      monthScreen.getGlobalBounds().top+0.1*monthScreen.getGlobalBounds().height);
            //std::cout <<"\nfor " << monthName << " " << monthScreen.getGlobalBounds().top+0.1*monthScreen.getGlobalBounds().height;
        }
        else
        {
            daysOfWeek[i].setPosition(daysOfWeek[i-1].getGlobalBounds().left+daysOfWeek[i-1].getGlobalBounds().width+0.1*monthScreen.getGlobalBounds().width,
                                      daysOfWeek[i-1].getGlobalBounds().top);
        }
        //std::cout << "w: " << monthScreen.getGlobalBounds().width << "\n";
        titles[i].setPosition(daysOfWeek[i].getGlobalBounds().left+2, daysOfWeek[i].getGlobalBounds().top+2);
    }
}
void Month::repositionDates()
{
    //
    //std::cout << "called repos\n";
    sf::Vector2f pos;

    //same x as days of week titles and just below in terms of y
    //pos.x = daysOfWeek[0].getGlobalBounds().left;
    pos.y = daysOfWeek[0].getGlobalBounds().top + 2*daysOfWeek[0].getGlobalBounds().height;
    //dates[0].setPosition(pos.x, pos.y);

    for(int i=0;i<31;i++)
    {
        if(dates[i].getDayValue()==-1)
        {
            //std::cout << "gwanna exit at i: " << i << "\n";
            break;
        }
        //(1 to 7)*box width
        //pos.x += dates[i].getDayOfTheWeek()*dates[i].getGlobalBounds().width;
        pos.x = daysOfWeek[dates[i].getDayOfTheWeek()].getGlobalBounds().left+daysOfWeek[dates[i].getDayOfTheWeek()].getGlobalBounds().width-dates[i].getGlobalBounds().width;
        //std::cout <<  "x: " << pos.x << ", y: " << pos.y << "\n";

        dates[i].setPosition(pos.x,pos.y);

        if(dates[i].getDayOfTheWeek()==6)
        {
            //std::cout << "y bef: " << pos.y;
            pos.y += dates[i].getGlobalBounds().height;
            //std::cout << ", y aft: " << pos.y << "\n";
            pos.x = daysOfWeek[0].getGlobalBounds().left;
        }

    }

}

void Month::getDOW()
{
    for(int i=0;i<31;i++)
    {
        if(dates[i].getDayOfTheWeek()==-1)
        {
            break;
        }
        std::cout << dates[i].getDayOfTheWeek() << " ";

    }
}

void Month::setLightView()
{
   // sf::Color::White

    sf::Color c(209,209,209);
    monthScreen.setFillColor(sf::Color::White);

    for(int i=0;i<31;i++)
    {
        if(dates[i].getDayValue()==-1)
        {
            // std::cout << "here " << i+1 << "\n";
            break;
        }
        dates[i].setLightView();
    }
}

void Month::setNightView()
{
    //(196, 196, 196)
    //sf::Color c(91,91,91);
    monthScreen.setFillColor(sf::Color::Black);
    for(int i=0;i<31;i++)
    {
        if(dates[i].getDayValue()==-1)
        {
            // std::cout << "here " << i+1 << "\n";
            break;
        }
        dates[i].setNightView();
    }

}

void Month::highlightTasks() {
    for(int i=0;i<31;i++)
    {
        //std::cout << "here\n";
        if(dates[i].getDayValue()==-1)
        {
            // std::cout << "here " << i+1 << "\n";
            break;
        }
        dates[i].disableState(BIRTHDAY);
        if(dates[i].numTasks()>0)
        {
            std::cout << "date: " << dates[i].getDayValue() << "\n";
            dates[i].enableState(TASK);
        }

    }
}

void Month::highlightBirthdays() {
    for(int i=0;i<31;i++)
    {
        if(dates[i].getDayValue()==-1)
        {
            // std::cout << "here " << i+1 << "\n";
            break;
        }
        dates[i].disableState(TASK);
        if(dates[i].numBirthdays()>0)
        {
            dates[i].enableState(BIRTHDAY);
            //return true;
        }
    }
}

void Month::higlightBoth()
{
    for(int i=0;i<31;i++)
    {
        if(dates[i].getDayValue()==-1)
        {
            // std::cout << "here " << i+1 << "\n";
            break;
        }
        if(dates[i].numTasks()>0 && dates[i].numBirthdays()>0)
        {
            dates[i].enableState(BIRTHDAY);
            dates[i].enableState(TASK);
            //return true;
        }
    }
}



