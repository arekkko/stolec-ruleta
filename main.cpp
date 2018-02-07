#include <iostream>
#include <math.h>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <ctime>

#include "sprawdz.cpp"

using namespace std;


void OProgramie();
void Menu();
int StanKasyno(int* );
int StanGracz(int* );
int Czysc();
void Zasady();
int Losowanie();

int main(){
	int n;
	int PlCash = 100;
	int CasCash = 1000;



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
							StanGracz(&PlCash);
							break;
					case 4: Czysc();
							StanKasyno(&CasCash);
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
	cout << "2. Dowolny jeden numer, za wyj¹tkiem 0, wygrana = k*35" << endl;
	cout << "3. Dwa kolejne numery, wygrana = k * 17" << endl;
	cout << "4. Trzy kolejne numery, wygrana = k * 11" << endl;
	cout << "WYNIK RZUTU 0 ZAWSZE OZNACZA WYGRANA KASYNA!!!" << endl;
	cout << "5. Tuziny: 1-12(pierwszy), 13-24(drugi), 25-36(trzeci), wygrana = k * 2" << "\n\n---------------------------\n" << endl;
}

int Czysc(){
	system("cls");
}

int StanKasyno(int *a){
	cout << "Stan konta kasyna: " << *a << "\n-----------------\n";
}

int StanGracz(int *a){
	cout << "Stan konta gracza: " << *a << "\n--------------------\n";
}

void OProgramie(){

	cout << "Autorzy: Mikolaj Porebski, Arkadiusz Kopczynski" << endl;
	cout << "Klasa: 3b1t" << endl;
	cout << "Data publikacji kodu: 07.02.2018r. godz. 12:17" << endl;


}

void Menu(){
	cout << "Wybierz liczbe!" << endl;
	cout << "1. Wybierz liczbe" << endl;
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

	int Zaklad;
	cout << "Obstaw liczbe!!!" << endl;
	cin >> Zaklad;
	int Pula;
	cout << "Podaj ile pieniedzy obstawiasz!!!" << endl;
	cin >> Pula;
	int Wygrana;
	cout << "Wylosowales: " << losowana << endl;

	if(losowana == Zaklad){
		cout << "Brawo, to ta sama liczba!!!" << endl;
		Wygrana = Pula * 35;
		cout << "Tyle wygrales: " << Wygrana << endl;
	}else{
		cout << "Nastepnym razem Ci sie uda!!!" << endl;
	}
	
	sprawdz(); 
    return 0;
}

