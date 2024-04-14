//
//  funkcijos.h
//  v1_2
//
//  Created by Kamilė Zobėlaitė on 2024-04-14.
//


#ifndef funkcijos_h
#define funkcijos_h

#include "biblioteka.h"

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
    ~Vartotojas() {nd_.clear(), vardas_.clear(), pavarde_.clear();}
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
void skaityti(vector<Vartotojas>& vart, string pavadinimas, int vm);
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
void RusiavimasDviGrupes2(vector<Vartotojas>& vart, vector<Vartotojas>& vargsai, int vm);
void RusiavimasDviGrupes3(vector<Vartotojas>& vart, vector<Vartotojas>& vargsai, int vm);


#endif /* funkcijos_h */
