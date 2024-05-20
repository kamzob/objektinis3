//
//  main.cpp
//  V3.0
//
//  Created by Kamilė Zobėlaitė on 2024-05-15.
//




#include "funkcijos.h"
#include "vektorius.h"
/**
 * @file v2.cpp
 * @brief Pagrindinio failo vykdymas
 */
int main() {
    srand( static_cast<unsigned int>(time(nullptr)));       // xcode neveikia srand(time(0))
    int n;
    
    
    Vektorius<Vartotojas> vart;
    int pasirinkimas;   // meniu
    int gener;  // duomenu ivedimo budas (1 - ranka, 2 - is failo, 3 - baigti darba)
    
    do {
        cout << "Pasirinkite: " << endl;
        cout << "Iveskite 1 jei norite duomenis ivesti ranka" << endl;
        cout << "Iveskite 2 jei norite, kad duomenis skaitytu is failo" << endl;
        cout << "Iveskite 3 jei norite, kad duomenu failai butu sugeneruojami automatiskai" << endl;
        cout << "Iveskite 4 jei norite, kad butu dirbama su duomenimis is sugeneruotu failu" << endl;
        cout << "Iveskite 5 jei norite, kad butu atliekamas testavimas su klase" << endl;
        cout << "Iveskite 6 jei norite isbandyti custom vektoriu:" << endl;
        cout << "Iveskite 7 jei norite baigti darba:" << endl;
        cin >> gener;
        while(!cin>>gener || gener < 1 || gener > 7)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida! Turite pasirinkti nuo 1 iki 7: \n";
            cin >> gener;
            
        }
        switch (gener) {
            case 1:{
                cout << "Iveskite vartotoju skaiciu:" << endl;
                cin >> n;
                while(!cin>>n || n < 0 )
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaida! Turite ivesti vartotoju skaiciu!" << endl;
                    cin >> n;
                }
                int rnkts;      // pasirinkimas, kaip norima skaiciuoti galutini ivertinima - pagal vidurki ar mediana
                cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
                cin >> rnkts;
                while (!cin>>rnkts || (rnkts != 0 && rnkts !=1))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaida! Turite pasirinkti 0 (galutinis ivert. skaiciuojamas pagal vidurki) arba 1 (pagal mediana): \n";
                    cin >> rnkts;
                }
                do{
                    // meniu skiltis pasirinkimai
                    cout << "Jeigu norite ivesti duomenis ranka, spauskite 1" << endl;
                    cout << "Jeigu norite, kad pazymiai butu generuojami automatiskai, spauskite 2" << endl;
                    cout << "Jeigu norite, kad pazymiai, studentu vardai ir pavardes butu generuojami automatiskai, spauskite 3" << endl;
                    cout << "Jeigu norite, kad programa baigtu darba, spauskite 4" << endl;
                    cin >> pasirinkimas;
                    while(!cin>>pasirinkimas || pasirinkimas < 1 || pasirinkimas > 4)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida! Turite pasirinkti nuo 1 iki 4: \n";
                        cin >> pasirinkimas;
                        
                    }
                    switch(pasirinkimas) {
                        case 1: {
                            for (int i = 0; i < n; i++)
                            {
                                Vartotojas var;
                                string v, p;
                                double sum = 0.0;
                                cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
                                do{
                                    cin >> v;
                                }while (!arZodis(v));
                                var.setVar(v);
                                cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
                                do{
                                    cin >> p;
                                }while (!arZodis(p));
                                var.setPav(p);
                                cout << "Iveskite pazymius uz namu darbus kai noresite baigti ivedima, irasykite 0: " << endl;
                                int pazymys, egz;
                                string input;
                                int kiek = 0;
                                while(true){
                                        try {
                                            cin >> input;
                                            if(!arSveikasisSk(input)){
                                                cerr << "Klaida! Pazymys turi buti sveikasis skaicius. Iveskite is naujo!\n";
                                                continue;
                                            }
                                            
                                            pazymys = stoi(input);
                                            if(cin.fail() || pazymys < 0 || pazymys > 10)
                                            {
                                                throw runtime_error("Netinkama ivestis. Pazymys turi buti sveikasis skaicius nuo 1 iki 10");
                                                
                                            }
                                                
                                        } catch (exception& e) {
                                            cout << "Klaida: " << e.what() << endl;
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cout << "Iveskite is naujo: " << endl;
                                            cin >> pazymys;
                                        

                                        }

                                    
                                    if(pazymys==0)
                                        break;
                                    var.setPaz(pazymys);
                                    sum+=pazymys;
                                    kiek++;
                                   
                                }
                                cout << "Iveskite egzamino rezultata:" << endl;
                                cin >> egz;
                                while(!cin >> egz || egz<1 || egz>10)
                                {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Klaida! Egzamino rezultatas turi buti nuo 1 iki 10: \n";
                                    cin >> egz;
                                }
                                var.setEgz(egz);
                                var.setMed(Mediana(var.getPaz(), kiek));
                                var.setVid(Vidurkis(sum, kiek));
                                var.setGalmed(0.4*var.getMed()+0.6*var.getEgz());
                                var.setGalvid(0.4*var.getVid()+0.6*var.getEgz());
                                if(rnkts==0) var.setGal(var.getGalvid());
                                else var.setGal(var.getMed());
                                vart.push_back(var);
                            }
                            spausdinti (rnkts, vart, n);
                            break;
                            
                        }
                        case 2: {
                            for (int i = 0; i < n; i++)
                            {
                                Vartotojas var;
                                string v, p;
                                double sum = 0.0;
                                cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
                                do{
                                    cin >> v;
                                }while (!arZodis(v));
                                var.setVar(v);
                                cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
                                do{
                                    cin >> p;
                                }while (!arZodis(p));
                                var.setPav(p);
                                int pazymys, egz;
                                int kiek = 0;
                                int renku = 0;
                                while(true)
                                {
                                    cout << "Jei norite kad sugeneruotu pazymi spauskite 1, jei norite kad baigtu generuoti spauskite 0: " << endl;
                                    cin >> renku;
                                    while(!cin>>renku || renku < 0 || renku > 1)
                                    {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        
                                        cout << "Jei norite kad sugeneruotu pazymi spauskite 1, jei norite kad baigtu generuoti spauskite 0: " << endl;
                                        cin >> renku;
                                    }
                                    if(renku==0)
                                        break;
                                    pazymys = generavimasPaz();
                                    cout << pazymys << endl;
                                    var.setPaz(pazymys);
                                    sum += pazymys;
                                    kiek++;
                                    
                                }
                                egz = generavimasPaz();
                                var.setEgz(egz);
                                cout << "Egzamino rezultatas :" << egz << endl;
                                var.setVid(Vidurkis(sum, kiek));
                                var.setMed(Mediana(var.getPaz(), kiek));
                                var.setGalmed(0.4*var.getMed()+0.6*var.getEgz());
                                var.setGalvid(0.4*var.getVid()+0.6*var.getEgz());
                                if(rnkts==0) var.setGal(var.getGalvid());
                                else var.setGal(var.getMed());
                                vart.push_back(var);
                            }
                            spausdinti (rnkts, vart, n);
                            break;
                        }
                        case 3: {
                            for(int i = 0; i < n; i++)
                            {
                                Vartotojas var;
                                bool gender;        // lytis
                                string v, p;
                                gender = rand()%2;
                                v = generavimasVard(gender);
                                p = generavimasPav(gender);
                                var.setVar(v);
                                var.setPav(p);
                                cout << i+1 << " studentas: " << v << " " << p << endl;
                                double sum = 0.0;
                                int pazymys, egz;
                                int kiek = 0;
                                int renku = 0;
                                while(true)
                                {
                                    cout << "Jei norite kad sugeneruotu pazymi spauskite 1, jei norite kad baigtu generuoti spauskite 0: " << endl;
                                    cin >> renku;
                                    while(!cin>>renku || renku < 0 || renku > 1)
                                    {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        
                                        cout << "Jei norite kad sugeneruotu pazymi spauskite 1, jei norite kad baigtu generuoti spauskite 0: " << endl;
                                        cin >> renku;
                                    }
                                    if(renku==0)
                                        break;
                                    pazymys = generavimasPaz();
                                    cout << pazymys << endl;
                                    sum += pazymys;
                                    var.setPaz(pazymys);
                                    kiek++;
                                    
                                }
                                egz = generavimasPaz();
                                var.setEgz(egz);
                                cout << "Egzamino rezultatas :" << egz << endl;
                                var.setMed(Mediana(var.getPaz(), kiek));
                                var.setVid(Vidurkis(sum, kiek));
                                var.setGalmed(0.4*var.getMed()+0.6*var.getEgz());
                                var.setGalvid(0.4*var.getVid()+0.6*var.getEgz());
                                if(rnkts==0) var.setGal(var.getGalvid());
                                else var.setGal(var.getMed());
                                vart.push_back(var);
                            }
                            
                            spausdinti (rnkts, vart, n);
                            break;
                        }
                            
                            
                    }
                    
                } while(pasirinkimas != 4);
                break;
            }
            case 2:{
                string pavadinimas;;
                int opt;
                cout << "Egzistuojantys .txt failai kataloge: \n";
                system("ls -a *.txt");
                cout << "Pasirinkite, is kurio failo norite nuskaityti duomenis: " << endl;
                cout << "1 - kursiokai.txt\n";
                cout << "2 - studentai10000.txt\n";
                cout << "3 - studentai100000.txt\n";
                cout << "4 - studentai1000000.txt\n";
                cin >> opt;
                while(cin.fail()|| opt < 1 || opt > 4)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaida! Reikia pasirinkti nuo 1 iki 4" << endl;
                    cin >> opt;
                    
                }
                switch (opt) {
                    case 1:
                        pavadinimas = "kursiokai.txt";
                        break;
                    case 2:
                        pavadinimas = "stud10000.txt";
                        break;
                    case 3:
                        pavadinimas = "studentai100000.txt";
                        break;
                    case 4:
                        pavadinimas = "studentai1000000.txt";
                        break;
                }
             
               
                skaityti (vart, pavadinimas, 0);
                rezrikiavimas(vart);
                spausdinti_skaitomus_duomenis(vart);
                break;
            }
            case 3:{
                int kiek = 1000;
                for (int i = 0; i < 5; i++)
                {
                    FailuGeneravimas(kiek);
                    kiek*=10;
                }
                break;
            }
            case 4:{
                int rinktis;
                int vm;         // vidurkis ar mediana
                int strategy;
                string pavadinimas;
                Vektorius<Vartotojas> vargsai;
                Vektorius<Vartotojas> laimingi;
                
                cout << "Pasirinkite, pagal ka noresite, kad rikiuotu duomenis ir isvestu galutini pazymi: " << endl;
                cout << "0 - pagal vidurki" << endl;
                cout << "1 - pagal mediana" << endl;
                cin >> vm;
                while(cin.fail()|| (vm != 0 && vm != 1))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaida! Iveskite 1 arba 0: " << endl;
                    cin >> vm;
                }
                cout << "Pasirinkite strategija 1 arba 2 arba 3: " << endl;
                cin >> strategy;
                while(cin.fail()|| (strategy != 1 && strategy != 2 && strategy != 3))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Klaida! Iveskite 1-3: " << endl;
                    cin >> strategy;
                }
                do{
                    cout << "Pasirinkite studentu kieki: " << endl;
                    cout << "1 - 1000 studentu" << endl;
                    cout << "2 - 10000 studentu" << endl;
                    cout << "3 - 100000 studentu" << endl;
                    cout << "4 - 1000000 studentu" << endl;
                    cout << "5 - 10000000 studentu" << endl;
                    cout << "6 - baigti darba" << endl;
                    cin >> rinktis;
                    while(cin.fail()|| rinktis < 1 || rinktis > 6)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida! Reikia pasirinkti nuo 1 iki 6" << endl;
                        cin >> rinktis;
                        
                    }
                    switch (rinktis) {
                        case 1:{
                            cout << "1000:" << endl;
                            cout << strategy << " strategija" << endl;
                            auto start = std::chrono::high_resolution_clock::now();
                            pavadinimas = "stud1000.txt";
                            if(strategy == 1){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes(vart, vargsai, laimingi, vm);
                                spausdintiLaimingiVargsai(vargsai, laimingi, vm);
                            }
                            if(strategy==2){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes2(vart, vargsai, vm);
                            }
                            if(strategy==3){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes3(vart, vargsai, vm);
                                
                            }
                            auto end = std::chrono::high_resolution_clock::now();
                            std::chrono::duration<double> laikas = end - start;
                            cout << "Visas programos laikas: " << laikas.count() << " sek." << endl;
                            break;
                        }
                            
                        case 2:{
                            cout << "10000:" << endl;
                            cout << strategy << " strategija" << endl;
                            auto start = std::chrono::high_resolution_clock::now();
                            pavadinimas = "stud10000.txt";
                            if(strategy == 1){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes(vart, vargsai, laimingi, vm);
                                spausdintiLaimingiVargsai(vargsai, laimingi, vm);
                            }
                            if(strategy==2){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes2(vart, vargsai, vm);
                            }
                            if(strategy==3){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes3(vart, vargsai, vm);
                            }
                            auto end = std::chrono::high_resolution_clock::now();
                            std::chrono::duration<double> laikas = end - start;
                            cout << "Visas programos laikas: " << laikas.count() << " sek."<< endl;
                            break;
                        }
                           
                        case 3:{
                            cout << "100000:" << endl;
                            cout << strategy << " strategija" << endl;
                            auto start = std::chrono::high_resolution_clock::now();
                            pavadinimas = "stud100000.txt";
                            if(strategy == 1){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes(vart, vargsai, laimingi, vm);
                                spausdintiLaimingiVargsai(vargsai, laimingi, vm);
                            }
                            if(strategy==2){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes2(vart, vargsai, vm);
                            }
                            if(strategy==3){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes3(vart, vargsai, vm);
                            }
                            auto end = std::chrono::high_resolution_clock::now();
                            std::chrono::duration<double> laikas = end - start;
                            cout << "Visas programos laikas: " << laikas.count() << " sek." << endl;
                            break;
                        }
                            
                        case 4:{
                            cout << "1000000:" << endl;
                            cout << strategy << " strategija" << endl;
                            auto start = std::chrono::high_resolution_clock::now();
                            pavadinimas = "stud1000000.txt";
                            if(strategy == 1){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes(vart, vargsai, laimingi, vm);
                                spausdintiLaimingiVargsai(vargsai, laimingi, vm);
                            }
                            if(strategy==2){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes2(vart, vargsai, vm);
                            }
                            if(strategy==3){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes3(vart, vargsai, vm);
                            }
                            auto end = std::chrono::high_resolution_clock::now();
                            std::chrono::duration<double> laikas = end - start;
                            cout << "Visas programos laikas: " << laikas.count() << " sek." << endl;
                            break;
                        }
                        case 5:{
                            cout << "10000000:" << endl;
                            cout << strategy << " strategija" << endl;
                            auto start = std::chrono::high_resolution_clock::now();
                            pavadinimas = "stud10000000.txt";
                            if(strategy == 1){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes(vart, vargsai, laimingi, vm);
                                spausdintiLaimingiVargsai(vargsai, laimingi, vm);
                            }
                            if(strategy==2){
//                                cout << "vector" << endl;
//                                skaityti(vart, pavadinimas, vm);
//                                RusiavimasDviGrupes2(vart, vargsai, vm);

                            }
                            if(strategy==3){
                                cout << "vector" << endl;
                                skaityti(vart, pavadinimas, vm);
                                RusiavimasDviGrupes3(vart, vargsai, vm);
                            }
                            auto end = std::chrono::high_resolution_clock::now();
                            std::chrono::duration<double> laikas = end - start;
                            cout << "Visas programos laikas: " << laikas.count() << " sek." << endl;
                            break;
                        }
                    }
                }while(rinktis!=6);
                break;

            }
            case 5:{
                testas();
                break;
            }
            case 6:{
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
                cout << endl;
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
                cout << endl;
                cout << "3. size() testavimas: " << endl;
                {
                    Vektorius<int> nums {1, 3, 5, 7};
                    cout << "Turimas vektorius: ";
                    nums.print();
                    cout << "Jis sudarytas is " << nums.size() << " elementu.\n";
                }
               
                
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
                cout << endl;
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
                cout << endl;
                
//                std::vector<int> v1{1,5,6,8,9,7,4,5,6,2,1,3,5,8,9,5,6,8,7,4,5,5,5,8,7,8,9,6,5,8,74,5,6,8,7,4,5,56,4,45};
//                 std::cout << "Vector v.size(): "<< v1.at(2)<<"\n";
//                Vektorius<int> v2{1,5,6,8,9,7,4,5,6,2,1,3,5,8,9,5,6,8,7,4,5,5,5,8,7,8,9,6,5,8,74,5,6,8,7,4,5,56,4,45};
//                std::cout << "Vector v2.size(): "<< v2.at(2)<<"\n";
//                Vektorius<int> v3(6,5);
//                cout << v3 << endl;
//                std::cout << "Vector v2.size(): "<< v3.size()<<"\n";
//                Vektorius<int> original(10, 5); // Sukuriamas vektorius su 10 elementų, kurių kiekvienas lygus 5
//                Vektorius<int> moved;
//                moved = std::move(original); // Naudojamas perkėlimo priskyrimo operatorius
//
//                for(int i = 0; i < moved.size(); i++)
//                {
//                    cout << moved[i] << " ";
//                }
//                cout << moved.begin() << " " << moved.end() << endl;
//                cout << moved.capacity() << endl;
//                unsigned int sz = 100000000;
//                Vektorius<int> v2;
//                int vector_perskirstymas = 0;
//                for (int i = 0; i < sz; ++i) {
//                    v2.push_back(i);
//                    if (v2.capacity() == v2.size()) {
//                        ++vector_perskirstymas;
//                    }
//                }
//                cout << "Atmintis buvo perskirstyta " << vector_perskirstymas << " kartu su Vector" << endl;
                cout << left << setw(20) << "El. kiekis" << setw(30) << "std::vector laikas (s)" << setw(20)<< "Vektorius laikas" << setw(28)<< "std::vector perskirstymai"<< setw(28) << "Vektorius perskirstymai" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------------"
                         << endl;
                // Pradėti v1 užpildymo laiko matavimą
                for (unsigned int sz : {10000, 100000, 1000000, 10000000, 100000000})
                {
                    auto start1 = std::chrono::high_resolution_clock::now();
                    int perskirstymas1 = 0;
                    std::vector<int> v1;
                    for (int i = 1; i <= sz; ++i)
                    {
                        v1.push_back(i);
                        if(v1.size()==v1.capacity())
                        {
                            perskirstymas1++;
                        }
                        
                    }
                      
                    auto end1 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> laikas1 = end1- start1;
                    // Baigti v1 užpildymo laiko matavimą

                    // Pradėti v2 užpildymo laiko matavimą
                    auto start2 = std::chrono::high_resolution_clock::now();
                    int perskirstymas2 = 0;
                    Vektorius<int> v2;
                    for (int i = 1; i <= sz; ++i)
                    {
                        v2.push_back(i);
                        if(v2.size()==v2.capacity())
                        {
                            perskirstymas2++;
                        }
                    }
                      
                    auto end2 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> laikas2 = end2 - start2;
                    // Baigti v2 užpildymo laiko matavimą
                    cout << left << setw(20) << sz << setw(30) << laikas1.count() << setw(20)<< laikas2.count() << setw(28)<< perskirstymas1<< setw(28) << perskirstymas2 << endl;
                }
                
            }
                
        }
        
    } while (gener!=7);
    
    
    return 0;
}

