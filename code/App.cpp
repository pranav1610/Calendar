//
// Created by hello on 12/1/2021.
//

#include "App.h"

void App::run()
{
    //Video mode below in {} can also be done as a seperate object as follows:
    //sf::VideoMode v(720,420,32);
    sf::RenderWindow window({1000,600,32}, "Calendar_GUI");
    window.setFramerateLimit(60);

    //sf::RenderTexture texture;
    //texture.create(1000,600);

    //sf::Sprite sprite;


    //sprite.setTexture(texture.getTexture());

    //sf::Image img = texture.getTexture().copyToImage();

    //img.saveToFile()

//    Calendar calendar;
//    calendar.setMonthPosition(window.getSize().x, window.getSize().y);
    Calendar calendar(background, window.getSize().x, window.getSize().y);

    //Month month(3, 2022, 1000, 600);

    //TextInput input;


    //window.setKeyRepeatEnabled(false);

    //Date date1;
    //Date date1(27, 3, 2022, {50,50});

//    FileTree tree;
//    tree.setPosition(50,50);
//    tree.push("27", "Tasks");
//    tree.push("27", "Birthdays");
//    //tree.push("dir 1", "c2");
//    tree.push("Tasks", "add");
//    //tree.push("add", "");
//    tree.push("Tasks", "remove");
//    tree.push("Birthdays", "add");
//    tree.push("Birthdays", "remove");
//    //TODO c2 doesnt move down
//    tree.push("c111", "file1");
//    tree.push("c111", "file2");
//    tree.push("c1", "c112");
//    tree.push("c1", "c113");

    //std::cout << "running\n";

    while(window.isOpen())
    {
        //std::cout << "running\n";
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }
            //input.addEventHandler(window,event);
            //tree.addEventHandler(window, event);
            //date1.addEventHandler(window, event);
            calendar.addEventHandler(window,event);

            //month.addEventHandler(window, event);
            History::addEventHandler(window,event);
        }
        //input.update();
        //tree.update();
        calendar.update();
        //month.update();
        //date1.update();
        //sf::Color c(sf::Color::White);
        window.clear(getBackground(calendar));
        //window.draw(tree);
        window.draw(calendar);
        //window.draw(month);
        //window.draw(date1);
        //window.draw(input);
        window.display();
    }
}

sf::Color App::getBackground(Calendar& cal)
{
    if(cal.isEnabled(NIGHTVIEW))
    {
        return sf::Color::Black;
    }
    else
    {
        return sf::Color::White;
    }
}
