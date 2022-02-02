#include <iostream>
#include <string>
using namespace std;

int main() {
	char ent;
	string str;
	string res;
	int max = 0, index = 0;

	cout << "Enter data: ";

	while (cin.get(ent)) {	// Ввод строки
		if (ent != '\n') {
			str = str + ent;
		}
		else break;
	}
	
	for (int i = 0; i < str.length(); i++) // нахождение подстроки максимум из 2 разных символов
	{
		int j = i + 1;
		for (; (str[j] == str[i] && j < str.length()); j++);
		if (j == str.length()) {
			break;
		} 
		int z = j + 1;
		for (; (str[z] == str[i] || str[z] == str[j]); z++);
		if ((z - i) > max)
		{
			max = (z - i);
			index = i;
		}
					
	}
	res = str.substr(index, max);

	if (res == "") {
		cout << endl << "Result: " << str << endl;
	}
	else {
		cout << endl << "Result: " << res << endl;
	}
}
