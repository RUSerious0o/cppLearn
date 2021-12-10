#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <stack>
#include <cmath>
#include <ctime>
#include <algorithm>

// 6.1
class Pcout {
public:	
	template <class T>
	Pcout& operator<<(const T& data) {
		m.lock();
		{
			std::cout << data;			
		}
		m.unlock();

		return *this;
	}
private:
	std::mutex m;
};

template <class T>
void print(const T& data, Pcout& pcout) {
	for (int i{ 0 }; i < 5; ++i) {
		std::cout << data << " ";
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}	
}

// 6.2
unsigned long getPrimeNumber(unsigned int i) {
	std::vector<unsigned long> primeNumbers{ 2, 3 };
	
	unsigned long currentNumber = 3;
	bool isPrime = true;
	unsigned int counter = 2;

	std::thread t([&]() {
			std::cout << "Counting...";

			while (counter < i) {
				++currentNumber;
				isPrime = true;

				for (unsigned long base : primeNumbers) {
					if (currentNumber % base == 0) {
						isPrime = false;
						break;
					}
				}

				if (isPrime) {
					primeNumbers.push_back(currentNumber);
					++counter;

					if (counter % 75 == 0 || counter == i) {
						system("cls");
						std::cout.precision(2);
						std::cout << "Counting... " << std::fixed << (double) counter / i * 100 << " %";
					}
				}
			}
		});
	t.detach();
	
	system("pause");
	
	return primeNumbers[primeNumbers.size() - 1];
}

int main(int argc, char** argv) {
	system("cls");

	// 6.1
	Pcout pcout;

	std::vector<std::string> words{ "The", "World", "is", "mine" };
	std::thread t1(print<std::string>, words[0], std::ref(pcout));
	std::thread t2(print<std::string>, words[1], std::ref(pcout));
	std::thread t3(print<std::string>, words[2], std::ref(pcout));
	std::thread t4(print<std::string>, words[3], std::ref(pcout));

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	// 6.2
	system("pause");
	std::cout << "\n" << getPrimeNumber(10000) << "\n";
	system("pause");

	// 6.3
	srand(time(0));
	const int RANGE = 200;
	std::vector<int> items;
	std::mutex itemsLock;

	std::thread owner([&items, &RANGE, &itemsLock]() {
			while (true) {
				itemsLock.lock();
					items.push_back(rand() % RANGE);
				itemsLock.unlock();
				
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
			}
		});
	owner.detach();

	std::thread printer([&items, &itemsLock]() {
			while (true) {
				itemsLock.lock();
				{
					system("cls");
					for (auto item : items) {
						std::cout << item << " ";
					}
					std::cout << "\n";
				}
				itemsLock.unlock();

				std::this_thread::sleep_for(std::chrono::milliseconds(250));
			}
		});
	printer.detach();

	std::thread thief([&items, &itemsLock]() {
			std::this_thread::sleep_for(std::chrono::milliseconds(750));

			while (true) {
				itemsLock.lock();
					items.erase(std::max_element(items.begin(), items.end()));
				itemsLock.unlock();
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		});
	thief.detach();
	
	system("pause");
	
	return 0;
}