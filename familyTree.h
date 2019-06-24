#ifndef _familyTree_H_
#define _familyTree_H_

#include <iostream>
#include <vector>
#include "person.h"

class Tree
{
public:
    Tree();
    void addPerson(Person* person);
    Person* getPerson(const int gid);
    void printChildren(const int gid);
    void printParents(const int gid);
    void printSiblings(const int gid);
private:
    std::vector<Person*> _gids;

};

#endif // _familyTree_H_
