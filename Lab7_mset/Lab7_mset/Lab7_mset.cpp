#include <iostream>
#include <set>
#include <map>
#include <ctime>


double avgNegativeNums(std::multiset<int>& mset);

std::multiset<int> generateMset(std::multiset<int> mainMset);


int main() {
	srand(time(nullptr));

	std::multiset<int> mainMset;

	mainMset = generateMset(mainMset);

	std::cout << "My multiset contains: \n";

	// for good output with commas
	bool firstElement = true;
	for (auto& num : mainMset) {
		if (!firstElement) {
			std::cout << ", ";
		}
		std::cout << num;
		firstElement = false;
	}
	std::cout << "\n\n";

	std::map<int, int> countMap;
	for (auto& num : mainMset) {
		countMap[num]++;
	}

	for (auto& pair : countMap) {
		std::cout << pair.first << " : " <<
			pair.second << " times repeated. \n";
	}

	double avgNegNum = avgNegativeNums(mainMset);
	std::cout << "\n\nAverage number of negative nums: " << avgNegNum << std::endl;

	system("pause"); return 0;
}


double avgNegativeNums(std::multiset<int>& mset) {
	
	int negativeNums{}; int negativeCount{};

	for (auto it = mset.begin(); it != mset.end(); it++) {
		
		int num = *it;
		if (num < 0) {
			negativeCount++;
			negativeNums += num;
		}
	}

	return negativeNums / negativeCount;
}


// strictly includes -50 as first num and 50 as last num
std::multiset<int> generateMset(std::multiset<int> mainMset) {
	
	std::multiset<int> testMset;

	bool check = false;
	while (!check) {

		testMset.clear();

		for (int i = 0; i < 20; i++) {

			testMset.insert(rand() % 101 - 50);
		}

		if (*testMset.begin() == -50 && *testMset.rbegin() == 50) {
			check = true;
		}
	}

	mainMset.insert(testMset.begin(), testMset.end());
	return mainMset;
}
