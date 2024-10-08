#include "Time.h"
#include <iostream>

int main() {
	Time t1, t2, duration;

	std::cout << "Enter time 1 (HH:MM): ";
	std::cin >> t1;
	if (!std::cin) {
		std::cerr << "Invalid time format\n";
		return 1;
	}

	std::cout << "Enter time 2 (HH:MM): ";
	std::cin >> t2;
	if (!std::cin) {
		std::cerr << "Invalid time format\n";
		return 1;
	}

	if (t1.lessThan(t2)) {
		duration = t2.subtract(t1);
		std::cout << "Starting time was ";
		t1.display();
	} else {
		duration = t1.subtract(t2);
		std::cout << "Starting time was ";
		t2.display();
	}
	std::cout << "Duration was      ";
	duration.display();

	return 0;
}