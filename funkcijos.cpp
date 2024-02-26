//
//  funkcijos.cpp
//  v03
//
//  Created by Kamilė Zobėlaitė on 2024-02-27.
//

#include "funkcijos.h"
double Vidurkis(double suma, int nariai)
{
    if (nariai==0)
        return nariai;
    return suma/nariai;
    
}

double Mediana(vector<int> paz, int nariai)
{
    sort(paz.begin(), paz.end());
    if(nariai % 2 != 0)
        return double(paz[nariai/2]);
    return double(paz[(nariai-1) / 2] + paz[nariai/2] / 2.0);
    
}

void spausdinti(int rnkts, vector<Vartotojas>& vart, int n)// spausdina i ekrana ranka sugeneruotus duomenis
{
    while (!cin>>rnkts || (rnkts != 0 && rnkts !=1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida! Turite pasirinkti 0 (galutinis ivert. skaiciuojamas pagal vidurki) arba 1 (pagal mediana): \n";
        cin >> rnkts;
    }
    if (rnkts == 0)
    {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)<< "Galutinis (vid.)" << endl;
        cout << "---------------------------------------------------" << endl;
        for ( int i = 0; i < n; i++)
        {
           
            vart[i].gal = 0.4*vart[i].vid+0.6*vart[i].egz;
            cout << left << setw(15) << vart[i].pavarde << setw(15) << vart[i].vardas << setw(15) << fixed << setprecision(2) << vart[i].gal << endl;
        }
        
        
    }
    else if (rnkts == 1)
    {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)<< "Galutinis (med.)" << endl;
        cout << "---------------------------------------------------" << endl;
        for ( int i = 0; i < n; i++)
        {
            vart[i].gal = 0.4*vart[i].med+0.6*vart[i].egz;
            cout << left << setw(15) << vart[i].pavarde << setw(15) << vart[i].vardas << setw(15) << fixed << setprecision(2) << vart[i].gal << endl;
        }
        
    }
}
double generavimasPaz()
{
    return rand()%10+1;
}
string generavimasVard(int pas)
{
    vector<string> vyr_vard = {"Petras", "Arnas", "Jonas", "Juozas", "Aleksandras", "Kajus", "Kipras", "Mantas", "Matas", "Algis"};
    vector<string>  mot_vard = {"Agne", "Jurgita", "Emilija", "Kamile", "Rugile", "Selina", "Paulina", "Marija", "Ugne", "Monika"};
    if(pas==0)
        return vyr_vard[rand()%10];
    return mot_vard[rand()%10];
}
string generavimasPav(int pas)
{
    vector<string>  vyr_pav={"Petraitis", "Jonaitis", "Sabonis", "Macaitis", "Pocius", "Malinauskas", "Pociunas", "Grabauskas", "Girulis", "Zobela"};
    vector<string>  mot_pav={"Petraityte", "Macaite", "Girulyte", "Grabauskaite", "Genyte", "Rimkute", "Mockute", "Povilaityte", "Zobelaite", "Brazauskiene"};
    if(pas==0)
        return vyr_pav[rand()%10];
    return mot_pav[rand()%10];
}
void skaityti(vector<Vartotojas>& vart)
{
    string pavadinimas;;
    int opt;
    cout << "Egzistuojantys .txt failai kataloge: \n";
    system("ls -a *.txt");
    cout << "Pasirinkite, is kurio failo norite nuskaityti duomenis: " << endl;
    cout << "1 - kursiokai.txt\n";
    cout << "2 - studentai10000.txt\n";
    cout << "3 - studentai100000.txt\n";
    cout << "4 - studentai1000000.txt\n";
    cin >> opt;
    switch (opt) {
        case 1:
            pavadinimas = "kursiokai.txt";
            break;
        case 2:
            pavadinimas = "studentai10000.txt";
            break;
        case 3:
            pavadinimas = "studentai100000.txt";
            break;
        case 4:
            pavadinimas = "studentai1000000.txt";
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida! Reikia pasirinkti nuo 1 iki 4" << endl;
            cin >> opt;
            break;
    }
 
   
    
//    cout << "Iveskite failo pavadinima, is kurio norite, kad butu skaitomi duomenys: \n";
//    cin >> pavadinimas;
    auto start = std::chrono::high_resolution_clock::now();
    ifstream failas(pavadinimas);
    try {
         if (!failas)
             throw runtime_error("Failas neegzistuoja arba nepasiekiamas.");
     } catch(const std::exception& e) {
         cerr << "Klaida: " << e.what() << endl;
         return;
     }
    int kiek;
    string eilute;
    vector<int> pazymiai;
    vector<string> eilvekt;
    getline(failas,eilute);
    while(failas){
        if(!failas.eof()){
            getline(failas,eilute);
            eilvekt.push_back(eilute);
        }
        else break;
    }
    failas.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas = end - start;
    
    cout << "Skaitymas is failo uztruko: " << laikas.count() << " sek." << endl;
    
    for ( int i = 0; i < eilvekt.size(); i++){
        istringstream iss(eilvekt[i]);
        Vartotojas naujas;
        double sum = 0;
        int paz;
        iss >> naujas.vardas >> naujas.pavarde;
        while (iss>>paz) {
            naujas.nd.push_back(paz);
            sum+=paz;
        }
        if(!naujas.nd.empty()){
            naujas.egz = naujas.nd.back();
            sum -= naujas.nd.back();
            naujas.nd.pop_back();
        }
        kiek = (int)naujas.nd.size();
        naujas.vid = Vidurkis(sum, kiek);
        naujas.med = Mediana(naujas.nd, kiek);
        naujas.galvid = 0.4*naujas.vid+0.6*naujas.egz;
        naujas.galmed = 0.4*naujas.med+0.6*naujas.egz;
        vart.push_back(naujas);
        
    }
    rezrikiavimas(vart);
    spausdinti_skaitomus_duomenis(vart);


}
void rezrikiavimas(vector<Vartotojas>& vart){
    int rinktis;
    cout << "Pasirinkita pagal kokia tvarka norite, kad surikiuotu ir spausdintu rezultatus:" << endl;
    cout << "1 - pagal studento varda\n";
    cout << "2 - pagal studento pavarde\n";
    cout << "3 - pagal studento galutini ivertinima (vidurki) \n";
    cout << "4 - pagal studento galutini ivertinima (mediana) \n";
    cin >> rinktis;
    switch(rinktis){
        case 1:{
            sort(vart.begin(), vart.end(), rikiuotiVarda);
            break;
        }
        case 2:{
            sort(vart.begin(), vart.end(), rikiuotiPavarde);
            break;
        }
        case 3:{
            sort(vart.begin(), vart.end(), rikiuotiVid);
            break;
        }
        case 4:{
            sort(vart.begin(), vart.end(), rikiuotiMed);
            break;
        }
    }
}
void spausdinti_skaitomus_duomenis(vector<Vartotojas>& vart)// spausdina nuskaitytu duomenu rezultatus i faila
{
    
    
        auto start = std::chrono::high_resolution_clock::now();
        ofstream fr("rezultatai.txt");
        fr << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20)<< "Galutinis (vid.)" << setw(20)<< "Galutinis (med.)" << endl;
        fr << "--------------------------------------------------------------------------" << endl;
        for ( int i = 0; i < vart.size(); i++)
        {
            
            fr << left << setw(20) << vart[i].pavarde << setw(20) << vart[i].vardas << setw(20) << fixed << setprecision(2) << vart[i].galvid << setw(20) << setprecision(2) << vart[i].galmed << endl;
        }
        
        fr.close();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> laikas = end - start;
        cout << "Rezultatu irasymas i faila uztruko: " << laikas.count() << " sek." << endl;
 
}
bool rikiuotiVarda(const Vartotojas &a, const Vartotojas &b) {
    return a.vardas < b.vardas;
}
bool rikiuotiPavarde(const Vartotojas &a, const Vartotojas &b) {
    return a.pavarde < b.pavarde;
}
bool rikiuotiVid(const Vartotojas &a, const Vartotojas &b) {
    return a.galvid < b.galvid;
}
bool rikiuotiMed(const Vartotojas &a, const Vartotojas &b) {
    return a.galmed < b.galmed;
}
bool arZodis(string tekstas){
    for(char i : tekstas)
    {
        if(!isalpha(i))
        {
            cout << "Vardo ar pavardes ivedimui naudokite tik raides! Iveskite is naujo: \n";
            return false;
        }
    }
    return true;
}
