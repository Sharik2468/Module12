#include <iostream>
#include "Builder.cpp"
#include "Prototype.cpp"
#include "Singleton.cpp"

class Sedan {}; //also interfaces
class Coupe {};

class LadaCoupe : public Coupe { //concrete product
public:
	LadaCoupe() : Coupe()
	{
		std::cout << "Create LadaCoupe";
	}
};

class LadaSedan : public Sedan {
public:
	LadaSedan() : Sedan() {
		std::cout << "Create LadaSedan";
	}
};

class NissanCoupe : public Coupe {
public:
	NissanCoupe() :Coupe() {
		std::cout << "Create NissanCoupe";
	}
};

class NissanSedan : public Sedan {
public:
	NissanSedan() :Sedan() {
		std::cout << "Create NissanSedan";
	}
};

class ICarsFactory //Abstract fabric
{
public:
	Sedan virtual CreateSedan() = 0; //only virtual functions
	Coupe virtual CreateCoupe() = 0;
};

class LadaFactory : public ICarsFactory //concrete fabric
{
public:
	Sedan virtual CreateSedan() override //all function must be overrided
	{
		return *new LadaSedan();
	}
	Coupe virtual CreateCoupe() override
	{
		return *new LadaCoupe();
	}
};

class NissanFactory : public ICarsFactory
{
public:
	Sedan virtual CreateSedan() override //all function must be overrided
	{
		return *new NissanSedan();
	}
	Coupe virtual CreateCoupe() override
	{
		return *new NissanCoupe();
	}
};

int main()
{
	//AbstractFabric

	ICarsFactory* factory; // now we can create abstract fabric
	factory = new NissanFactory(); //assign with concrete fabric
	factory->CreateSedan(); // and call function

	//Builder

	Director dir;
	RomanArmyBuilder ra_builder;

	Army* ra = dir.createArmy(ra_builder);
	std::cout << "Roman army:" << std::endl;
	ra->info();

	//Prototype

	Warrior* prototype = new ArcherA(1);
	Warrior clone = prototype->Clone();
	prototype = new SwordMan(2);
	clone = prototype->Clone();

	//Singleton

	GameInstance& MyGameInstance = GameInstance::getInstance();
}
