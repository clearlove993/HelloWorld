#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
using namespace std;

class WordCount
{
	private:
		int charNum;      //�ַ��� 
		int wordsNum;     //������
		int sentencesNum; //������
	public:
		bool Init();     //���г�ʼ���� 
		void Count();    //���м��� 
		void Print();    //������ 
};

int main()
{
	string command;  //��������� 
	Wordcount a;     
	while( getline(cin, command) )
	{
		a.Init();
		a.Count();
		a.Print();
	}
	return 0;
} 
