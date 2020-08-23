#include <iostream>

using namespace std;

bool isNumberGood(int value) {
	if (value == 1 || value == 7) {
		return true;
	}
	int sumOfDigitsSquares = value;
	int currentNumber = value;

	while (sumOfDigitsSquares > 9) {
		sumOfDigitsSquares = 0;

		while (currentNumber > 0) {
			sumOfDigitsSquares += (int)pow(currentNumber % 10, 2);
			currentNumber /= 10;
		}
		if (sumOfDigitsSquares == 1) {
			return true;
		}
		currentNumber = sumOfDigitsSquares;
	}
	if (sumOfDigitsSquares == 7) {
		return true;
	}
	return false;
}

int main() {
	
	int numberOfTests, value;
	cin >> numberOfTests;

	for (int i = 0; i < numberOfTests; i++) {
		cin >> value;
		for (; value < 1000000; value++) {
			if (isNumberGood(value) == true && isNumberGood(value + 1) == true) {
				cout << value << " " << value + 1 << endl;
				break;
			}
		}
	}
}