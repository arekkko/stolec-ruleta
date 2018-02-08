#include <iostream>
#include <math.h>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <ctime>

//#include "sprawdz.cpp"

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

int Pojedyncza(int pojedyncza, int losowana, int Pula);




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

int losowana;

losowana = rand()%38;

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
	int tuzin;
	int liczba1, liczba2, liczba3;
	int liczba4, liczba5;

	do{
		cin >> n;

		switch(n){
			case 1: do{
                        cout << "Wprowadz pojedyncza liczbe" << endl;
                        cin >> pojedyncza;
                    }while(pojedyncza<1 || pojedyncza>37);
					Pojedyncza(pojedyncza, losowana, Pula);
                    sprawdzKoniec();
					break;
			case 2:
                    cout << "Wprowadz parzysta lub nieparzysta" << endl;
					cin >> parzysta;
					break;
			case 3:
                    cout << "Wprowadz jeden z tuzinow" << endl;
					cin >> tuzin;
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



int Pojedyncza(int Pojedyncza, int losowana, int Pula){

	int WygranaPojedyncza;

	cout<<"Wylosowana liczba to: "<<losowana<<endl;

	WygranaPojedyncza = Pula*35;

	if (losowana==0){
        cout << "Przegrałeś czlowieku" << endl;
	}else{
	    if(Pojedyncza == losowana){
            cout << "Wygrales czlowieku" << endl;
            KontoGracza += WygranaPojedyncza;
            KontoKasyna -= WygranaPojedyncza;
        }else{
            cout << "Przegrales czlowieku" << endl;
            KontoGracza -= WygranaPojedyncza;
            KontoKasyna += WygranaPojedyncza;
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




