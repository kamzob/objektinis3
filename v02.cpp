//
//  main.cpp
//  v02
//
//  Created by Kamilė Zobėlaitė on 2024-02-19.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>


using namespace std;

struct Vartotojas
{
    string vardas;
    string pavarde;
    vector<int> nd;              // namu darbu masyvas
    int egz;                // studento egzamino rezultatas
    double vid = 0.0;       // namu darbu pazymiu vidurkis
    double gal = 0.0;       // galutinis ivertinimas
    double med = 0.0;       // namu darbu mediana
    
};
double Vidurkis(double suma, int nariai);
double Mediana(vector<int> paz, int nariai);
void spausdinti(int rnkts, vector<Vartotojas>& vart, int n);
double generavimasPaz();
string generavimasVard(int pas);
string generavimasPav(int pas);

int main() {
    srand( static_cast<unsigned int>(time(nullptr)));       // xcode neveikia srand(time(0))
    int n;
    cout << "Iveskite vartotoju skaiciu:" << endl;
    cin >> n;
    while(!cin>>n || n < 0 )
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida! Turite ivesti vartotoju skaiciu!" << endl;
        cin >> n;
    }
    
    vector<Vartotojas> vart;
    int pasirinkimas;
    cout << "Pasirinkite: " << endl;
    do{
        // meniu skiltis pasirinkimai
        cout << "Jeigu norite ivesti duomenis ranka, spauskite 1" << endl;
        cout << "Jeigu norite, kad pazymiai butu generuojami automatiskai, spauskite 2" << endl;
        cout << "Jeigu norite, kad pazymiai, studentu vardai ir pavardes butu generuojami automatiskai, spauskite 3" << endl;
        cout << "Jeigu norite, kad programa baigtu darba, spauskite 4" << endl;
        cin >> pasirinkimas;
        while(!cin>>pasirinkimas || pasirinkimas < 1 || pasirinkimas > 4)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida! Turite pasirinkti nuo 1 iki 4: \n";
            cin >> pasirinkimas;
            
        }
        switch(pasirinkimas) {
            case 1: {
                for (int i = 0; i < n; i++)
                {
                    Vartotojas naujas;
                    double sum = 0.0;
                    cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
                    cin >> naujas.vardas;
                    cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
                    cin >> naujas.pavarde;
                    cout << "Iveskite pazymius uz namu darbus kai noresite baigti ivedima, irasykite 0: " << endl;
                    int pazymys;
                    int kiek = 0;
                    while(true){
                        cin >> pazymys;
                        
                        while (!cin>>pazymys || pazymys < 0 || pazymys > 10)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Klaida! Pazymys turi buti nuo 1 iki 10: \n";
                            cin >> pazymys;
                          
                        }
                        if(pazymys==0)
                            break;
                        naujas.nd.push_back(pazymys);
                        sum+=pazymys;
                        kiek++;
                       
                    }
                    cout << "Iveskite egzamino rezultata:" << endl;
                    cin >> naujas.egz;
                    while(!cin >> naujas.egz ||naujas.egz<1 || naujas.egz>10)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida! Egzamino rezultatas turi buti nuo 1 iki 10: \n";
                        cin >> naujas.egz;
                    }
                    naujas.vid = Vidurkis(sum, kiek);
                    naujas.med = Mediana(naujas.nd, kiek);
                    vart.push_back(naujas);
                }
                int rnkts;      // pasirinkimas, kaip norima skaiciuoti galutini ivertinima - pagal vidurki ar mediana
                cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
                cin >> rnkts;
                spausdinti (rnkts, vart, n);
                break;
                
            }
            case 2: {
                for (int i = 0; i < n; i++)
                {
                    Vartotojas naujas;
                    double sum = 0.0;
                    cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
                    cin >> naujas.vardas;
                    cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
                    cin >> naujas.pavarde;
                    int pazymys;
                    int kiek = 0;
                    int renku = 0;
                    while(true)
                    {
                        cout << "Jei norite kad sugeneruotu pazymi spauskite 1, jei norite kad baigtu generuoti spauskite 0: " << endl;
                        cin >> renku;
                        while(!cin>>renku || renku < 0 || renku > 1)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            
                            cout << "Jei norite kad sugeneruotu pazymi spauskite 1, jei norite kad baigtu generuoti spauskite 0: " << endl;
                            cin >> renku;
                        }
                        if(renku==0)
                            break;
                        pazymys = generavimasPaz();
                        cout << pazymys << endl;
                        sum += pazymys;
                        naujas.nd.push_back(pazymys);
                        kiek++;
                        
                    }
                    naujas.egz = generavimasPaz();
                    cout << "Egzamino rezultatas :" << naujas.egz << endl;
                    naujas.vid = Vidurkis(sum, kiek);
                    naujas.med = Mediana(naujas.nd, kiek);
                    vart.push_back(naujas);
                }
                int rnkts;      // pasirinkimas, kaip norima skaiciuoti galutini ivertinima - pagal vidurki ar mediana
                cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
                cin >> rnkts;
                spausdinti (rnkts, vart, n);
                break;
            }
            case 3: {
                for(int i = 0; i < n; i++)
                {
                    Vartotojas naujas;
                    bool gender;        // lytis
                    gender = rand()%2;
                    naujas.vardas = generavimasVard(gender);
                    naujas.pavarde = generavimasPav(gender);
                    cout << i+1 << " studentas: " << naujas.vardas << " " << naujas.pavarde << endl;
                    double sum = 0.0;
                    int pazymys;
                    int kiek = 0;
                    int renku = 0;
                    while(true)
                    {
                        cout << "Jei norite kad sugeneruotu pazymi spauskite 1, jei norite kad baigtu generuoti spauskite 0: " << endl;
                        cin >> renku;
                        while(!cin>>renku || renku < 0 || renku > 1)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            
                            cout << "Jei norite kad sugeneruotu pazymi spauskite 1, jei norite kad baigtu generuoti spauskite 0: " << endl;
                            cin >> renku;
                        }
                        if(renku==0)
                            break;
                        pazymys = generavimasPaz();
                        cout << pazymys << endl;
                        sum += pazymys;
                        naujas.nd.push_back(pazymys);
                        kiek++;
                        
                    }
                    naujas.egz = generavimasPaz();
                    cout << "Egzamino rezultatas :" << naujas.egz << endl;
                    naujas.vid = Vidurkis(sum, kiek);
                    naujas.med = Mediana(naujas.nd, kiek);
                    vart.push_back(naujas);
                }
                int rnkts;      // pasirinkimas, kaip norima skaiciuoti galutini ivertinima - pagal vidurki ar mediana
                cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
                cin >> rnkts;
                spausdinti (rnkts, vart, n);
                break;
            }
                
                
        }
        
    } while(pasirinkimas != 4);
    
    
    
    return 0;
}
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

void spausdinti(int rnkts, vector<Vartotojas>& vart, int n)
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
