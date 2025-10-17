#include "Animal.h"
#include "PairsLL.h"

#include <iostream>
using namespace std;

int main(void) {
    Animal a{"Aardvark", 100, false};
    Animal b{"Bear", 1000, true};
    Animal c{"Crocodile", 600, true};
    Animal d{"Deer", 80, false};
    Animal e{"Elephant", 800, true};
    Animal f{"Frog", 1, false};

    PairsLL ark1;

    if (ark1.isEmpty()) {
        cout << "ark1 is empty" << endl;
    } else {
        cout << "ark1 is not empty" << endl;
    }

    ark1.board(a);
    ark1.board(b);
    ark1.board(a);

    if (ark1.isEmpty()) {
        cout << "ark1 is empty" << endl;
    } else {
        cout << "ark1 is not empty" << endl;
    }

    /* This code should print out all of the animals in the list ark1.
     * Does it work with your implementation?
     * Does your implementation store the animals in the right order?
     * Pay attention to these questions the other times we print out the list.
     */
    cout << "Printing ark1" << endl;
    ark1.reset();
    while (!ark1.done()) {
        cout << "[" << ark1.next() << "]";
    }

    ark1.board(c);
    ark1.board(d);
    ark1.board(e);
    ark1.board(f);
    ark1.board(e);

    cout << "Paired animals in ark1:" << endl;
    ark1.show(false);

    ark1.board(d);
    ark1.board(b);

    unsigned short i = ark1.dismiss("Elephant");
    cout << "Dismissed " << i << " elephant(s)" << endl;

    cout << "Printing ark1" << endl;
    ark1.show();

    ark1.board(e);
    PairsLL ark2{ark1};
    cout << "Printing ark1" << endl;
    ark1.show();
    cout << "Printing ark2" << endl;
    ark2.show();

    ark1.disembark();

    ark2.board(c);
    ark2.board(d);
    ark2.board(f);

    if (ark1.isEmpty()) {
        cout << "ark1 is empty" << endl;
    } else {
        cout << "ark1 is not empty" << endl;
    }
    cout << "Printing ark1" << endl;
    ark1.show();
    cout << "Printing ark2" << endl;
    ark2.show();

    ark1.board(a);
    ark1.board(f);
    ark1.board(c);
    ark1.board(a);

    cout << "Paired animals in ark1:" << endl;
    ark1.show(false);

    PairsLL ark3, ark4, ark5;
    ark3.board(b);
    ark3.board(b);
    ark3.board(c);
    ark3.board(c);
    ark3.board(e);
    ark3.board(f);
    ark4.board(b);
    ark4.board(a);
    ark4.board(c);
    ark5.board(c);
    ark5.board(e);
    ark5.board(f);

    cout << "Printing ark3" << endl;
    ark3.show();
    cout << "Printing ark4" << endl;
    ark4.show();
    cout << "Printing ark5" << endl;
    ark5.show();

    ark1.join(ark2);
    cout << "Printing ark1" << endl;
    ark1.show();

    ark5.join(ark5, true);
    cout << "Printing ark5" << endl;
    ark5.show();

    ark4.join(ark5, true);
    cout << "Printing ark4" << endl;
    ark4.show();
    cout << "Printing ark5" << endl;
    ark5.show();

    ark3.join(ark3);
    cout << "Printing ark3" << endl;
    ark3.show();
}
