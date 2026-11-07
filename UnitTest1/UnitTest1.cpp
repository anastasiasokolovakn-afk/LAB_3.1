#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB3.1/Car.h"
#include "../LAB3.1/Lorry.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCarInitialization)
		{
			Car c("Toyota", 4, 150.0);

			Assert::AreEqual(string("Toyota"), c.GetBrand());
			Assert::AreEqual(4, c.GetCylinders());
			Assert::AreEqual(150.0, c.GetPower());
		}

		TEST_METHOD(TestLorryInheritance)
		{
			Lorry l("MAN", 8, 400.0, 20.0);

			Assert::AreEqual(string("MAN"), l.GetBrand());
			Assert::AreEqual(8, l.GetCylinders());
			Assert::AreEqual(400.0, l.GetPower());

			Assert::AreEqual(20.0, l.GetCapacity());
		}

		TEST_METHOD(TestVariantMethods)
		{
			Lorry l("Ford", 6, 250.0, 15.0);

			l.ReassignBrand("Ford Trucks");
			l.ChangePower(300.0);
			l.ChangeCapacity(18.5);

			Assert::AreEqual(string("Ford Trucks"), l.GetBrand());
			Assert::AreEqual(300.0, l.GetPower());
			Assert::AreEqual(18.5, l.GetCapacity());
		}

		TEST_METHOD(TestSubstitutionPrinciple)
		{
			Lorry l("Scania", 8, 500.0, 25.0);

			Car c = l;
			Assert::AreEqual(string("Scania"), c.GetBrand());
			Assert::AreEqual(8, c.GetCylinders());
			Assert::AreEqual(500.0, c.GetPower());
		}
	};
}