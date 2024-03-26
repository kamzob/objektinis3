# objektinis2
# V1.1 versija
```
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
```
