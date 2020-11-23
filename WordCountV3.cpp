#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
#include<sstream>
using namespace std;

class WordCount
{
private:
	vector <string> content;
	int charNum;      //字符数 
	int wordsNum;     //单词数
	int sentencesNum; //句子数
	int lineNum;      //代码行数 
	int blankLineNum; //空行数
	int commentNum;   //注释行数
public:
	WordCount(string);     //进行初始处理 
	void Count();          //进行计数 
	void Print(string);    //输出结果 
};

WordCount::WordCount(string fname)
{
	wordsNum = 0;
	sentencesNum = 0;
	lineNum = 0;
	blankLineNum = 0;
	commentNum = 0;
	ifstream openFile(fname, ios::ate);
	if (!openFile)
	{
		cout << "Open file error" << endl;
	}
	charNum = openFile.tellg();       //使用ifstream的类自带的函数进行字符串计数
	openFile.seekg(0);                //把读指针定于文件开头
	string line;
	while (getline(openFile, line))
	{
		content.push_back(line);    //以每一列的形式放入vector类型的content中
		lineNum++;
		if (line.length() == 0)
		{
			blankLineNum++;
		}
	}
}

void WordCount::Count()
{
	string line;
	for (int i = 0; i < lineNum; i++)   //每次处理一列
	{
		line = content[i];
		int nowPos;
		int lastPos;
		for (nowPos = 0, lastPos = 0; nowPos < line.length(); nowPos++)
		{
			if ((line[nowPos] == ' ' || line[nowPos] == '.' || line[nowPos] == '!' || line[nowPos] == '?') && line[lastPos] != ' ')
			{
				wordsNum++;
			}
			if (line[nowPos] == '.' || line[nowPos] == '!' || line[nowPos] == '?')
			{
				sentencesNum++;
			}
			if ((line[nowPos] == '/') && (line[nowPos + 1] == '/' || line[nowPos+ 1] == '*'))
			{
				commentNum++;
			}
			if (line[nowPos] == '*' && line[nowPos + 1] == '/')
			{
				commentNum++;
			}
			lastPos = nowPos;            
		}
	}
}

void WordCount::Print(string cmd)
{
	if (cmd == "-c")
	{
		cout << "Number of characters: " << charNum << endl;
	}
	else if (cmd == "-w")
	{
		cout << "Number of Words: " << wordsNum << endl;
	}
	else if (cmd == "-s")
	{
		cout << "Number of sentences: " << sentencesNum << endl;
	}
	else if (cmd == "-l")
	{
		cout << "Number of line: " << lineNum << endl;
	}
	else if (cmd == "-b")
	{
		cout << "Number of blank line: " << blankLineNum << endl;
	}
	else if (cmd == "-f")
	{
		cout << "Number of comment line: " << commentNum << endl;
	}
	else
	{
		cout << "error" << endl;
	}
}

bool CheckInput(string program, string cmd, string filename)
{
	if (program != "wc.exe")
	{
		cout << "please enter wc.exe at the begining." << endl;
		return false;
	}
	if ((cmd != "-c") && (cmd != "-w") && (cmd != "-s") && (cmd != "-l") && (cmd != "-b") && (cmd != "-f"))
	{
		cout << "Do not enter commands other than -c -w -s -l -b -f" << endl;
		return false;
	}
	return true;
}

int main()
{
	string command;  //输入的命令 
	while (getline(cin, command))
	{
		if (command == "quit")
		{
			break;
		}
		string program;
		string cmd;
		string filename;
		istringstream is(command);
		is >> program >> cmd >> filename;   //对命令进行划分 
		//cout<<program<<" "<<cmd<<" "<<filename<<endl; 

		if (CheckInput(program, cmd, filename))
		{
			WordCount a(filename);
			a.Count();
			a.Print(cmd);
		}
	}
	return 0;
}
