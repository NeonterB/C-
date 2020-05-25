#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>

void ReadInput(std::string fileName, std::vector<std::vector<int>> &_towns) {
	std::ifstream fin(fileName);
	int n;
	fin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		fin >> num;
		_towns.push_back({num});
		for (int j = 0; j < num; j++) {
			int town;
			fin >> town;
			town--;
			_towns[i].push_back(town);
		}
	}
}

int main() {
	const clock_t begin_time = clock();
	std::vector<std::vector<int>> towns;
	ReadInput("input.txt", towns);
	std::vector<bool> toSet(towns.size());
	int count = 0;
	while (true) {
		for (int i = 0; i < towns.size(); i++) {
			if ((!towns[i].empty()) && (towns[i][0] == 1)) {
				if (!toSet[i] && !toSet[towns[i][1]]) {
					toSet[towns[i][1]] = true;
					count++;
				}
				for (int j = 1; j <= towns[towns[i][1]][0]; j++) {
					if (towns[towns[i][1]][j] == i) {
						towns[towns[i][1]].erase(towns[towns[i][1]].begin() + j);
						towns[towns[i][1]][0]--;
						if (towns[towns[i][1]][0] == 0) {
							std::ofstream fout("output.txt");
							fout << count;
							std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
							return 0;
						}
						break;
					}
				}
				towns[i].clear();
			}
		}
	}
}