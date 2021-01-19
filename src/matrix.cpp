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

        if (x <= rows() && x > 0 && y <= cols() && y > 0) {
             
            return tab[x-1][y-1];
        }
        else {
            throw WrongPoint();
        }
        
    }

    matrix matrix::operator+(matrix &add) {

        if ((a != add.rows()) || (b != add.cols())) {

            throw WrongSize();
        }

        matrix dodanemacierze(a,b);
            for(int i = 0; i < a; i++) {
                for(int j = 0; j < b; j++){
                    dodanemacierze.tab[i][j] = tab[i][j] + add.tab[i][j];
                }
            }
        return dodanemacierze;
    }

    matrix matrix::operator-(matrix &susbtract)  {

        if ((a != susbtract.rows()) || (b != susbtract.cols())) {
            
            throw WrongSize();
        }

        matrix odjetemacierze(a,b);
            for(int i = 0; i < a; i++) {
                for(int j = 0; j < b; j++){
                    odjetemacierze.tab[i][j] = tab[i][j] - susbtract.tab[i][j];
                }
            }
        return odjetemacierze;
    }

    matrix matrix::operator*(matrix &multiply) {

        if (a != multiply.rows()) {
            
            throw WrongSize();
        }

        matrix mnozonemacierze(a,b);
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                mnozonemacierze.tab[i][j] = 0;
                for(int k = 0; k < b; k++) {
                    mnozonemacierze.tab[i][j] += tab[i][k] * multiply.tab[k][j];
                }
            }
        }
        return mnozonemacierze;
    }
/*
    ostream& operator<<(std::ostream &file, matrix &tablica) {
        
        int a = tablica.rows();
        int b = tablica.cols();

        file << a << " " << b << endl;
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                file << tablica[i][j];
                file << " ";
            }
            file << endl;
        }
        return file;
    } */

    bool matrix::operator==(matrix &porow) {

        int a = rows();
        int b = cols();
    
        if ((a != porow.rows()) || (b != porow.cols())) {
        
            throw WrongSize();
        }

        for(int i = 1; i <= a; i++) {
            for(int j = 1; j <= b; j++) {

                if(this->get(i, j) != porow.get(i, j)) {
                    return false;
            }
        }
    }
    return true;
}


    bool matrix::operator!=(matrix &porow) {

        int a = rows();
        int b = cols();
    
        if((a != porow.rows()) || (b != porow.cols())) {
        
            throw WrongSize();
        }

        for(int i = 1; i <= a; i++) {
            for(int j = 1; j <= b; j++) {

                if(this->get(i, j) != porow.get(i, j)) {
                    return true;
            }
        }
    }
    return false;
}

    matrix matrix::operator++() {
    
        for(int i = 1; i <= rows(); i++) {
            for(int j = 1; j <= cols(); j++) {
                double inkrementacja = (1 + get(i,j));
                set(i,j,inkrementacja);
            }
        }
    }

    matrix matrix::operator--() {

        for(int i = 1; i <= rows(); i++) {
            for(int j = 1; j <= cols(); j++) {
                double deinkrementacja = (get(i,j) - 1);
                set(i,j,deinkrementacja);
            }
        }        
    }


    void matrix::operator[](int row)  {

        if (row >= this->rows() || row < 0) {
            
            throw WrongSize();
        } else {
            for (int i = 0; i < cols(); i++) {
                cout << tab[row][i] << " ";
        }
            cout << endl;
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
