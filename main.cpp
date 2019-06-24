#include <iostream>
#include "familyTree.h"

using namespace std;

int main()
{
    Tree tree;
    Person ek(0, "Erich", "Kainz");
    Person gk(1, "Gabi", "Kainz");
    Person wk(2, "Wolfgang", "Kainz");
    Person hk(3, "Hannes", "Kainz");
    Person mm(4, "Matthias", "Mullner");

    tree.addPerson(&ek);
    tree.addPerson(&gk);
    tree.addPerson(&wk);
    tree.addPerson(&hk);
    tree.addPerson(&mm);

    ek.Add_Parent(1);
    ek.Add_Parent(2);
    hk.Add_Parent(1);

    gk.Add_Child(0);
    wk.Add_Child(0);
    gk.Add_Child(2);


    //tree.printChildren(2);
    //tree.printParents(0);
    //tree.printParents(1);
    //tree.printParents(4);
    tree.printSiblings(0); // Ausgabe nicht 100% okay

    return 0;
}
