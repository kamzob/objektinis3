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

# Testas 2
## class
<img width="221" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/b7171358-a398-4b67-b97c-2234c229a739">

### 100000
#### O1
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/0a062b7b-3d8d-4c02-a840-4a303326bc8d">
<img width="263" alt="Screenshot 2024-03-27 at 15 28 10" src="https://github.com/kamzob/objektinis2/assets/149818908/2b02bda6-6106-4c12-8f80-9bb143888a9d">


#### O2
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/7c34ea44-0178-4976-81d1-1cb46e5e1b4e">
<img width="259" alt="Screenshot 2024-03-27 at 15 27 24" src="https://github.com/kamzob/objektinis2/assets/149818908/7e004e84-fd5c-421c-8f38-4a6f99d76749">


#### O3
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/e97e6d73-469b-4d73-b461-433989771f4c">
<img width="261" alt="Screenshot 2024-03-27 at 15 26 56" src="https://github.com/kamzob/objektinis2/assets/149818908/d508e2c9-85b2-49d7-af3d-6a7a2ba5b22d">

### 1000000
#### O1
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/1d7def22-2a6d-46b2-b0c9-64c00df4d2ac">

#### O2
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/24fe8a48-8ca7-493c-b8e0-60b60e669e10">

#### O3
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/1f953fa1-65b2-4fd9-9a4c-b628fdc53098">

<img width="218" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/919ec5a9-14a5-419a-b4f5-b8d8f2bce0eb">

## struct
### 100000
#### O1
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/4d86b3a9-fbe2-4036-aa2a-a3b3cdc29681">
<img width="268" alt="Screenshot 2024-03-27 at 15 32 19" src="https://github.com/kamzob/objektinis2/assets/149818908/e30b60b0-2e7b-4b39-8892-50c029dde258">

#### O2
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/e5c9d412-9927-43eb-8c73-cb29e77bfaf6">
<img width="266" alt="Screenshot 2024-03-27 at 15 39 57" src="https://github.com/kamzob/objektinis2/assets/149818908/5e6b576c-99f9-4f09-859f-e41326d8184c">

#### O3
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/bed92dad-5a80-46be-bd00-99fa4d839e09">
<img width="262" alt="Screenshot 2024-03-27 at 15 41 13" src="https://github.com/kamzob/objektinis2/assets/149818908/ebb22f04-7cdd-4784-8e63-7716b138512d">

### 1000000
#### O1
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/adbc9c19-a493-460c-be4e-92fca5de060e">

#### O2
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/b9d5a0a1-02d3-43a2-a6ff-64245710679f">

#### O3
<img width="452" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/efc8af3c-6d5d-4914-a533-d7ea8995e1f9">

<img width="214" alt="image" src="https://github.com/kamzob/objektinis2/assets/149818908/72cd46cd-1071-4718-b974-e88c2b0b4cd9">

## Išvada
Su 3 flagu veikia greičiausiai, o su 2 veikia greičiau nei su 1. 
Atminties kiekis mažėja su kiekvienu flagu.
