#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) //�������� �������
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}




class Person
{
public:
	long int p = 0; // ������� ����� p
	long int q = 0; // ������� ����� q
	long int n = 0; //p*q
	vector<long int> m_decrypted; //�������������� ������ ������
	vector<long int> m_encrypted; //�������������� ������ ������
	int k = 2;
	long int fn = 0; //f(n)=(p-1)(q-1)
	int e = 0;//�������� ����
	long int d_secret;//   �������� ���� 

	void Form_n() //���������� n
	{
		n=p*q;
	}
	void Form_fn() //���������� fn
	{
		fn = (p - 1)*(q - 1);
	}
	void Form_d_secret() //���������� d
	{
		int  d_simple = 0;
		while (d_simple != 1)
		{
			d_secret = rand() % 25;
			d_simple = gcd(d_secret, ((p - 1)*(q - 1)));
		}
	}
	void Form_vector_m() //���������� ��������� � �������� �������
	{
		int k = 0;
		cout << "������� ��������� � �������� ������� (100-����� �����) \n";
		while (1)
		{
			cin >> k;
			if (k == 100) break;
			m_decrypted.push_back(k);
		}

		
	}

	void encryption() //��������
	{
		for (int i=0;i<m_decrypted.capacity();i++)
		{
			m_encrypted.push_back(pow(m_decrypted[i], e));
			m_encrypted[i]=m_encrypted[i] % n;
			
		}
	}

	void decryption() //����������
	{
		for (int i = 0;i<m_encrypted.capacity();i++)
		{
			m_decrypted.push_back(pow(m_encrypted[i], d_secret));
			m_decrypted[i] = m_decrypted[i] % n;

		}
	}
	
};

int main(int args, const char * argv[])
{   //�������� ������ ���, ������ 2 ������ �����
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	Person Alice, Bob; //��������
	cout << "ENTER p\n";
	cin >> Alice.p;
	cout << "ENTER q\n";
	cin >> Alice.q;
	Alice.Form_n();
	Alice.Form_fn();
	Alice.Form_d_secret();
	unsigned int  e_simple = 0;
	while (e_simple != 1)
	{
		Alice.e += 1;
		e_simple = (Alice.e *Alice.d_secret) % ((Alice.p - 1)*(Alice.q - 1));
	}
	ofstream bobW1("bob.txt"); //�������� n, e ����
	bobW1 << Alice.n << ' ';
	bobW1 << Alice.e << ' ';
	bobW1.close();

	ifstream bobR1("bob.txt"); //��������� ������ � ����� ���� 
	bobR1 >> Bob.n;
	bobR1 >> Bob.e;
	bobR1.close();
	
	
	Bob.Form_vector_m(); //��������� ��������� ���� � �������� ��������
	Bob.encryption(); //�������� ��������� ���� � ����

	ofstream aliceW1("alice.txt"); //�������� ��������������� ��������� ����->����
	for(int i=0;i<Bob.m_encrypted.capacity();i++)
	{
		if (i != (Bob.m_encrypted.capacity()-1)) aliceW1 << Bob.m_encrypted[i] << ' ';
		else aliceW1 << Bob.m_encrypted[i];
	}
	aliceW1.close();

	int temp;
	ifstream aliceR1("alice.txt");
	while (!aliceR1.eof())
	{
		aliceR1 >> temp;
		Alice.m_encrypted.push_back(temp);
	};
	

	Alice.decryption(); //����������� ��������� ���� d �� ������� �^d mod n = X, ��� �-�������������� ��������� ����, d- ����, n-p*q, X-�������� ���������


	system("pause");
	return 0;
}