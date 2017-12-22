#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <math.h>
#include <random>
#include <algorithm>

using namespace std;

void show_vector(vector<char>&a)
{
	for (vector<char>::iterator it = a.begin(); it != a.end(); ++it)
		cout << *it;
}



class HelloWorld
{
public:
	
	vector<char> CreateNewAlpabet(vector<char> mas1, vector<char> mas2)
	{
		int i, j = 0;
		vector<char> NEWalpabet;
		for (i= 0;i < mas1.size();i++) //на место кодовых букв ставим * - звезду
		{ 
			for (j = 0;j < mas2.size();j++) 
				{
					if (mas1[i] == mas2[j])
						{
							mas1[i] = '*';
							break;
						}
				}
		}

		for (j = 0;j < mas2.size();j++) { NEWalpabet.push_back(mas2[j]);} //помещаем кодовое слово в начало
		for (i = 0;i < mas1.size();i++) //дописываем справа от кодового слова буквы из старого алфавита, не затертые *
			{
				if (mas1[i] != '*') { NEWalpabet.push_back(mas1[i]);}
			}
		return NEWalpabet;
	}

	vector<char> FileEncoding(vector<char> mas1, vector<char> mas2)
	{
		int k = 0;
		char ch;
		ifstream INPUTFILE("input.txt"); //файл с исходным текстом
		ofstream OUTPUTFILE("output.txt"); //файл в который записывается шифрованный текст

		vector<char> inputtext;  //считываем файл input.txt
		while (1) {
			INPUTFILE.get(ch);
			inputtext.push_back((char)tolower(ch));
			if (INPUTFILE.eof()) break;
				  }
	
		vector<char> encrypted;
		for (int i = 0;i < inputtext.size();i++) //заменяем буквы файла input.txt шифрованными
		{
			for (int j = 0;j < mas1.size();j++)
			{
				if (inputtext[i] == mas1[j]) 
				{ encrypted.push_back(mas2[j]);
					break; 
				}
				if (inputtext[i] == ' ') { encrypted.push_back(' ');break; } //не буквы остаются не закодированными
				if (inputtext[i] == '.') { encrypted.push_back('.');break; }
				if (inputtext[i] == ',') { encrypted.push_back(',');break; }
				if (inputtext[i] == '?') { encrypted.push_back('?');break; }
				if (inputtext[i] == '!') { encrypted.push_back('!');break; }
				if (inputtext[i] == ';') { encrypted.push_back(';');break; }
				if (inputtext[i] == ':') { encrypted.push_back(':');break; }
				if (inputtext[i] == '"') { encrypted.push_back('"');break; }
				if (inputtext[i] == '(') { encrypted.push_back('(');break; }
				if (inputtext[i] == ')') { encrypted.push_back(')');break; }
				if (inputtext[i] == '`') { encrypted.push_back('`');break; }
				if (inputtext[i] == '-') { encrypted.push_back('-');break; }
				if (inputtext[i] == '0') { encrypted.push_back('0');break; }
				if (inputtext[i] == '1') { encrypted.push_back('1');break; }
				if (inputtext[i] == '2') { encrypted.push_back('2');break; }
				if (inputtext[i] == '3') { encrypted.push_back('3');break; }
				if (inputtext[i] == '4') { encrypted.push_back('4');break; }
				if (inputtext[i] == '5') { encrypted.push_back('5');break; }
				if (inputtext[i] == '6') { encrypted.push_back('6');break; }
				if (inputtext[i] == '7') { encrypted.push_back('7');break; }
				if (inputtext[i] == '8') { encrypted.push_back('8');break; }
				if (inputtext[i] == '9') { encrypted.push_back('9');break; }
				
			}

		}
		int f = 0;
		while (f!=encrypted.size()) //запись шифрованного текст в output.txt
		{
			OUTPUTFILE << encrypted[f];
			f++;
		}

		INPUTFILE.close();
		OUTPUTFILE.close();
		return encrypted;
	}

	void Chastotniy_analiz(vector<char> text)
	{
		
		int k = 0;
		int tempmas[26][3] = { 0 };
		
		for (int i = 0; i < text.size(); i++) //находим количество каждой буквы алфавита в тексте
		{
			if (text[i] == 'a') {
				++tempmas[0][0];
				tempmas[0][1] = 97;
			}

			if (text[i] == 'b') {
				++tempmas[1][0];
				tempmas[1][1] = 98;
			}

			if (text[i] == 'c') {
				++tempmas[2][0];
				tempmas[2][1] = 99;
			}

			if (text[i] == 'd') {
				++tempmas[3][0];
				tempmas[3][1] = 100;
			}

			if (text[i] == 'e') {
				++tempmas[4][0];
				tempmas[4][1] = 101;
			}

			if (text[i] == 'f') {
				++tempmas[5][0];
				tempmas[5][1] = 102;
			}

			if (text[i] == 'g') {
				++tempmas[6][0];
				tempmas[6][1] = 103;
			}

			if (text[i] == 'h') {
				++tempmas[7][0];
				tempmas[7][1] = 104;
			}

			if (text[i] == 'i') {
				++tempmas[8][0];
				tempmas[8][1] = 105;
			}

			if (text[i] == 'j') {
				++tempmas[9][0];
				tempmas[9][1] = 106;
			}

			if (text[i] == 'k') {
				++tempmas[10][0];
				tempmas[10][1] = 107;
			}

			if (text[i] == 'l') {
				++tempmas[11][0];
				tempmas[11][1] = 108;
			}

			if (text[i] == 'm') {
				++tempmas[12][0];
				tempmas[12][1] = 109;
			}

			if (text[i] == 'n') {
				++tempmas[13][0];
				tempmas[13][1] = 110;
			}

			if (text[i] == 'o') {
				++tempmas[14][0];
				tempmas[14][1] = 111;
			}

			if (text[i] == 'p') {
				++tempmas[15][0];
				tempmas[15][1] = 112;
			}

			if (text[i] == 'q') {
				++tempmas[16][0];
				tempmas[16][1] = 113;
			}

			if (text[i] == 'r') {
				++tempmas[17][0];
				tempmas[17][1] = 114;
			}

			if (text[i] == 's') {
				++tempmas[18][0];
				tempmas[18][1] = 115;
			}

			if (text[i] == 't') {
				++tempmas[19][0];
				tempmas[19][1] = 116;
			}

			if (text[i] == 'u') {
				++tempmas[20][0];
				tempmas[20][1] = 117;
			}

			if (text[i] == 'v') {
				++tempmas[21][0];
				tempmas[21][1] = 118;
			}

			if (text[i] == 'w') {
				++tempmas[22][0];
				tempmas[22][1] = 119;
			}

			if (text[i] == 'x') {
				++tempmas[23][0];
				tempmas[23][1] = 120;
			}

			if (text[i] == 'y') {
				++tempmas[24][0];
				tempmas[24][1] = 121;
			}

			if (text[i] == 'z') {
				++tempmas[25][0];
				tempmas[25][1] = 122;
			}
		}

		//сортировка по убыванию 
		size_t imax;
		for (size_t i = 0; i < 26; ++i) 
		{
			imax = i;
			for (size_t j = i + 1; j < 26; ++j)
			{
				if (tempmas[j][0] > tempmas[imax][0])
					imax = j;
			}

			if (imax != i) {
				for (size_t c = 0; c < 3; ++c)
					swap(tempmas[imax][c], tempmas[i][c]);
			}
		}
		//шаблонная таблица встречаемости символов, заполняем ей третий стоблбец, чтобы сопоставить с отсортированным на предыдущем шаге массивом
		tempmas[0][2] = 101;   
		tempmas[1][2] = 116;   
		tempmas[2][2] = 97;   
		tempmas[3][2] = 111;   
		tempmas[4][2] = 105;  
		tempmas[5][2] = 110;   
		tempmas[6][2] = 115;   
		tempmas[7][2] = 104;   
		tempmas[8][2] = 104;   
		tempmas[9][2] = 100;    
		tempmas[10][2] = 108;   
		tempmas[11][2] = 99;  
		tempmas[12][2] = 117;   
		tempmas[13][2] = 109;   
		tempmas[14][2] = 119;    
		tempmas[15][2] = 102;    
		tempmas[16][2] = 103;   
		tempmas[17][2] = 121;  
		tempmas[18][2] = 112;  
		tempmas[19][2] = 98;  
		tempmas[20][2] = 118;  
		tempmas[21][2] = 107;  
		tempmas[22][2] = 120; 
		tempmas[23][2] = 106;  
		tempmas[24][2] = 113; 
		tempmas[25][2] = 122; 

		vector<char> decrypted;

		ofstream OUTPUTFILE2("output2.txt"); //файл в который будет дешифрироваться текст
		int i;
		for (i = 0; i < text.size(); i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (text[i] == (char)tempmas[j][1]) {
					decrypted.push_back((char)tempmas[j][2]);
					break;
				}

				if (text[i] == ' ') {
					decrypted.push_back(' ');
					break;
				}

				if (text[i] == '.') {
					decrypted.push_back('.');
					break;
				}

				if (text[i] == ',') {
					decrypted.push_back(',');
					break;
				}

				if (text[i] == '?') {
					decrypted.push_back('?');
					break;
				}

				if (text[i] == '!') {
					decrypted.push_back('!');
					break;
				}

				if (text[i] == ';') {
					decrypted.push_back('!');
					break;
				}

				if (text[i] == ':') {
					decrypted.push_back(':');
					break;
				}

				if (text[i] == '"') {
					decrypted.push_back('"');
					break;
				}

				if (text[i] == '(') {
					decrypted.push_back('(');
					break;
				}

				if (text[i] == ')') {
					decrypted.push_back(')');
					break;
				}

				if (text[i] == '`') {
					decrypted.push_back('`');
					break;
				}

				if (text[i] == '-') {
					decrypted.push_back('-');
					break;
				}

				if (text[i] == '0') {
					decrypted.push_back('0');
					break;
				}

				if (text[i] == '1') {
					decrypted.push_back('1');
					break;
				}

				if (text[i] == '2') {
					decrypted.push_back('2');
					break;
				}

				if (text[i] == '3') {
					decrypted.push_back('3');
					break;
				}

				if (text[i] == '4') {
					decrypted.push_back('4');
					break;
				}

				if (text[i] == '5') {
					decrypted.push_back('5');
					break;
				}

				if (text[i] == '6') {
					decrypted.push_back('6');
					break;
				}

				if (text[i] == '7') {
					decrypted.push_back('7');
					break;
				}

				if (text[i] == '8') {
					decrypted.push_back('8');
					break;
				}

				if (text[i] == '9') {
					decrypted.push_back('9');
					break;
				}
			}
		}

		int f = 0;
		while (f != decrypted.size()) //запись шифрованного текст в output.txt
		{
			OUTPUTFILE2 << decrypted[f];
			f++;
		}
		OUTPUTFILE2.close();


	}



};

int main(int args, const char * argv[])
{
	int N = 0;
	vector<char> alphabet;
	vector<char> NEWalphabet;
	setlocale(LC_ALL, "rus");
	HelloWorld A;
	srand(time(0));
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(97, 122);
	int x = 0;
	cout << "Введите количество символов для генерации кодового слова" << endl;
	cin >> N;
	map<int, char> unique;
	while (unique.size() != N)
	{
		 x = distribution(generator);
		 unique.emplace(x, (char(x)));
	}
	int k = 0;
	for (int i = 97;i < 123;i++) //заполнение массива начальным алфавитом
	{
		alphabet.push_back((char(i)));
		k++;
	}
	vector<char> password; //выбираем кодовое слово
	for (auto it = unique.begin(); it != unique.end(); ++it)
	{
		password.push_back(it->second);

	}
	cout << "KEYWORD --> ";
	show_vector(password);
	cout << endl;
	cout << "Old alphabet-->";
	show_vector(alphabet);
	

	NEWalphabet = A.CreateNewAlpabet(alphabet, password); //создание нового алфавита
	cout << endl;
	cout << "New alphabet-->";
	show_vector(NEWalphabet);

	vector<char> encryptedtext=A.FileEncoding(alphabet,NEWalphabet); // шифруем текст новым алфавитом и записываем в output.txt

	A.Chastotniy_analiz(encryptedtext); //дешифрируем методом частотного анализа
	cout << endl;
	system("pause");
	return 0;
}