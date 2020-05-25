// Dictionary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <locale.h>
#include<windows.h>

using namespace std;


//fffffffffffffffffffff

template<class T, class Y> bool CompareTwoPairs(pair<T, Y>& PairA, pair<T, Y>& PairB) {
	if (PairA.second >= PairB.second) {
		return (true);
	}
	else if (PairA.second < PairB.second) {
		return (false);
	}

	else if (PairA.first > PairB.first) {
		return (true);
	}
	else if (PairA.first < PairB.first) {
		return (false);
	}

}

void merge(vector<pair<string, int>>& arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	vector<pair<string, int>> L(n1), R(n2);

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
void mergeSort(vector<pair<string, int>>& arr, int l, int r)
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

//fffffffffffffffffffff






void ReadText(string file_name, vector<string> &words) {
	ifstream fin(file_name);
	string Charac = "abcdefghigklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ1234567890";
	string word ="";

	while (fin) {
		string line;
		getline(fin, line);
		for (int i = 0; i < line.length(); i++) {
			char el = line[i];
			if (Charac.find(el) != -1) {
				word += el;
			}

			if ((word != "") && ((el == ' ') || (i == line.length() - 1))) {
				words.push_back(word);
				word = "";
			}
		}
	}
	fin.close();
}

char bufRus[256];
char* Rus(wchar_t* text)
{
	CharToOem(text, bufRus);
	return bufRus;
}

void ReadDictionary(string file_name, map<string, string> &Dict) {
	ifstream fin(file_name);
	while (fin) {
		string key, value;
		fin >> key >> value;
		//for (auto ch : value) {
		//	ch = Rus();
		//}
		if ((key != "") && (value != "")) {
			Dict.insert(pair<string, string>(key, value));
		}
	}
	fin.close();
}

void Translate(map<string, string> &Dict, vector<string> &text) {
	for (int i = 0; i < text.size(); i++) {
		if (Dict.find(text[i]) != Dict.end()) {
			text[i] = Dict.at(text[i]);
		}
	}
}

void FrequencyDictionary(vector<string> text) {
	vector<pair<string, int>> frequency;
	sort(text.begin(), text.end());
	int counter = 1;
	string current = text[0];
	for (int i = 1; i < text.size(); i++) {

		/*if ((i == text.size() - 1) && (text[i] != text[i - 1])) {
			frequency.push_back(pair<string, int>(text[i], 1));
		}*/
		if (text[i] == current) {
			counter++;
		}
		else {
			frequency.push_back(pair<string, int>(current, counter));
			counter = 1;
			current = text[i];
		}
	}
	frequency.push_back(pair<string, int>(current, counter));
	mergeSort(frequency, 0, frequency.size() - 1);

	for (auto pair : frequency) {
		cout << pair.first << " " << pair.second << "\n";
	}
}

string Join(vector<string>& text) {
	string text_line = "";
	for (auto word : text) {
		text_line += word + " ";
	}
	return text_line;
}

void WriteText(string file_name, vector<string> text) {
	string output = Join(text);
	ofstream fout(file_name);
	fout << output;
};

int main()
{
	
	vector<string> text;
	map<string, string> Dictionary;
	ReadText("input.txt", text);
	FrequencyDictionary(text);
	ReadDictionary("dictionary.txt", Dictionary);
	Translate(Dictionary, text);
	FrequencyDictionary(text);
	WriteText("output.txt", text);
}