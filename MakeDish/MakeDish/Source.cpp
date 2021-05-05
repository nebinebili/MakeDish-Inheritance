#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class Ingredient {
protected:
	string name;
	double fats;
	double protein;
	double carbohydrates;
	int kcal;
public:
	Ingredient() :name(), fats(NULL), protein(NULL), carbohydrates(NULL), kcal(NULL) {};
	
	Ingredient(const string name,const double fats,const double protein,const double carbohydrates,const int kcal)
	{
	   SetName(name);
	   SetFats(fats);
	   SetProtein(protein);
	   SetCarbohydrates(carbohydrates);
	   SetKcal(kcal);
	}
	string GetName()const {
		return name;
	}
	double GetFats()const {
		return fats;
	}
	double GetProtein()const {
		return protein;
	}
	double GetCarbohydrates()const{
		return carbohydrates;
	}
	int GetKcal()const{
		return kcal;
	}

	void SetName(const string name) {
		if (name != "")
		this->name = name;
	}
	void SetFats(const double fats) {
		if (fats > 0)
		this->fats = fats;
	}
	void SetProtein(const double protein) {
		if (protein > 0)
			this->protein = protein;
	}
	void SetCarbohydrates(const double carbohydrates) {
		if (carbohydrates > 0)
			this->carbohydrates = carbohydrates;
	}
	void SetKcal(const int kcal) {
		if (kcal > 0)
			this->kcal = kcal;
	}

    virtual void PrintIngredient() {
		cout << "Name->" << name << endl;
		cout << "Fats->" << fats << endl;
		cout << "Protein->" << protein << endl;
		cout << "Carbohydracts->" << carbohydrates << endl;
		cout << "Kcal->" << kcal << endl;
	}
    virtual ~Ingredient()=0
	{

	}

};

class Mushrooms :public Ingredient {
	string country;
public:
	Mushrooms() = default;
	Mushrooms(const string country,const string name,const double fat,const double protein,const double carbohydrates, 
	const int kcal) :Ingredient(name,fat,protein,carbohydrates,kcal)
	{
		SetCountry(country);
	}
	string GetCountry()const {
		return country;
	}
	void SetCountry(const string country) {
		if(country!=" ")
		this->country = country;
	}
	void PrintIngredient()override {
		Ingredient::PrintIngredient();
		cout << "Country->" << country << endl;
	}
};

class Meat :public Ingredient {
	string rateOfFrying;
public:
	Meat() :rateOfFrying() {};
	Meat(const string name, const double fat, const double protein, const double carbohydrates, const int kcal,
	 const string rateOfFrying) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{
	  SetRateOfFrying(rateOfFrying);
	}
	string GetRateOfFrying()const{
		return rateOfFrying;
	}
	void SetRateOfFrying(const string rateOfFrying) {
		if (rateOfFrying != "")
		this->rateOfFrying = rateOfFrying;
	}
	void PrintIngredient()override {
		Ingredient::PrintIngredient();
		cout << "Rate Of Frying->" << rateOfFrying << endl;
	}
};

class Spices :public Ingredient {
	string type;
public:
	Spices() = default;
	Spices(const string name,const string type, const double fat, const double protein, const double carbohydrates,
		const int kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{
		SetType(type);
	}
	string GetType()const {
		return type;
	}
	void SetType(const string type) {
		if(type!=" ")
		this->type = type;
	}
	void PrintIngredient()override {
		Ingredient::PrintIngredient();
		cout << "Type->" << type << endl;
	}
};

class Cheese :public Ingredient {
	string size;
public:
	Cheese() :size() {};
	Cheese(const string name, const double fat, const double protein, const double carbohydrates, const int kcal,
	 const string size):Ingredient(name,fat,protein,carbohydrates,kcal)
	{
		SetSize(size);
	}
	string GetSize()const {
		return size;
	}
	void SetSize(const string size) {
		if (size != "")
			this->size = size;
	}
	void PrintIngredient()override{
		Ingredient::PrintIngredient();
		cout << "Size->" << size << endl;
	}
};

class Tomatoes :public Ingredient {
	string shape;
public:
	Tomatoes() = default;
	Tomatoes(const string name,const string shape,const double fat, const double protein, const double carbohydrates,
		const int kcal) :Ingredient(name, fat, protein, carbohydrates, kcal)
	{
		SetShape(shape);
	}
	string GetShape()const {
		return shape;
	}
	void SetShape(const string shape) {
		if(shape!=" ")
		this->shape = shape;
	}
	void PrintIngredient()override {
		Ingredient::PrintIngredient();
		cout << "Shape->" << shape << endl;
	}
};


struct RecipetItem {
	Ingredient* ingredient; //one object
	int amount;
	RecipetItem( Ingredient*ingredient, int amount)
	{
		SetAmount(amount);
		SetIngredient(ingredient);
	}
	int GetAmount() {
		return amount;
	}
	Ingredient* GetIngredient()const {
		return ingredient;
	}
	void SetAmount(const int amount) {
		if(amount>0)
		this->amount = amount;
	}
	void SetIngredient(Ingredient*ingredient) {
		this->ingredient = ingredient;
	}
};

//Yemek
class Dish { // Meal
protected:
	RecipetItem** ingredients;
	int count;
	string name;
public:
	Dish() :ingredients(), count(), name() {};
	Dish(const string name)
	{
		SetName(name);
	}
	string GetName()const {
		return name;
	}
	void SetName(const string name) {
		if(name!="")
		this->name = name;
	}
	
	

	void addIngredient(Ingredient* ingredient, int amount) {
		RecipetItem** newingredients = new RecipetItem * [count +1];
		for (int i = 0; i < count; i++)
		{
			newingredients[i] = ingredients[i];
			newingredients[i] = ingredients[i];
		}
		auto newitem = new RecipetItem(ingredient, amount);
		newingredients[count] = newitem;
		

		delete[] ingredients;
		ingredients=newingredients;
		newingredients = nullptr;
		count++;
	}

	virtual void taste() {
		cout << "I do not know what is this ? " << endl;
	}

	virtual void printRecipe()const {
		cout << "------- Ingredients Info ---------" << endl;
		for (int i = 0; i < count; i++)
		{
			ingredients[i]->ingredient->PrintIngredient();
			cout << "Amount->" << ingredients[i]->amount << endl << endl;
		}
	}
	virtual ~Dish() = 0//for abstraction
	{

	}
};


class Pizza :public Dish {
	string size;
public:
	Pizza() = default;
	Pizza(const string name,const string size)
	 :Dish(name)
	{
		SetSize(size);
	}
	string GetSize()const {
		return size;
	}
	void SetSize(const string size) {
		if(size!="")
		this->size = size;
	}
	void Print() {
		cout << "--------- Pizza Info ------------" << endl;
		cout << "Name->" << name << endl;
		cout << "Size->" << size << endl;
		Dish::printRecipe();
	}
	void taste()override{
		cout << "------ Pizza Taste --------" << endl;
		cout << "The pizza is soft and tastes just I want it.Pizza so Perfect." << endl;
	}
};


class Kabab :public Dish {
	bool withChoppedOnion;//dogranmis sogan ile
public:
	Kabab() = default;
	Kabab(bool const withChoppedOnion,const string name)
	 :Dish(name)
	{
		SetwithChoppedOnion(withChoppedOnion);
	}
	bool GetwithChoppedOnion()const {
		return withChoppedOnion;
	}
	void SetwithChoppedOnion(const bool withChoppedOnion) {
		this->withChoppedOnion = withChoppedOnion;
	}
	void Print() {
		cout << "--------- Kabab Info ------------" << endl;
		if (withChoppedOnion == true) {
			cout << "With Chopped Onion->Yes" << endl;
		}
		else if (withChoppedOnion == false) {
			cout << "With Chopped Onion->NO" << endl;
		}
		Dish::printRecipe();
	}
	void taste()override {
		cout << "------ Kabab Taste------" << endl;
		cout << "The meat of the kabab is very nicely cooked.I like this.Thank you" << endl;
	}
};

class Dolma :public Dish {
	bool withSourclottedMilk;//qatiq ile 
public:
	Dolma() = default;
	Dolma(const bool withSourclottedMilk,const string name)
	 :Dish(name)
	{
		SetWithSourclottedMilk(withSourclottedMilk);
	}
	bool GetWithSourclottedMilk()const {
		return withSourclottedMilk;
	}
	void SetWithSourclottedMilk(const bool withSourclottedMilk) {
		this->withSourclottedMilk = withSourclottedMilk;
	}
	void Print() {
		cout << "--------- Dolma Info ------------" << endl;
		if (withSourclottedMilk == true) {
			cout << "With Sourclotted Milk->Yes" << endl;
		}
		else if (withSourclottedMilk == false) {
			cout << "With Sourclotted Milk->NO" << endl;
		}
		Dish::printRecipe();
	}
	void taste()override {
		cout << "--------- Dolma Taste -----------" << endl;
		cout << "The meat of the dolma is very nicely cooked.But much pepper was added." << endl;
	}
};


class CookingDevice {
protected:
	Dish* dish;
	bool isCooked;
	int second;
	CookingDevice() :dish(), isCooked(), second() {};
	CookingDevice( Dish*dish,const bool isCooked,const int second)
	{
		SetDish(dish);
		SetIsCooked(isCooked);
		SetSecond(second);
	}
	Dish* GetDish()const{
		return dish;
	}
	bool GetIsCooked()const {
		return isCooked;
	}
	int GetSecond()const {
		return second;
	}
	void SetDish( Dish* dish) {
		this->dish = dish;
	}
	void SetIsCooked(const bool isCooked) {
		this->isCooked = isCooked;
	}
	void SetSecond(const int second) {
		this->second = second;
	}
	
	virtual void cook() {
		cout << "Meal is cooking..";
		auto temp = second * 1000;
		Sleep(temp);
		cout << "Meal is cooked" << endl;
	}
};

class Oven :public CookingDevice {
public:

	Oven(Dish* dish, const bool isCooked, const int second)
	 :CookingDevice(dish,isCooked,second)
	{

	}
	void cook() {
		cout << "Please wait.Pizza is cooking.." << endl;
		auto temp = second * 1000;
		Sleep(temp);
		SetIsCooked(true);
		if (GetIsCooked() == true) {

		 cout << "Pizza is cooked" << endl;
		}
	}
};

class Pot :public CookingDevice {
public:
	Pot(Dish* dish, const bool isCooked, const int second)
	:CookingDevice(dish, isCooked, second)
	{
		
	}
	void cook() {
		cout << "Please wait.Dolma is cooking.." << endl;
		auto temp = second * 1000;
		Sleep(temp);
		SetIsCooked(true);
		if (GetIsCooked() == true) {

			cout << "Dolma is cooked" << endl;
		}
	}
};

class Brazier :public CookingDevice {
public:
	Brazier(Dish* dish, const bool isCooked, const int second)
	:CookingDevice(dish, isCooked, second)
	{

	}
	void cook() {
		cout << "Please wait.Kabab is cooking.." << endl;
		auto temp = second * 1000;
		Sleep(temp);
		SetIsCooked(true);
		if (GetIsCooked() == true) {

			cout << "Kabab is cooked" << endl;
		}
	}
};
void Display() {
	cout << "<<<<<<<<<<<<<<<< MENU >>>>>>>>>>>>>>>>>>" << endl;
	cout << "Pizza[1]" << endl;
	cout << "Kabab[2]" << endl;
	cout << "Dolma[3]" << endl;
	int chooseM;
	cout << "Enter your choose->";
	cin >> chooseM;
	
	
	int chooseeI;
	int amount;

	Mushrooms* mushroom = new Mushrooms("Azerbaijan","mushroom white", 23, 456, 12433, 5465);
	Meat* meat = new Meat("Beef", 14, 234, 23.4, 123, "normal");
	Spices* spices = new Spices("Pepper", "in powder form", 12, 435, 323.5, 234);
	Cheese* cheese = new Cheese("Holland Cheese", 100, 34, 354, 12, "Little");
	Tomatoes* tomatoes = new Tomatoes("Vosxod Tomatoes", "sliced", 123, 456.4, 56, 239);

	if (chooseM == 1) {
		char* name = new char [10]{};
		char* size=new char[10]{};
		cout << "Enter Pizza name->";
		cin >> name;
		cout << "Enter Pizza Size->";
		cin >> size;
		cout << "~~~~~~~~~~~~ INGREDIENTS ~~~~~~~~~~" << endl;
		cout << "Mushroom[1]" << endl;
		cout << "Meat[2]" << endl;
		cout << "Spices[3]" << endl;
		cout << "Cheese[4]" << endl;
		cout << "Tomatoes[5]" << endl;
		cout << "    \nIf select all want ingredients enter 6" << endl;
	    Pizza pizza(name, size);
		while (true)
		{
			cout << "Enter your choose->";
			cin >> chooseeI;
			if (chooseeI != 6) {
				cout << "Enter how many grams or numbers->";
				cin >> amount;
			}
			if (chooseeI == 1) {
				pizza.addIngredient(mushroom, amount);
			}
			else if (chooseeI == 2) {
				pizza.addIngredient(meat, amount);
			}
			else if (chooseeI == 3) {
				pizza.addIngredient(spices, amount);
			}
			else if (chooseeI == 4) {
				pizza.addIngredient(cheese, amount);
			}
			else if (chooseeI == 5) {
				pizza.addIngredient(tomatoes, amount);
			}
			else if (chooseeI == 6) {
				break;
			}
		}
		system("cls");
		pizza.Print();
		Oven oven(&pizza, false, 2);
		oven.cook();
		pizza.taste();
	}
	if (chooseM == 2) {
		char* name = new char[10]{};
		bool temp;
		cout << "Enter Kabab name->";
		cin >> name;
		cout << "With Chopped Onion(1(yes) or 0(no)->";
		cin >> temp;
		cout << "~~~~~~~~~~~~ INGREDIENTS ~~~~~~~~~~" << endl;
		cout << "Mushroom[1]" << endl;
		cout << "Meat[2]" << endl;
		cout << "Spices[3]" << endl;
		cout << "Cheese[4]" << endl;
		cout << "Tomatoes[5]" << endl;
		cout << "    \nIf select all want ingredients enter 6" << endl;
		Kabab kabab(temp,name);
		while (true)
		{
			cout << "Enter your choose->";
			cin >> chooseeI;
			if (chooseeI != 6) {
				cout << "Enter how many grams or numbers->";
				cin >> amount;
			}
			if (chooseeI == 1) {
				kabab.addIngredient(mushroom, amount);
			}
			else if (chooseeI == 2) {
				kabab.addIngredient(meat, amount);
			}
			else if (chooseeI == 3) {
				kabab.addIngredient(spices, amount);
			}
			else if (chooseeI == 4) {
				kabab.addIngredient(cheese, amount);
			}
			else if (chooseeI == 5) {
				kabab.addIngredient(tomatoes, amount);
			}
			else if (chooseeI == 6) {
				break;
			}
		}
		system("cls");
		kabab.Print();
		Brazier brazier(&kabab, false, 3);
		brazier.cook();
		kabab.taste();
	}
	if (chooseM == 3) {
		char* name = new char[10]{};
		bool temp;
		cout << "Enter Dolma name->";
		cin >> name;
		cout << "With Sourclotted Milk(1(yes) or 0(no)->";
		cin >> temp;
		cout << "~~~~~~~~~~~~ INGREDIENTS ~~~~~~~~~~" << endl;
		cout << "Mushroom[1]" << endl;
		cout << "Meat[2]" << endl;
		cout << "Spices[3]" << endl;
		cout << "Cheese[4]" << endl;
		cout << "Tomatoes[5]" << endl;
		cout << "    \nIf select all want ingredients enter 6" << endl;
		Dolma dolma(temp, name);
		while (true)
		{
			cout << "Enter your choose->";
			cin >> chooseeI;
			if (chooseeI != 6) {
				cout << "Enter how many grams or numbers->";
				cin >> amount;
			}
			if (chooseeI == 1) {
				dolma.addIngredient(mushroom, amount);
			}
			else if (chooseeI == 2) {
				dolma.addIngredient(meat, amount);
			}
			else if (chooseeI == 3) {
				dolma.addIngredient(spices, amount);
			}
			else if (chooseeI == 4) {
				dolma.addIngredient(cheese, amount);
			}
			else if (chooseeI == 5) {
				dolma.addIngredient(tomatoes, amount);
			}
			else if (chooseeI == 6) {
				break;
			}
		}
		system("cls");
		dolma.Print();
		Pot pot(&dolma, false, 3);
		pot.cook();
		dolma.taste();
	}
	
}

int main() {
	Display();
	
	return EXIT_SUCCESS;
}

