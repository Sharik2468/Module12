#include <iostream>

class Warrior // prototype class
{
public:
	int Id=0;
		
	Warrior(int id)
	{
		Id = id;
	}
	virtual Warrior Clone() { return NULL; } // virtual function which allow to clone instances
};

class ArcherA : public Warrior
{
public:
	ArcherA(int id)
		: Warrior(id)
	{
		Id = id;
	}
	Warrior Clone() //override func
	{
		std::cout << "Archer clone" << std::endl;
		return *new ArcherA(Id);
	}
};

class SwordMan : public Warrior
{
public:
	SwordMan(int id)
		: Warrior(id)
	{
		Id = id;
	}
	Warrior Clone()
	{
		std::cout << "Swordman clone" << std::endl;
		return *new SwordMan(Id);
	}
};