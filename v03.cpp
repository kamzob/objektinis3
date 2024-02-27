//
//  main.cpp
//  v03
//
//  Created by Kamilė Zobėlaitė on 2024-02-26.
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
        cout << "Iveskite 3 jei norite baigti darba" << endl;
        cin >> gener;
        while(!cin>>gener || gener < 1 || gener > 3)
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
                skaityti (vart);
                break;
            }
            default:
                break;
        }
        
    } while (gener!=3);
    
    
    return 0;
}
