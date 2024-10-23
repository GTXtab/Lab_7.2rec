#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2rec/Lab_7.2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int row[5] = { 5, 3, 6, 1, 8 };

			int result = Search(row, 5, 0, 0);

			Assert::AreEqual(3, result);
		}
	};
}
