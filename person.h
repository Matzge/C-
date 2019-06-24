#ifndef _person_H_
#define _person_H_

#include <vector>
#include <string>
#include <iostream>

class Person
{
public:
    Person(const int gid, const std::string& forename, const std::string& surname, const int pa_gid = -1, const int pb_gid = -1);
    int getGid() const;
    int getPa() const;
    int getPb() const;
    std::string getName() const;
    void Add_Parent(const int p_gid);
    void Add_Child(const int c_gid);
    std::vector<int> getChildren();
private:
    int _gid;
    const std::string& _forename;
    const std::string& _surname;
    int _pa_gid;  //parent A
    int _pb_gid;   //parent B
    std::vector<int> _c_gids;   //children-gids
};

#endif // _person_H_
