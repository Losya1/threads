#include <iostream>
#include <thread>
#include <vector>

std::vector<int> thread1_vec;
std::vector<int> thread2_vec;
std::vector<int> vec = { 42,2,5,4,6,71,0,8,125,9,63,5,4,37,5,1,91,0,7,10 };

const int threads = 2;

int main() {
	int sum1 = 0, sum2 = 0, sum_all = 0;
	int x = vec.size() / threads;
	for (int i = 0; i < vec.size(); i++) {
		if (i < x) {
			thread1_vec.push_back(vec[i]);
		}
		if (i >= x) {
			thread2_vec.push_back(vec[i]);
		}
	}

	std::thread t1([&sum1] () {	
		for (int i = 0; i < thread1_vec.size(); i++) {
			std::cout << thread1_vec[i] << " ";
			sum1 += thread1_vec[i];
		}
	});

	std::thread t2([&sum2]() {
		for (int i = 0; i < thread2_vec.size(); i++) {
			std::cout << thread2_vec[i] << " ";
			sum2 += thread2_vec[i];
		}
	});

	if (t1.joinable()) { t1.join(); }
	if (t2.joinable()) { t2.join(); }
	std::cout << std::endl << "thread 1 " << sum1 << std::endl << "thread 2 " << sum2 << std::endl;
	sum_all += sum1 + sum2;
	std::cout << "sum " << sum_all << std::endl;
	return 0;
}