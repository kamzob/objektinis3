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
#### Norimas rezultatas
```
pirmas ir antras nera lygus
pirmas yra mazesnis uz antra
pirmas yra mazesnis arba lygus antram
```
#### Rezultatas
<img width="241" alt="Screenshot 2024-05-20 at 17 28 08" src="https://github.com/kamzob/objektinis3/assets/149818908/1418f96f-74ca-4f65-8658-86d082203026">

### 2. resize() tikrinimas
#### Testuojama funkcija:
```
            void resize(size_type new_size)
        {
            if (new_size < mdydis_) {
                mdydis_ = new_size;
            } else if (new_size > mdydis_) {
                reserve(new_size);
                mdydis_ = new_size;
            }
        }
```
#### Tikrinamas kodas:
```
cout << "2. resize() tikrinimas:" << endl;
                {
                    Vektorius<int>c = {1, 2, 3};
                    cout << "Vektorius is pradziu: ";
                    c.print();
                    c.resize(5);
                    cout << "Vektorius po dydzio pakeitimo iki 5: ";
                    c.print();
                    c.resize(2);
                    cout << "Vektorius po dydzio pakeitimo iki 2: ";
                    c.print();
                    
                }
```
#### Norimas rezultatas
```
Vektorius is pradziu: { 1 2 3 }
Vektorius po dydzio pakeitimo iki 5: { 1 2 3 0 0 }
Vektorius po dydzio pakeitimo iki 2: { 1 2 }
```
#### Gautas rezultatas
<img width="326" alt="Screenshot 2024-05-20 at 20 48 37" src="https://github.com/kamzob/objektinis3/assets/149818908/59955d5a-ef5f-4ae3-8aa9-ce79e8809471">

### 3. size()
#### Testuojama funkcija
```
size_type size() const noexcept { return mdydis_; }
```
#### Tikrinamas kodas
```
  Vektorius<int> nums {1, 3, 5, 7};
                    cout << "Turimas vektorius: ";
                    nums.print();
                    cout << "Jis sudarytas is " << nums.size() << " elementu.\n";
 ```
#### Norimas rezultatas
```
Turimas vektorius: {1 3 5 7 }
Jis sudarytas is 4 elementu.
```
#### Gautas rezultatas
<img width="225" alt="Screenshot 2024-05-20 at 20 58 38" src="https://github.com/kamzob/objektinis3/assets/149818908/ec45ff8c-8c23-47be-8469-021871977aac">

### 4. clear()
#### Testuojama funkcija
```
        void clear() noexcept
        {
            mdydis_ = 0;
        }
```
#### Tikrinamas kodas:
```
 cout << "4. clear() testavimas: " << endl;
                {
                    Vektorius<int> container{1, 2, 3};
                    cout << "Before clear: ";
                    container.print();
                    cout << "Size=" << container.size() << ", Capacity=" << container.capacity() << '\n';
                    container.clear();
                    cout << "After clear: ";
                    container.print();
                    cout << "Size=" << container.size() << ", Capacity=" << container.capacity() << '\n';
                }
```
#### Norimas rezultatas
```
Before clear: {1 2 3 }
Size=3, Capacity=3
After clear: {}
Size=0, Capacity=3
```
#### Gautas rezultatas
<img width="153" alt="Screenshot 2024-05-20 at 20 52 59" src="https://github.com/kamzob/objektinis3/assets/149818908/31fcfb08-a955-4611-871d-f93cde9b9ce1">

### 5. shrink_to_fit()
#### Testuojama funkcija
```
void shrink_to_fit() 
        {
            if (mdydis_ < mtalpa_) {
                T* naujiDuom = new T[mdydis_];
                std::copy(mduom_, mduom_ + mdydis_, naujiDuom);
                delete[] mduom_;
                mduom_ = naujiDuom;
                mtalpa_ = mdydis_;
            }
        }
```
#### Tikrinamas kodas
```
cout << "5. shrink_to_fit() testavimas" << endl;
                {
                    Vektorius<int> a;
                    cout << "1. default Vektoriaus talpa: " << a.capacity() << endl;
                    a.resize(100);
                    cout << "2. Vektoriaus talpa po resize(100): " << a.capacity() << endl;
                    a.resize(10);
                    cout << "2. Vektoriaus talpa po resize(10): " << a.capacity() << endl;
                    a.shrink_to_fit();
                    cout << "3. Vektoriaus talpa po shrink_to_fit: " << a.capacity() << endl;
                }
```
#### Norimas rezultatas
```
default Vektoriaus talpa: 0
Vektoriaus talpa po resize(100): 100
Vektoriaus talpa po resize(10): 100
Vektoriaus talpa po shrink_to_fit: 10
```
#### Gautas rezultatas
<img width="271" alt="Screenshot 2024-05-20 at 21 02 50" src="https://github.com/kamzob/objektinis3/assets/149818908/57b49fde-ced2-4bc6-bfef-3c3d3206839f">

## Vector ir std::vector spartos analizė bei capacity() perskirstymai
|El. kiekis| std::vector laikas (s) |  Vektorius laikas  |  std::vector perskirstymai |  Vektorius perskirstymai |    
|-----------|-----------|-----------|-----------|-----------|
|10000 | 0.00226392 |   0.000204041      |   14  | 14 |                         
|100000 |  0.0109413 | 0.0006915 |17 | 17  |                        
1000000 |0.0286203 | 0.00552029 | 20 | 20  |                       
10000000 | 0.383573 | 0.0697559 | 24 | 24  |                        
100000000 |3.53119| 0.691559 | 27|27 |                   
