//
//  funkcijos.cpp
//  v1.0
//
//  Created by Kamilė Zobėlaitė on 2024-03-14.
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
    if (nariai==0)
        return nariai;
    sort(paz.begin(), paz.end());
    if(nariai % 2 != 0)
        return double(paz[nariai/2]);
    return double(paz[(nariai-1) / 2] + paz[nariai/2]) / 2.0;
    
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
void skaityti(vector<Vartotojas>& vart, string pavadinimas)
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
    getline(failas,header);
    while(failas){
        if(!failas.eof()){
            getline(failas,eilute);
            if(!eilute.empty()){
                istringstream iss(eilute);
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
    for (int i = 0; i < vart.size(); i++){
        if(vm==0) vart[i].gal = vart[i].galvid;
        if(vm==1) vart[i].gal = vart[i].galmed;
        
        if(vart[i].gal < 5.0){
            vargsai.push_back(vart[i]);
        }
        if(vart[i].gal>=5.0) laimingi.push_back(vart[i]);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas2 = end2 - start2;
    cout << "Studentu rusiavimas i du konteinerius uztruko: " << laikas2.count() << " sek." << endl;
}
void spausdintiLaimingiVargsai (vector<Vartotojas>& vargsai, vector<Vartotojas>& laimingi, int vm){
    auto start = std::chrono::high_resolution_clock::now();
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
    for ( int i = 0; i < vargsai.size(); i++)
    {
        
        fr << left << setw(20) << vargsai[i].vardas << setw(20) << vargsai[i].pavarde << setw(20) << fixed << setprecision(2) << vargsai[i].gal << endl;
    }
    
    fr.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas = end - start;
    cout << "Vargsiuku irasymas i faila uztruko: " << laikas.count() << " sek." << endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    
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
    for ( int i = 0; i < laimingi.size(); i++)
    {
        
        fo << left << setw(20) << laimingi[i].vardas << setw(20) << laimingi[i].pavarde << setw(20) << fixed << setprecision(2) << laimingi[i].gal << endl;
    }
    
    fo.close();
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas2 = end2 - start2;
    cout << "Kieteku irasymas i faila uztruko: " << laikas2.count() << " sek." << endl;
    
}

void skaitytiList(list<Vartotojas>& vart, string pavadinimas)
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
    getline(failas,header);
    while(failas){
        if(!failas.eof()){
            getline(failas,eilute);
            if(!eilute.empty()){
                istringstream iss(eilute);
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
            
        }
        else break;
    }
    failas.close();
  
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas = end - start;
    
    cout << "Skaitymas uztruko: " << laikas.count() << " sek." << endl;
   
}
void RusiavimasList(list<Vartotojas>& vart, list<Vartotojas>& vargsai, list<Vartotojas>& laimingi, int vm){
    vargsai.clear();
    laimingi.clear();
    auto start1 = std::chrono::high_resolution_clock::now();
    
    if(vm==0) sort(vart.begin(), vart.end(), rikiuotiVid);
    else sort(vart.begin(), vart.end(), rikiuotiMed);
    
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas1 = end1 - start1;
    cout << "Vartotoju rikiavimas pagal vartotojo parinkta parametra: " << laikas1.count() << " sek." << endl;
    
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < vart.size(); i++){
        if(vm==0) vart[i].gal = vart[i].galvid;
        if(vm==1) vart[i].gal = vart[i].galmed;
        
        if(vart[i].gal < 5.0){
            vargsai.push_back(vart[i]);
        }
        if(vart[i].gal>=5.0) laimingi.push_back(vart[i]);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas2 = end2 - start2;
    cout << "Studentu rusiavimas i du konteinerius uztruko: " << laikas2.count() << " sek." << endl;
}
