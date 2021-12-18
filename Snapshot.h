//
// Created by hello on 10/3/2021.
//

#ifndef LETTER_CPP_SNAPSHOT_H
#define LETTER_CPP_SNAPSHOT_H

#include <iostream>
#include <string>
//#include "SnapshotInterface.h"

class Snapshot{
private:
    std::string objectInfo;
public:
    std::string getObjectInfo();

    void setObjectInfo(std::string info);

//    // this function will return a snapshot of the object's current state
//    virtual Snapshot& getSnapshot();
//
//    // this function will apply a snapshot to the object.
//    //This will revert the object back to the state that has been recorded in the snapshot
//    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //LETTER_CPP_SNAPSHOT_H
