#include "person.h"


Person::Person(const int gid, const std::string& forename, const std::string& surname, const int pa_gid, const int pb_gid) : _gid(gid), _forename(forename), _surname(surname), _pa_gid(pa_gid), _pb_gid(pb_gid)
{
    std::vector<int> _c_gids;
}

int Person::getGid() const
{
    return _gid;
}

int Person::getPa() const
{
    return _pa_gid;
}

int Person::getPb() const
{
    return _pb_gid;
}

std::string Person::getName() const
{
    return _forename + " " + _surname;
}

void Person::Add_Parent(const int p_gid)
{
    if(_pa_gid == -1)
    {
        _pa_gid = p_gid;
    }
    else if(_pb_gid == -1)
    {
        _pb_gid = p_gid;
    }
    else
    {
        std::cout << getName() << " hat schon 2 Eltern!" << std::endl;
    }
    return;
}

void Person::Add_Child(const int c_gid)
{
    _c_gids.push_back(c_gid);
    return;
}

std::vector<int> Person::getChildren()
{
    return _c_gids;
}
