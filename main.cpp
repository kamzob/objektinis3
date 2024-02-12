//
//  main.cpp
//  pirmasobj
//
//  Created by Kamilė Zobėlaitė on 2024-02-07.
//

#include <iostream>
using namespace std;
struct Vartotojas
{
    string vardas;
    string pavarde;
    int nd;
    int egz;
    double gal;
    
};


int main() {

    int n;
    int kiek;       // tarpiniu pazymiu kiekis
    int paz;        // tarpinis pazymys
    int sum = 0;        // tarpiniu pazymiu suma
    cout << "Iveskite vartotoju skaiciu:" << endl;
    cin >> n;
    Vartotojas vart[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Iveskite varda:" << endl;
        cin >> vart[i].vardas;
        cout << "Iveskite pavarde:" << endl;
        cin >> vart[i].pavarde;
        cout << "Kiek yra tarpiniu pazymiu?" << endl;
        cin >> kiek;
        for (int i = 1; i <= kiek; i++){
            cout << "Iveskite " << i << " pazymi" << endl;
            cin >> paz;
            sum += paz;
        }
        vart[i].nd = sum/kiek;
        cout << "Iveskite egzamino rezultata:" << endl;
        cin >> vart[i].egz;
        vart[i].gal = 0.4*vart[i].nd+0.6*vart[i].egz;
        
    }
    cout << "Pavarde\t" << "Vardas\t" << "Galutinis (vid.)" << endl;
    cout << "---------------------------------------------------" << endl;
    for ( int i = 0; i < n; i++)
    {
        cout << vart[i].pavarde << "\t" << vart[i].vardas << "\t" << vart[i].gal << endl;
    }
    
    
    return 0;
}
