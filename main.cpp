#include"Header.h"
//не совсем полный алгоритм Бриллхарта-Моррисона для факторизации числа (не совсем полный значит требует оценки результатов со стороны человека)


int main()
{
	cout << "Enter the number to factorize: ";
	int n;
	cin >> n;

	BMfactorize(n);

	cout << "Session is over. Thank you.";
	cin.sync();
	cin.get();
	return 0;
}