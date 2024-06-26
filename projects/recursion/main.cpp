﻿#include <iostream>
#include <vector>
#include <string>

void count_numbers(
	int n, int m, int& count,
	long number = 0,
	long sum = 0, long product = 1
);
void count_palindromes(
	int n, int d, int& count,
	std::string number
);

namespace EAbrakhin {
	void quick_sort(int* array, int low, int high);
	void swap(int& x, int& y);
}

void decomposite_in_terms(
	const int n,
	std::vector<int> vec,
	int sum_rest,
	int& count
);

void decomposite_in_k_terms(
	const int n, const int k,
	std::vector<int> vec,
	int sum_rest, int& count
);

int main() {
	 {
		const int n = 3;
		const int m = 10;
		int count = 0;
		count_numbers(n, m, count);
		std::cout << "количество чисел = " << count << std::endl;
	}
	
	{
		const int n = 3;
		const int d = 1;
		int count = 0;
		std::string number;
		count_palindromes(n, d, count, number);
		std::cout << "Количество полиндромов = " << count << std::endl; 
	}
	
	{
		int arr[] = { 3, 12, 4, 0, 6, -2, -6, 11, 3, 5, 8 };
		const int size = sizeof(arr) / sizeof(arr[0]);
		EAbrakhin::quick_sort(arr, 0, size - 1);
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << ' ';
		}
	}
	
	{
		std::vector<int> terms;
		const int n = 5;
		int count = 0;
		decomposite_in_terms(n, terms, n, count);
		std::cout << "Количество вариантов = " << count << std::endl;
	}
	
	{
		std::vector<int> terms;
		const int n = 10;
		const int k = 3;
		int count = 0;
		decomposite_in_k_terms(n, k, terms, n, count);
		std::cout << "Количество вариантов = " << count << std::endl;
	}
}

void count_numbers(
	int n, int m, int& count,
	long number,
	long sum, long product
) {
	if (n == 0) {
		if (product == m * sum) {
			++count;
			std::cout << number << std::endl;
		}
		return;
	}

	for (int i = (n == 1) ? 1 : 0; i < 10; ++i) {
		count_numbers(n - 1, m, count, number * 10 + i, sum + i, product * i);
	}
}

void count_palindromes(
	int n, int d, int& count,
	std::string number 
) {
	if (number.size() == n) {
		int sum = 0;
		for (char digit : number) {
			sum += (digit - '0');
		}
		if (sum % d == 0) {
			++count;
			std::cout << number << std::endl;
		}
		return;
	}

	if (number.empty() && n % 2 == 1) {
		for (int i = (n == 1) ? 1 : 0; i < 10; ++i) {
			std::string newNumber = number + std::to_string(i);
			count_palindromes(n, d, count, newNumber);
		}
	} else {
		for (int i = (number.size() == (n - 2)) ? 1 : 0; i < 10; ++i) {
			std::string newNumber = std::to_string(i) + number + std::to_string(i);
			count_palindromes(n, d, count, newNumber);
		}
	}
}

namespace EAbrakhin {
	void quick_sort(int* array, int low, int high) {
		if (low < high) {
			int pivot = array[high];
			int l = low;
			for (int i = low; i < high; ++i) {
				if (array[i] < pivot)
					swap(array[l++], array[i]);
			}
			swap(array[l], array[high]);

			quick_sort(array, low, l - 1);
			quick_sort(array, l + 1, high);
		}
	}

	void swap(int& x, int& y) {
		int temp = x;
		x = y;
		y = temp;
	}
}

void decomposite_in_terms(
	const int n,
	std::vector<int> vec,
	int sum_rest,
	int& count
) {
	if (sum_rest == 0) {
		++count;
		std::cout << n << " = ";
		for (int i = 0; i < vec.size() - 1; ++i) {
			std::cout << vec[i] << " + ";
		}
		std::cout << vec.back() << std::endl;
		return;
	}

	for (int i = (vec.empty()) ? 1 : vec.back(); i <= sum_rest; ++i) {
		vec.push_back(i);
		decomposite_in_terms(n, vec, sum_rest - i, count);
		vec.pop_back();
	}
}

void decomposite_in_k_terms(
	const int n, const int k,
	std::vector<int> vec,
	int sum_rest, int& count
) {
	if (vec.size() > k || sum_rest < 0)
		return;

	if (sum_rest == 0 && vec.size() == k) {
		++count;
		std::cout << n << " = ";
		for (int i = 0; i < vec.size() - 1; ++i) {
			std::cout << vec[i] << " + ";
		}
		std::cout << vec.back() << std::endl;
		return;
	}

	for (int i = (vec.empty()) ? 1 : vec.back(); i <= sum_rest; ++i) {
		vec.push_back(i);
		decomposite_in_k_terms(n, k, vec, sum_rest - i, count);
		vec.pop_back();
	}
}
