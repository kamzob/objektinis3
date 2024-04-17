# objektinis1
# V1.5 versija
## Buvusi klase padalinta i dvi naujas bazinę (abstrakti) Zmogus ir išvestinę derived Vartotojas
### abstrakti Zmogus
```
class Zmogus
{
protected:
    string vardas_;
    string pavarde_;
public:
    Zmogus() = default;
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
```
### derived Vartotojas
```
class Vartotojas : public Zmogus
{
private:
    vector<int> nd_;              // namu darbu vekt
    int egz_;                // studento egzamino rezultatas
    double vid_;       // namu darbu pazymiu vidurkis
    double gal_;       // galutinis ivertinimas
    double med_;       // namu darbu mediana
    double galmed_;
    double galvid_;
public:
    Vartotojas() : vid_(0.0), gal_(0.0), med_(0.0), galmed_(0.0), galvid_(0.0) {}
    Vartotojas(const string vardas, const string pavarde, const vector<int>& nd, int egz, double vid, double gal, double med, double galmed, double galvid)
    : Zmogus(vardas, pavarde), nd_(nd), egz_(egz), vid_(vid), gal_(gal), med_(med), galmed_(galmed), galvid_(galvid) {}
    // destruktorius
    ~Vartotojas() {
        cout << "Objektas sunaikintas" << endl;
        nd_.clear();
        }
    // copy konstruktorius
    Vartotojas(const Vartotojas& other)
    : Zmogus(other.getVar(), other.getPav()), nd_(other.nd_), egz_(other.egz_), vid_(other.vid_), gal_(other.gal_), med_(other.med_), galmed_(other.galmed_), galvid_(other.galvid_) {}
    //void kazkas () const override{}
    
    // Copy assignment operatorius
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
    Vartotojas(Vartotojas&& other) noexcept
    : Zmogus(std::move(other.vardas_), std::move(other.pavarde_)), nd_(std::move(other.nd_)), egz_(other.egz_), vid_(other.vid_), gal_(other.gal_), med_(other.med_), galmed_(other.galmed_), galvid_(other.galvid_) {}
    // move assignment operatorius
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
    void setVar(const std::string& vard) { Zmogus::setVar(vard); }

    void setPav(const std::string& pav) { Zmogus::setPav(pav);
    }
    const vector<int>& getPaz() const { return nd_; }
    int getEgz() const { return egz_; }
    double getVid() const { return vid_; }
    double getGal() const { return gal_; }
    double getMed() const { return med_; }
    double getGalmed() const { return galmed_; }
    double getGalvid() const { return galvid_; }
    string getVar() const override { return vardas_; }
    string getPav() const override { return pavarde_; }
    
    
};
 
```
## class Zmogus abstrakti
Kad klase Zmogus butu abstrakti, naudojamos grynai virtualios funkcijos:
<img width="225" alt="Screenshot 2024-04-17 at 00 29 06" src="https://github.com/kamzob/objektinis2/assets/149818908/6a1d294f-7da8-4d77-93b7-5d849a30f2f0">

Jos override'inamos klaseje Vartotojas:
<img width="325" alt="Screenshot 2024-04-17 at 00 29 58" src="https://github.com/kamzob/objektinis2/assets/149818908/999028db-c12c-497c-a9f7-33142643289e">

## Rule of five
### Destructor
(*destruktorius*) - jis užtikrina išvalymą/resursų atlaisvinimą:
<img width="300" alt="Screenshot 2024-04-17 at 00 32 50" src="https://github.com/kamzob/objektinis2/assets/149818908/e827cccd-7dac-41ec-85e1-03c5c144e3ca">



### Copy constructor
(*kopijavimo konstruktorius*) - konstruktorius, skirtas sukurti naują objektą kaip esamo objekto kopiją.

<img width="599" alt="Screenshot 2024-04-17 at 00 33 15" src="https://github.com/kamzob/objektinis2/assets/149818908/1d614795-257c-4f24-82d6-cb4dedb2b586">


### Move constructor
(*perkėlimo konstruktorius*) - perkėlimo konstruktorius yra naudojamas perkelti resursus iš vieno objekto į kitą objektą.

<img width="635" alt="Screenshot 2024-04-17 at 00 33 38" src="https://github.com/kamzob/objektinis2/assets/149818908/904e8225-50ba-475b-a81c-46bf352956ca">



### Copy asssignment operator
(*kopijavimo priskyrimo operatorius*) - operatorius, kuris priskira vieną objektą kitam, naudojant operatoriu =. 

<img width="339" alt="Screenshot 2024-04-17 at 00 34 11" src="https://github.com/kamzob/objektinis2/assets/149818908/f3bd3de2-8ac9-490d-81d0-3a6daf2ca93b">



### Move assignment operator
(*perkėlimo priskyrimo operatorius*) - operatorius, kuris perkeltą objektą priskiria kitam objektui, naudojant operatorių =.
<img width="355" alt="Screenshot 2024-04-17 at 00 34 45" src="https://github.com/kamzob/objektinis2/assets/149818908/896ca3bb-09bb-4464-9614-d4fe117d0bd5">

## Atliktas testavimas
### Testuojamas kodas
<img width="569" alt="Screenshot 2024-04-15 at 23 33 32" src="https://github.com/kamzob/objektinis2/assets/149818908/a3032425-2b80-4abb-95ae-ea5483680442">

<img width="846" alt="Screenshot 2024-04-15 at 23 34 06" src="https://github.com/kamzob/objektinis2/assets/149818908/90294b3c-18c2-40de-96ac-766b41e51644">

### Testavimo rezultatas
<img width="366" alt="Screenshot 2024-04-17 at 00 25 19" src="https://github.com/kamzob/objektinis2/assets/149818908/f832aeb7-5a0e-42be-bbfb-46703de7156f">

## Įvesties/išvesties operatorių perdengimas
<img width="657" alt="Screenshot 2024-04-15 at 16 29 53" src="https://github.com/kamzob/objektinis2/assets/149818908/bba410b7-76a5-4592-88b0-a8ab3eec4101">

### Panaudojimas programoje
#### Isvestis
<img width="480" alt="Screenshot 2024-04-15 at 16 30 40" src="https://github.com/kamzob/objektinis2/assets/149818908/ba60e17e-8245-4518-9a7a-50e02ebd41f7">
<img width="450" alt="Screenshot 2024-04-15 at 16 31 24" src="https://github.com/kamzob/objektinis2/assets/149818908/ad71120a-9039-42cb-b5c2-ec6cb1687bae">
<img width="637" alt="Screenshot 2024-04-15 at 16 32 54" src="https://github.com/kamzob/objektinis2/assets/149818908/b0aa13d2-a0d3-4db5-9950-1b71d6221770">

#### Ivestis
<img width="508" alt="Screenshot 2024-04-15 at 16 34 12" src="https://github.com/kamzob/objektinis2/assets/149818908/902f9d4a-dd47-457d-9e5c-0a38327722f2">

## Laikai
### nepadalinta klase
| Studentu kiekis | Skaitymas (sek.) | Rikiavimas (sek.) | Rusiavimas i konteinerius (sek.)| 
|-----------------|-----------------|-----------------|-----------------|
| 1000 | 0.0306058 | 0.000639958 | 0.000361125 | 
| 10000 |  0.133864 | 0.00610438 | 0.00361938 | 
| 100000 | 1.10602 | 0.059842 | 0.0345146 | 
| 1000000 | 10.8627 | 0.603886 | 0.369491 |
| 10000000 | 128.084 | 7.25368 | 4.99316 |
### isskirstyta klase i bazine ir derived
| Studentu kiekis | Skaitymas (sek.) | Rikiavimas (sek.) | Rusiavimas i konteinerius (sek.)| 
|-----------------|-----------------|-----------------|-----------------|
| 1000 | 0.0302277 | 0.000499375 | 0.000349708 | 
| 10000 |  0.136767 | 0.00476746 | 0.00327629 | 
| 100000 | 1.14226 | 0.0465272 | 0.0325425 | 
| 1000000 | 11.2364 | 0.475037 | 0.35646 |
| 10000000 | 114.4 | 4.86333 | 4.16166 |
