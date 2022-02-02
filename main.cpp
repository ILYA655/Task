#include <iostream>
#include <string>
using namespace std;

int main() {
	char ent;
	string str;
	string res, res1;
	int b = 0, prev = 0, next = 0;
	char p = 0, h = 0;
	int max = 0, index = 0;

	cout << "Enter data: ";

	while (cin.get(ent)) {	// Ввод строки
		if (ent != '\n') {
			str = str + ent;
		}
		else break;
	}


	for (auto c : str) // Нахождение подстроки из соседей
	{
		if (b == 0) {
			res = c;
			b++;
			p = c;
		}
		else {
			next = (int)c + 1;
			prev = (int)c - 1;
			if ((c == p || (int)p == prev || (int)p == next)) {
				res.assign(res + c);
			}
			else {
				if (res.length() > res1.length()) {
					res1.assign(res);
					res = { 0 };
				}
				else {
					res = { 0 };
				}
				res = c;
			}
			p = c;
		}
	}
	
	if (res.length() > res1.length()) { // res1 - найденная подстрока
		res1.assign(res);
		res = { 0 };
	}
	else {
		res = { 0 };
	}
	
	for (int i = 0; i < res1.length(); i++) // нахождение подстроки максимум из 2 разных символов
	{
		int j = i + 1;
		for (; (res1[j] == res1[i] && j < res1.length()); j++);
		if (j == res1.length()) {
			break;
		} 
		int z = j + 1;
		for (; (res1[z] == res1[i] || res1[z] == res1[j]); z++);
		if ((z - i) > max)
		{
			max = (z - i);
			index = i;
		}
					
	}
	res = res1.substr(index, max);

	if (res == "") {
		cout << endl << "Result: " << res1 << endl;
	}
	else {
		cout << endl << "Result: " << res << endl;
	}
}
