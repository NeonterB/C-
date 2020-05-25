// Caravan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::vector<int>> g; // граф
int n, X1, Y1, X2, Y2; // число вершин
std::vector<std::vector<char>> used;

void getInput(std::string fileName);

void outputFile(std::string fileName);

void search(int i, int j);

int main() {
	getInput("in.txt");
	search(--X1, --Y1);
	outputFile("out.txt");
	return 0;
}

void getInput(std::string fileName) {
	std::ifstream fin(fileName);
	fin >> n >> X1 >> Y1 >> X2 >> Y2;
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < n; i++) {
		g[i].resize(n);
		used[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			fin >> num;
			g[i][j] = num;
		}
	}
}

void outputFile(std::string fileName) {
	std::ofstream fout(fileName);
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size(); j++) {
			if (j!=g[i].size()-1){
				fout << g[i][j] * ((used[i][j] == 3)?(1):(used[i][j])) << " ";
			}
			else{
				fout << g[i][j] * ((used[i][j] == 3) ? (1) : (used[i][j])) << "\n";
			}
		}
	}
}

void search(int i, int j) {
	used[i][j] = true;

	if (j + 1 < n && g[i][j] > g[i][j + 1] && used[i][j + 1] != 3) {
		search(i, j + 1);
	}
	if (i + 1 < n && g[i][j] > g[i + 1][j] && used[i + 1][j] != 3) {
		search(i + 1, j);
	}
	if (j - 1 >= 0 && g[i][j] > g[i][j - 1] && used[i][j - 1] != 3) {
		search(i, j - 1);
	}
	if (i - 1 >= 0 && g[i][j] > g[i - 1][j] && used[i - 1][j] != 3) {
		search(i - 1, j);
	}
	used[i][j] = 3;
}