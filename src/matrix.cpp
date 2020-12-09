#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <Matrix/matrix.hpp>

using namespace std;

class WrongPoint : public exception {
    virtual const char *what() const throw() {
        return "Podales zle wspolrzedne macierzy!";
    }
};

class WrongSize : public exception {
    virtual const char *what() const throw() {
        return "Podales zly rozmiar macierzy! Rozmiary nie zgadzaja sie!";
    }
};

class FileNoOpen : public exception {
    virtual const char *what() const throw() {
        return "Plik nie zostal otwarty!";
    }
};

    matrix::matrix(int n, int m) {
        a = n;
        b = m;
        tab = new double*[a];
         for(int i = 0; i < a; i++) {
             tab[i] = (double*)calloc(b, sizeof(double));
         }
    }

    matrix::matrix(int n) {
        a = n;
        b = n;
        tab = new double*[a];
         for(int i = 0; i < a; i++) {
             tab[i] = (double*)calloc(b, sizeof(double));
         }
    }

    matrix::matrix(std::string path) {
		std::ifstream plik;
		plik.open(path);
		if (plik.good() != 0) {
			throw FileNoOpen();
		}

		plik >> a;
		plik >> b;

		for (int i = 0; i < a; i++) {

			for (int j = 0; j < b; j++) {

				plik >> tab[i][j];
			}
		}
		plik.close();
	}

    void matrix::set(int x, int y, double val) {

        if ((x < 0 || x > a) || (y < 0 || y > b)) {

            throw WrongPoint();
        }

        tab[x-1][y-1] = val;
    }

    double matrix::get(int x, int y) {

        if ((x < 0 || x > a) || (y < 0 || y >= b)) {
             
            throw WrongPoint();
        }

        return tab[x-1][y-1];
    }

    matrix matrix::add(matrix tablica3) {

        if ((a != tablica3.rows()) || (b != tablica3.cols())) {

            throw WrongSize();
        }

        matrix dodanemacierze(a,b);
            for(int i = 0; i < a; i++) {
                for(int j = 0; j < b; j++){
                    dodanemacierze.tab[i][j] = tab[i][j] + tablica3.tab[i][j];
                }
            }
        return dodanemacierze;
    }

    matrix matrix::substract(matrix tablica3) {

        if ((a != tablica3.rows()) || (b != tablica3.cols())) {
            
            throw WrongSize();
        }

        matrix odjetemacierze(a,b);
            for(int i = 0; i < a; i++) {
                for(int j = 0; j < b; j++){
                    odjetemacierze.tab[i][j] = tab[i][j] - tablica3.tab[i][j];
                }
            }
        return odjetemacierze;
    }

    matrix matrix::multiply(matrix tablica4) {

        if (a != tablica4.rows()) {
            
            throw WrongSize();
        }

        matrix mnozonemacierze(a,b);
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                mnozonemacierze.tab[i][j] = 0;
                for(int k = 0; k < b; k++) {
                    mnozonemacierze.tab[i][j] += tab[i][k] * tablica4.tab[k][j];
                }
                return mnozonemacierze;
            }
        }
    }


    int matrix::rows() {
        //cout << "Liczba wierszy: " << a << endl;
        return a;
    }

    int matrix::cols() {
        //cout << "Liczba kolumn: " << b << endl;
        return b;
    }

    void matrix::print() {
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                cout << tab[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void matrix::store(std::string filename, std::string path) {

        std::ofstream  plik;
		path += "\\" + filename;
		plik.open(path, std::ios_base::out);
		if (!plik.good())
		{
			throw FileNoOpen();
		}

		plik << a << "\t" << b << endl;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
				plik << tab[i][j] << "\t";
			plik << endl;
		}

		plik.close();
	}
