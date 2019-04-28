// Lab_2_C_P_P.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;

struct Сountry {
	char contryName[15], capital[15], countryLanguage[15];

	char valute[15], govermentType[15], mrPresident[15];

	int population, square;

};

int main()
{
	int numberOfCountries = 1;
	int size = 1;
	int numberOfCustomers;

	int elitePopulation, eliteSquare;// переменные с которыми мы будем сравнивать соответвующие переменные

	Сountry *c = new Сountry[1];//динамический массив структур

	while (numberOfCountries) {// цикл ввода информации
		if (size == 1) {
			cout << "Contry Name, capital of the country and country language: ";
			cin >> c[size - 1].contryName >> c[size - 1].capital >> c[size - 1].countryLanguage;

			cout << " Enter valute, govermentType and president's name: " << endl;
			cin >> c[size - 1].valute >> c[size - 1].govermentType >> c[size - 1].mrPresident;

			cout << "Enter population and square: " << endl;
			cin >> c[size - 1].population >> c[size - 1].square;

			cout << " Your country: " << c[size - 1].contryName << " " << c[size - 1].capital << " " << c[size - 1].countryLanguage << endl;
			cout << c[size - 1].valute << " " << c[size - 1].govermentType << c[size - 1].mrPresident << endl;
			cout << c[size - 1].population << " " << c[size - 1].square << endl;
		}
		else
		{
			Сountry* copy = new Сountry[size - 1];//создаем новую структуру для копирования в нее данных

			for (int i = 0; i < size - 1; i++)//копируем данные перед отчисткой памяти объекта р
			{
				strcpy_s(copy[i].contryName, c[i].contryName);
				strcpy_s(copy[i].capital, c[i].capital);
				strcpy_s(copy[i].countryLanguage, c[i].countryLanguage);
				strcpy_s(copy[i].valute, c[i].valute);
				strcpy_s(copy[i].govermentType, c[i].govermentType);
				strcpy_s(copy[i].mrPresident, c[i].mrPresident);

				copy[i].population = c[i].population;
				copy[i].square = c[i].square;

			}

			delete[] c; //освобождаем  память

			c = new Сountry[size]; //выделяем новую память

			for (int i = 0; i < size - 1; i++) // обратное копирование в новый массив
			{
				strcpy_s(c[i].contryName, copy[i].contryName);
				strcpy_s(c[i].capital, copy[i].capital);
				strcpy_s(c[i].countryLanguage, copy[i].countryLanguage);
				strcpy_s(c[i].valute, copy[i].valute);
				strcpy_s(c[i].govermentType, copy[i].govermentType);
				strcpy_s(c[i].mrPresident, copy[i].mrPresident);

				c[i].population = copy[i].population;
				c[i].square = copy[i].square;
			}

			delete[] copy; //освобождаем память

			cout << "Country name, capital and country Language: " << endl;//дописываем новые введенные данные
			cin >> c[size - 1].contryName;
			cin >> c[size - 1].capital;
			cin >> c[size - 1].countryLanguage;

			cout << "Valute and goverment Type : " << endl;
			cin >> c[size - 1].valute;
			cin >> c[size - 1].govermentType;

			cout << "President: " << endl;
			cin >> c[size - 1].mrPresident;

			cout << " Population and square: " << endl;
			cin >> c[size - 1].population;
			cin >> c[size - 1].square;

			for (int i = 0; i < size - 1; i++) { //сортируем по популяции  или площади страны
				for (int j = 0; j < size - i - 1; i++) {
					if (c[j].population > c[j + 1].population || c[j].square > c[j + 1].square) {
						swap(c[j].contryName, c[j + 1].contryName);
						swap(c[j].capital, c[j + 1].capital);
						swap(c[j].countryLanguage, c[j + 1].countryLanguage);

						swap(c[j].valute, c[j + 1].valute);
						swap(c[j].govermentType, c[j + 1].govermentType);
						swap(c[i].mrPresident, c[j + 1].mrPresident);

						swap(c[j].population, c[j + 1].population);
						swap(c[j].square, c[j + 1].square);
					}
				}
			}
			cout << endl;
			for (int i = 0; i < size; i++)//выводим все данные  на экран
			{
				cout << i << "Maybe sorted maybe not: " << c[i].contryName << " " << c[i].capital << " " << c[i].countryLanguage << ";" << endl;
				cout << c[i].valute << " " << c[i].govermentType << " " << c[i].mrPresident << endl;
				cout << c[i].population << " " << c[i].square << endl;
			}

			cout << "Enter population about square, and we do some fan: " << endl;//просим пользователя ввсести произвольное значение площади и если оно совпадает то выводим на экран страну
			cin >> elitePopulation >> eliteSquare;

			for (int i = 0; i < size; i++) {
				if (elitePopulation == c[i].population || eliteSquare == c[i].square)
				{
					cout << "We find equal country: " << endl;
					cout << i << "swaped countries:  " << c[i].contryName << " " << c[i].capital << " " << c[i].countryLanguage << ";" << endl;
					cout << c[i].valute << " " << c[i].govermentType << " " << c[i].mrPresident << endl;
					cout << c[i].population << " " << c[i].square << endl;
				}
				else {
					cout << "Fun doesn't happend with array. " << endl;
				}
			}
		}
		size++;
		cout << "\nEnte 1 - to continue or 0 to end this program: ";
		cin >> numberOfCustomers;
		while (numberOfCustomers != 0 && numberOfCustomers != 1)//если пользователь ввел не 0 и не 1
		{
			cout << "Stop right there!\n";
			cout << "\nENTER - 1, OR - 0: ";
			cin >> numberOfCustomers;
		}
	}
	delete[] c;//освобождение памяти перед завершением работы программы.0

	return 0;
}