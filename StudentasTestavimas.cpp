#include "pch.h"
#include "CppUnitTest.h"
#include "funkcijos.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentasTestavimas
{
	TEST_CLASS(StudentasTestavimas)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
            string vardas = "Jonas", pavarde = "Jonaitis";
            vector <int> pzm = { 4, 6, 8, 10 };
            int egz = 8;
            double vid = 7.0;
            double med = 7.0;
            double gal = 0.6 * vid + 0.4 * egz;
            double galm = 0.6 * med + 0.4 * egz;
            double galv = 0.6 * vid + 0.4 * egz;
            Vartotojas v1(vardas, pavarde, pzm, egz, vid, gal, med, galm, galv);
            Assert::AreEqual(v1.getVar(), vardas);
            Assert::AreEqual(v1.getPav(), pavarde);
            Assert::IsTrue(v1.getPaz() == pzm);
            Assert::AreEqual(v1.getEgz(), egz);
            Assert::AreEqual(v1.getVid(), vid);
            Assert::AreEqual(v1.getGal(), gal);
            Assert::AreEqual(v1.getMed(), med);
            Assert::AreEqual(v1.getGalmed(), galm);
            Assert::AreEqual(v1.getGalvid(), galv);
           
		}
        TEST_METHOD(CopyConstructor)
        {
            string vardas = "Jonas", pavarde = "Jonaitis";
            vector <int> pzm = { 4, 6, 8, 10 };
            int egz = 8;
            double vid = 7.0;
            double med = 7.0;
            double gal = 0.6 * vid + 0.4 * egz;
            double galm = 0.6 * med + 0.4 * egz;
            double galv = 0.6 * vid + 0.4 * egz;
            Vartotojas v1(vardas, pavarde, pzm, egz, vid, gal, med, galm, galv);
            Vartotojas v2(v1);
            Assert::AreEqual(v2.getVar(), v1.getVar());
            Assert::AreEqual(v2.getPav(), v1.getPav());
            Assert::IsTrue(v2.getPaz() == v1.getPaz());
            Assert::AreEqual(v2.getEgz(), v1.getEgz());
            Assert::AreEqual(v2.getVid(), v1.getVid());
            Assert::AreEqual(v2.getGal(), v1.getGal());
            Assert::AreEqual(v2.getMed(), v1.getMed());
            Assert::AreEqual(v2.getGalmed(), v1.getGalmed());
            Assert::AreEqual(v2.getGalvid(), v1.getGalvid());

        }
        TEST_METHOD(MoveConstructor)
        {
            string vardas = "Jonas", pavarde = "Jonaitis";
            vector <int> pzm = { 4, 6, 8, 10 };
            int egz = 8;
            double vid = 7.0;
            double med = 7.0;
            double gal = 0.6 * vid + 0.4 * egz;
            double galm = 0.6 * med + 0.4 * egz;
            double galv = 0.6 * vid + 0.4 * egz;
            Vartotojas v1(vardas, pavarde, pzm, egz, vid, gal, med, galm, galv);
            Vartotojas v3(std::move(v1));
            Assert::AreEqual(v3.getVar(), vardas);
            Assert::AreEqual(v3.getPav(), pavarde);
            Assert::IsTrue(v3.getPaz() == pzm);
            Assert::AreEqual(v3.getEgz(), egz);
            Assert::AreEqual(v3.getVid(), vid);
            Assert::AreEqual(v3.getGal(), gal);
            Assert::AreEqual(v3.getMed(), med);
            Assert::AreEqual(v3.getGalmed(), galm);
            Assert::AreEqual(v3.getGalvid(), galv);

            Assert::AreEqual(v1.getVar(), std::string(""));
            Assert::AreEqual(v1.getPav(), string(""));
            Assert::IsTrue(v1.getPaz() == std::vector<int>{});
            Assert::AreEqual(v1.getEgz(), 0);
            Assert::AreEqual(v1.getVid(), 0.0);
            Assert::AreEqual(v1.getGal(), 0.0);
            Assert::AreEqual(v1.getMed(), 0.0);
            Assert::AreEqual(v1.getGalmed(), 0.0);
            Assert::AreEqual(v1.getGalvid(), 0.0);

        }
        TEST_METHOD(CopyAssignmentOperatorius)
        {
            string vardas = "Antanas", pavarde = "Antanaitis";
            vector <int> pzm = { 4, 6, 8, 10 };
            int egz = 8;
            double vid = 7.0;
            double med = 7.0;
            double gal = 0.6 * vid + 0.4 * egz;
            double galm = 0.6 * med + 0.4 * egz;
            double galv = 0.6 * vid + 0.4 * egz;
            Vartotojas v4(vardas, pavarde, pzm, egz, vid, gal, med, galm, galv);
            Vartotojas v5;
            v5 = v4;
            Assert::AreEqual(v5.getVar(), v4.getVar());
            Assert::AreEqual(v5.getPav(), v4.getPav());
            Assert::IsTrue(v5.getPaz() == v4.getPaz());
            Assert::AreEqual(v5.getEgz(), v4.getEgz());
            Assert::AreEqual(v5.getVid(), v4.getVid());
            Assert::AreEqual(v5.getGal(), v4.getGal());
            Assert::AreEqual(v5.getMed(), v4.getMed());
            Assert::AreEqual(v5.getGalmed(), v4.getGalmed());
            Assert::AreEqual(v5.getGalvid(), v4.getGalvid());

        }
        TEST_METHOD(MoveAssignmentOperatorius)
        {
            string vardas = "Petras", pavarde = "Petraitis";
            vector <int> pzm = { 4, 6, 8, 10 };
            int egz = 8;
            double vid = 7.0;
            double med = 7.0;
            double gal = 0.6 * vid + 0.4 * egz;
            double galm = 0.6 * med + 0.4 * egz;
            double galv = 0.6 * vid + 0.4 * egz;
            Vartotojas v6(vardas, pavarde, pzm, egz, vid, gal, med, galm, galv);
            Vartotojas v7(std::move(v6));
            Assert::AreEqual(v7.getVar(), vardas);
            Assert::AreEqual(v7.getPav(), pavarde);
            Assert::IsTrue(v7.getPaz() == pzm);
            Assert::AreEqual(v7.getEgz(), egz);
            Assert::AreEqual(v7.getVid(), vid);
            Assert::AreEqual(v7.getGal(), gal);
            Assert::AreEqual(v7.getMed(), med);
            Assert::AreEqual(v7.getGalmed(), galm);
            Assert::AreEqual(v7.getGalvid(), galv);

            Assert::AreEqual(v6.getVar(), std::string(""));
            Assert::AreEqual(v6.getPav(), string(""));
            Assert::IsTrue(v6.getPaz() == std::vector<int>{});
            Assert::AreEqual(v6.getEgz(), 0);
            Assert::AreEqual(v6.getVid(), 0.0);
            Assert::AreEqual(v6.getGal(), 0.0);
            Assert::AreEqual(v6.getMed(), 0.0);
            Assert::AreEqual(v6.getGalmed(), 0.0);
            Assert::AreEqual(v6.getGalvid(), 0.0);

        }
	};
}
