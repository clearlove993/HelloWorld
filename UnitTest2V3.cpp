#include "pch.h"
#include "CppUnitTest.h"
#include"../Project2/WordCount.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(Init)
		{
			string filename = "words.txt";
			WordCount wc(filename);
			Assert::AreEqual(0, wc.sentencesNum);
		}

		TEST_METHOD(charasctesr)
		{
			string filename = "words.txt";
			WordCount wc(filename);
			wc.Count();
			Assert::AreEqual(179, wc.charNum);
		}
		TEST_METHOD(word)
		{
			string filename = "words.txt";
			WordCount wc(filename);
			wc.Count();
			Assert::AreEqual(17, wc.wordsNum);
		}
		TEST_METHOD(sentences)
		{
			string filename = "words.txt";
			WordCount wc(filename);
			wc.Count();
			Assert::AreEqual(1, wc.sentencesNum);
		}
		TEST_METHOD(line)
		{
			string filename = "words.txt";
			WordCount wc(filename);
			wc.Count();
			Assert::AreEqual(7, wc.lineNum);
		}
		TEST_METHOD(blank_line)
		{
			string filename = "words.txt";
			WordCount wc(filename);
			wc.Count();
			Assert::AreEqual(0, wc.blankLineNum);
		}
		TEST_METHOD(comment_line)
		{
			string filename = "words.txt";
			WordCount wc(filename);
			wc.Count();
			Assert::AreEqual(2, wc.commentNum);
		}
	};
}
