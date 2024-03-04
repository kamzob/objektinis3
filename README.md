# objektinis1
# v0.4 versija
1. Sukurta failų generavimo funkcija "FailuGeneravimas", kuri atitinkamai pagal vartotojo pasirinkimą gali generuoti: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų.
2. Vardai ir pavardės generuojami šabloniniai, tuo tarpu ND skaičius imamas atsitiktinis ir nd pažymiai bei egzamino rezultatas generuojami atsitiktinai.
3. Funkcijoje "RusiavimasDviGrupes" studentai išrūšiuojami didėjimo tvarka pagal galutinį pažymį ir išskirstomi į vargšus (jei galutinis < 5.0) ir laimingus (jei galutinis >= 5.0).
4. Funkcijoje "spausdintiLaimingiVargsai" išrūšiuoti studentai išspausdinami atitinkamai į failus: vargsiukai.txt ir kietekai.txt
# Testavimas
## Nuotraukos 
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/ffd60808-7ee4-445e-b4c2-f71e468ee779">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/40bd40ef-3e8a-49d5-a15b-2c7a5411bad2">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/d0c8b9e7-34dd-42f4-9f3a-e781047b4a0b">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/e9e0c859-eca3-4cca-9b81-09a85b5f2d8a">
<img width="452" alt="image" src="https://github.com/kamzob/ojektinis1/assets/149818908/6d2fa9e5-f00e-4aaa-85a6-8217b0726562">

## Lentele

| Studentu kiekis | Failo generavimas | Skaitymas | Rikiavimas | Rusiavimas i konteinerius | Vargsiuku irasymas | Kieteku irasymas | Visas laikas |
|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|
| 1000 | 0.00420225 sek. | 0.00581221 sek. | 0.000409834 sek. | 0.00040825 sek. | 0.00123225 sek. | 0.00156313 sek. | 0.013741 sek. |
| 10000 | 0.0443222 sek. | 0.120868 sek. | 0.00501208 sek. | 0.00401629 sek. | 0.00746621 sek. | 0.0103518 sek. | 0.192859 sek. |
| 100000 | 0.361036 sek. | 1.25446 sek. | 0.0467972 sek. | 0.0445358 sek. | 0.0756157 sek. | 0.105351 sek. | 1.90049 sek. |
| 1000000 | 1.87465 sek. | 8.06188 sek. | 0.422601 sek. | 0.448288 sek. | 0.731535 sek. | 1.03456 sek. | 12.6925 sek. | 
| 10000000 | 36.2127 sek. | 130.176 sek. | 5.20619 sek. | 4.92128 sek. | 8.7346 sek. | 12.5703 sek. | 200.035 sek. |
