#include "pch.h"
#include "CppUnitTest.h"
#include "../Project2/checkInput.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string program1 = "wc.exe";
			string program2 = "wjj.exe";
			string cmd1 = "-c";
			string cmd2 = "-w";
			string cmd3 = "-s";
			string cmd4 = "-l";
			string cmd5 = "-b";
			string cmd6 = "-f";
			string cmd7 = "-a";
			string filename = "fight.txt";
			Assert::AreEqual(true,CheckInput(program1,cmd1,filename));
			Assert::AreEqual(true, CheckInput(program1, cmd2, filename));
			Assert::AreEqual(true, CheckInput(program1, cmd3, filename));
			Assert::AreEqual(true, CheckInput(program1, cmd4, filename));
			Assert::AreEqual(true, CheckInput(program1, cmd5, filename));
			Assert::AreEqual(true, CheckInput(program1, cmd6, filename));
			Assert::AreEqual(false, CheckInput(program1, cmd7, filename));
			Assert::AreEqual(false, CheckInput(program2, cmd1, filename));
		}
	};
}
