#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lib\Parking.h"
#include <Windows.h>
#include <time.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PaymentSystemTests
{
	TEST_CLASS(PaymentSystemUnitTest)
	{
	public:

		TEST_METHOD(PSys_create)
		{
			PaymentSystem psys = PaymentSystem();
		}
	};
}
