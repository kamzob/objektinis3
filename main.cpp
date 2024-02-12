//
//  main.cpp
//  pirmasobj
//
//  Created by Kamilė Zobėlaitė on 2024-02-07.
//

#include <iostream>
#include <iomanip>
#define x 50
using namespace std;
struct Vartotojas
{
    string vardas;
    string pavarde;
    int nd[x];
    int egz;
    double gal = 0;
    
};


int main() {

    int n;
    int kiek;       // tarpiniu pazymiu kiekis
    int paz;        // tarpinis pazymys
    cout << "Iveskite vartotoju skaiciu:" << endl;
    cin >> n;
    Vartotojas vart[n];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;        // tarpiniu pazymiu suma
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
        vart[i].gal = 0.4*(double(sum)/kiek)+0.6*vart[i].egz;
        
    }
    cout << left << setw(10) << "Pavarde" << setw(10) << "Vardas" << setw(10)<< "Galutinis (vid.)" << endl;
    cout << "---------------------------------------------------" << endl;
    for ( int i = 0; i < n; i++)
    {
        cout << left << setw(10) << vart[i].pavarde << setw(10) << vart[i].vardas << setw(10) << fixed << setprecision(2) << vart[i].gal << endl;
    }
    
    
    return 0;
}
