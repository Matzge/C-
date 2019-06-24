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
    Person* getPerson(const int gid) const;
    void printChildren(const int gid) const;
    void printParents(const int gid) const;
    void printSiblings(const int gid) const;
    void printGrandparents(const int gid) const;
    void printUncle(const int gid) const;
private:
    std::vector<Person*> _gids;

};

#endif // _familyTree_H_
