//
// Created by hello on 10/3/2021.
//

#ifndef LETTER_CPP_STATES_H
#define LETTER_CPP_STATES_H

#include <map>
#include "ObjectStates.h"

class States{
private:
    std::map<ObjectStates, bool> states;
public:
    States();
    //Check if a particular state is enabled
     //prof's : bool isEnabled(ObjectStates state) const;
    bool isEnabled(ObjectStates state) const;
    //Enable a state
    void enableState(ObjectStates state);
    //Disable a state
    void disableState(ObjectStates state);
};


#endif //LETTER_CPP_STATES_H
