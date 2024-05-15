//
//  funkcijos.cpp
//  V3.0
//
//  Created by Kamilė Zobėlaitė on 2024-05-15.
//

//
//  funkcijos.cpp
//  v2.0
//
//  Created by Kamilė Zobėlaitė on 2024-04-29.
//


#include "funkcijos.h"

/**
 * @file funkcijos.cpp
 * @brief Pagalbiniu funciju failo vykdymas
 */

double Vidurkis(double suma, int nariai)
{
    if (nariai==0)
        return 0.0;
    return suma/nariai;
    
}

double Mediana(vector<int> paz, int nariai)
{
    if (nariai==0)
        return 0.0;
    sort(paz.begin(), paz.end());
    if(nariai % 2 != 0)
        return double(paz[nariai/2]);
    return double(paz[(nariai-1) / 2] + paz[nariai/2]) / 2.0;
    
}

void spausdinti(int rnkts, vector<Vartotojas>& vart, int n)// spausdina i ekrana ranka sugeneruotus duomenis
{
    
    if (rnkts == 0)
    {
        cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20)<< "Galutinis (vid.)" << endl;
        cout << "---------------------------------------------------" << endl;
        for (const auto& stud : vart)
        {
            
            cout << stud;       // isvesties operatoriu perdengimas
        }
        
        
    }
    else if (rnkts == 1)
    {
        cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20)<< "Galutinis (med.)" << endl;
        cout << "---------------------------------------------------" << endl;
        for (const auto& stud : vart)
        {
            cout << stud;       // isvesties operatoriu perdengimas
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
void skaityti(vector<Vartotojas>& vart, string pavadinimas, int vm)
{
    vart.clear();
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
    string header;
    vector<int> pazymiai;
    string v, p;
    getline(failas,header);
    while(failas){
        if(!failas.eof()){
            getline(failas,eilute);
            if(!eilute.empty()){
                istringstream iss(eilute);
                Vartotojas naujas;
                pazymiai.clear();
                double sum = 0;
                iss >> naujas;  // naudojamas ivesties operatoriu perdengimas
                for(int paz : naujas.getPaz()){
                    sum+=paz;
                }
                kiek = int(naujas.getPaz().size());
                naujas.setVid(Vidurkis(sum, kiek));
                naujas.setMed(Mediana(naujas.getPaz(), kiek));
                naujas.setGalmed(0.4*naujas.getMed()+0.6*naujas.getEgz());
                naujas.setGalvid(0.4*naujas.getVid()+0.6*naujas.getEgz());
                if (vm == 0) naujas.setGal(naujas.getGalvid());
                else naujas.setGal(naujas.getGalmed());
                vart.push_back(naujas);
            }
            
        }
        else break;
    }
    failas.close();
  
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas = end - start;
    
    cout << "Skaitymas uztruko: " << laikas.count() << " sek." << endl;
   
}
void rezrikiavimas(vector<Vartotojas>& vart){
    int rinktis;
    cout << "Pasirinkita pagal kokia tvarka norite, kad surikiuotu ir spausdintu rezultatus:" << endl;
    cout << "1 - pagal studento varda\n";
    cout << "2 - pagal studento pavarde\n";
    cout << "3 - pagal studento galutini ivertinima (vidurki) \n";
    cout << "4 - pagal studento galutini ivertinima (mediana) \n";
    cin >> rinktis;
    while(cin.fail()|| rinktis < 1 || rinktis > 4)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida! Reikia pasirinkti nuo 1 iki 4" << endl;
        cin >> rinktis;
        
    }
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
        try {
         if (!fr)
             throw runtime_error("Rezultatu failas neegzistuoja arba nepasiekiamas.");
        } catch(const std::exception& e) {
            cerr << "Klaida: " << e.what() << endl;
         return;
     }
        fr << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20)<< "Galutinis (vid.)" << setw(20)<< "Galutinis (med.)" << endl;
        fr << "--------------------------------------------------------------------------" << endl;
        for (const auto& stud : vart)
        {
            
            fr << left << setw(20) << stud.getPav() << setw(20) << stud.getVar() << setw(20) << fixed << setprecision(2) << stud.getGalvid() << setw(20) << setprecision(2) << stud.getGalmed() << endl;
        }
        
        fr.close();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> laikas = end - start;
        cout << "Rezultatu irasymas i faila uztruko: " << laikas.count() << " sek." << endl;
 
}
bool rikiuotiVarda(const Vartotojas &a, const Vartotojas &b) {
    return a.getVar() < b.getVar();
}
bool rikiuotiPavarde(const Vartotojas &a, const Vartotojas &b) {
    return a.getPav() < b.getPav();
}
bool rikiuotiVid(const Vartotojas &a, const Vartotojas &b) {
    return a.getGalvid() < b.getGalvid();
}
bool rikiuotiMed(const Vartotojas &a, const Vartotojas &b) {
    return a.getGalmed() < b.getGalmed();
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
bool arSveikasisSk(string tekstas){
    for(char i : tekstas)
    {
        if(!isdigit(i))
        {
            return false;
        }
    }
    return true;
}
void FailuGeneravimas (int studSk){
    auto start = std::chrono::high_resolution_clock::now();
    using hrClock = std::chrono::high_resolution_clock;
    auto now = hrClock::now().time_since_epoch();
    auto count = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
    std::mt19937 mt(static_cast<unsigned int>(count));
    std::uniform_int_distribution<int> random20(1, 20);
    std::uniform_int_distribution<int> random10(1, 10);
    string failoPav;
    std::stringstream ss;
    int kiekNd = 15;
    ss <<  "stud" << studSk << ".txt";
    failoPav = ss.str();
    ofstream fr (failoPav);// stringstream
    std::stringstream aa;
    aa << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for(int i = 1; i <=kiekNd; i++)
    {
        aa << "ND" << left << setw(8) << i;
    }
    aa << "Egz.\n";
    int pazymys = 0;
    for (int i = 1; i <= studSk; i++)
    {
        aa << "Vardas" << setw(14) << left << i << "Pavarde" << setw(14) << left << i;
        for (int i = 0; i <= kiekNd; i++){
            pazymys = random10(mt);
            aa << setw(10) << left << pazymys;
        }
        aa << "\n";
    }
    fr << aa.str();
    fr.close();
    aa.clear();
    auto end = std::chrono::high_resolution_clock::now();
     std::chrono::duration<double> laikas = end - start;
    cout << "Failo generavimas su " << studSk << " uztruko: " << laikas.count() << " sek." << endl;
}
void RusiavimasDviGrupes(vector<Vartotojas>& vart, vector<Vartotojas>& vargsai, vector<Vartotojas>& laimingi, int vm){
    vargsai.clear();
    laimingi.clear();
    auto start1 = std::chrono::high_resolution_clock::now();
    
    if(vm==0) sort(vart.begin(), vart.end(), rikiuotiVid);
    else sort(vart.begin(), vart.end(), rikiuotiMed);
    
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas1 = end1 - start1;
    cout << "Vartotoju rikiavimas pagal vartotojo parinkta parametra: " << laikas1.count() << " sek." << endl;
    
    auto start2 = std::chrono::high_resolution_clock::now();
    for (const auto& stud : vart){
        
        if(stud.getGal() < 5.0){
            vargsai.push_back(stud);
        }
        if(stud.getGal()>=5.0) laimingi.push_back(stud);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas2 = end2 - start2;
    cout << "Studentu rusiavimas i du konteinerius uztruko: " << laikas2.count() << " sek." << endl;
}
void spausdintiLaimingiVargsai (vector<Vartotojas>& vargsai, vector<Vartotojas>& laimingi, int vm){
//    auto start = std::chrono::high_resolution_clock::now();
    ofstream fr("vargsiukai.txt");
    try {
     if (!fr)
         throw runtime_error("Vargsiukai failas neegzistuoja arba nepasiekiamas.");
    } catch(const std::exception& e) {
        cerr << "Klaida: " << e.what() << endl;
     return;
 }
    fr << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    if( vm == 0) fr << setw(20)<< "Galutinis (vid.)" << endl;
    else if(vm == 1) fr << setw(20)<< "Galutinis (med.)" << endl;
    fr << "--------------------------------------------------------------------------" << endl;
    for (const auto& var : vargsai)
    {
        
        fr << var;          // isvesties operatoriu perdengimas
    }
    
    fr.close();
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> laikas = end - start;
//    cout << "Vargsiuku irasymas i faila uztruko: " << laikas.count() << " sek." << endl;
//    auto start2 = std::chrono::high_resolution_clock::now();
    
    ofstream fo("kietekai.txt");
    try {
     if (!fo)
         throw runtime_error("Kietekai failas neegzistuoja arba nepasiekiamas.");
    } catch(const std::exception& e) {
        cerr << "Klaida: " << e.what() << endl;
     return;
 }
    fo << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    if( vm == 0) fo << setw(20)<< "Galutinis (vid.)" << endl;
    else if(vm == 1) fo << setw(20)<< "Galutinis (med.)" << endl;
    fo << "--------------------------------------------------------------------------" << endl;
    for (const auto& mldc : laimingi)
    {
        
        fo << mldc;     // isvesties operatoriu perdengimas
    }
    
    fo.close();
//    auto end2 = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> laikas2 = end2 - start2;
//    cout << "Kieteku irasymas i faila uztruko: " << laikas2.count() << " sek." << endl;
//
}



//2 STRATEGIJA
void RusiavimasDviGrupes2(vector<Vartotojas>& vart, vector<Vartotojas>& vargsai, int vm){
    vargsai.clear();
    auto start1 = std::chrono::high_resolution_clock::now();
    
    if(vm==0) sort(vart.begin(), vart.end(), rikiuotiVid);
    else sort(vart.begin(), vart.end(), rikiuotiMed);
    
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas1 = end1 - start1;
    cout << "Vartotoju rikiavimas pagal vartotojo parinkta parametra: " << laikas1.count() << " sek." << endl;
    
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < vart.size();){
        
        if(vart[i].getGal() < 5.0){
            vargsai.push_back(vart[i]);
            vart.erase(vart.begin()+i);
            
        }
        else i++;
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas2 = end2 - start2;
    cout << "Studentu rusiavimas i du konteinerius uztruko: " << laikas2.count() << " sek." << endl;
    //cout << vart.size() << " " << vargsai.size() << endl;
    spausdintiLaimingiVargsai(vargsai, vart, vm);
}

// 3 STRATEGIJA
void RusiavimasDviGrupes3(vector<Vartotojas>& vart, vector<Vartotojas>& vargsai, int vm){
    vargsai.clear();
    auto start1 = std::chrono::high_resolution_clock::now();
    
    if(vm==0) sort(vart.begin(), vart.end(), rikiuotiVid);
    else sort(vart.begin(), vart.end(), rikiuotiMed);
    
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas1 = end1 - start1;
    cout << "Vartotoju rikiavimas pagal vartotojo parinkta parametra: " << laikas1.count() << " sek." << endl;
    
    auto start2 = std::chrono::high_resolution_clock::now();
    for (auto& v : vart) {
            
            if (v.getGal() < 5.0) {
                vargsai.push_back(v);
            }
        }
        
        vart.erase(std::remove_if(vart.begin(), vart.end(), [&vm](const Vartotojas& v) {
            return (vm == 0) ? v.getGalvid() < 5.0 : v.getGalmed()< 5.0;
        }), vart.end());
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas2 = end2 - start2;
    cout << "Studentu rusiavimas i du konteinerius uztruko: " << laikas2.count() << " sek." << endl;
    //cout << vart.size() << " " << vargsai.size() << endl;
    spausdintiLaimingiVargsai(vargsai, vart, vm);
}
void testas(){
     //konstruktoriaus testavimas
    string vardas = "Jonas", pavarde = "Jonaitis";
    vector <int> pzm = {4, 6, 8, 10};
    int egz = 8;
    double vid = 7.0;
    double med = 7.0;
    double gal = 0.6*vid + 0.4*egz;
    double galm = 0.6*med + 0.4*egz;
    double galv = 0.6*vid + 0.4*egz;
    Vartotojas v1 (vardas, pavarde, pzm, egz, vid, gal, med, galm, galv);
    assert(v1.getVar()==vardas);
    assert(v1.getPav()==pavarde);
    assert(v1.getPaz()==pzm);
    assert(v1.getEgz()==egz);
    assert(v1.getVid()==vid);
    assert(v1.getGal()==gal);
    assert(v1.getMed()==med);
    assert(v1.getGalmed()==galm);
    assert(v1.getGalvid()==galv);
    cout << v1;
    cout << "Konstruktoriaus testavimas pavyko!" << endl;
    // copy konstruktoriaus testavimas
    Vartotojas v2(v1);
    assert(v1.getVar()==v2.getVar());
    assert(v1.getPav()==v2.getPav());
    assert(v1.getPaz()==v2.getPaz());
    assert(v1.getEgz()==v2.getEgz());
    assert(v1.getVid()==v2.getVid());
    assert(v1.getGal()==v2.getGal());
    assert(v1.getMed()==v2.getMed());
    assert(v1.getGalmed()==v2.getGalmed());
    assert(v1.getGalvid()==v2.getGalvid());
    cout << v2;
    cout << "Copy konstruktoriaus testavimas pavyko!" << endl;
    // move konstruktoriaus testavimas
    Vartotojas v3(std::move(v1));
    assert(v3.getVar() == vardas);
    assert(v3.getPav() == pavarde);
    assert(v3.getPaz() == pzm);
    assert(v3.getEgz() == egz);
    assert(v3.getVid() == vid);
    assert(v3.getGal() == gal);
    assert(v3.getMed() == med);
    assert(v3.getGalmed() == galm);
    assert(v3.getGalvid() == galv);
    cout << v3;
    cout << v1;
    cout << "Move konstruktoriaus testavimas pavyko!" << endl;
    // Kopijavimo priskyrimo operatoriaus testavimas
    Vartotojas v4;
    v4 = v3;
    assert(v4.getVar() == vardas);
    assert(v4.getPav() == pavarde);
    assert(v4.getPaz() == pzm);
    assert(v4.getEgz() == egz);
    assert(v4.getVid() == vid);
    assert(v4.getGal() == gal);
    assert(v4.getMed() == med);
    assert(v4.getGalmed() == galm);
    assert(v4.getGalvid() == galv);
    cout << v4;
    cout << "Kopijavimo priskyrimo operatoriaus testavimas pavyko!" << endl;
// Perkėlimo priskyrimo operatoriaus testavimas
    Vartotojas v5;
    v5 = std::move(v3);
    assert(v5.getVar() == vardas);
    assert(v5.getPav() == pavarde);
    assert(v5.getPaz() == pzm);
    assert(v5.getEgz() == egz);
    assert(v5.getVid() == vid);
    assert(v5.getGal() == gal);
    assert(v5.getMed() == med);
    assert(v5.getGalmed() == galm);
    assert(v5.getGalvid() == galv);
    cout << v5;
    cout << v3;
    cout << "Perkėlimo priskyrimo operatoriaus testavimas pavyko!" << endl;
    cout << "Zmogus yra abstrakti klase (1 - taip, 0 - ne): " << std::is_abstract<Zmogus>::value << std::endl;

    
}
