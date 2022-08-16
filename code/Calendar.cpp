//
// Created by hello on 11/22/2021.
//

#include "Calendar.h"

int Calendar::imgCount = 1;

void Calendar::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(menuBar);
    //std::string s = dropdownMonth.getDropdownMenuChoice();
    window.draw(sprite);
//    texture.draw(*months.at(monthChoice));
//    //window.draw(month);
//    texture.draw(dropdownMonth);


}

void Calendar::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    menuBar.addEventHandler(window, event);

    if(menuBar.isEnabled(CLICKED))
    {
        menuBarClicked = menuBar.getClicked();
        //std::cout << menuBarClicked << " clicked\n";
        performMenuBarAction(window, menuBarClicked);
        menuBar.disableState(CLICKED);

    }
    //std::string prevChoice = dropdownMonth.getDropdownMenuChoice();
    dropdownMonth.addEventHandler(window,event);
    monthChoice = dropdownMonth.getDropdownMenuChoice();
   // month.addEventHandler(window,event);
    if(months[monthChoice]!=nullptr)
        months[monthChoice]->addEventHandler(window, event);
}

//TODO if month is changed while the Date FileTree is showing, also if changed, and go back to the original month(by undo or otherway),
//then reset to Calendar view(with all dates showing)
void Calendar::update()
{
    menuBar.update();
    //update days of the week and days of the month based on the month chosen from dropdown
    //month.updateMonth(monthNIndex[dropdownMonth.getDropdownMenuChoice()],2022);
    if(months[dropdownMonth.getDropdownMenuChoice()]==nullptr)
    {
        months[dropdownMonth.getDropdownMenuChoice()] = new Month(monthNIndex[dropdownMonth.getDropdownMenuChoice()], 2022, 1000, 600 );
        if(!this->isEnabled(NIGHTVIEW))
        {
            months.at(dropdownMonth.getDropdownMenuChoice())->setLightView();
        }
        //months[dropdownMonth.getDropdownMenuChoice()]->updateMonth(monthNIndex[dropdownMonth.getDropdownMenuChoice()],2022);
        //month.updateMonth(monthNIndex[dropdownMonth.getDropdownMenuChoice()],2022);
    }
    monthChoice = dropdownMonth.getDropdownMenuChoice();
    if(months[dropdownMonth.getDropdownMenuChoice()]!=nullptr)
    {
        months[dropdownMonth.getDropdownMenuChoice()]->update();
    }
    //pas param

    texture.clear(sf::Color::Transparent);
    texture.draw(sfTitle);
    texture.draw(*months.at(monthChoice));
    //window.draw(month);
    texture.draw(dropdownMonth);
    texture.display();
    //month.update();
}

Snapshot &Calendar::getSnapshot() {
    //return <#initializer#>;
}

void Calendar::applySnapshot(const Snapshot &snapshot) {

}

void Calendar::setMonthPosition(float windowWidth, float windowHeight)
{
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;

    float x = 0.026*windowWidth;
    float y = 0.26*windowHeight;

    menuBar.setPosition(0, 0);

    //set the size of screen
    months[dropdownMonth.getDropdownMenuChoice()]->setMonthScreenSize((windowWidth-2*x),0.71*windowHeight); // 0.03*windowHeight now becomes bottom padding

    float dpdX = this->windowWidth/2.0 - dropdownMonth.getInputBoxBounds().width/2;
    float dpdY = y-dropdownMonth.getInputBoxBounds().height;

    float titleX = this->windowWidth/2.0 - sfTitle.getGlobalBounds().width/2.0;
    float titleY = dpdY-2.5*sfTitle.getCharacterSize();
    sfTitle.setPosition(titleX,titleY);

    dropdownMonth.setPosition(dpdX, dpdY);
    //position the sized screen
    months[dropdownMonth.getDropdownMenuChoice()]->setPosition(x,y);
}

Calendar::Calendar()
{
    //menuBar initialization
    initMenubar();
    //dropdownmenu initialization
    initializeDropdown();
    monthChoice = "January";
    months[monthChoice] = new Month(1,2022,1000,600);
    //months[dropdownMonth.getDropdownMenuChoice()] = new Month(1,2022,1000,1000);


    initMonthNIndex();
    setMonthPosition(1000,600);

    //dropdown of month position relative to the screen
    //dropdownMonth.setPosition(windowWidth/2-(dropdownMonth.getInputBoxBounds().width/2.0),
    //                          months[dropdownMonth.getDropdownMenuChoice()]->getGlobalBounds().top-2*dropdownMonth.getInputBoxBounds().height);
    //default position
    menuBar.setPosition(200, 0);
    dropdownMonth.setPosition(200, 100);
}

void Calendar::initializeDropdown()
{
    dropdownMonth.setDropdownMenuName("January");
    dropdownMonth.addItem("January");
    dropdownMonth.addItem("February");
    dropdownMonth.addItem("March");
    dropdownMonth.addItem("April");
    dropdownMonth.addItem("May");
    dropdownMonth.addItem("June");
    dropdownMonth.addItem("July");
    dropdownMonth.addItem("August");
    dropdownMonth.addItem("September");
    dropdownMonth.addItem("October");
    dropdownMonth.addItem("November");
    dropdownMonth.addItem("December");


}

void Calendar::initMonthNIndex()
{
    monthNIndex["January"] = 1;
    monthNIndex["February"] = 2;
    monthNIndex["March"] = 3;
    monthNIndex["April"] = 4;
    monthNIndex["May"] = 5;
    monthNIndex["June"] = 6;
    monthNIndex["July"] = 7;
    monthNIndex["August"] = 8;
    monthNIndex["September"] = 9;
    monthNIndex["October"] = 10;
    monthNIndex["November"] = 11;
    monthNIndex["December"] = 12;
}

void Calendar::initMenubar()
{

    menuBar.addMenu("File");
    menuBar.addMenu("Edit");

    menuBar.addMenu("View");


    menuBar.addItemtoMenu("File" , "Save as .png");
    menuBar.addItemtoMenu("File" , "Light view");
    menuBar.addItemtoMenu("File" , "Night view");

    menuBar.addItemtoMenu("Edit" , "Undo");
    menuBar.addItemtoMenu("Edit" , "Redo");


    menuBar.addItemtoMenu("View" , "Tasks");
    menuBar.addItemtoMenu("View" , "Birthdays");
    menuBar.addItemtoMenu("View" , "Both");

    menuBar.setTextSize(15);
}

Calendar::Calendar(sf::Color& back, float windowWidth, float windowHeight)
{
    this->enableState(NIGHTVIEW);
    background = &back;
    title="Calendar 2022";
    sfTitle.setFont(Fonts::getFont());
    sfTitle.setCharacterSize(20);
    sfTitle.setString(title);
    sf::Color c(234,191,50);
    sfTitle.setFillColor(c);
    //menuBar initialization
    initMenubar();
    //dropdownmenu initialization
    initializeDropdown();
    monthChoice = "January";
    months[monthChoice] = new Month(1,2022,windowWidth,windowHeight);
    //months[dropdownMonth.getDropdownMenuChoice()] = new Month(1,2022,1000,1000);

    initMonthNIndex();
    setMonthPosition(windowWidth,windowHeight);

    //dropdown of month position relative to the screen
    //dropdownMonth.setPosition(windowWidth/2-(dropdownMonth.getInputBoxBounds().width/2.0),
    //                          months[dropdownMonth.getDropdownMenuChoice()]->getGlobalBounds().top-2*dropdownMonth.getInputBoxBounds().height);
    //default position
    //menuBar.setPosition(200, 0);
    //dropdownMonth.setPosition(200, 100);

    //setNightView();

    texture.create(windowWidth,windowHeight-menuBar.getTitleBounds().height);
    setSpriteView();


}

void Calendar::performMenuBarAction(sf::RenderTarget& window, std::string action)
{
    //File --> Save as .png, Light View, Night View
    //Edit --> Undo, Redo
    //View --> Tasks, Birthdays, Both
    if(action == "Save as .png")
    {
        sf::Image img = sprite.getTexture()->copyToImage();
        std::string path = "Images/img" + std::to_string(imgCount) + ".png";
        img.saveToFile(path);
        Calendar::imgCount += 1;

    }
    else if(action == "Light view")
    {
        this->disableState(NIGHTVIEW);
        sf::Color c(153,96,0);
        sfTitle.setFillColor(c);
         //window.clear(sf::Color::White);
         // menubar --> (209,209,209), text black
         menuBar.setLightView();
         // dropdown --> (209,209,209), text black
         dropdownMonth.setLightView();

         // dates --> transparent box & black text
         // monthscreen --> (209,209,209)
         for(auto iter=months.begin();iter!=months.end();++iter)
         {
             if(iter->second!= nullptr)
             {
                 iter->second->setLightView();
             }
         }

    }
    else if(action == "Night view")
    {
        this->enableState(NIGHTVIEW);
        sf::Color c(234,191,50);
        sfTitle.setFillColor(c);
        // menubar --> (112, 107, 105), text white
        menuBar.setNightView();
        // dropdown --> (112, 107, 105), text white
        dropdownMonth.setNightView();

        // dates --> transparent box & white text
        // monthscreen --> black
        for(auto iter=months.begin();iter!=months.end();++iter)
        {
            if(iter->second!= nullptr)
            {
                iter->second->setNightView();
            }
        }
    }
    else if(action == "Undo")
    {

    }
    else if(action == "Redo")
    {

    }
    else if(action == "Tasks")
    {
        if(months[monthChoice]!=nullptr)
            months[monthChoice]->highlightTasks();
    }
    else if(action == "Birthdays")
    {
        if(months[monthChoice]!=nullptr)
            months[monthChoice]->highlightBirthdays();
    }
    else if(action == "Both")
    {
        if(months[monthChoice]!=nullptr)
        {
            months[monthChoice]->higlightBoth();
        }
    }

    menuBar.setClicked("");
}

void Calendar::setSpriteView()
{
    //texture.create()
    sprite.setTexture(texture.getTexture());
    //sprite.setScale();
}
