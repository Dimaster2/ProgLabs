#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;



int main(int args, const char * argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	map <char, string> alphabet = { { '�', "00000" }, { '�', "00001" }, { '�', "00010" }, { '�', "00011" }, { '�', "00100" }, { '�', "00101" },
	{ '�', "00110" }, { '�', "00111" }, { '�', "01000" }, { '�', "01001" }, { '�', "01010" }, { '�', "01011" },
	{ '�', "01100" }, { '�', "01101" }, { '�', "01110" }, { '�', "01111" }, { '�', "10000" }, { '�', "10001" },
	{ '�', "10010" }, { '�', "10011" }, { '�', "10100" }, { '�', "10101" }, { '�', "10110" }, { '�', "10111" },
	{ '�', "11000" }, { '�', "11001" }, { '�', "11010" }, { '�', "11011" }, { '�', "11100" }, { '�', "11101" },
	{ '�', "11110" }, { '�', "11111" } };




	string input_text;                               //���� ������ �� �������� �����
	ifstream inputFile;
	inputFile.open("input.txt");
	getline(inputFile, input_text, '\0');
	inputFile.close();

	string dvoichniy;                 //������� � �������� ���
	for (int i = 0; i < input_text.length(); i++)
	{
		auto in = alphabet.find(input_text[i]);
		dvoichniy = dvoichniy + in->second;

	}

	int a = 0;
	string key = dvoichniy; //������������ ����� 
	for (int i = 0; i < dvoichniy.length(); i++)
	{
		a = rand() % 2;
		if (a == 0)	key[i] = '0';
		else key[i] = '1';
	}
	cout << dvoichniy << endl;
	cout << key << endl;

	string xorosho = dvoichniy;
	for (int i = 0; i < dvoichniy.length(); i++) //�������� xor
	{
		if (dvoichniy[i] == key[i]) xorosho[i] = '0';
		else xorosho[i] = '1';
	}
	cout << xorosho << endl;
	string buf;
	string obichniy;       
	int k = 0;//������� � ������� ���
	for (int j = 0; j < dvoichniy.length() / 5; j++)
	{
	
	      for (int i = 0; i <5; i++)
	        {
		      buf = buf+xorosho[k];
			  k++;
	        }

	      for (auto it = alphabet.begin(); it != alphabet.end(); ++it)
	        {
		      if (it->second == buf) obichniy = obichniy + it->first;
	        }
		  buf = "";
	}
	cout << obichniy<<endl;
	cin.get();
	return 0;

};