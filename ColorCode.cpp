//
// Created by hello on 10/6/2021.
//

#include "ColorCode.h"

sf::Color ColorCode::getColor(std::string word) {
    std::string numbers = "0123456789";
    //When the words int, char, double and float are typed, the color of the word changes to blue
    if(word=="int" || word=="char" || word=="double" || word=="float")
    {
        //std::cout << "keyword\n";
        return sf::Color::Blue;
    }
    //When an operator is typed, it is changed to green
    else if(word=="+" || word=="-" || word=="*" || word=="/")
    {
        //std::cout << "operator\n";
        return sf::Color::Green;
    }
    //When a number is typed, it is changed to red
    else if(numbers.find(word)<numbers.length() && numbers.find(word)>=0)
    {
        //std::cout << "number\n";
        return sf::Color::Red;
    }
    else
    {
        //std::cout << "regular\n";
        return sf::Color::White;
    }
}

void ColorCode::changeColor(MultiText::iterator& begin, MultiText::iterator& end)
{
    MultiText::iterator walker = begin;
    std::string result = "";
    MultiText::iterator wordBegin = begin;
    while(walker!=end)
    {

        while(walker!=end && (*walker).getCharacter()!=" ")
        {
            result += (*walker).getCharacter();
            ++walker;
        }
        //if(result.length()>0 && getColor(result)!=sf::Color::White)
        if(result.length()>0)
        {
            //std::cout << "result: " << result << std::endl;
            MultiText::iterator walker2;
            for(walker2=wordBegin;walker2!=walker;++walker2) {
                (*walker2).setCharacterColor(getColor(result));
            }
            result = "";
            //next word checking begins..
            if(walker!=end)
                ++walker;
            wordBegin = walker;
        }
    }

}

std::string ColorCode::gC(std::string word) {
    std::string numbers = "0123456789";
    //When the words int, char, double and float are typed, the color of the word changes to blue
    if(word=="int" || word=="char" || word=="double" || word=="float")
    {
        //std::cout << "keyword\n";
        return "blue";
    }
        //When an operator is typed, it is changed to green
    else if(word=="+" || word=="-" || word=="*" || word=="/")
    {
        //std::cout << "operator\n";
        return "green";
    }
        //When a number is typed, it is changed to red
    else if(numbers.find(word)<numbers.length() && numbers.find(word)>=0)
    {
        //std::cout << "number\n";
        return "red";
    }
    else
    {
        //std::cout << "regular\n";
        return "white";
    }
}

//ColorCode::ColorCode()
//{
////    keywords["int"] = sf::Color::Blue;
////    keywords["float"] = sf::Color::Blue;
////    keywords[""] = sf::Color::;
////    keywords[""] = sf::Color::;
////    keywords[""] = sf::Color::;
////    keywords[""] = sf::Color::;
////    keywords[""] = sf::Color::;
////    keywords[""] = sf::Color::;
////    keywords[""] = sf::Color::;
////    keywords[""] = sf::Color::;
////    keywords[""] = sf::Color::;
////    keywords[""] = sf::Color::;
//
//}


//    for(walker=begin;walker!=end;++walker)
//    {
//        if((*walker).getCharacter()!=" ")
//            result += (*walker).getCharacter();
//        //std::cout << "result: " << result << ", color: " << gC(result) << std::endl;
//        if(result.length()>0 && getColor(result)!=sf::Color::White)
//        {
//            //std::cout << "result: " << result << std::endl;
//            MultiText::iterator walker2;
//            for(walker2=wordBegin;walker2!=walker;++walker2)
//            {
//                (*walker2).setCharacterColor(getColor(result));
//            }
//            (*walker2).setCharacterColor(getColor(result));
//            result = "";
//            ++walker2;
//            //next word checking begins..
//            wordBegin = walker2;
//        }
//    }