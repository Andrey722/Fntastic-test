#include <iostream>
#include <string>
#include <locale>
#include <map>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// Вводим исходную строку
	string input = "";
	cout << "enter the string: ";
	getline(cin, input);
	string res = "";

	map<char, int> m; // Словарь символов строки

	// Считаем каждый символ (в нижнем регистре
	for (int i = 0; i < input.size(); i++) {
		m[tolower(input[i])]++;
	}
	// Записываем результат в строку скобок
	for (int i = 0; i < input.size(); i++) {
		if (m[tolower(input[i])] == 1) {
			res.append("(");
		}
		else {
			res.append(")");
		}
	}

	// Выводим ответ
	cout << "result string is: " << res << endl;

	system("PAUSE");
	return 0;
}