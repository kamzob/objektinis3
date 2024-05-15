//
//  funkcijos.h
//  V3.0
//
//  Created by Kamilė Zobėlaitė on 2024-05-15.
//

//
//  funkcijos.h
//  v2.0
//
//  Created by Kamilė Zobėlaitė on 2024-04-29.
//

/**
 * @file funkcijos.h
 * @brief Zmogus ir Vartotojas klases deklaracija ir funkciju reiksmiu priskyrimas.
 */
#ifndef funkcijos_h
#define funkcijos_h

#include "biblioteka.h"
/**
 * @class Zmogus
 * @brief atstovauja zmogu su vardu ir pavarde
 */
class Zmogus
{
protected:
    
    string vardas_; ///< Studento vardas
    string pavarde_; ///< Studento pavardė.
public:
    /**
        * @brief default Zmogus klasės konstruktorius.
        */
    Zmogus() = default;
    /**
        * @brief Zmogus klasės konstruktorius su parametrais.
        */
    Zmogus(string vardas, string pavarde)
    : vardas_(vardas), pavarde_(pavarde) {}
    virtual ~Zmogus() {}
   // virtual void  kazkas() const = 0;
    virtual void setVar (string vard) {
        vardas_=vard;
    }
    virtual void setPav (string pav) {
        pavarde_=pav;
    }

    virtual string getVar() const = 0;
    virtual string getPav() const = 0;
};
/**
 * @class Vartotojas
 * @brief atstovauja vartotoja
 */
class Vartotojas : public Zmogus
{
private:
    vector<int> nd_;  ///< Studento namų darbai.
    int egz_;         ///< Studento  egzamino rezultatas.
    double vid_;       ///< Studento namų darbų pažymių vidurkis.
    double gal_;       ///< Studento galutinis įvertinimas.
    double med_;       ///< Studento namų darbų pažymių mediana.
    double galmed_;     ///< Studento galutinis įvertinimas su mediana.
    double galvid_;     ///< Studento galutinis įvertinimas su vidurkiu.
public:
    /**
        * @brief Vartotojas klasės konstruktorius su nulinėmis reikšmėmis.
        */
    Vartotojas() : vid_(0.0), gal_(0.0), med_(0.0), galmed_(0.0), galvid_(0.0) {}
    /**
        * @brief Vartotojas klasės konstruktorius su parametrais.
        */
    Vartotojas(const string vardas, const string pavarde, const vector<int>& nd, int egz, double vid, double gal, double med, double galmed, double galvid)
    : Zmogus(vardas, pavarde), nd_(nd), egz_(egz), vid_(vid), gal_(gal), med_(med), galmed_(galmed), galvid_(galvid) {}
    // destruktorius
    /**
        * @brief Vartotojas klasės destruktorius.
        */
    ~Vartotojas() {
        //cout << "Objektas sunaikintas" << endl;
        nd_.clear();
        }
    // copy konstruktorius
    /**
            * @brief kopijavimo konstruktorius. */
    Vartotojas(const Vartotojas& other)
    : Zmogus(other.getVar(), other.getPav()), nd_(other.nd_), egz_(other.egz_), vid_(other.vid_), gal_(other.gal_), med_(other.med_), galmed_(other.galmed_), galvid_(other.galvid_) {}
    //void kazkas () const override{}
    
    // Copy assignment operatorius
    /**
            * @brief copy assignment operatorius. */
        Vartotojas& operator=(const Vartotojas& other) {
            if (this != &other) {
                Zmogus::setVar(other.getVar());
                Zmogus::setPav(other.getPav());
                nd_ = other.nd_;
                egz_ = other.egz_;
                vid_ = other.vid_;
                gal_ = other.gal_;
                med_ = other.med_;
                galmed_ = other.galmed_;
                galvid_ = other.galvid_;
            }
            return *this;
        }
    // move konstruktorius
    /**
            * @brief move (perkėlimo) konstruktorius. */
    Vartotojas(Vartotojas&& other) noexcept
    : Zmogus(std::move(other.vardas_), std::move(other.pavarde_)), nd_(std::move(other.nd_)), egz_(other.egz_), vid_(other.vid_), gal_(other.gal_), med_(other.med_), galmed_(other.galmed_), galvid_(other.galvid_) {
        other.egz_ = 0;
        other.vid_ = 0.0;
        other.gal_ = 0.0;
        other.med_ = 0.0;
        other.galmed_ = 0.0;
        other.galvid_ = 0.0;
    }
    // move assignment operatorius
    /**
            * @brief move assignment operatorius. */
    Vartotojas& operator=(Vartotojas&& other) noexcept {
            if (this != &other) {
                Zmogus::setVar(std::move(other.vardas_));
                Zmogus::setPav(std::move(other.pavarde_));
                nd_ = std::move(other.nd_);
                egz_ = other.egz_;
                vid_ = other.vid_;
                gal_ = other.gal_;
                med_ = other.med_;
                galmed_ = other.galmed_;
                galvid_ = other.galvid_;
                other.egz_ = 0;
                other.vid_ = 0.0;
                other.gal_ = 0.0;
                other.med_ = 0.0;
                other.galmed_ = 0.0;
                other.galvid_ = 0.0;
            }
            return *this;
        }
    /**
            * @brief Išvesties perdengimo operatoriai. */
    friend ostream& operator<<(ostream& out, const Vartotojas &vart){
        out << left << setw(20) << vart.vardas_ << setw(20) << vart.pavarde_ << setw(20) << fixed << setprecision(2) << vart.gal_ << endl;
        return out;
    }
    /**
            * @brief Įvesties perdengimo operatoriai. */
    friend istream& operator>>(istream& in, Vartotojas &vart){
        in >> vart.vardas_ >> vart.pavarde_;
        int paz;
        vector <int> pzm;
        while(in >> paz){
            pzm.push_back(paz);
        }
        if (!pzm.empty()) {
                vart.egz_ = pzm.back();
                pzm.pop_back();
                }
        vart.nd_=pzm;
        return in;
    }
    /**
            * @brief Nustato namų darbų pažymius. */
    void setPaz(int paz){
        nd_.push_back(paz);
    }
    /**
            * @brief Nustato namų darbų pažymių vidurkį. */
    void setVid(double vidurkis){
        vid_=vidurkis;
    }
    /**
            * @brief Nustato namų darbų pažymių medianą. */
    void setMed(double med){
        med_=med;
    }
    /**
            * @brief Nustato egzamino rezultatą. */
    void setEgz (int egz){
        egz_ = egz;
    }
    /**
            * @brief Nustato galutinį pažymį. */
    void setGal(double gal){
        gal_ = gal;
    }
    /**
            * @brief Nustato galutinį pažymį su namų darbų vidurkiu. */
    void setGalvid(double galv){
        galvid_=galv;
    }
    /**
            * @brief Nustato galutinį pažymį su namų darbų mediana. */
    void setGalmed(double galm){
        galmed_=galm;
    }
    /**
            * @brief Nustato studento varda.*/
    void setVar(const std::string& vard) { Zmogus::setVar(vard); }
    /**
            * @brief Nustato studento varda.*/

    void setPav(const std::string& pav) { Zmogus::setPav(pav);
    }
    /**
            * @brief Grąžina namų darbų pažymius. */
    const vector<int>& getPaz() const { return nd_; }
    /**
            * @brief Grąžina egzamino rezultatą. */
    int getEgz() const { return egz_; }
    /**
            * @brief Grąžina namų darbų pažymių vidurkį. */
    double getVid() const { return vid_; }
    /**
            * @brief Grąžina galutinį pažymį. */
    double getGal() const { return gal_; }
    /**
            * @brief Grąžina namų darbų medianą. */
    double getMed() const { return med_; }
    /**
            * @brief Grąžina galutinį pažymį su mediana. */
    double getGalmed() const { return galmed_; }
    /**
            * @brief Grąžina galutinį pažymį su vidurkiu. */
    double getGalvid() const { return galvid_; }
    /**
            * @brief Grąžina vardą. */
    string getVar() const override { return vardas_; }
    /**
            * @brief Grąžina pavardę. */
    string getPav() const override { return pavarde_; }
    
    
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
void testas();


#endif /* funkcijos_h */
