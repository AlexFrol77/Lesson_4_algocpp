#include <iostream>
#include <Windows.h>

void request(int& logic_num, int& fact_num) {
	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> fact_num;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logic_num;
}

void check_size_arr(int& logic_num, int& fact_num) {
	bool
		flag = true;
	do {
		request(logic_num, fact_num);
		if (fact_num >= logic_num) {
			flag = false;
		}
		else if (fact_num < logic_num) {
			std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
			Sleep(1500);
			system("cls");
			flag = true;
		}
	} while (flag);
}

int* create_and_fill_arr(int& logic_num, int& fact_num) {
	int* arr = new int[fact_num];
	int temp;
	for (int i = 0; i < logic_num; i++) {
		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> temp;
		arr[i] = temp;
	}
	return arr;
}

int request_new_num() {
	int temp;
	std::cout << "Введите элемент для добавления: ";
	std::cin >> temp;
	return temp;
}

int* copy_arr(int *arr, int *new_arr, int logic_num) {
	for (int i = 0; i < logic_num; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	return new_arr;
}

void add_num_arr(int* arr, int& logic_num, int& temp_num_add) {
	arr[logic_num] = temp_num_add;
	logic_num++;
}

int* add_new_arr(int* arr, int &logic_num, int &fact_num, int &temp_num_add) {
	int* new_arr = new int[fact_num];
	new_arr = copy_arr(arr, new_arr, logic_num);
	return new_arr;
}

void print_work(int* arr, int &logic_num, int &fact_num) {
		std::cout << "Динамический массив: ";
		for (int i = 0; i < fact_num; i++) {
			if (i < logic_num) {
				std::cout << arr[i] << " ";
			}
			if (i >= logic_num) {
				std::cout << "_" << " ";
			}
		}
		std::cout << std::endl;
}

void print_exit(int* arr, int& logic_num, int& fact_num) {
	std::cout << std::endl;
	std::cout << "Спасибо! Ваш массив: ";
	for (int i = 0; i < fact_num; i++) {
		if (i < logic_num) {
			std::cout << arr[i] << " ";
		}
		if (i >= logic_num) {
			std::cout << "_" << " ";
		}
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int
		fact_num = 0,
		logic_num = 0,
		temp_num_add;

		check_size_arr(logic_num, fact_num);
		int* arr = create_and_fill_arr(logic_num, fact_num);
		print_work(arr, logic_num, fact_num);
		do {
			temp_num_add = request_new_num();
			if ((logic_num == fact_num) && (temp_num_add != 0)) {
				fact_num *= 2;
				arr = add_new_arr(arr, logic_num, fact_num, temp_num_add);
			}
			if (temp_num_add != 0) {
				add_num_arr(arr, logic_num, temp_num_add);
				print_work(arr, logic_num, fact_num);
			}
		} while (temp_num_add != 0);
	
		print_exit(arr, logic_num, fact_num);
		delete[] arr;

	return 0;
}
