#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>

class matrix {

    double **tab;
    int a, b;

    public:

    matrix(int n, int m);
    matrix(int n);
    matrix(std::string path);
    void set(int x, int y, double val);
    double get(int x, int y);
    matrix operator+(matrix &add);
    matrix operator-(matrix &susbtract);
    matrix operator*(matrix &multiply);
    //friend ostream& operator<<(std::ostream &file, matrix &tablica);
    bool operator==(matrix&);
    void operator[](int row);
    bool operator!=(matrix&);
    matrix operator++();
    matrix operator--();
    int rows();
    int cols();
    void print();
    void store(std::string filename, std::string path);

};

#endif