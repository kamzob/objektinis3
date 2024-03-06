# objektinis1
# v0.4 versija
1. Sukurta failų generavimo funkcija "FailuGeneravimas", kuri atitinkamai pagal vartotojo pasirinkimą gali generuoti: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų.
2. Vardai ir pavardės generuojami šabloniniai, tuo tarpu ND skaičius imamas atsitiktinis ir nd pažymiai bei egzamino rezultatas generuojami atsitiktinai.
3. Funkcijoje "RusiavimasDviGrupes" studentai išrūšiuojami didėjimo tvarka pagal galutinį pažymį ir išskirstomi į vargšus (jei galutinis < 5.0) ir laimingus (jei galutinis >= 5.0).
4. Funkcijoje "spausdintiLaimingiVargsai" išrūšiuoti studentai išspausdinami atitinkamai į failus: vargsiukai.txt ir kietekai.txt
# Testavimas
## Nuotraukos 
### Tyrimas Nr. 1
<img width="407" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/892187c5-9d53-4d68-8af1-7313a844b913">;
### Tyrimas Nr. 2
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/db2337c1-7f37-43ad-8065-f6d4ab99e9c5">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/aefc131d-1f75-489f-bfd8-26ea364f55fd">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/a53923b1-e17f-47cb-97fa-671c0c7a61c0">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/459c90b8-79f8-4d54-909c-2b35597fd80f">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/08405a75-a080-4da9-9063-b33d4a96f4ba">




## Lentele

| Studentu kiekis | Skaitymas | Rikiavimas | Rusiavimas i konteinerius | Vargsiuku irasymas | Kieteku irasymas | Visas laikas |
|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000 | 0.021934 sek. | 0.000558417 sek. | 0.000403584 sek. | 0.000941333 sek. | 0.00120404 sek. | 0.0251143 sek. |
| 10000 | 0.11657 sek. | 0.00506167 sek. | 0.00424329 sek. | 0.0073165 sek. | 0.0103315 sek. | 0.145652 sek. |
| 100000 | 1.07174 sek. | 0.0484143 sek. | 0.0443029 sek. | 0.0722727 sek. | 0.100486 sek. | 1.35731 sek. |
| 1000000 | 10.7625 sek. | 0.501343 sek. | 0.503381 sek. | 0.729538 sek. | 1.03639 sek. | 13.6793 sek. | 
| 10000000 | 111.38 sek. | 5.31539 sek. | 4.8297 sek. | 9.08339 sek. | 12.7645 sek. | 145.408 sek. |
