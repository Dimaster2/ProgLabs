#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int f_euler_rec(int n) //������� ������
{
	int i, m = 1;
	for (i = 2; i <= n / 2; i++)
	if (n % i == 0)
	{
		n /= i;
		while (n % i == 0)
		{
			m *= i;
			n /= i;
		}
		if (n == 1) return m*(i - 1);
		else return m*(i - 1)*f_euler_rec(n);
	}
	return n - 1;
}

bool IsPRoot(int p, int a) // �������� �� ������������� ������ p- ������ �-������
{
	int temp = pow(a, f_euler_rec(p));
	temp = temp%p;
	if (temp == 1) return true;
	else return false;
};

class Person
{
public:
	int p=0; // ������
	int g = 0; // ������������� ������
	int n = 0; //������� a ��� b
	long OwnNumber=0; //��� ����� � ���� ��� �
	long OtherNumber = 0; // ����� ����� � ���� ��� B
	int KEY = 0; //����
	void GenOwnNumber() //�������� ������ �����
	{
		
		n = rand() % 14 + 1;
		OwnNumber = pow(g, n); OwnNumber = OwnNumber%p;
	}
	void KeyGen() // �������� �����
	{
		KEY = pow(OtherNumber, n); KEY = KEY%p;
	}

};



int main(int args, const char * argv[])
{   //� ����� ���� �������� ��� �������� p � g
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int temp=0;
	Person Alice,Bob; //��������
	ifstream aliceR1("Alice.txt"); // ������� ����� �� ��������� �����
	aliceR1 >> Alice.p;
	aliceR1 >> Alice.g;
	aliceR1.close();
	Alice.GenOwnNumber(); //������ �=g^a mod p
	
	if (!(IsPRoot(Alice.p, Alice.g))) //�������� �������� �� g ������������� �� ������ p
	{
		cout << "�����  " << Alice.g<< " �� �������� ������������� ������ �� ������ " << Alice.p << endl;
		system("pause");
		return 0;
	}
	
	ofstream bobW1("Bob.txt"); //�������� ���� p,g,A � ����
	bobW1 << Alice.p <<' ';
	bobW1 << Alice.g << ' ';
	bobW1<< Alice.OwnNumber <<' ';
	bobW1.close();

	ifstream bobR1("Bob.txt"); //��������� ������ � ����� ����
	bobR1 >> Bob.p;
	bobR1 >> Bob.g;
	bobR1 >> Bob.OtherNumber;
	bobR1.close();

	Bob.GenOwnNumber(); // ������ B = g^b mod p
	Bob.KeyGen(); // ������� ���� K=A^b mod p
	
	ofstream bobW2("Bob.txt", ios_base::app); //��������� � ����� ����� ���� ����
	bobW2 <<Bob.KEY;
	bobW2.close();
	
	ofstream aliceW1("Alice.txt",ios_base::app); //��������� � ����� ����� ���� ����� ����
	aliceW1 <<' '<< Bob.OwnNumber;
	aliceW1.close();

	ifstream aliceR2("Alice.txt");
	aliceR2 >> temp;
	aliceR2 >> temp;
	aliceR2 >> Alice.OtherNumber;
	aliceR2.close();

	Alice.KeyGen(); // ������� ���� K=B^a mod p

	ofstream aliceW2("Alice.txt", ios_base::app); //��������� � ����� ����� ���� ����
	aliceW2 << ' ' << Alice.KEY;
	aliceW2.close();

	//���� ���� �������� p(������) g(������������� ������) B(����� �����������) KEY(���� ��� �����)
	//���� ���� �������� p(������) g(������������� ������) A(����� �����������) KEY(���� ��� �����)
	

	system("pause");
	return 0;

}