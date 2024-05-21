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
			Vektorius<int> v2{ 1, 2, 3, 4, 5 };
			Assert::AreEqual(static_cast<size_t>(5), v2.size());
			v2.resize(6);
			Assert::AreEqual(1, v2[0]);
			Assert::AreEqual(2, v2[1]);
			Assert::AreEqual(3, v2[2]);
			Assert::AreEqual(4, v2[3]);
			Assert::AreEqual(5, v2[4]);
			Assert::AreEqual(0, v2[5]);

		}
		TEST_METHOD(AtMetodas)
		{
			Vektorius<int> v{ 1, 2, 3, 4, 5 };

			Assert::AreEqual(1, v.at(0));
			Assert::AreEqual(2, v.at(1));
			Assert::AreEqual(3, v.at(2));
			Assert::AreEqual(4, v.at(3));
			Assert::AreEqual(5, v.at(4));
		}
		TEST_METHOD(IndeksoOperatorius)
		{
			Vektorius<int> v{ 1, 2, 3, 4, 5 };

			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(3, v[2]);
			Assert::AreEqual(4, v[3]);
			Assert::AreEqual(5, v[4]);
		}
		TEST_METHOD(Capacity)
		{
			// Test default constructor
			Vektorius<int> v1;
			Assert::AreEqual(static_cast<size_t>(0), v1.capacity());

			// Test fill constructor
			Vektorius<int> v2(5, 10); // Initialize with 5 elements, each of value 10
			Assert::AreEqual(static_cast<size_t>(5), v2.capacity());

			// Test push_back and automatic capacity increase
			Vektorius<int> v3;
			Assert::AreEqual(static_cast<size_t>(0), v3.capacity());
			v3.push_back(1);
			Assert::AreEqual(static_cast<size_t>(1), v3.capacity()); 
			v3.push_back(2);
			Assert::AreEqual(static_cast<size_t>(2), v3.capacity()); // Capacity 2
			v3.push_back(3);
			Assert::AreEqual(static_cast<size_t>(4), v3.capacity()); // Capacity dvigubeja iki 4
			v3.push_back(4);
			v3.push_back(5);
			Assert::AreEqual(static_cast<size_t>(8), v3.capacity()); // Capacity dvigubeja iki 8

			// Test reserve method
			Vektorius<int> v4;
			v4.reserve(10);
			Assert::AreEqual(static_cast<size_t>(10), v4.capacity());

			// Test resize method increasing size
			Vektorius<int> v5(5, 1); // 5 elements with value 1
			Assert::AreEqual(static_cast<size_t>(5), v5.capacity());
			v5.resize(10); // Resize to 10
			Assert::AreEqual(static_cast<size_t>(10), v5.capacity());

			// Test resize method decreasing size
			v5.resize(3); // Resize to 3
			Assert::AreEqual(static_cast<size_t>(10), v5.capacity()); // Capacity nesikeicia
		}
		TEST_METHOD(Begin)
		{
			// paprasto begin
			Vektorius<int> v3;
			v3.push_back(1);
			v3.push_back(2);
			v3.push_back(3);
			Assert::IsTrue(*v3.begin() == 1);
			Assert::IsTrue(*(v3.begin() + 1) == 2);
			Assert::IsTrue(*(v3.begin() + 2) == 3);

			// const Vektoriaus begin
			const Vektorius<int> v4 = v3;
			Assert::IsTrue(*v4.begin() == 1);
			Assert::IsTrue(*(v4.begin() + 1) == 2);
			Assert::IsTrue(*(v4.begin() + 2) == 3);
		}
		TEST_METHOD(Swap)
		{
			Vektorius<int> v1{ 1, 2, 3 };
			Vektorius<int> v2{ 4, 5, 6, 7 };

			v1.swap(v2);

			// Tikrinam v1
			Assert::AreEqual(static_cast<size_t>(4), v1.size());
			Assert::AreEqual(4, v1[0]);
			Assert::AreEqual(5, v1[1]);
			Assert::AreEqual(6, v1[2]);
			Assert::AreEqual(7, v1[3]);

			// tikrinam v2
			Assert::AreEqual(static_cast<size_t>(3), v2.size());
			Assert::AreEqual(1, v2[0]);
			Assert::AreEqual(2, v2[1]);
			Assert::AreEqual(3, v2[2]);
		}
		TEST_METHOD(Front)
		{
			Vektorius<int> v{ 1, 2, 3, 4 };

			Assert::AreEqual(1, v.front());

			// pakeiciam pirma elementa i 10
			v.front() = 10;
			Assert::AreEqual(10, v.front());
			Assert::AreEqual(10, v[0]);

			// ar kiti elementai liko savo vietose
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(3, v[2]);
			Assert::AreEqual(4, v[3]);
		}
		TEST_METHOD(Back)
		{
			Vektorius<int> v{ 1, 2, 3, 4 };

			Assert::AreEqual(4, v.back());

			// keiciam paskutini elementa i 10
			v.back() = 10;

			Assert::AreEqual(10, v.back());
			Assert::AreEqual(10, v[v.size() - 1]);

			// ar kiti elementai liko savo vietose
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(3, v[2]);
		}
		TEST_METHOD(AccessByIndexOutOfRange)
		{
			Vektorius<int> vec;
			vec.push_back(1);

			Assert::ExpectException<std::out_of_range>([&] { int x = vec[1]; });
		}
	};
}
