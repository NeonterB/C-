//
// Created by barka on 2/22/2020.
//

#ifndef GAUSSMETHOD_VECTOR_H
#define GAUSSMETHOD_VECTOR_H

#include <vector>

class Vector {
public:
    template<class T>
    static std::vector<T> add(std::vector<T>, std::vector<T>);

    template<class T>
    static std::vector<T> multiply(std::vector<T>, T);
};

template<class T>
std::vector<T> Vector::add(std::vector<T> first, std::vector<T> second) {
    if (first.size() != second.size()) return first;

    for (int i = 0; i < first.size(); i++) {
        first[i] = first[i] + second[i];
    }
    return first;
}

template<class T>
vector<T> Vector::multiply(vector<T> first, T second) {
    for (auto &el:first) {
        el = el * second;
    }
    return first;
}


#endif //GAUSSMETHOD_VECTOR_H
