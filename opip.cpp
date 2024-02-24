#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

class Pet {

	string species;
	double price;
	int amount;

public: 
	
	void setSpecies(string spec) {
		species = spec;
	}

	void setPrice(double pr) {
		price = pr;
	}

	void setAmount(int amnt) {
		amount = amnt;
	}

	
	double totalCost();
	void displayPets();
	

};

double Pet::totalCost() {

	return amount * price;

}


void Pet::displayPets() {

	cout << "Вид питомца: " << species << "\tЦена: " << price << "\tКоличество: " << amount << endl;

}

 class PetStore {

	string storeName;
	string address;
	vector <Pet> pets; 
		
 public:
	 
	 void setStoreName(string name) {
		 storeName = name;
	 }

	 void setAddress(string addr) {
		 address = addr;
	 }
	

	 void displayStore();
	 double calcucalateTotalCost();
	 void addPet(Pet pet);


};

 void PetStore::addPet(Pet pet) {

	 pets.push_back(pet);

 }

 void PetStore::displayStore() {

	 cout << "Зоомагазин " << storeName << " по адресу: " << address << endl;
	 cout << "------------------------------------------" << endl;
	 for (auto& pet : pets) {
		 pet.displayPets();
	 }

 }

 double PetStore::calcucalateTotalCost() {

	 double totalCost = 0.0;
	 for ( auto& pet : pets)
	 {
		 totalCost += pet.totalCost();
	 }
	 return totalCost;

 } 


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	PetStore store;
	string name, addr;

	cout << "Введите название зоомагазина: " << endl;
	getline(cin, name);
	store.setStoreName(name);


	cout << "Введите адрес зоомагазина: " << endl;
	getline(cin, addr);
	store.setAddress(addr);


	int petAmount;
	cout << "Сколько животных вы хотите добавить в магазин? ";
	cin >> petAmount;

	for (int i = 0; i < petAmount; i++)
	{
		Pet pet;
		string spec;
		double pr;
		int amnt;

		cout << "Введите вид животного: ";
		cin.ignore();
		getline(cin, spec);
		pet.setSpecies(spec);

		cout << "Введите цену животного: ";
		cin >> pr;
		pet.setPrice(pr);

		cout << "Введите количество животных: ";
		cin >> amnt;
		pet.setAmount(amnt);

		store.addPet(pet);

	}
	store.displayStore();
	
	double totalCost = store.calcucalateTotalCost();

	cout << "Общая стоимость питомцев: " << totalCost;
	return 0;
}


