#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab №7.3 it/Lab №7.3 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestColFunction)
		{
			const int k = 3;
			int column[3] = { -3, 5, -7 };

			int result = col(column, k);

			Assert::AreEqual(10, result);
		}
	};
}
