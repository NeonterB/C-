#include <iostream>
#include <vector>
#include <iomanip>

int numOfDisks; //Количество дисков

std::vector<std::string> A; //Стержни
std::vector<std::string> B(0);
std::vector<std::string> C(0);

void Output() { //Визуализация
//    for (int i = numOfDisks - 1; i >= 0; i--) {
//        if (i < A.size()) std::cout << std::setw(12 + A[i].size()/2) << A[i];
//        else std::cout << std::setw(14) << "**";
//
//        if (i < B.size()) std::cout << std::setw(12 + A[i].size()/2) << B[i];
//        else std::cout << std::setw(14) << "**";
//
//        if (i < C.size()) std::cout << std::setw(12 + A[i].size()/2) << C[i] << "\n";
//        else std::cout << std::setw(14) << "**" << "\n";
//    }

    for (int i = numOfDisks - 1; i >= 0; i--) {
        if (i < A.size()) std::cout << std::setw(12 + A[i].size() / 2) << A[i] << "\n";
        else std::cout << std::setw(14) << "**\n";
    }
    std::cout << "\n\n";
    for (int i = numOfDisks - 1; i >= 0; i--) {
        if (i < B.size()) std::cout << std::setw(12 + B[i].size() / 2) << B[i] << "\n";
        else std::cout << std::setw(14) << "**\n";
    }
    std::cout << "\n\n";
    for (int i = numOfDisks - 1; i >= 0; i--) {
        if (i < C.size()) std::cout << std::setw(12 + C[i].size() / 2) << C[i] << "\n";
        else std::cout << std::setw(14) << "**\n";
    }
   std::cout << "\n--------------------------\n";
}

void Hanoi(int n, std::vector<std::string> &o1, std::vector<std::string> &o2,
           std::vector<std::string> &o3) { //Рекурсивный алгоритм
    if (n > 1) {
        Hanoi(n - 1, o1, o3, o2);
    }

    o2.push_back(o1.back());
    o1.pop_back();

    Output();

    if (n > 1) {
        Hanoi(n - 1, o3, o2, o1);
    }
}

int main() {
    std::cout << "Welcome To Hanoi!" << std::endl;
    std::cout << "Enter number of disks:";
    std::cin >> numOfDisks;

    A.resize(numOfDisks);

    for (int i = numOfDisks - 1, j = 4; i >= 0; i--, j += 2) {
        for (int k = 0; k < j; k++, A[i] += "*");
    }

    Output();

    Hanoi(numOfDisks, A, B, C);
    return 0;
}
