#include <iostream>
#include "familyTree.h"

using namespace std;

int main()
{
    Tree tree;
    //Personen anlegen
    Person hg(0, "Hans", "Gruber");
    Person jb(1, "Julia", "Bauer");
    Person fg(2, "Fritz", "Gruber", 0, 1);
    Person hb(3, "Hannah", "Gruber", 0, 1);
    Person mm(4, "Matthias", "Meier");
    Person kh(5, "Karoline", "Hauser");
    Person fh(6, "Franz", "Hauser", 4, 5);
    Person jh(7, "Johannes", "Hauser", 3, 6);
    Person sh(8, "Sabine", "Hauser", 3, 6);
    Person ah(9, "Andrea", "Hauser", 3, 6);
    Person lm(10, "Lukas", "Mitter");
    Person sm(11, "Sebastian", "Mitter", 8, 10);
    Person ag(12, "Alfred", "Gruber", 2, 15);
    Person gg(13, "Gernot", "Gruber", 2, 15);
    Person lg(14, "Lisa", "Gruber", 2, 15); 
    Person lk(15, "Linda", "Kraft");
    Person mg(16, "Max", "Gruber", 14, 11);
    Person hs(17, "Herbert", "Stark");
    

    //Personen zu Stammbaum hinzufügen
    tree.addPerson(&hg);
    tree.addPerson(&jb);
    tree.addPerson(&fg);
    tree.addPerson(&hb);
    tree.addPerson(&mm);    
    tree.addPerson(&kh);
    tree.addPerson(&fh);
    tree.addPerson(&jh);
    tree.addPerson(&sh);
    tree.addPerson(&ah);
    tree.addPerson(&lm);
    tree.addPerson(&sm);


    cout << "Kinder von 2:" << endl;
    tree.printChildren(2);
    cout << "Kinder von 6:" << endl;
    tree.printChildren(6);
    cout << "Eltern von 8:" << endl;
    tree.printParents(8);
    cout << "Geschwister von 9:" << endl;
    tree.printSiblings(9); // Ausgabe nicht 100% okay

    return 0;
}
