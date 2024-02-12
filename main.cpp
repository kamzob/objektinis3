//
//  main.cpp
//  pirmasobj
//
//  Created by Kamilė Zobėlaitė on 2024-02-07.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#define x 50
using namespace std;
struct Vartotojas
{
    string vardas;
    string pavarde;
    int nd[x];
    int egz;
    double vid = 0.0;
    double gal = 0.0;
    double med = 0.0;
    int rnkts;          // pasirinkimas pagal mediana ar pagal vidurki skaiciuto galutini ivertinima
    
};
double Vidurkis(int suma, int nariai);
double Mediana(int paz[], int nariai);
int main() {

    int n;
    int kiek;       // tarpiniu pazymiu kiekis
    int paz;        // tarpinis pazymys
    cout << "Iveskite vartotoju skaiciu:" << endl;
    cin >> n;
    Vartotojas vart[n];
    for (int i = 0; i < n; i++)
    {
        double sum = 0.0;        // tarpiniu pazymiu suma
        cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
        cin >> vart[i].vardas;
        cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
        cin >> vart[i].pavarde;
        cout << "Kiek yra tarpiniu pazymiu?" << endl;
        cin >> kiek;
        for (int j = 0; j < kiek; j++){
            cout << "Iveskite " << j+1 << " pazymi" << endl;
            cin >> vart[i].nd[j];
            sum += vart[i].nd[j];
        }
        cout << "Iveskite egzamino rezultata:" << endl;
        cin >> vart[i].egz;
        
        int rnkts;      // pasirinkimas kaip skaiciuoti galutini ivertinima - pagal mediana ar vidurki
        cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
        cin >> rnkts;
        if (rnkts == 0)
        {
            vart[i].vid = Vidurkis(sum, kiek);
            vart[i].gal = 0.4*vart[i].vid+0.6*vart[i].egz;
            
        }
        else if (rnkts == 1)
        {
            vart[i].med = Mediana(vart[i].nd, kiek);
            vart[i].gal = 0.4*vart[i].med+0.6*vart[i].egz;
            
        }
        
    }
    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)<< "Galutinis (vid.)" << endl;
    cout << "---------------------------------------------------" << endl;
    for ( int i = 0; i < n; i++)
    {
        cout << left << setw(15) << vart[i].pavarde << setw(15) << vart[i].vardas << setw(15) << fixed << setprecision(2) << vart[i].gal << endl;
    }
    
    
    return 0;
}
double Vidurkis(int suma, int nariai){
    return suma/nariai;
    
}
double Mediana(int paz[], int nariai)
{
    sort(paz, paz+nariai);
    if(nariai % 2 != 0)
        return double(paz[nariai/2]);
    return double(paz[(nariai-1) / 2] + paz[nariai/2] / 2.0);
    
}
