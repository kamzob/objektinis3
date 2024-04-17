# objektinis1
# V1.2 versija
## Rule of five
### Destructor
(*destruktorius*) - jis užtikrina išvalymą/resursų atlaisvinimą:

<img width="488" alt="Screenshot 2024-04-15 at 15 59 30" src="https://github.com/kamzob/objektinis2/assets/149818908/937fb2dc-399d-4b2e-9403-c0801c4305c4">

### Copy constructor
(*kopijavimo konstruktorius*) - konstruktorius, skirtas sukurti naują objektą kaip esamo objekto kopiją.

<img width="654" alt="Screenshot 2024-04-15 at 16 04 10" src="https://github.com/kamzob/objektinis2/assets/149818908/61e9f761-5b89-4c92-a457-c76379cb27a8">

### Move constructor
(*perkėlimo konstruktorius*) - perkėlimo konstruktorius yra naudojamas perkelti resursus iš vieno objekto į kitą objektą, nepriklausomai nuo to, kuriuo objektu yra naudojamas šis konstruktorius.

<img width="652" alt="Screenshot 2024-04-15 at 16 20 34" src="https://github.com/kamzob/objektinis2/assets/149818908/e5ce59c9-7f55-4727-807e-b289a9f231c6">

### Copy asssignment operator
(*kopijavimo priskyrimo operatorius*) - operatorius, kuris priskira vieną objektą kitam. 

<img width="436" alt="Screenshot 2024-04-15 at 16 26 58" src="https://github.com/kamzob/objektinis2/assets/149818908/69a3a8fa-e7f8-4ebf-8f8c-265b952dfbb4">

### Move assignment operator
(*perkėlimo priskyrimo operatorius*) - operatorius, kuris perkeltą objektą priskiria kitam objektui, naudojant operatorių =.
<img width="421" alt="Screenshot 2024-04-15 at 16 28 49" src="https://github.com/kamzob/objektinis2/assets/149818908/862ebfb9-7ed3-425a-8ed4-49cfa323ac99">

### Rule of five testavimas programoje
<img width="581" alt="Screenshot 2024-04-15 at 16 38 30" src="https://github.com/kamzob/objektinis2/assets/149818908/08cdbdcc-8dcd-4719-91cc-4cf15184ea5e">
<img width="587" alt="Screenshot 2024-04-15 at 16 38 53" src="https://github.com/kamzob/objektinis2/assets/149818908/f38a21d3-88df-4830-9b1b-f72b9a1566b1">

#### Testavimo rezultatas

<img width="412" alt="Screenshot 2024-04-16 at 22 46 56" src="https://github.com/kamzob/objektinis2/assets/149818908/291b03c9-367f-4c53-9802-43083c18a147">



## Įvesties/išvesties operatorių perdengimas
<img width="657" alt="Screenshot 2024-04-15 at 16 29 53" src="https://github.com/kamzob/objektinis2/assets/149818908/bba410b7-76a5-4592-88b0-a8ab3eec4101">

### Panaudojimas programoje
#### Isvestis
<img width="480" alt="Screenshot 2024-04-15 at 16 30 40" src="https://github.com/kamzob/objektinis2/assets/149818908/ba60e17e-8245-4518-9a7a-50e02ebd41f7">
<img width="450" alt="Screenshot 2024-04-15 at 16 31 24" src="https://github.com/kamzob/objektinis2/assets/149818908/ad71120a-9039-42cb-b5c2-ec6cb1687bae">
<img width="637" alt="Screenshot 2024-04-15 at 16 32 54" src="https://github.com/kamzob/objektinis2/assets/149818908/b0aa13d2-a0d3-4db5-9950-1b71d6221770">

#### Ivestis
<img width="508" alt="Screenshot 2024-04-15 at 16 34 12" src="https://github.com/kamzob/objektinis2/assets/149818908/902f9d4a-dd47-457d-9e5c-0a38327722f2">

## class po atliktu pakeitimu
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
    // destruktorius
    ~Vartotojas() {nd_.clear(), vardas_.clear(), pavarde_.clear();}
    // copy konstruktorius
    Vartotojas(const Vartotojas& other)
    : vardas_(other.vardas_), pavarde_(other.pavarde_), nd_(other.nd_), egz_(other.egz_), vid_(other.vid_), gal_(other.gal_), med_(other.med_), galmed_(other.galmed_), galvid_(other.galvid_) {}
    
    // Copy assignment operatorius
        Vartotojas& operator=(const Vartotojas& other) {
            if (this != &other) {
                vardas_ = other.vardas_;
                pavarde_ = other.pavarde_;
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
    Vartotojas(Vartotojas&& other) noexcept
    : vardas_(std::move(other.vardas_)), pavarde_(std::move(other.pavarde_)), nd_(std::move(other.nd_)), egz_(other.egz_), vid_(other.vid_), gal_(other.gal_), med_(other.med_), galmed_(other.galmed_), galvid_(other.galvid_) {}
    // move assignment operatorius
    Vartotojas& operator=(Vartotojas&& other) noexcept {
            if (this != &other) {
                vardas_ = std::move(other.vardas_);
                pavarde_ = std::move(other.pavarde_);
                nd_ = std::move(other.nd_);
                egz_ = other.egz_;
                vid_ = other.vid_;
                gal_ = other.gal_;
                med_ = other.med_;
                galmed_ = other.galmed_;
                galvid_ = other.galvid_;
            }
            return *this;
        }
    friend ostream& operator<<(ostream& out, const Vartotojas &vart){
        out << left << setw(20) << vart.vardas_ << setw(20) << vart.pavarde_ << setw(20) << fixed << setprecision(2) << vart.gal_ << endl;
        return out;
    }
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
## Laikai
| Studentu kiekis | Skaitymas (sek.) | Rikiavimas (sek.) | Rusiavimas i konteinerius (sek.)| 
|-----------------|-----------------|-----------------|-----------------|
| 1000 | 0.0306058 | 0.000639958 | 0.000361125 | 
| 10000 |  0.133864 | 0.00610438 | 0.00361938 | 
| 100000 | 1.10602 | 0.059842 | 0.0345146 | 
| 1000000 | 10.8627 | 0.603886 | 0.369491 |
| 10000000 | 128.084 | 7.25368 | 4.99316 |
