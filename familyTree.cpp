#include "familyTree.h"

Tree::Tree()
{
    std::vector<Person*> _gids;
}

void Tree::addPerson(Person* person)
{
    _gids.push_back(person);
    if(person->getPa() != -1)
    {
        Person* p = _gids[person->getPa()];
        p->Add_Child(person->getGid());
    }
    if(person->getPb() != -1)
    {
        Person* p = _gids[person->getPb()];
        p->Add_Child(person->getGid());
    }
    return;
}

Person* Tree::getPerson(const int gid)
{
    return _gids[gid];
}

void Tree::printChildren(const int gid)
{
    Person* person = getPerson(gid);
    std::vector<int> c_gids = person->getChildren();
    if(!c_gids.empty())
    {
        for(unsigned int i = 0; i < c_gids.size(); ++i)
        {
            Person* p = getPerson(c_gids[i]);
            std::cout <<p->getName() << std::endl;
        }
    }
    return;
}

void Tree::printParents(const int gid)
{
    Person* person = getPerson(gid);
    if(person->getPa()!= -1)
    {
        Person* p = getPerson(person->getPa());
        std::cout <<p->getName() << std::endl;
    }
    if(person->getPb()!= -1)
    {
        Person* p = getPerson(person->getPb());
        std::cout <<p->getName() << std::endl;
    }

    return;
}

void Tree::printSiblings(const int gid)
{
    Person* person = getPerson(gid);
    std::vector<int> siblings;
    //Eltern finden
    if(person->getPa()!= -1)
    {
        siblings = getPerson(person->getPa())->getChildren();
    }
    else if(person->getPb()!= -1)
    {
        siblings = getPerson(person->getPb())->getChildren();
    }


    //Ausgabe
    if(siblings.size() >= 2)
    {
        int anzahl = siblings.size()-1;   //-1 weil die Person selbst ja auch ein Kind ist
        std::cout << person->getName() << " hat " << anzahl << " Geschwister:" << std::endl;
        for(unsigned int i = 0; i<siblings.size(); ++i)
        {
            if (getPerson(siblings[i]) != person)
                std::cout <<getPerson(siblings[i])->getName() << std::endl;
        }
    }
    else
    {
        std::cout << person->getName() << " hat keine Geschwister oder sie sind unbekannt." << std::endl;
    }
    return;
}

void Tree::printGrandparents(const int gid)
{
    Person* person = getPerson(gid);
    std::vector<int> gp;    //grandparents
    if(person->getPa() != -1 || person->getPb() != -1)
    {  
        if(person->getPa() != -1)
        {
            Person* pa = getPerson(person->getPa());
            if(pa->getPa() != -1)
            {
                gp.push_back(pa->getPa());
            }
            if(pa->getPb() != -1)
            {
                gp.push_back(pa->getPb());
            }
        }
        if(person->getPb() != -1)
        {
            Person* pb = getPerson(person->getPb());
            if(pb->getPa() != -1)
            {
                gp.push_back(pb->getPa());
            }
            if(pb->getPb() != -1)
            {
                gp.push_back(pb->getPb());
            }
        }
        std::cout << person->getName() << " hat " << gp.size() << " Großeltern:" << std::endl;
        for(unsigned int i = 0; i < gp.size(); ++i)
        {
            std::cout << getPerson(gp[i])->getName() << std::endl;
        }
    else
    {
        std::cout << person->getName() << " hat keine bekannten Großeltern." << std::endl;
    }
    return;
}

void Tree::printUncle(const int gid)
{
    Person* person = getPerson(gid);
    if(person->getPa() != -1 || person->getPb() != -1)
    {
        if(person->getPa() != -1)
        {
            printSiblings(person->getPa());
        }
        if(person->getPb() != -1)
        {
            printSiblings(person->getPb());
        }
    }
    return;
}
