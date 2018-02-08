#include <iostream>
#include <math.h>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <ctime>

//Mikołaj Porębski, Arek Kopczyński klasa 3B1T

using namespace std;

int KontoGracza = 100;
int KontoKasyna = 1000;

void OProgramie();
void Menu();
int StanKasyno(int KontoKasyna);
int StanGracz(int KontoGracza);
int Czysc();
void Zasady();
int Losowanie();
void sprawdzKoniec();

int Pojedyncza(int pojedyncza, int Pula);
int PrzystaNieparzysta(int parzysta, int Pula);
int Tuziny(int Pula);



int main(){
	int n;
	do{
		Menu();
			cin >> n;

				switch(n){
					case 0: Czysc();
							cout << "DOWIDZENIA!!!" << endl;
							break;
					case 1: Czysc();
							Losowanie();
							break;
					case 2: Czysc();
							Zasady();
							break;
					case 3: Czysc();
							StanGracz(KontoGracza);
							break;
					case 4: Czysc();
							StanKasyno(KontoKasyna);
							break;
					case 5: Czysc();
							OProgramie();
							break;
					default: cout << "podaj jeszcze raz: " << endl;
				}
		}while(n!=0);





	return 0;
}

void Zasady(){
	cout << "1. Numery parzyste, albo nieparzyste - wygrana = k * 1" << endl;
	cout << "2. Dowolny jeden numer, za wyj1tkiem 0, wygrana = k*35" << endl;
	cout << "3. Dwa kolejne numery, wygrana = k * 17" << endl;
	cout << "4. Trzy kolejne numery, wygrana = k * 11" << endl;
	cout << "WYNIK RZUTU 0 ZAWSZE OZNACZA WYGRANA KASYNA!!!" << endl;
	cout << "5. Tuziny: 1-12(pierwszy), 13-24(drugi), 25-36(trzeci), wygrana = k * 2" << "\n\n---------------------------\n" << endl;
}

int Czysc(){
	system("cls");
}

int StanKasyno(int a){
	cout << "Stan konta kasyna: " << a << "\n-----------------\n";
}

int StanGracz(int a){
	cout << "Stan konta gracza: " << a << "\n--------------------\n";
}

void OProgramie(){

	cout << "Autorzy: Mikolaj Porebski, Arkadiusz Kopczynski" << endl;
	cout << "Klasa: 3b1t" << endl;
	cout << "Data publikacji kodu: 07.02.2018r. godz. 12:17" << endl;


}

void Menu(){
	cout << "Wybierz liczbe!" << endl;
	cout << "1. GRAJ" << endl;
	cout << "2. Zasady!" << endl;
	cout << "3. Stan konta gracza" << endl;
	cout << "4. Stan konta kasyna" << endl;
	cout << "5. O programie" << endl;
	cout << "0. Przerwij dzialanie programu" << endl;
}

int Losowanie(){

srand(time(NULL));

	//int Zaklad;
//	cout << "Obstaw liczbe!!!" << endl;
//	cin >> Zaklad;
	int Pula;
	cout << "Podaj ile pieniedzy obstawiasz!!!" << endl;
	cin >> Pula;

	cout<<"\nAktualnie obstawiasz: "<<Pula<<" zetonow\n"<<endl;
//	int Wygrana;
/*	cout << "Wylosowales: " << losowana << endl;

	if(losowana == Zaklad){
		cout << "Brawo, to ta sama liczba!!!" << endl;
		Wygrana = Pula * 35;
		cout << "Tyle wygrales: " << Wygrana << endl;
	}else{
		cout << "Nastepnym razem Ci sie uda!!!" << endl;
	}

	sprawdz(); */


			cout << "1 - Obstaw pojedyncza liczbe" << endl;
			cout << "2 - Obstaw parzysta lub nieparzysta" << endl;
			cout << "3 - Obstaw tuziny" << endl;
			cout << "4 - Obstaw 3 liczby obok siebie" << endl;
			cout << "5 - Obstaw 2 liczby obok siebie" << endl;
			cout << "0 - Powrot / zmiana wysokosci zakladu" << endl;

	int n;
	int pojedyncza;
	int parzysta;
	int liczba1, liczba2, liczba3;
	int liczba4, liczba5;

	do{
		cin >> n;

		switch(n){
			case 1: do{
                        cout << "Wprowadz pojedyncza liczbe" << endl;
                        cin >> pojedyncza;
                    }while(pojedyncza<1 || pojedyncza>37);
					Pojedyncza(pojedyncza, Pula);
                    sprawdzKoniec();
					break;

			case 2: do{
                        cout << "Obstaw parzysta lub nieparzysta 0 - Parzysta, 1 - Nieparzysta" << endl;
                        cin >> parzysta;
                    }while(parzysta<0 || parzysta>1);
					PrzystaNieparzysta(parzysta, Pula);
                    sprawdzKoniec();
					break;
			case 3:
                    Tuziny(Pula);
                    sprawdzKoniec();
					break;
			case 4:
                    cout << "Wprowadz 3 liczby obok siebie" << endl;
					cin >> liczba1;
					cin >> liczba2;
					cin >> liczba3;
					break;
			case 5:
                    cout << "Wprowadz 2 liczby obok siebie" << endl;
					cin >> liczba4;
					cin >> liczba5;
					break;
			default: cout << "Podaj jeszcze raz" << endl;
					break;
		}
	}while(n!=0);

    return 0;
}



int Pojedyncza(int Pojedyncza, int Pula){

    int losowana;
    losowana = rand()%38;

	int WygranaPojedyncza;

	cout<<"Wylosowana liczba to: "<<losowana<<endl;

	WygranaPojedyncza = Pula*35;

	if (losowana==0){
        cout << "Przegrales czlowieku" << endl;
        KontoGracza -= Pula;
        KontoKasyna += Pula;
	}else{
	    if(Pojedyncza == losowana){
            cout << "Wygrales czlowieku" << endl;
            KontoGracza += WygranaPojedyncza;
            KontoKasyna -= WygranaPojedyncza;
        }else{
            cout << "Przegrales czlowieku" << endl;
            KontoGracza -= Pula;
            KontoKasyna += Pula;
        }
	}


	cout<<"\nTwoj aktualny stan konta:"<<KontoGracza<<endl;

	return 0;
}

int PrzystaNieparzysta(int PrzystaNieparzysta, int Pula){

    int losowana;
    losowana = rand()%37;

	int Wygrana;
    int liczba;
	cout<<"Wylosowana liczba to: "<<losowana<<endl;

	Wygrana = Pula*1;

	if (losowana==0){
        cout << "Przegrales czlowieku" << endl;
        KontoGracza -= Wygrana;
        KontoKasyna += Wygrana;
	}else{
	    if(losowana%2){
            liczba = 1;
            cout<<"Liczba jest nieparzysta - ";
            if(liczba == PrzystaNieparzysta){
                cout<<"wygrywasz"<<endl;
                KontoGracza += Wygrana;
                KontoKasyna -= Wygrana;
            }else{
                cout<<"przegrywasz"<<endl;
                KontoGracza -= Pula;
                KontoKasyna += Pula;
            }
        }else{
            liczba = 0;
            cout<<"Liczba jest parzysta - ";
            if(liczba == PrzystaNieparzysta){
                cout<<"wygrywasz"<<endl;
                KontoGracza += Wygrana;
                KontoKasyna -= Wygrana;
            }else{
                cout<<"przegrywasz"<<endl;
                KontoGracza -= Pula;
                KontoKasyna += Pula;
            }
        }


	}


	cout<<"\nTwoj aktualny stan konta:"<<KontoGracza<<endl;

	return 0;
}

int Tuziny(int Pula){

    int iletuzinow, TylkoJedenTuzin;
    //zakladamy ze mozna obstawic tylko 1 tuzin
    /*
    do{
        cout<<"Ile tuzinow chcesz obstawiac? 1 | 2 | 3? Wpisz liczbe"<<endl;
        cin>>iletuzinow;
    }while(iletuzinow<0 || iletuzinow>3);
*/
    iletuzinow =1 ;

    if(iletuzinow==1){
        cout<<"Wybierz tuzin do wyboru 1 | 2 | 3  wpisz cyfre \n 1 - (liczby 1-12) | 2 - (liczby - 13-24) | 3 - (liczby 25 - 36)"<<endl;
        cin>>TylkoJedenTuzin;
        cout<<"Wybrales "<<TylkoJedenTuzin<<" tuzin"<<endl;
    }

    int losowana;
    losowana = rand()%37;

	int Wygrana;
    int liczba;
	cout<<"Wylosowana liczba to: "<<losowana<<endl;

	Wygrana = Pula*2 ;

	if (losowana==0){
        cout << "Przegrales czlowieku" << endl;
        KontoGracza -= Wygrana;
        KontoKasyna += Wygrana;
	}else{
        if(iletuzinow==1)
        {
            if(losowana>0 && losowana<13)
            {
                if(TylkoJedenTuzin == 1)
                {
                    cout<<"Wygrales"<<endl;
                    KontoGracza += Wygrana;
                    KontoKasyna -= Wygrana;
                }else{
                    cout<<"Przegrywasz"<<endl;
                    KontoGracza -= Pula;
                    KontoKasyna += Pula;
                }

            }
            else if(losowana>12 && losowana<25)
            {
                if(TylkoJedenTuzin == 2)
                {
                    cout<<"Wygrales"<<endl;
                    KontoGracza += Wygrana;
                    KontoKasyna -= Wygrana;
                }else{
                    cout<<"Przegrywasz"<<endl;
                    KontoGracza -= Pula;
                    KontoKasyna += Pula;
                }

            }
            else if(losowana>24 && losowana<37)
            {
                if(TylkoJedenTuzin == 3)
                {
                    cout<<"Wygrales"<<endl;
                    KontoGracza += Wygrana;
                    KontoKasyna -= Wygrana;
                }else{
                    cout<<"Przegrywasz"<<endl;
                    KontoGracza -= Pula;
                    KontoKasyna += Pula;
                }

            }
        }

    }

	cout<<"\nTwoj aktualny stan konta:"<<KontoGracza<<endl;

    return 0;
}



void sprawdzKoniec(){

    if(KontoGracza<=0){
        cout<<"Twoj stan konta: "<<KontoGracza<<" PRZEGRALES| KONIEC GRY"<<endl;
    }
    if(KontoKasyna<=0){
        cout<<"Twoj stan konta: "<<KontoGracza<<" WYGRALES | Stan konta kasyna: "<<KontoKasyna<<endl;
    }

}




