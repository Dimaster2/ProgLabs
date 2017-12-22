#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <ctime>
#include <map>
using namespace std;

class Filtr
{
public:
	multimap <int,string> CORRECT; //����� ��� ������
	multimap <int,string> NOT_CORRECT; //����� � ��������
	multimap <int, string> CORRECTED; //������������
	multimap <int, string> COMBINE; //����������� ������������ ���� � �������������

	void Analization(vector<string> text, int word_count) // ��������� �� ����� � �������� � ���
	{		
		int i= 0;
		int j = 0;
		int a = 0;
		int b = 0;
		while (i != word_count) //������� ���� ����
			{
			
			for (j = 0;j < text[i].length();j++) //�������� ������� ������� ������������ ����� [i]
				{
					if (isalpha(text[i][j])) a++;  
					if (isdigit(text[i][j])) b++;
				}
			if (a == text[i].length()) 	CORRECT.insert(pair<int, string>(i,text[i])); //���� ����� �������, ������ �� ���� - ������� � "��� ������"
			else  if (b == text[i].length()) 	CORRECT.insert(pair<int, string>(i, text[i])); //���� ����� �� � �����, � ��� ���������������, �� ������� � "��� ������"
			else NOT_CORRECT.insert(pair<int, string>(i,text[i])); //�� �������������
			i++;
			a = 0;
			b = 0;
			}
	}

	void correction() //���������� ����� � ������ "�� �������������"
	{
		
		int k = 0;
		for (const auto& e : NOT_CORRECT)
		{
			string temp;
			string temp2;
			string temp3;
			int i = 0;
			int k = 0;
			int id = -1;
			temp = e.second;
			
			for (i = 0;i < temp.length();i++) //������� ����� �� �����
			{
				if (!isdigit(temp[i])) //���� �� ����� ���������� � temp2
				{
					temp2.insert(temp2.end(), temp[i]);
				}
			}

			for (i = 0;i < temp2.length();i++)
			{
				if (isalpha(temp2[i])) //���� ����� �������� ���������� � temp3
				{
					temp3.insert(temp3.end(), temp2[i]); //morn,,,ing
				}
				else
				{   
					
					 for(k=i;k<temp2.length();k++)
					 {
						 if (isalpha(temp2[k])) { i = k-1; id = 0;break; } //���� ������ ������ � ����� �����, ��������� �������� �� ���
					 }

				  if (id!=0) { temp3.insert(temp3.end(), temp2[i]);  break; } //���� �� ����� ����� ������, �� ��� ����� �����, ��� ���������� ����� ���������, �������� ������ ����
				  id = -1;
					
				}
			}
			CORRECTED.emplace(e.first, temp3); //���������� � ������������ ������
		}
	}

	vector <string> ReWork() //�������
	{
		vector <string> forOUTPUT;
		int i = 0;
		for (const auto& e : CORRECT)
		{
			COMBINE.emplace(e.first, e.second);
		}
		for (const auto& e : CORRECTED)
		{
			COMBINE.emplace(e.first, e.second);
		}

		for (const auto& e : COMBINE)
		{
			forOUTPUT.push_back(e.second);
			i++;
		}

		
		return forOUTPUT;
	}
};

int main(int args, const char * argv[])
{
	setlocale(LC_ALL, "rus");
	string temp;
	Filtr Check;
	vector<string> slovechki;
	ifstream InputTXT("input.txt");
	int slovechki_count = 0;
	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000; // CLOCKS_PER_SEC - ���������� ������ ��������� ����� � �������
	clock_t end_time = clock() + 2* CLOCKS_PER_MSEC; // ����� ���������� 2 ms
	
	while (clock() < end_time) // ���� �������� ������� 
	{
	InputTXT >> temp;
	slovechki.push_back(temp);
	slovechki_count++;
	}
	cout <<"���������� ����, ��������� �� ��������� ���������� ������� - "<< slovechki_count << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	InputTXT.close();
	for (int i = 0;i < slovechki.size();i++)
	{
		cout << slovechki[i];
		cout << " ";
	}
	cout << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	Check.Analization(slovechki, slovechki_count); // ��������� �� ����� � �������� � ���
	Check.correction(); //���������� ����� � ��������
	slovechki = Check.ReWork(); //��������� ������������ ����� � �����������
	for (int i = 0;i < slovechki.size();i++)
	{
		cout << slovechki[i];
		cout << " ";
	}
	cout << endl;
	ofstream OutputTXT("output.txt"); //������ � ���� 
	for (int i=0;i<slovechki.size();i++)
	{
		OutputTXT << slovechki[i];
		OutputTXT << " ";
	}
	OutputTXT.close();
	
	system("pause");
	return 0;
}