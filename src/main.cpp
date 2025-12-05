#include <iostream>
#include "Array.h"
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"
using namespace std;

void printMenu() {
    cout << "\nPrikoli v nalichii\n";
    cout << "1. dobavitb kvadrate\n";
    cout << "2. dobavitb pryamougolnika\n";
    cout << "3. dobavitb trapecii\n";
    cout << "4. pokazatb vse figure\n";
    cout << "5. Obshi ploshad\n";
    cout << "6. Udalit figure po indeksu\n";
    cout << "0. There is no escape\n";
    cout << "Nu che tam?: ";
}

int main() {
    Array arr;
    int cmd;

    cout << "programe rabota s figurame\n";

    while (true) {
        printMenu();
        if (!(cin >> cmd)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Durachek?\n";
            continue;
        }

        if (cmd == 0) {
            cout << "Thy end is now\n";
            break;
        }

        if (cmd == 1) {
            cout << "Centr (x y) i storana: ";
            Square* sq = new Square();
            try {
                cin >> *sq;
                arr.add(sq);
                cout << "kvadrat imeeca\n";
            } catch (const exception& e) {
                delete sq;
                cout << "oshibke: " << e.what() << "\n";
            }
        }
        else if (cmd == 2) {
            cout << "Centr (x y), shririna i visota: ";
            Rectangle* r = new Rectangle();
            try {
                cin >> *r;
                arr.add(r);
                cout << "pryamougolnik v nalicii\n";
            } catch (const exception& e) {
                delete r;
                cout << "oshibke: " << e.what() << "\n";
            }
        }
        else if (cmd == 3) {
            cout << "Centre (x y), verhnee osnov, nijnee, visota: ";
            Trapezoid* t = new Trapezoid();
            try {
                cin >> *t;
                arr.add(t);
                cout << "trapecia da\n";
            } catch (const exception& e) {
                delete t;
                cout << "Oshibke: " << e.what() << "\n";
            }
        }
        else if (cmd == 4) {
            if (arr.size() == 0) {
                cout << "Figure ne bude..\n";
            } else {
                cout << "\n--- Figurki) ---\n";
                arr.printAll(cout);
            }
        }
        else if (cmd == 5) {
            cout << "Jilaya ploshad (figure): " << arr.totalArea() << "\n";
        }
        else if (cmd == 6) {
            cout << "Index?: ";
            size_t idx;
            if (cin >> idx) {
                try {
                    arr.remove(idx);
                    cout << "💥\n";
                } catch (const exception& e) {
                    cout << "oshibke: " << e.what() << "\n";
                }
            } else {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "duralei?\n";
            }
        }
        else {
            cout << "Russkiy tvoy rodnoy yazik?\n";
        }
    }

    return 0;
}
