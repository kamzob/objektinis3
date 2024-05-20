#include "pch.h"
#include "CppUnitTest.h"
#include "vektorius.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VektoriusTestavimas
{
	TEST_CLASS(VektoriusTestavimas)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
			Vektorius<int> v1;
			Assert::IsTrue(v1.empty());
			Assert::AreEqual(static_cast<size_t>(0), v1.size());
		}
		TEST_METHOD(InitializerListConstructor)
		{
			Vektorius<int> v{ 1, 2, 3, 4 };
			Assert::AreEqual(static_cast<size_t>(4), v.size());
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(3, v[2]);
			Assert::AreEqual(4, v[3]);
		}

		TEST_METHOD(CopyConstructor)
		{
			Vektorius<int> v3{ 1, 2, 3, 4 };
			Vektorius<int> v4(v3);
			Assert::AreEqual(v3.size(), v4.size());
			Assert::AreEqual(v3[0], v4[0]);
			Assert::AreEqual(v3[1], v4[1]);
			Assert::AreEqual(v3[2], v4[2]);
			Assert::AreEqual(v3[3], v4[3]);
		}
		TEST_METHOD(MoveConstructor)
		{
			Vektorius<int> v5{ 1, 2, 3, 4 };
			Vektorius<int> v6(std::move(v5));
			Assert::AreEqual(static_cast<size_t>(0), v5.size());
			Assert::IsTrue(v5.empty());
			Assert::AreEqual(1, v6[0]);
			Assert::AreEqual(2, v6[1]);
			Assert::AreEqual(3, v6[2]);
			Assert::AreEqual(4, v6[3]);
			Assert::IsTrue(v5.empty());
		}
		TEST_METHOD(CopyAssignmentOperatorius)
		{
			Vektorius<int> v3{ 1, 2, 3, 4 };
			Vektorius<int> v4;
			v4 = v3;
			Assert::AreEqual(v3.size(), v4.size());
			Assert::AreEqual(v3[0], v4[0]);
			Assert::AreEqual(v3[1], v4[1]);
			Assert::AreEqual(v3[2], v4[2]);
			Assert::AreEqual(v3[3], v4[3]);
		}
		TEST_METHOD(MoveAssignmentOperatorius)
		{
			Vektorius<int> v5{ 1, 2, 3, 4 };
			Vektorius<int> v6;
			v6 = std::move(v5);
			Assert::AreEqual(static_cast<size_t>(0), v5.size());
			Assert::IsTrue(v5.empty());
			Assert::AreEqual(1, v6[0]);
			Assert::AreEqual(2, v6[1]);
			Assert::AreEqual(3, v6[2]);
			Assert::AreEqual(4, v6[3]);
			Assert::IsTrue(v5.empty());
		}
		TEST_METHOD(PushBack)
		{
			Vektorius<int> v;
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);

			Assert::AreEqual(static_cast<size_t>(3), v.size());
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(3, v[2]);
		}
		TEST_METHOD(PopBack)
		{
			Vektorius<int> v{ 1, 2, 3, 4 };
			v.pop_back();

			Assert::AreEqual(static_cast<size_t>(3), v.size());
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(3, v[2]);
		}
		TEST_METHOD(Clear)
		{
			Vektorius<int> v{ 1, 2, 3, 4 };
			v.clear();
			Assert::IsTrue(v.empty());
		}
		TEST_METHOD(Insert)
		{
			Vektorius<int> v{ 1, 2, 4, 5 };
			auto it = v.begin() + 2;
			v.insert(it, 3);

			Assert::AreEqual(static_cast<size_t>(5), v.size());
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(3, v[2]);
			Assert::AreEqual(4, v[3]);
			Assert::AreEqual(5, v[4]);
		}
		TEST_METHOD(Erase)
		{
			Vektorius<int> v{ 1, 2, 3, 4, 5 };
			auto it = v.begin() + 2;
			v.erase(it);

			Assert::AreEqual(static_cast<size_t>(4), v.size());
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(4, v[2]);
			Assert::AreEqual(5, v[3]);
		}
		TEST_METHOD(Resize)
		{
			Vektorius<int> v{ 1, 2, 3, 4, 5 };
			Assert::AreEqual(static_cast<size_t>(5), v.size());
			v.resize(3);
			Assert::AreEqual(static_cast<size_t>(3), v.size());
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(3, v[2]);

		}


	};
}
