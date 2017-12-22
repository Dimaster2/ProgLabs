#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) //алгоритм ≈вклида
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
	long int p = 0; // простое число p
	long int q = 0; // простое число q
	long int n = 0; //p*q
	vector<long int> m_decrypted; //расшифрованный массив данных
	vector<long int> m_encrypted; //засшифрованный массив данных
	int k = 2;
	long int fn = 0; //f(n)=(p-1)(q-1)
	int e = 0;//открытый ключ
	long int d_secret;//   закрытый ключ 

	void Form_n() //вычисление n
	{
		n=p*q;
	}
	void Form_fn() //вычисление fn
	{
		fn = (p - 1)*(q - 1);
	}
	void Form_d_secret() //вычисление d
	{
		int  d_simple = 0;
		while (d_simple != 1)
		{
			d_secret = rand() % 25;
			d_simple = gcd(d_secret, ((p - 1)*(q - 1)));
		}
	}
	void Form_vector_m() //добавление сообщений в числовом формате
	{
		int k = 0;
		cout << "¬водите сообщени€ в цифровом формате (100-конец ввода) \n";
		while (1)
		{
			cin >> k;
			if (k == 100) break;
			m_decrypted.push_back(k);
		}

		
	}

	void encryption() //шифраци€
	{
		for (int i=0;i<m_decrypted.capacity();i++)
		{
			m_encrypted.push_back(pow(m_decrypted[i], e));
			m_encrypted[i]=m_encrypted[i] % n;
			
		}
	}

	void decryption() //дешифраци€
	{
		for (int i = 0;i<m_encrypted.capacity();i++)
		{
			m_decrypted.push_back(pow(m_encrypted[i], d_secret));
			m_decrypted[i] = m_decrypted[i] % n;

		}
	}
	
};

int main(int args, const char * argv[])
{   //исходных данных нет, только 2 пустых файла
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	Person Alice, Bob; //человеки
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
	ofstream bobW1("bob.txt"); //передача n, e бобу
	bobW1 << Alice.n << ' ';
	bobW1 << Alice.e << ' ';
	bobW1.close();

	ifstream bobR1("bob.txt"); //считываем данные с файла боба 
	bobR1 >> Bob.n;
	bobR1 >> Bob.e;
	bobR1.close();
	
	
	Bob.Form_vector_m(); //формируем сообщение боба в числовом варианте
	Bob.encryption(); //кодируем сообщение боба к элис

	ofstream aliceW1("alice.txt"); //передача закодированного сообщени€ боба->элис
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
	

	Alice.decryption(); //расшифровка использу€ ключ d по формуле с^d mod n = X, где с-закодированное сообщение боба, d- ключ, n-p*q, X-исходное сообщение


	system("pause");
	return 0;
}