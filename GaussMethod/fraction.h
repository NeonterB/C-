//
// Created by barka on 2/19/2020.
//

#ifndef GAUSSMETHOD_FRACTION_H
#define GAUSSMETHOD_FRACTION_H


#include <iostream>
#include <string>

using namespace std;

class fraction {
    friend ostream &operator<<(ostream &, const fraction &);

    friend istream &operator>>(istream &, fraction &);

private:
    int up, down;

    void simplify();

public:
    fraction();

    explicit fraction(int);

    fraction(int, int);

    fraction(const fraction &);

    static int gcd(int, int);

    fraction getReverse();

    fraction operator+(const fraction &);

    fraction operator-(const fraction &);

    fraction operator*(const fraction &);

    fraction operator/(const fraction &);

    bool operator==(const fraction &) const;

    bool operator!=(const fraction &) const;
};


#endif //GAUSSMETHOD_FRACTION_H
