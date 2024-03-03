//
//  main.cpp
//  v0.4
//
//  Created by Kamilė Zobėlaitė on 2024-03-03.
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
        cout << "Iveskite 4 jei norite baigti darba" << endl;
        cin >> gener;
        while(!cin>>gener || gener < 1 || gener > 4)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida! Turite pasirinkti nuo 1 iki 3: \n";
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
                                Vartotojas naujas;
                                double sum = 0.0;
                                cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
                                do{
                                    cin >> naujas.vardas;
                                }while (!arZodis(naujas.vardas));
                                
                               
                                cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
                                do{
                                    cin >> naujas.pavarde;
                                }while (!arZodis(naujas.pavarde));
                                cout << "Iveskite pazymius uz namu darbus kai noresite baigti ivedima, irasykite 0: " << endl;
                                int pazymys;
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
                                    naujas.nd.push_back(pazymys);
                                    sum+=pazymys;
                                    kiek++;
                                   
                                }
                                cout << "Iveskite egzamino rezultata:" << endl;
                                cin >> naujas.egz;
                                while(!cin >> naujas.egz ||naujas.egz<1 || naujas.egz>10)
                                {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Klaida! Egzamino rezultatas turi buti nuo 1 iki 10: \n";
                                    cin >> naujas.egz;
                                }
                                naujas.vid = Vidurkis(sum, kiek);
                                naujas.med = Mediana(naujas.nd, kiek);
                                vart.push_back(naujas);
                            }
                            int rnkts;      // pasirinkimas, kaip norima skaiciuoti galutini ivertinima - pagal vidurki ar mediana
                            cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
                            cin >> rnkts;
                            spausdinti (rnkts, vart, n);
                            break;
                            
                        }
                        case 2: {
                            for (int i = 0; i < n; i++)
                            {
                                Vartotojas naujas;
                                double sum = 0.0;
                                cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
                                do{
                                    cin >> naujas.vardas;
                                }while (!arZodis(naujas.vardas));
                                
                                cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
                                do{
                                    cin >> naujas.pavarde;
                                }while (!arZodis(naujas.pavarde));
                                
                                int pazymys;
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
                                    naujas.nd.push_back(pazymys);
                                    kiek++;
                                    
                                }
                                naujas.egz = generavimasPaz();
                                cout << "Egzamino rezultatas :" << naujas.egz << endl;
                                naujas.vid = Vidurkis(sum, kiek);
                                naujas.med = Mediana(naujas.nd, kiek);
                                vart.push_back(naujas);
                            }
                            int rnkts;      // pasirinkimas, kaip norima skaiciuoti galutini ivertinima - pagal vidurki ar mediana
                            cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
                            cin >> rnkts;
                            spausdinti (rnkts, vart, n);
                            break;
                        }
                        case 3: {
                            for(int i = 0; i < n; i++)
                            {
                                Vartotojas naujas;
                                bool gender;        // lytis
                                gender = rand()%2;
                                naujas.vardas = generavimasVard(gender);
                                naujas.pavarde = generavimasPav(gender);
                                cout << i+1 << " studentas: " << naujas.vardas << " " << naujas.pavarde << endl;
                                double sum = 0.0;
                                int pazymys;
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
                                    naujas.nd.push_back(pazymys);
                                    kiek++;
                                    
                                }
                                naujas.egz = generavimasPaz();
                                cout << "Egzamino rezultatas :" << naujas.egz << endl;
                                naujas.vid = Vidurkis(sum, kiek);
                                naujas.med = Mediana(naujas.nd, kiek);
                                naujas.galvid = 0.4*naujas.vid+0.6*naujas.egz;
                                naujas.galmed = 0.4*naujas.med+0.6*naujas.egz;
                                vart.push_back(naujas);
                            }
                            int rnkts;      // pasirinkimas, kaip norima skaiciuoti galutini ivertinima - pagal vidurki ar mediana
                            cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
                            cin >> rnkts;
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
                        pavadinimas = "studentai10000.txt";
                        break;
                    case 3:
                        pavadinimas = "studentai100000.txt";
                        break;
                    case 4:
                        pavadinimas = "studentai1000000.txt";
                        break;
                }
             
               
                skaityti (vart, pavadinimas);
                rezrikiavimas(vart);
                spausdinti_skaitomus_duomenis(vart);
                break;
            }
            case 3:{
                int rinktis;
                string pavadinimas;
                vector<Vartotojas> vargsai;
                vector<Vartotojas> laimingi;
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
                        cout << "Klaida! Reikia pasirinkti nuo 1 iki 4" << endl;
                        cin >> rinktis;
                        
                    }
                    switch (rinktis) {
                        case 1:{
                            cout << "1000:" << endl;
                            FailuGeneravimas(1000);
                            pavadinimas = "stud1000.txt";
                            skaityti(vart, pavadinimas);
                            RusiavimasDviGrupes(vart, vargsai, laimingi);
                            spausdintiLaimingiVargsai(vargsai, laimingi);
                            break;
                        }
                            
                        case 2:{
                            cout << "10000:" << endl;
                            FailuGeneravimas(10000);
                            pavadinimas = "stud10000.txt";
                            skaityti(vart, pavadinimas);
                            RusiavimasDviGrupes(vart, vargsai, laimingi);
                            spausdintiLaimingiVargsai(vargsai, laimingi);
                            break;
                        }
                           
                        case 3:{
                            cout << "100000:" << endl;
                            FailuGeneravimas(100000);
                            pavadinimas = "stud100000.txt";
                            skaityti(vart, pavadinimas);
                            RusiavimasDviGrupes(vart, vargsai, laimingi);
                            spausdintiLaimingiVargsai(vargsai, laimingi);
                            break;
                        }
                            
                        case 4:{
                            cout << "1000000:" << endl;
                            FailuGeneravimas(1000000);
                            pavadinimas = "stud1000000.txt";
                            skaityti(vart, pavadinimas);
                            RusiavimasDviGrupes(vart, vargsai, laimingi);
                            spausdintiLaimingiVargsai(vargsai, laimingi);
                            break;
                        }
                        case 5:{
                            cout << "10000000:" << endl;
                            FailuGeneravimas(10000000);
                            pavadinimas = "stud10000000.txt";
                            skaityti(vart, pavadinimas);
                            RusiavimasDviGrupes(vart, vargsai, laimingi);
                            spausdintiLaimingiVargsai(vargsai, laimingi);
                            break;
                        }
                    }
                }while(rinktis!=6);
                

            }///
        }
        
    } while (gener!=4);
    
    
    return 0;
}
