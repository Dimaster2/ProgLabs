#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int f_euler_rec(int n) //функция Эйлера
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

bool IsPRoot(int p, int a) // проверка на первообразный корень p- модуль а-корень
{
	int temp = pow(a, f_euler_rec(p));
	temp = temp%p;
	if (temp == 1) return true;
	else return false;
};

class Person
{
public:
	int p=0; // модуль
	int g = 0; // первообразный корень
	int n = 0; //степень a или b
	long OwnNumber=0; //Своё число У Элис это А
	long OtherNumber = 0; // Чужое число у Элис это B
	int KEY = 0; //Ключ
	void GenOwnNumber() //создание своего числа
	{
		
		n = rand() % 14 + 1;
		OwnNumber = pow(g, n); OwnNumber = OwnNumber%p;
	}
	void KeyGen() // создание ключа
	{
		KEY = pow(OtherNumber, n); KEY = KEY%p;
	}

};



int main(int args, const char * argv[])
{   //в файле элис хранятся два значения p и g
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int temp=0;
	Person Alice,Bob; //человеки
	ifstream aliceR1("Alice.txt"); // входной поток из исходного файла
	aliceR1 >> Alice.p;
	aliceR1 >> Alice.g;
	aliceR1.close();
	Alice.GenOwnNumber(); //Создаём А=g^a mod p
	
	if (!(IsPRoot(Alice.p, Alice.g))) //проверка является ли g первообразным по модулю p
	{
		cout << "Число  " << Alice.g<< " не является первообразным корнем по модулю " << Alice.p << endl;
		system("pause");
		return 0;
	}
	
	ofstream bobW1("Bob.txt"); //передача бобу p,g,A в файл
	bobW1 << Alice.p <<' ';
	bobW1 << Alice.g << ' ';
	bobW1<< Alice.OwnNumber <<' ';
	bobW1.close();

	ifstream bobR1("Bob.txt"); //считываем данные с файла боба
	bobR1 >> Bob.p;
	bobR1 >> Bob.g;
	bobR1 >> Bob.OtherNumber;
	bobR1.close();

	Bob.GenOwnNumber(); // Создаём B = g^b mod p
	Bob.KeyGen(); // Создаем ключ K=A^b mod p
	
	ofstream bobW2("Bob.txt", ios_base::app); //добавляем в конец файла боба ключ
	bobW2 <<Bob.KEY;
	bobW2.close();
	
	ofstream aliceW1("Alice.txt",ios_base::app); //добавляем в конец файла элис число боба
	aliceW1 <<' '<< Bob.OwnNumber;
	aliceW1.close();

	ifstream aliceR2("Alice.txt");
	aliceR2 >> temp;
	aliceR2 >> temp;
	aliceR2 >> Alice.OtherNumber;
	aliceR2.close();

	Alice.KeyGen(); // Создаем ключ K=B^a mod p

	ofstream aliceW2("Alice.txt", ios_base::app); //добавляем в конец файла элис ключ
	aliceW2 << ' ' << Alice.KEY;
	aliceW2.close();

	//файл Элис содержит p(модуль) g(первообразный корень) B(число собеседника) KEY(ключ для шифра)
	//файл Боба содержит p(модуль) g(первообразный корень) A(число собеседника) KEY(ключ для шифра)
	

	system("pause");
	return 0;

}