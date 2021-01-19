#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <Matrix/matrix.hpp>

using namespace std;


int main() {

    cout << "Tablica (niekwadratowa) zainicjowana zerami:" << endl;
    matrix tablica1(4,5);
    tablica1.print();

    cout << "Tablica (kwadratowa) zainicjowana zerami:" << endl;
    matrix tablica2(4);
    tablica2.print();

    cout << "Funkcja set dla tablicy niekwadratowa:" << endl;
    try {
        tablica1.set(2,1,768);
        tablica1.set(5,5,768);
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }
    tablica1.print();

    cout << "Element, ktory pobrales testujac funkcje get to: ";
    try {
        cout << tablica1.get(2,1) << endl;
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }

    cout << "Suma macierzy tablica1 oraz tablica3:" << endl;
    matrix tablica3(4,5);
    try {
        tablica3.set(2,1,100);
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }
    tablica1.print();
    cout << "+" << endl;
    tablica3.print();
    try {
        matrix dodanemacierze = tablica1 + tablica3;
        cout << "=" << endl;
        dodanemacierze.print();
        cout << "Liczba wierszy: " << tablica1.rows() << endl;
        cout << "Liczba kolumn: " << tablica1.cols() << endl;
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }

    cout << "Odejmowanie tablicy1 i tablicy3:" << endl;
    tablica1.print();
    cout << "-" << endl;
    tablica3.print();
    try {
        matrix odjetemacierze = tablica1 - tablica3;
        cout << "=" << endl;
        odjetemacierze.print();
        cout << "Liczba wiersz: " << odjetemacierze.rows() << endl;
        cout << "Liczba kolumn: " << odjetemacierze.cols() << endl;
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }


    cout << "Mnozenie macierzy tablica5 i tablica4" << endl;
    matrix tablica5(4,4);
    try {
        tablica5.set(1,1,2);
        tablica5.set(1,2,2);
        tablica5.set(1,3,2);
        tablica5.set(1,4,2);
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }

    matrix tablica4(4,4);
    try {
        tablica4.set(1,1,2);
        tablica4.set(2,1,2);
        tablica4.set(3,1,2);
        tablica4.set(4,1,2);
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }

    try {
        tablica5.print();
        cout << "*" << endl;
        tablica4.print();
        matrix mnozonemacierze = tablica5 * tablica4;
        cout << "=" << endl;
        mnozonemacierze.print();
        cout << "Liczba wierszy: " << mnozonemacierze.rows() << endl;
        cout << "Liczba kolumn: " << mnozonemacierze.cols() << endl;
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }

    //cout << "Macierz wypisana operatorem <<:" << endl;
    //cout << tablica3;

    cout << "Porownanie dwoch macierzy operatorem == oraz !=:" << endl;
    
    try {
        if(tablica1 == tablica1) {
            cout << "Macierze sa takie same" << endl;
        }
        if (tablica1 != tablica3) {
            cout << "Macierze sa inne" << endl;
        }
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }

    cout << "Inkrementacja macierzy:" << endl;

    ++tablica3;
    tablica3.print();

    cout << "Deinkrementacja macierzy:" << endl;
    --tablica3;
    tablica3.print();

    cout << "Wypisanie wiersza operatorem []:" << endl;
    tablica3[1];

    cout << "Zapisywanie macierzy do pliku" << endl;
    string nazwa;
    string sciezka;

    cout << "Podaj nazwe pliku, w ktorym chcesz zapisac macierz: ";
    cin >> nazwa;
    cout << "Podaj sciezke do tego pliku: ";
    cin >> sciezka;
    try {
        tablica3.store(nazwa,sciezka);
    }
    catch(const exception& e) {
        std::cerr << e.what() << endl;
    }
    
    return 0;

}