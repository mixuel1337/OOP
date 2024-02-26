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
	
	void setSpecies(string species) {
		this->species = species;
	}

	void setPrice(double price) {
		this->price = price;
	}

	void setAmount(int amount) {
		this->amount = amount;
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
	 
	 void setStoreName(string storeName) {
		this->storeName = storeName;
	 }

	 void setAddress(string address) {
		 this->address = address;
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
	string storeName, address;

	cout << "Введите название зоомагазина: " << endl;
	getline(cin, storeName);
	store.setStoreName(storeName);


	cout << "Введите адрес зоомагазина: " << endl;
	getline(cin, address);
	store.setAddress(address);


	int petAmount;
	cout << "Сколько животных вы хотите добавить в магазин? ";
	cin >> petAmount;

	for (int i = 0; i < petAmount; i++)
	{
		Pet pet;
		string species;
		double price;
		int amount;

		cout << "Введите вид животного: ";
		cin.ignore();
		getline(cin, species);
		pet.setSpecies(species);

		cout << "Введите цену животного: ";
		cin >> price;
		pet.setPrice(price);

		cout << "Введите количество животных: ";
		cin >> amount;
		pet.setAmount(amount);

		store.addPet(pet);

	}
	store.displayStore();
	
	double totalCost = store.calcucalateTotalCost();

	cout << "Общая стоимость питомцев: " << totalCost;
	return 0;
}


