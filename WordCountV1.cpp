#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
using namespace std;

class WordCount
{
	private:
		int charNum;      //字符数 
		int wordsNum;     //单词数
		int sentencesNum; //句子数
	public:
		bool Init();     //进行初始处理 
		void Count();    //进行计数 
		void Print();    //输出结果 
};

int main()
{
	string command;  //输入的命令 
	Wordcount a;     
	while( getline(cin, command) )
	{
		a.Init();
		a.Count();
		a.Print();
	}
	return 0;
} 
