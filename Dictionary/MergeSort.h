
#ifndef MERGESORT_h
#define MERGESORT_h

#include <vector>
#include <string>

using namespace std;

template<class T, class Y> bool CompareTwoPairs(pair<T, Y>& PairA, pair<T, Y>& PairB);

void merge(vector<std::pair<string, int>>& arr, int l, int m, int r);

void mergeSort(vector<pair<string, int>>& arr, int l, int r);
#endif