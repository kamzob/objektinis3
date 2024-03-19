//
//  funkcijos.h
//  v1.0
//
//  Created by Kamilė Zobėlaitė on 2024-03-14.
//

#ifndef funkcijos_h
#define funkcijos_h

#include "biblioteka.h"
struct Vartotojas
{
    string vardas;
    string pavarde;
    vector<int> nd;              // namu darbu vekt
    int egz;                // studento egzamino rezultatas
    double vid = 0.0;       // namu darbu pazymiu vidurkis
    double gal = 0.0;       // galutinis ivertinimas
    double med = 0.0;       // namu darbu mediana
    double galmed = 0.0;
    double galvid = 0.0;
    
};
double Vidurkis(double suma, int nariai);
double Mediana(vector<int> paz, int nariai);
void spausdinti(int rnkts, vector<Vartotojas>& vart, int n);
double generavimasPaz();
string generavimasVard(int pas);
string generavimasPav(int pas);
void skaityti(vector<Vartotojas>& vart, string pavadinimas);
void rezrikiavimas(vector<Vartotojas>& vart);
void spausdinti_skaitomus_duomenis(vector<Vartotojas>& vart);
bool rikiuotiVarda(const Vartotojas &a, const Vartotojas &b);
bool rikiuotiPavarde(const Vartotojas &a, const Vartotojas &b);
bool rikiuotiVid(const Vartotojas &a, const Vartotojas &b);
bool rikiuotiMed(const Vartotojas &a, const Vartotojas &b);
bool arZodis(string tekstas);
bool arSveikasisSk(string tekstas);
void FailuGeneravimas (int studSk);
void RusiavimasDviGrupes(vector<Vartotojas>& vart, vector<Vartotojas>& vargsai, vector<Vartotojas>& laimingi, int vm);
void spausdintiLaimingiVargsai (vector<Vartotojas>& vargsai, vector<Vartotojas>& laimingi, int vm);
void skaitytiList(list<Vartotojas>& vartlist, string pavadinimas);
void RusiavimasList(list<Vartotojas>& vartlist, list<Vartotojas>& vargsailist, list<Vartotojas>& laimingilist, int vm);
void spausdintiList (list<Vartotojas>& vargsailist, list<Vartotojas>& laimingilist, int vm);
void skaitytiDeque(deque <Vartotojas>& vartdeq, string pavadinimas);
void RusiavimasDeque(deque<Vartotojas>& vartdeq, deque<Vartotojas>& vargsaideq, deque<Vartotojas>& laimingideq, int vm);
void spausdintiDeque (deque<Vartotojas>& vargsaideq, deque<Vartotojas>& laimingideq, int vm);
void RusiavimasDviGrupes2(vector<Vartotojas>& vart, vector<Vartotojas>& vargsai, int vm);
void RusiavimasDeque2(deque<Vartotojas>& vartdeq, deque<Vartotojas>& vargsaideq, int vm);
void RusiavimasList2(list<Vartotojas>& vartlist, list<Vartotojas>& vargsailist, int vm);
#endif /* funkcijos_h */
