# objektinis1
# V1.0 
# Testavimas 1
Su iš anksčiau sugeneruotais 1000, 10000, 100000, 1000000, 10000000 failais bus atliekamas testavimas su skirtingais konteineriais: vector, list, deque.
## Testavimo sistemos parametrai
1. Apple M2 chip 8-core CPU 
2. 16GB RAM 
3. 256GB SSD
## 1 dalies rezultatai
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/641ffeff-d175-4a3a-ba75-008122e0a28e">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/fb48a627-5dbc-442d-bdbe-17c9145a87c6">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/484a30b6-fceb-485a-841b-c5226e7b1c43">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/cdca3e6b-2701-4135-8182-748f90d0ea3e">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/cd6883d2-42e5-4175-a483-404d2cb03b25">

# Testavimas 2
## 1 strategija
Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai).
Ši strategija ypač neefektyvi dėl naudojamos atminties kiekio.
### 1000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/b2abb4d9-f3ad-4e49-91e9-bb5fa2880523">
<img width="223" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/a008628f-78ba-42dd-8636-f8c6213a63f7">

### 10000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/20fbab8f-a830-4f6a-9964-2b06c405b59b">
<img width="224" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/d287f609-6bb3-4e91-aa58-fa8a6312feab">

### 100000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/ecb9e52c-0927-4c26-a687-7f84a2a85b91">
<img width="221" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/6b7ac60f-0152-46b9-870e-ac9e985e41ba">

### 1000000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/1f5d22d0-5431-4130-ac20-8e4e1f218a16">
<img width="223" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/4d263864-578c-4356-883e-517b77166a28">

### 10000000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/66b6f5ea-416d-44da-b4c0-b8920ab94c3e">
<img width="217" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/503abb76-6223-4673-84e7-985ba996d966">

## 2 strategija
Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai. 
Dirbant su šia strategija, atminties naudojama žymiai mažiau nei dirbant su 1, tačiau ši strategija ypač skausminga vector konteineriams.
### 1000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/5381066e-a37d-427e-8713-420628da1c81">
<img width="222" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/435a3404-4df3-4227-bc46-8a1e616e0e40">

### 10000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/0d7683f3-c0f0-47ab-8ecc-d38454cb8ae2">
<img width="222" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/476d4e12-c188-42b9-995e-a701f367f206">

### 100000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/216559e4-2faa-4a6e-bcca-aa32e9f50d6c">
<img width="230" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/94f33fdc-ee9b-4c74-b050-53b1df7505de">

### 1000000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/3f6a19f2-409b-46ad-bd37-ad4cc3c8b870">
<img width="238" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/b15aefb0-755e-4f56-afd9-2850cf0da519">
Programa buvo palikta veikti per naktį, kadangi vektoriaus skirstymo laikas buvo labai didelis.

### 10000000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/fe061623-ebfe-4734-b6a8-4c0e79bc9e6a">
<img width="227" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/12d42395-81ef-48f3-a7f0-ecfa3b345dfd">
Pateikiami rezultatai tik su list ir deque, nes vector naudojant 2 strategiją per ilgas skirstymo laikas, kadangi kiekvieną kartą ištrynus elementą, kiekvieną vektoriaus elementą, esantį prieš trinamą elementą, reikia perstumti per 1 poziciją atgal.

## 3 strategija
Visų konteinerių efektyvumui pagerinti naudojama remove_if
### 1000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/2c965988-821d-4cf4-9395-19f5bbe285ef">
<img width="230" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/230f6203-ee6b-43b8-a3be-34c573eceaf9">

### 10000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/e8db6740-7a03-492a-bbb7-ab6ad4c77bcc">
<img width="219" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/0a129abe-1da1-4426-b350-e35e91c4a13f">

### 100000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/212b9534-3a83-4942-a320-1d674059d1aa">
<img width="229" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/c2d5049d-457f-47b9-9159-5f33909b8d16">

### 1000000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/e5c97362-7de1-4454-bf75-7ff7aa8fea69">
<img width="236" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/384d08b7-3fbc-4408-8c79-32c7c360cb5a">

### 10000000:
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/ea57c3aa-c8b3-4e08-9cca-d82dd9a4e935">
<img width="218" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/23a8eebb-c139-4423-9ded-2e10154bba80">

## Rezultatu lentele
| Studentu kiekis | vector1 (sek.) | vector2 (sek.) | vector3 (sek.) | list1 (sek.) | list2 (sek.) | list3 (sek.) | deque1 (sek.) | deque2 (sek.) | deque3 (sek.) |
|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000 | 0.000513292 | 0.0183459 | 0.000296042 | 0.000366375 | 0.000278291 | 0.000325208 | 0.000264833 | 0.000368166 | 0.000274 |
| 10000 | 0.00418696 | 1.79028 | 0.0032695 | 0.0032925 | 0.00274708 | 0.00255521 | 0.00271683 | 0.00343221 | 0.00279658 |
| 100000 | 0.0407465 | 186.712 | 0.0355116 | 0.035529  | 0.0326913  | 0.032074 | 0.0292748 | 0.037706 | 0.0306626 |
| 1000000 | 0.517403 | 45229.9. | 0.406475 | 0.370716 | 0.456799 | 0.396621 | 0.346574 |0.453579 | 0.357981 |
| 10000000 | 5.19888 | - | 4.51907 | 4.09259 | 4.30961 | 4.64485 | 4.08952 | 5.23358 | 5.79361|
# Naudojimo instrukcija
1. Parsisiųskite programą iš [versijų puslapio](https://github.com/kamzob/ojektinis1/tags), o jei kažkas neaišku, pridedu nuorodą: https://blog.hubspot.com/website/download-from-github. Jums reikia šių failų: **makefile, v1.cpp, biblioteka.h, funkcijos.cpp, funkcijos.h**
2. Parsisiųskite ir įsidiekite C++ kompiliatorių
3. Parsisiųskite (jei esate MacBook naudotojas) Xcode: https://www.youtube.com/watch?v=LBYj-xVvM1k, o visoms OS tinka Visual Studio: https://www.youtube.com/watch?v=DMWD7wfhgNY.
4. Tuomet jei naudojat MacBook, nueinate į ta aplanką, kuriame yra visi parsisiųsti failai, spaudžiate dešinį pelės klavišą ir Open in terminal: 
<img width="234" alt="Screenshot 2024-03-19 at 23 16 19" src="https://github.com/kamzob/ojektinis1/assets/149818908/9e516c7d-9673-4cc8-aea2-fd1eafef7e11">

5. Jei esat kitos OS naudotojai, tai nukopijuojat pathname, atsidarote terminalą, rašote cd ir įklijuojate kelią iki jūsų aplankalo.
6. Tada galit parašyti ls, spaudžiate enter ir turėtumėte matyti visus failus, esančius jūsų aplanke.
7. Įrašykite į terminalą:  make pagrindine, spauskite enter
8. Įrašykite į terminalą:  make funkcijos, spauskite enter
9. Įrašykite į terminalą:  make prog, spauskite enter
10. Įrašykite į terminalą:  ./prog, spauskite enter
    
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
   
   kietekaiList.txt, vargsiukaiList.txt (list)

   kietekaideq.txt, vargsiukaideq.txt (deque)
