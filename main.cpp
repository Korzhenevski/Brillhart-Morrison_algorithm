#include"Header.h"
//�� ������ ������ �������� ����������-��������� ��� ������������ ����� (�� ������ ������ ������ ������� ������ ����������� �� ������� ��������)


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