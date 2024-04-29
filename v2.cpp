//
//  main.cpp
//  v2.0
//
//  Created by Kamilė Zobėlaitė on 2024-04-29.
//



#include "funkcijos.h"
int main() {
    srand( static_cast<unsigned int>(time(nullptr)));       // xcode neveikia srand(time(0))
    int n;
    
    
    vector<Vartotojas> vart;
    int pasirinkimas;   // meniu
    int gener;  // duomenu ivedimo budas (1 - ranka, 2 - is failo, 3 - baigti darba)
    
    do {
        cout << "Pasirinkite: " << endl;
        cout << "Iveskite 1 jei norite duomenis ivesti ranka" << endl;
        cout << "Iveskite 2 jei norite, kad duomenis skaitytu is failo" << endl;
        cout << "Iveskite 3 jei norite, kad duomenu failai butu sugeneruojami automatiskai" << endl;
        cout << "Iveskite 4 jei norite, kad butu dirbama su duomenimis is sugeneruotu failu" << endl;
        cout << "Iveskite 5 jei norite, kad butu atliekamas testavimas su klase" << endl;
        cout << "Iveskite 6 jei norite baigti darba" << endl;
        cin >> gener;
        while(!cin>>gener || gener < 1 || gener > 6)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida! Turite pasirinkti nuo 1 iki 5: \n";
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
                vector<Vartotojas> vargsai;
                vector<Vartotojas> laimingi;
                
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
                
        }
        
    } while (gener!=6);
    
    
    return 0;
}

