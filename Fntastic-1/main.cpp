#include <iostream>
#include <string>
#include <locale>
#include <map>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// ������ �������� ������
	string input = "";
	cout << "enter the string: ";
	getline(cin, input);
	string res = "";

	map<char, int> m; // ������� �������� ������

	// ������� ������ ������ (� ������ ��������
	for (int i = 0; i < input.size(); i++) {
		m[tolower(input[i])]++;
	}
	// ���������� ��������� � ������ ������
	for (int i = 0; i < input.size(); i++) {
		if (m[tolower(input[i])] == 1) {
			res.append("(");
		}
		else {
			res.append(")");
		}
	}

	// ������� �����
	cout << "result string is: " << res << endl;

	system("PAUSE");
	return 0;
}