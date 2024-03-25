//
//  funkcijos.h
//  v1_1
//
//  Created by Kamilė Zobėlaitė on 2024-03-25.
//

#ifndef funkcijos_h
#define funkcijos_h

#include "biblioteka.h"
struct Vartotojas1
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
class Vartotojas
{
private:
    string vardas_;
    string pavarde_;
    vector<int> nd_;              // namu darbu vekt
    int egz_;                // studento egzamino rezultatas
    double vid_;       // namu darbu pazymiu vidurkis
    double gal_;       // galutinis ivertinimas
    double med_;       // namu darbu mediana
    double galmed_;
    double galvid_;
public:
    Vartotojas() : vid_(0.0), gal_(0.0), med_(0.0), galmed_(0.0), galvid_(0.0){}
    Vartotojas(string vardas, string pavarde, const vector<int>& nd, int egz, double vid, double gal, double med, double galmed, double galvid)
    : vardas_(vardas), pavarde_(pavarde), nd_(nd), egz_(egz), vid_(vid), gal_(gal), med_(med), galmed_(galmed), galvid_(galvid) {}
    ~Vartotojas() {}
    //setteriai
    void setVar (string vard) {
        vardas_=vard;
    }
    void setPav (string pav) {
        pavarde_=pav;
    }
    void setPaz(int paz){
        nd_.push_back(paz);
    }
    void setVid(double vidurkis){
        vid_=vidurkis;
    }
    void setMed(double med){
        med_=med;
    }
    void setEgz (int egz){
        egz_ = egz;
    }
    void setGal(double gal){
        gal_ = gal;
    }
    void setGalvid(double galv){
        galvid_=galv;
    }
    void setGalmed(double galm){
        galmed_=galm;
    }
    //getteriai
    string getVar() const { return vardas_;}
    string getPav() const {return pavarde_;}
    const vector<int>& getPaz() const { return nd_; }
    int getEgz() const { return egz_; }
    double getVid() const { return vid_; }
    double getGal() const { return gal_; }
    double getMed() const { return med_; }
    double getGalmed() const { return galmed_; }
    double getGalvid() const { return galvid_; }
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
void skaitytiList(list<Vartotojas>& vartlist, string pavadinimas, int vm);
void RusiavimasList(list<Vartotojas>& vartlist, list<Vartotojas>& vargsailist, list<Vartotojas>& laimingilist, int vm);
void spausdintiList (list<Vartotojas>& vargsailist, list<Vartotojas>& laimingilist, int vm);
void skaitytiDeque(deque <Vartotojas>& vartdeq, string pavadinimas);
void RusiavimasDeque(deque<Vartotojas>& vartdeq, deque<Vartotojas>& vargsaideq, deque<Vartotojas>& laimingideq, int vm);
void spausdintiDeque (deque<Vartotojas>& vargsaideq, deque<Vartotojas>& laimingideq, int vm);
void RusiavimasDviGrupes2(vector<Vartotojas>& vart, vector<Vartotojas>& vargsai, int vm);
void RusiavimasDeque2(deque<Vartotojas>& vartdeq, deque<Vartotojas>& vargsaideq, int vm);
void RusiavimasList2(list<Vartotojas>& vartlist, list<Vartotojas>& vargsailist, int vm);
void RusiavimasDviGrupes3(vector<Vartotojas>& vart, vector<Vartotojas>& vargsai, int vm);
void RusiavimasList3(list<Vartotojas>& vartlist, list<Vartotojas>& vargsailist, int vm);
void RusiavimasDeque3(deque<Vartotojas>& vartdeq, deque<Vartotojas>& vargsaideq, int vm);

#endif /* funkcijos_h */
