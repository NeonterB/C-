//// Castle.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//
//struct Cell {
//	int roomNum;
//	bool walls[4];
//};
//
//std::vector<int> rooms;
//
//enum WALL { West, North, East, South };
//
//int ScanCells(std::vector<std::vector<Cell>> &, std::vector<std::vector<bool>> &);
//
//void Update(int, int, int, std::vector<std::vector<Cell>> &, std::vector<std::vector<bool>> &);
//
//int BestWall(std::vector<std::vector<Cell>> &);
//
//int RemoveWall(int, int, int, int, std::vector<std::vector<Cell>> &);
//
//int main() {
//	std::ofstream fout("out.txt");
//	std::ifstream fin("in.txt");
//	int m, n;
//	fin >> m >> n;
//	std::vector<std::vector<Cell>> Cells(m, std::vector<Cell>(n));;
//	std::vector<std::vector<bool>> Used(m, std::vector<bool>(n));
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			Cell current;
//			int p;
//			fin >> p;
//			for (int d = 0; d < 4; d++) {
//				current.walls[d] = (p % 2 != 0);
//				p /= 2;
//			}
//			Cells[i][j] = current;
//		}
//	}
//
//	int MaxArea = ScanCells(Cells, Used);
//	std::string wall;
//	int MaxValue = BestWall(Cells);
//
//	
//	fout << rooms.size() << "\n";
//	fout << MaxArea << "\n";
//	fout << MaxValue;
//	return 0;
//}
//
//int ScanCells(std::vector<std::vector<Cell>> &cells, std::vector<std::vector<bool>> &used) {
//	int N = -1;
//	int maxArea = 0;
//	for (unsigned i = 0; i < m; i++) {
//		unsigned j = 0;
//		while (j != n) {
//			if (!used[i][j]) {
//				N++;
//				rooms.push_back(0);
//				Update(i, j, N, cells, used);
//				if (rooms[N] > maxArea) maxArea = rooms[N];
//			}
//			j++;
//		}
//	}
//	return maxArea;
//}
//
//void Update(int i, int j, int n, std::vector<std::vector<Cell>> &cells, std::vector<std::vector<bool>> &used) {
//	used[i][j] = true;
//	cells[i][j].roomNum = n;
//	if (!cells[i][j].walls[East]) {
//		if (!used[i][j + 1]) Update(i, j + 1, n, cells, used);
//	}
//	if (!cells[i][j].walls[South]) {
//		if (!used[i + 1][j]) Update(i + 1, j, n, cells, used);
//	}
//	if (!cells[i][j].walls[West]) {
//		if (!used[i][j - 1]) Update(i, j - 1, n, cells, used);
//	}
//	if (!cells[i][j].walls[North]) {
//		if (!used[i - 1][j]) Update(i - 1, j, n, cells, used);
//	}
//	rooms[n]++;
//}
//
//int BestWall(std::vector<std::vector<Cell>> &cells) {
//	int maxValue = 0;
//	for (unsigned i = 0; i < m - 1; i++) {
//		for (unsigned j = 0; j < m - 1; j++) {
//			int value = 0;
//			if (cells[i][j].walls[West]) {
//				value = RemoveWall(i, j, i, j + 1, cells);
//				if (value > maxValue) {
//					maxValue = value;
//				}
//			}
//			if (cells[i][j].walls[South]) {
//				value = RemoveWall(i, j, i + 1, j, cells);
//				if (value > maxValue) {
//					maxValue = value;
//				}
//			}
//		}
//	}
//	return maxValue;
//}
//
//int RemoveWall(int i1, int j1, int i2, int j2, std::vector<std::vector<Cell>> &cells) {
//	int value;
//	if (cells[i1][j1].roomNum == cells[i2][j2].roomNum) {
//		value = rooms[cells[i1][j1].roomNum];
//	} else {
//		value = rooms[cells[i1][j1].roomNum] + rooms[cells[i2][j2].roomNum];
//	}
//	return value;
//}
// Castle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

struct Cell {
	int roomNum;
	bool walls[4];
};

std::vector<std::vector<Cell>> cells(1000, std::vector<Cell>(1000));

std::vector<int> rooms;

std::vector<std::vector<bool>> used(1000, std::vector<bool>(1000));

int m, n;

enum WALL { West, North, East, South };

clock_t begin_time;


void ReadInput(std::string);

int ScanCells();

void Update(int, int, int);

int BestWall();

int RemoveWall(int, int, int, int);

int main() {
	
	ReadInput("in.txt");
	int MaxArea = ScanCells();
	int MaxValue = BestWall();

	std::ofstream fout("out.txt");
	fout << rooms.size() <<"\n";
	fout << MaxArea << "\n";
	fout << MaxValue;
	fout.close();
	return 0;
}

void ReadInput(std::string fileName) {
	std::ifstream fin(fileName);

	fin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			Cell current;
			int p;
			fin >> p;
			for (int d = 0; d < 4; d++) {
				current.walls[d] = (p % 2 != 0);
				p /= 2;
			}
			cells[i][j] = current;
		}
	}
	fin.close();
}

int ScanCells() {
	int N = -1;
	int maxArea = 0;
	for (int i = 0; i < m; i++) {
		int j = 0;
		while (j != n) {
			if (!used[i][j]) {
				N++;
				rooms.push_back(0);
				Update(i, j, N);
				if (rooms[N] > maxArea) maxArea = rooms[N];
			}
			j++;
		}
	}
	return maxArea;
}

void Update(int i, int j, int n) {
	used[i][j] = true;
	cells[i][j].roomNum = n;
	if (!cells[i][j].walls[East]) {
		if (!used[i][j + 1]) Update(i, j + 1, n);
	}
	if (!cells[i][j].walls[South]) {
		if (!used[i + 1][j]) Update(i + 1, j, n);
	}
	if (!cells[i][j].walls[West]) {
		if (!used[i][j - 1]) Update(i, j - 1, n);
	}
	if (!cells[i][j].walls[North]) {
		if (!used[i - 1][j]) Update(i - 1, j, n);
	}
	rooms[n]++;
}

int BestWall() {
	int maxValue = 0;
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int value = 0;
			if (cells[i][j].walls[West]) {
				value = RemoveWall(i, j, i, j + 1);
				if (value > maxValue) {
					maxValue = value;
				}
			}
			if (cells[i][j].walls[South]) {
				value = RemoveWall(i, j, i + 1, j);
				if (value > maxValue) {
					maxValue = value;
				}
			}
		}
	}
	return maxValue;
}

int RemoveWall(int i1, int j1, int i2, int j2) {
	int value;
	if (cells[i1][j1].roomNum == cells[i2][j2].roomNum) {
		value = rooms[cells[i1][j1].roomNum];
	} else {
		value = rooms[cells[i1][j1].roomNum] + rooms[cells[i2][j2].roomNum];
	}
	return value;
}