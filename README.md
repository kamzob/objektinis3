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
    virtual void  kazkas() const = 0;
    virtual void setVar (string vard) {
        vardas_=vard;
    }
    virtual void setPav (string pav) {
        pavarde_=pav;
    }
    virtual string getVar() const { return vardas_;}
    virtual string getPav() const {return pavarde_;}
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
    ~Vartotojas() { nd_.clear(); }
    // copy konstruktorius
    Vartotojas(const Vartotojas& other)
    : Zmogus(other.getVar(), other.getPav()), nd_(other.nd_), egz_(other.egz_), vid_(other.vid_), gal_(other.gal_), med_(other.med_), galmed_(other.galmed_), galvid_(other.galvid_) {}
    void kazkas () const override{}
    
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
    string getVar() const override { return Zmogus::getVar(); }
    string getPav() const override { return Zmogus::getPav(); }
    
    
};
```
## Atliktas testavimas
### Testuojamas kodas
<img width="569" alt="Screenshot 2024-04-15 at 23 33 32" src="https://github.com/kamzob/objektinis2/assets/149818908/a3032425-2b80-4abb-95ae-ea5483680442">

<img width="846" alt="Screenshot 2024-04-15 at 23 34 06" src="https://github.com/kamzob/objektinis2/assets/149818908/90294b3c-18c2-40de-96ac-766b41e51644">

### Testavimo rezultatas
<img width="477" alt="Screenshot 2024-04-15 at 23 34 53" src="https://github.com/kamzob/objektinis2/assets/149818908/92311991-f8d5-4a69-8984-d69ad619a4d7">

