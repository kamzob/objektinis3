# objektinis1
# V3.0
## Vektorius klases funkcionalumas
### 1. Operatoriu tikrinimas
#### Testuojami operatoriai (==, !=, <, <=, >, >=):
```
        bool operator== (const Vektorius<T>& other) const {
                if (size() != other.size()) {
                    return false;
                }

                return std::equal(begin(), end(), other.begin());
            }
            bool operator!= (const Vektorius<T>& other) const {
                return !(*this == other);
            }
            bool operator < (const Vektorius<T> & other) const {
                return std::lexicographical_compare(begin(), end(), other.begin(), other.end());
            }
            bool operator <= (const Vektorius<T> & other) const {
                return !(other < *this);
            }
            bool operator > (const Vektorius<T> & other) const {
                return std::lexicographical_compare(other.begin(), other.end(), begin(), end());
            }
            bool operator >= (const Vektorius<T> & other) const {
                return !(other > *this);
            }
```
#### Tikrinamas kodas: 
```
 cout << "1. Operatoriu tikrinimas" << endl;
                {
                    Vektorius<int> pirmas (100);
                    Vektorius<int> antras (200);

                    if (pirmas==antras) cout << "pirmas ir antras yra lygus" << endl;
                    if (pirmas!=antras) cout << "pirmas ir antras nera lygus" << endl;
                    if (pirmas<antras) cout << "pirmas yra mazesnis uz antra" << endl;
                    if (pirmas>antras) cout << "pirmas yra didesnis uz antra" << endl;
                    if (pirmas<=antras) cout << "pirmas yra mazesnis arba lygus antram" << endl;
                    if (pirmas>=antras) cout << "pirmas yra didesnis arba lygus antram" << endl;

                }
```
#### Rezultatas
<img width="241" alt="Screenshot 2024-05-20 at 17 28 08" src="https://github.com/kamzob/objektinis3/assets/149818908/1418f96f-74ca-4f65-8658-86d082203026">

### 2. pop_back() tikrinimas
#### Testuojama funkcija:
```
        void pop_back()
            {
                if (mdydis_ > 0)
                    --mdydis_;
            }
```
#### Tikrinamas kodas:

## Vector ir std::vector spartos analizė bei capacity() perskirstymai
|El. kiekis| std::vector laikas (s) |  Vektorius laikas  |  std::vector perskirstymai |  Vektorius perskirstymai |    
|-----------|-----------|-----------|-----------|-----------|
|10000 | 0.00226392 |   0.000204041      |   14  | 14 |                         
|100000 |  0.0109413 | 0.0006915 |17 | 17  |                        
1000000 |0.0286203 | 0.00552029 | 20 | 20  |                       
10000000 | 0.383573 | 0.0697559 | 24 | 24  |                        
100000000 |3.53119| 0.691559 | 27|27 |                   
