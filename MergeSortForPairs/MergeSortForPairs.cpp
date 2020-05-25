// MergeSortForPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
template<class T, class Y> bool CompareTwoPairs(pair<T, Y>& PairA, pair<T, Y>& PairB) {
	if (PairA.first > PairB.first) {
		return (true);
	}
	if (PairA.first < PairB.first) {
		return (false);
	}
	else if (PairA.second >= PairB.second) {
		return (true);
	}
	else if (PairA.second < PairB.second) {
		return (true);
	}
}

void merge(vector<pair<int, int>>& arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	vector<pair<int, int>> L(n1), R(n2);

	/* Copy data to temp arrays L[] and R[] */
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	int i = 0; // Initial index of first subarray 
	int j = 0; // Initial index of second subarray 
	int k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (CompareTwoPairs(R[j], L[i])) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}



}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(vector<pair<int, int>> arr, int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


int main()
{
	vector<pair<int, int>> Points;
	mergeSort(Points, 0, 7);
}