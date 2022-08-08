#include <iostream>
#include <vector>

class Archer
{
public:
    void info() {
        std::cout << "Archer"<<std::endl;
    }
};

class Horseman
{
public:
    void info() {
        std::cout << "Horseman" << std::endl;
    }
};

class Army
{
public:
    std::vector<Archer> va;
    std::vector<Horseman> vh;
    void info() {
        int i;
        for (i = 0; i < va.size(); ++i)  va[i].info();
        for (i = 0; i < vh.size(); ++i)  vh[i].info();
    }
};

// Builder as interface with functions which need override

class ArmyBuilder
{
protected:
    Army* p;
public:
    ArmyBuilder() : p(0) {}
    virtual ~ArmyBuilder() {}
    virtual void createArmy() {}
    virtual void buildArcher() {}
    virtual void buildHorseman() {}
    virtual Army* getArmy() { return p; }
};


// concrete builder
class RomanArmyBuilder : public ArmyBuilder
{
public:
    void createArmy() { p = new Army; }
    void buildArcher() { p->va.push_back(Archer()); }
    void buildHorseman() { p->vh.push_back(Horseman()); }
};

//director wich create the army
class Director
{
public:
    Army* createArmy(ArmyBuilder& builder)
    {
        builder.createArmy();
        builder.buildArcher();
        builder.buildHorseman();
        return(builder.getArmy());
    }
};
