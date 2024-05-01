# objektinis1
# V2.0 
## Sukurta dokumentacija naudojant Doxygen

<img width="1702" alt="Screenshot 2024-05-01 at 19 34 48" src="https://github.com/kamzob/objektinis2/assets/149818908/251e6d51-9d5d-4621-8abd-5776f9df6d9b">

<img width="985" alt="Screenshot 2024-05-01 at 14 42 42" src="https://github.com/kamzob/objektinis2/assets/149818908/ccc1e375-ef8a-4070-a9c8-91843d5df73e">

## Unit Test Instrukcija
1. Per virtualią mašiną (nes naudoju MacBook) parsisiunčiau [Visual Studio Community 2022](https://visualstudio.microsoft.com/downloads/)
2. Tada pasirinkau Create New project -> paieškos laukelyje įvedžiau test - > pasirinkau Unit Native Test
3. Tada prie projekto pridėjau funkcijos.h ir biblioteka.h failus, su kuriais atlikau testatvimą.
4. Svarbu, kad nustatymuose Project-> properties-> C/C++ -> Pecompiled Headers -> Pažymėti Not Using
<img width="788" alt="Screenshot 2024-05-01 at 15 01 32" src="https://github.com/kamzob/objektinis2/assets/149818908/57a4cd12-a5cc-4803-9abc-20ead6f2350b">


## Testas

```
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
```
## Testo rezultatai

<img width="797" alt="Screenshot 2024-05-01 at 14 15 46" src="https://github.com/kamzob/objektinis2/assets/149818908/fbcfd9ab-f03d-4065-b9ec-e017cb77a12c">


# [V1.1](https://github.com/kamzob/objektinis2/tree/v1.1)
Struct buvo pakeista į class, atlikti testavimai su flag'ais (O1, O2, O3), greičiausiai veikė su O3 flag'u.
# [V1.2](https://github.com/kamzob/objektinis2/tree/v1.2)
Realizuota Rule of Five, panaudotas įvesties/išvesties operatorių perdengimas.
# [V1.5](https://github.com/kamzob/objektinis2/tree/v1.5)
Buvusi klasė padalinta i dvi naujas bazinę (abstrakti) Zmogus ir išvestinę derived Vartotojas.

# Naudojimo instrukcija
1. Parsisiųskite programą iš [versijų puslapio](https://github.com/kamzob/ojektinis1/tags), o jei kažkas neaišku, pridedu nuorodą: https://blog.hubspot.com/website/download-from-github. Jums reikia šių failų: **makefile, v2.cpp, biblioteka.h, funkcijos.cpp, funkcijos.h**
2. Parsisiųskite ir įsidiekite C++ kompiliatorių (jei esate windows naudotojas pridedu nuorodą su žingsniais: https://medium.com/@samsorrahman/how-to-run-a-makefile-in-windows-b4d115d7c516)
3. Parsisiųskite (jei esate MacBook naudotojas) Xcode: https://www.youtube.com/watch?v=LBYj-xVvM1k, o visoms OS tinka Visual Studio: https://www.youtube.com/watch?v=DMWD7wfhgNY.
4. Tuomet jei naudojat MacBook, nueinate į ta aplanką, kuriame yra visi parsisiųsti failai, spaudžiate dešinį pelės klavišą ir Open in terminal: 
<img width="234" alt="Screenshot 2024-03-19 at 23 16 19" src="https://github.com/kamzob/ojektinis1/assets/149818908/9e516c7d-9673-4cc8-aea2-fd1eafef7e11">

5. Jei esat kitos OS naudotojai, tai nukopijuojat pathname, atsidarote terminalą, rašote cd ir įklijuojate kelią iki jūsų aplankalo.
6. Tada galit parašyti ls, spaudžiate enter ir turėtumėte matyti visus failus, esančius jūsų aplanke.
7. Instrukcija macbook (UNIX) naudotojams:
   
   Įrašykite į terminalą:  make pagrindine, spauskite enter
   
   Įrašykite į terminalą:  make funkcijos, spauskite enter
   
   Įrašykite į terminalą:  make prog, spauskite enter
    
   Įrašykite į terminalą:  ./prog, spauskite enter
   
8. Instrukcija Windows naudotojams:

   Įrašykite į terminalą:  mingw32-make pagrindine, spauskite enter

   Įrašykite į terminalą:  mingw32-make funkcijos, spauskite enter

   Įrašykite į terminalą:  mingw32-make prog, spauskite enter

   Įrašykite į terminalą:  ./prog, spauskite enter
   

   
   
    
Čia pateikiu pavyzdį:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/801841b2-a2a3-49d2-8caa-88f6be2e79b1">
# Programos naudojimas
1. Jei neturite testavimo failų, spauskite 3, jie bus sugeneruojami automatiškai.
2. Spauskite 4 jei norite dirbti su sugeneruotais failais.
3. Paspaudę 4 jūs turėsite pasirinkti pagal ka noresite, kad rikiuotu duomenis ir isvestu galutini pazymi: 0 - pagal vidurkį, 1 - pagal medianą.
4. Tuomet jūs turėsite pasirinkti strategiją:

1 strategija (ji skaičiuos gan greitai, tačiau labai neefektyvi atminties atžvilgiu): Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargsai" ir "laimingi". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargsai arba laimingi).

2 strategija (šis būdas efektyvesnis atminties atžvilgiu, tačiau su didesniais konteineriais, pvz. vector gali būti skausmingas, tačiau su list veikia puikiai): Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargsas, jį turime įkelti į naująjį "vargsai" konteinerį ir ištrinti iš bendro studentai konteinerio.

3 strategija (šį būdą ir patarčiau naudoti, nes atminties užima panašiai kaip ir 2 strategija, tačiau dėl remove_if efektyvumo veikia žymiai sparčiau): perdaryta 2 strategija, naudojant efektyvius skirstymo būdus.

5. Dabar jums reikės pasirinkti, su kokio dydžio failu norėsite dirbti: 1000, 10000, 100000, 1000000, 10000000.
6. Po šio pasirinkimo ekrane jūs matysite rezultatus su kiekvienu konteineriu (vector, list, deque):
   
   Skaitymo iš failo laiką
   
   Rikiavimo didėjimo tvarka pagal galutinį pažymį (su vidurkiu ar mediana kaip pasirinkote) laiką
   
   Skirstymo į atskirus konteinerius laiką.
7. Po išvestų rezultatų, jus grąžins į meniu su failų dydžiais, jei norėsite pakeisti strategiją arba galutinio pažymio skaičiavimą, spauskite 6 - baigti darbą, jus grąžins į pradinį meniu (1 punktas) ir kartokite viską iš pradžių, o jei norite tęsti darbą - pasirinkite su kokiu kitu failu norėsite dirbti.
8. Surikiuoti studentai ir jų galutiniai pažymiai, dirbant su failais (4 punktas), išvesti failuose:

   kietekai.txt, vargsiukai.txt (vector)
   
