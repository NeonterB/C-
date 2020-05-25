#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "fraction.h"
#include "Vector.h"

int main() {
    std::cout << "Enter enter the number of variables:";
    int n = 3;
    std::cin >> n;

    std::vector<std::vector<fraction>> A(n, std::vector<fraction>(n + 1));
    std::cout << "Enter all odds:\n";
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            fraction num;
            std::cout << "A[" << i << "][" << j << "]:";
            std::cin >> num;
            A[i][j] = num;
        }
    }
    std::cout << '\n';

    for (auto &i:A) {   //Вывод матрицы
        for (const auto &j :i) {
            std::cout << setw(n * 3) << j;
        }
        std::cout << "\n";
    }

    std::cout << "\n\n";

    if (A[0][0] == fraction()) {
        for (int i = 0; i < A.size(); i++) {
            if (A[i][0] != fraction()) {
                std::swap(A[0], A[i]);
                break;
            }
        }
    }

    if (A[0][0] == fraction()) {
        std::cerr << "0 Column is Zero-Column!\n";
        return 0;
    }

    fraction neg(-1);

    for (int i1 = 0; i1 < n - 1; i1++) {
        if (A[i1][i1] == fraction()){
            for (int i = i1; i < A.size(); i++) {
                if (A[i][i1] != fraction()) {
                    std::swap(A[i1], A[i]);
                    break;
                }
            }
        }

        if (A[i1][i1] == fraction()) {
            std::cerr << i1 << " Column is Zero-Column!\n";
            return 0;
        }

        for (int i2 = i1 + 1; i2 < n; i2++) {
            A[i2] = Vector::add(A[i2], Vector::multiply(A[i1], (A[i2][i1] * neg / A[i1][i1])));
        }
    }

    int n2 = n;
    std::vector<fraction> zeroLine(n + 1);

    while (true) {   // Удаляю пустые строки
        auto ind = std::find(A.begin(), A.end(), zeroLine);

        if (ind == A.end()) {
            n2 = A.size();
            if (n2 == n) break;

            std::cout << "Endless solutions\n\n";


            std::vector<fraction> baseValues(0);

            for (int i = n2 - 1; i >= 0; i--) {
                if (!baseValues.empty()) {
                    fraction variable(A[i][n]);

                    for (int j = n - n2 + 1; j > i; j--) {
                        variable = variable - A[i][j] * baseValues[baseValues.size() + i - j];
                    }
                    baseValues.push_back(variable / A[i][i]);
                } else {
                    baseValues.push_back(A[i][n] / A[i][i]);
                }
            }

            std::cout << "One of solutions: (";
            for (int i = baseValues.size() - 1; i >= 0; i--) {

                std::cout << baseValues[i] << ", ";
            }
            for (int i = 0; i < n - baseValues.size(); i++) {
                std::cout << "0";
                if (i != n - baseValues.size() - 1) {
                    std::cout << ", ";
                }

            }
            std::cout << ")\n";
            return 0;
        } else {
            A.erase(ind);
        }
    }


    if (A.size() == n) {
        for (int i1 = n - 1; i1 >= 0; i1--) {
            if (A[i1][i1] == fraction()) continue;

            A[i1] = Vector::multiply(A[i1], A[i1][i1].getReverse());

            if (i1 > 0) {
                for (int i2 = i1 - 1; i2 >= 0; i2--) {
                    A[i2] = Vector::add(A[i2], Vector::multiply(A[i1], (A[i2][i1] * neg / A[i1][i1])));
                }
            }
        }

        std::cout << "Solutions: (";
        for (int i = 0; i < n2; i++) {
            std::cout << A[i][n];
            if (i != n2 - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")\n";
    }

    std::cout << "\n\n\n";

    for (auto &i : A) {   //Вывод матрицы
        for (const auto &j : i) {
            std::cout << setw(n * 3) << j;
        }
        std::cout << "\n";
    }


    return 0;
}