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

	cout << "��� �������: " << species << "\t����: " << price << "\t����������: " << amount << endl;

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

	 cout << "��������� ����������� " << storeName << " �� ������: " << address << endl;
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

	cout << "������� �������� �����������: " << endl;
	getline(cin, name);
	store.setStoreName(name);


	cout << "������� ����� �����������: " << endl;
	getline(cin, addr);
	store.setAddress(addr);


	int petAmount;
	cout << "������� �������� �� ������ �������� � �������? ";
	cin >> petAmount;

	for (int i = 0; i < petAmount; i++)
	{
		Pet pet;
		string spec;
		double pr;
		int amnt;

		cout << "������� ��� ���������: ";
		cin.ignore();
		getline(cin, spec);
		pet.setSpecies(spec);

		cout << "������� ���� ���������: ";
		cin >> pr;
		pet.setPrice(pr);

		cout << "������� ���������� ��������: ";
		cin >> amnt;
		pet.setAmount(amnt);

		store.addPet(pet);

	}
	store.displayStore();
	
	double totalCost = store.calcucalateTotalCost();

	cout << "����� ��������� ��������: " << totalCost;
	return 0;
}


