#include <iostream>
#include "familyTree.h"

using namespace std;

int main()
{
    Tree tree;
    Person hg(0, "Hans", "Gruber");
    Person jb(1, "Julia", "Bauer");
    Person fg(2, "Fritz", "Gruber");
    Person hb(3, "Hannes", "Bauer");
    Person mm(4, "Matthias", "Mullner");

    tree.addPerson(&hg);
    tree.addPerson(&jb);
    tree.addPerson(&fg);
    tree.addPerson(&hb);
    tree.addPerson(&mm);

    fg.Add_Parent(0);
    fg.Add_Parent(1);
    hb.Add_Parent(1);

    hg.Add_Child(2);
    jb.Add_Child(2);
    jb.Add_Child(3);


    //tree.printChildren(2);
    //tree.printParents(0);
    //tree.printParents(1);
    //tree.printParents(4);
    tree.printSiblings(0); // Ausgabe nicht 100% okay

    return 0;
}
