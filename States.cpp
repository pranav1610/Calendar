//
// Created by hello on 10/3/2021.
//

#include "States.h"

States::States()
{
    for(int i=0;i<LASTSTATE;i++)
    {
        states[static_cast<ObjectStates>(i)] = false;
    }
}

bool States::isEnabled(ObjectStates state) const
{
    return states.at(state)==true;
}

void States::enableState(ObjectStates state) {
    states[state] = true;
}

void States::disableState(ObjectStates state) {
    states[state] = false;
}
