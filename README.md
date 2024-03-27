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
# Testas 1
## class
### 100000
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/3f294b02-a70a-455f-a7dc-86445668ab77">
<img width="256" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/65ef9e1f-cb3d-40fe-a3e3-a641fbfce504">

### 1000000
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/09a4665b-757f-450b-9541-10c24e32f414">
<img width="248" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/f1ad260f-2ac0-49a3-9601-179c2086d5fc">

## struct
### 100000
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/d3fbbc30-c51d-4a8a-bf19-4462fcbefe97">
<img width="217" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/f1cd5be7-7dd4-47f7-8985-b43bbe8792e6">

### 1000000
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/243df1ac-0dcd-4465-a35d-bc3eb820990f">
<img width="221" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/4ec09799-6188-49f2-a92b-26dcb36ca965">




