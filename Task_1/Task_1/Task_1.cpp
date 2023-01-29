#include <iostream>
#include <Windows.h>

void request(int &fact_num, int &logic_num) {
	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> fact_num;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logic_num;
}

int* create_arr(int& fact_num, int& logic_num) {
	int* arr = new int[fact_num];
	return arr;
}

bool fill_and_check_arr(int* arr, int logic_num, int fact_num) {
	int temp;
	if (fact_num >= logic_num) {
		for (int i = 0; i < logic_num; i++) {
			std::cout << "Введите arr[" << i << "]: ";
			std::cin >> temp;
			arr[i] = temp;
		}
		return true;
	}
	else if (fact_num < logic_num) {
		return false;
	}
}

void print(int *arr, int logic_num, int fact_num, bool flag) {
	if (flag) {
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
	else {
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
	}
}

int check_exit() {
	int temp;
	bool flag;
	do {
		system("cls");
		std::cout << "Хотите повторить?" << std::endl;
		std::cout << "1. Повторить." << std::endl;
		std::cout << "0. Выйти." << std::endl;
		std::cin >> temp;
		if (temp != 0 && temp != 1) {
			std::cout << "Нет такого значения!";
			Sleep(1000);
			flag = false;
		}
		else {
			flag = true;
			return temp;
		}
	} while (!flag);
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int
		fact_num = 0,
		logic_num = 0,
		flag_exit;
	bool
		flag;
	do {
		system("cls");
		request(fact_num, logic_num);
		int* arr = create_arr(fact_num, fact_num);
		flag = fill_and_check_arr(arr, logic_num, fact_num);
		print(arr, logic_num, fact_num, flag);
		Sleep(1500);
		flag = check_exit();
	} while (flag);
	system("cls");
	std::cout << "Всего доброго!" << std::endl;

	return 0;
}
