#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12.1_C/lab_12.1_C.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest121C
{
	TEST_CLASS(UnitTest121C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(isValidForFunction(-1), false);
		}
	};
}
