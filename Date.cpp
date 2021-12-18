//
// Created by hello on 11/22/2021.
//

#include "Date.h"

Date::Date()
{
    sfDayValue.setFont(Fonts::getFont());
    dateBox.setFillColor(sf::Color::Transparent);

    //default positioning, & size of text and box of Date.
    sfDayValue.setCharacterSize(20);
    dateBox.setSize({40,40});

    dateBox.setOutlineColor(sf::Color::White);
    dateBox.setOutlineThickness(2);

}
Date::Date(int dayVal, int m, int y, sf::Vector2f pos, float sX, float sY)
{
    screenX = sX;
    screenY = sY;
    setDayValue(dayVal);
    setDayOfTheWeek(m,y);

    sfDayValue.setFont(Fonts::getFont());
    //dateBox.setFillColor(sf::Color::Red);

    //default positioning, & size of text and box of Date.
    sfDayValue.setCharacterSize(20);
    dateBox.setSize({40,40});

    //dateBox.setOutlineColor(sf::Color::White);
    //dateBox.setOutlineThickness(2);

    //default night view
    setNightView();

    setPosition(pos.x, pos.y);

    initOperationsHeader();
    initTree();
}
void Date::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(this->isEnabled(SHOWTREE))
    {
        //window.draw(operations);
        window.draw(operationsHead);
        window.draw(*operations);
    }
    else
    {
        //window.draw(operationsHead);
        window.draw(dateBox);
        window.draw(sfDayValue);
    }
}

//onclicking a date(object), change its color and show the tree associated with the date for event operations.
void Date::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(!this->isEnabled(SHOWTREE) && MouseEvents<Date>::mouseClicked(*this, window))
    {
        //this->setFillColor(sf::Color::Black);
        this->enableState(SHOWTREE);
        //std::cout << "show tree\n";
        //add event handler for the tree in a date object
        //operations.addEventHandler(window,event);
    }
        //TODO - a way to escape from Tree view (right now, should be when you hit ENTER)
    else if(this->isEnabled(SHOWTREE))
    {
       // std::cout << "going to tree\n";
        //operations.addEventHandler(window,event);
        if(operations!= nullptr)
            operations->addEventHandler(window,event);
        //std::cout << "back from tree\n";
        //return to normal calendar if user hits enter
        if(KeyShortcuts::isEntered())
        {
            // findInput("birthdays")
            //
            updateEvents();
            delete operations;
            operations = new FileTree();
            //initOperationsHeader();
            initTree();
            //this->setFillColor(sf::Color::Red);
            this->disableState(SHOWTREE);
            //std::cout<< "disabled\n";
            return;
        }

    }
//    else if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event))
//    {
//        this->setFillColor(sf::Color::Red);
//        this->disableState(SHOWTREE);
//        std::cout<< "disabled\n";
//    }
}

void Date::update()
{
    if(this->isEnabled(SHOWTREE))
    {
        //operations.update();
        if(operations!= nullptr)
            operations->update();
    }
}

Snapshot &Date::getSnapshot() {
    //return <#initializer#>;
}

void Date::applySnapshot(const Snapshot &snapshot) {

}

//ALGORITHM: Sakamoto's methods, SOURCE: http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week
//day of the week dayValue falls on in month @month and year @year (2022)
//1<=month<=12
void Date::setDayOfTheWeek(int month, int year) {
    int monthConstant[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if(month<3)
    {
        year -= 1;
    }
    dayOfWeek = (year + year/4 - year/100 + year/400 + monthConstant[month-1] + dayValue)%7;
}

int Date::getDayValue() const{
    return dayValue;
}

int Date::getDayOfTheWeek() const{
    return dayOfWeek;
}

void Date::setDayValue(int val) {
    dayValue = val;
    std::string a = std::to_string(val);
    sfDayValue.setString(a);
}

void Date::setPosition(float x, float y) {

    dateBox.setPosition({x,y});
    //sfDayValue.setPosition(dateBox.getGlobalBounds().left+0.1*dateBox.getGlobalBounds().width,
    //                       dateBox.getGlobalBounds().top+0.1*dateBox.getGlobalBounds().top);
    //sfDayValue.setPosition(dateBox.getGlobalBounds().left, dateBox.getGlobalBounds().top);
    sfDayValue.setPosition(dateBox.getGlobalBounds().left+dateBox.getGlobalBounds().width-sfDayValue.getGlobalBounds().width-5,
                           dateBox.getGlobalBounds().top);
}

sf::FloatRect Date::getGlobalBounds() const {
    return dateBox.getGlobalBounds();
}

bool Date::contains(float x, float y) {
    return dateBox.getGlobalBounds().contains(x,y);
}

void Date::setFillColor(sf::Color c)
{
    dateBox.setFillColor(c);
}

void Date::initTree()
{
    //TODO - change position
//    operations.setPosition(100,200);
//    operations.push(std::to_string(dayValue), "Tasks");
//    operations.push(std::to_string(dayValue), "Birthdays");
//    //tree.push("dir 1", "c2");
//    operations.push("Tasks", "add");
//    //tree.push("add", "");
//    operations.push("Tasks", "remove");
//    operations.push("Birthdays", "add");
//    operations.push("Birthdays", "remove");
//
//    //Hide the tree to start with
//    operations.enableState(HIDDEN);
    operations->setPosition(operationsHead.getGlobalBounds().left,operationsHead.getGlobalBounds().top+operationsHead.getGlobalBounds().height+5);
    //operations->setPosition(100,200);
    std::string temp = std::to_string(dayValue);
    operations->push(temp, "Tasks");
    operations->push(temp, "Birthdays");
    //tree.push("dir 1", "c2");
    operations->push("Tasks", "add");
    //tree.push("add", "");
    operations->push("Tasks", "remove");
    operations->push("Birthdays", "add");
    operations->push("Birthdays", "remove");

    //Hide the tree to start with
    operations->enableState(HIDDEN);
    //operationsHead.setPosition(operations->getGlobalBounds().left,operations->getGlobalBounds().top-2*operationsHead.getCharacterSize());
}

void Date::setTreePosition(sf::Vector2f pos)
{
    //operations.setPosition(pos.x,pos.y);
    if(operations!= nullptr)
        operations->setPosition(pos.x,pos.y);
}

void Date::updateEvents()
{
//    std::string temp1 = operations.findInput("Birthdays", "add");
//    std::string temp2 = operations.findInput("Birthdays", "remove");
//    std::string temp3 = operations.findInput("Tasks", "add");
//    std::string temp4 = operations.findInput("Tasks", "remove");
    if(operations!= nullptr)
    {
        std::string temp1 = operations->findInput("Birthdays", "add");
        std::string temp2 = operations->findInput("Birthdays", "remove");
        std::string temp3 = operations->findInput("Tasks", "add");
        std::string temp4 = operations->findInput("Tasks", "remove");
        if(temp1.length()>0)
        {
            birthdays.push_back(temp1);
        }
        if(temp2.length()>0)
        {
            auto iter = std::find(birthdays.begin(), birthdays.end(), temp2);
            if(iter!=birthdays.end())
            {
                std::cout << "removing: " << temp2 << "\n";
                this->disableState(ObjectStates::BIRTHDAY);
                birthdays.erase(iter);
            }
            else
            {
                std::cout << "Birthday: " << temp2 << " not found\n";
            }
        }
        if(temp3.length()>0)
        {
            tasks.push_back(temp3);
            //std::cout << "pushing back: "<< tasks[0] << "\n";
        }
        if(temp4.length()>0)
        {
            auto iter = std::find(tasks.begin(), tasks.end(), temp3);
            if(iter!=tasks.end())
            {
                std::cout << "removing: " << temp4 << "\n";
                this->disableState(ObjectStates::TASK);
                tasks.erase(iter);
            }
            else
            {
                std::cout << "Task: " << temp4 << " not found\n";
            }
        }
    }



//    std::cout << "Birthdays --> add: " << temp1 <<" " <<  temp1.length() << "\n";
//    std::cout << "Birthdays --> remove: " << temp2 <<" " <<  temp2.length() << "\n";
//
//    std::cout << "Tasks --> add: " << temp3 <<" " <<  temp3.length() << "\n";
//    std::cout << "Tasks --> remove: " << temp4 <<" " <<  temp4.length() << "\n";


}

std::vector<std::string> Date::getTasks() {
    return tasks;
}

std::vector<std::string> Date::getBirthdays() {
    return birthdays;
}

int Date::numTasks() {
    return tasks.size();
}

int Date::numBirthdays() {
    return birthdays.size();
}

void Date::setNightView()
{
    this->enableState(NIGHTVIEW);
    this->disableState(LIGHTVIEW);
    sf::Color c(196,196,196);
    operationsHead.setFillColor(c);
    sfDayValue.setFillColor(sf::Color::White);
    dateBox.setFillColor(sf::Color::Transparent);
    //operations.setNightView();
    if(operations!= nullptr)
        operations->setNightView();
}

void Date::setLightView() {
    this->enableState(LIGHTVIEW);
    this->disableState(NIGHTVIEW);
    sf::Color c(91,91,91);
    operationsHead.setFillColor(c);
    dateBox.setFillColor(sf::Color::Transparent);
    sfDayValue.setFillColor(sf::Color::Black);
    //operations.setLightView();
    if(operations!= nullptr)
        operations->setLightView();
}

void Date::lightViewConfig()
{

    dateBox.setFillColor(sf::Color::Transparent);
    sfDayValue.setFillColor(sf::Color::Black);
}

void Date::nightViewConfig()
{
    sfDayValue.setFillColor(sf::Color::White);
    dateBox.setFillColor(sf::Color::Transparent);
}

void Date::initOperationsHeader()
{
    //std::cout << "x: " << screenX << ", y: " << screenY << "\n";
    operationsHead.setFont(Fonts::getFont());
    operationsHead.setPosition(screenX+50, screenY+20);
    //operationsHead.setPosition(100, 200);
    operationsHead.setCharacterSize(15);
    std::string s = "(Press 'Enter' to submit/escape.)";
    operationsHead.setString(s);
    sf::Color c(196,196,196);
    operationsHead.setFillColor(c);
}

