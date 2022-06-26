#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lib\Parking.h"
#include <Windows.h>
#include <time.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParkingTests
{
	TEST_CLASS(ParkingUnitTest)
	{
	public:
		
		TEST_METHOD(Parking_create)
		{
			PaymentSystem psys = PaymentSystem();
			Parking p1 = Parking(psys);
			Assert::AreEqual((size_t) 0, p1.getAllVehicles().size());
			Assert::AreEqual((size_t) 0, p1.getDamagedVehicles().size());
		}
		TEST_METHOD(Parking_addVehicle)
		{
			PaymentSystem psys = PaymentSystem();
			Parking p1 = Parking(psys);
			Vehicle v1 = Vehicle("Vehicle1", Tariff());
			Vehicle v2 = Vehicle("Vehicle2", Tariff());
			p1.addVehicle(&v1);
			p1.addVehicle(&v2);
			Assert::AreEqual((size_t)2, p1.getAllVehicles().size());
		}
		TEST_METHOD(Parking_takeVehicle_NotOnParking)
		{
			PaymentSystem psys = PaymentSystem();
			Parking p1 = Parking(psys);
			Vehicle v1 = Vehicle("Vehicle1", Tariff());
			Parking* p = nullptr;
			bool isNull = nullptr == v1.currentParking;
			Assert::IsTrue(isNull);
		}
		TEST_METHOD(Parking_takeVehicle_OnParking)
		{
			PaymentSystem psys = PaymentSystem();
			Parking p1 = Parking(psys);
			Vehicle v1 = Vehicle("Vehicle1", Tariff());
			Vehicle v2 = Vehicle("Vehicle2", Tariff());
			p1.addVehicle(&v2);
			Worker* w = new Worker("Wiktor");
			bool isVehicleTaken = p1.takeVehicle(v2, *w);
			Assert::AreEqual(isVehicleTaken, true);
			Assert::AreEqual((size_t)0, p1.getAllVehicles().size());
			delete w;
		}
		TEST_METHOD(Parking_takeVehicle_OnParkingDamaged)
		{
			PaymentSystem psys = PaymentSystem();
			Parking p1 = Parking(psys);
			Tariff t = Tariff(Currency("PLN", 10, 99));
			Vehicle v1 = Vehicle("Vehicle1", t);
			Vehicle v2 = Vehicle("Vehicle2", t);
			p1.addVehicle(&v2);
			AdultUser w = AdultUser("Wiktor");
			p1.takeVehicle(v2, w);
			Assert::AreEqual(size_t(0), w.getPayments().size());
			Assert::AreEqual(size_t(0), p1.getAllVehicles().size());
			bool areEqual = v2 == *w.getCurrentVehicle();
			Assert::IsTrue(areEqual);
		}
		TEST_METHOD(Parking_returnVehicle)
		{
			PaymentSystem psys = PaymentSystem();
			Parking p1 = Parking(psys);
			Tariff t = Tariff(Currency("PLN", 4294967295, 99));
			Vehicle v1 = Vehicle("Vehicle1", t);
			Vehicle v2 = Vehicle("Vehicle2", t);
			p1.addVehicle(&v2);
			p1.addVehicle(&v1);
			Worker w = Worker("Wiktor");
			AdultUser u = AdultUser("Gerald");
			u.topUp(Currency("PLN", 100000, 44));
			p1.takeVehicle(v2, w);
			p1.takeVehicle(v1, u);
			Assert::AreEqual(size_t(0), p1.getAllVehicles().size());
			p1.returnVehicle(v2, w);
			p1.returnVehicle(v1, u);
			Assert::AreEqual(size_t(1), u.getPayments().size());
		}
		TEST_METHOD(Parking_getDamagedVehicles)
		{
			PaymentSystem psys = PaymentSystem();
			Parking p1 = Parking(psys);
			Tariff t = Tariff(Currency("PLN", 100000000000, 99));
			Vehicle v1 = Vehicle("Vehicle1", t);
			Vehicle v2 = Vehicle("Vehicle2", t);
			p1.addVehicle(&v2);
			p1.addVehicle(&v1);
			AdultUser w = AdultUser("Wiktor");
			AdultUser u = AdultUser("Gerald");
			p1.takeVehicle(v2, w);
			p1.takeVehicle(v1, u);
			Component c = Component();
			c.setDamaged(true);
			v2.addComponent(&c);
			p1.returnVehicle(v2, w);
			p1.returnVehicle(v1, u);
			Assert::AreEqual(size_t(1), p1.getDamagedVehicles().size());
		}
	};
}
