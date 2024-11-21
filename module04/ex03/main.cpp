#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Global.hpp"

AMateria *g_onfloor[10];

int items_on_floor()
{	
	int res = 0;
	for(int i = 0; i < 10; i++)
	{
		if (g_onfloor[i] != nullptr)
			res++;
	}
	return res;
}

void init_onfloor()
{
	for(int i = 0; i < 10; i++)
		g_onfloor[i] = nullptr;
}

int main()
{
	init_onfloor();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->unequip(0);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	ICharacter* pat = new Character("pat");

	bob = pat;
	
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(1);

	delete bob;
	delete me;
	delete src;

	std::cout << "-----------FLOOR TEST-----------" << std::endl;
	std::cout << "items on floor: " << items_on_floor() << std::endl;

	ICharacter* floorguy = new Character("floorguy");
	IMateriaSource *s = new MateriaSource();
	s->learnMateria(new Ice());
	s->learnMateria(new Cure());

	tmp = s->createMateria("ice");
	floorguy->equip(tmp);
	tmp = s->createMateria("ice");
	floorguy->equip(tmp);
	tmp = s->createMateria("ice");
	floorguy->equip(tmp);
	tmp = s->createMateria("ice");
	floorguy->equip(tmp);
	floorguy->unequip(0);
	floorguy->unequip(1);
	floorguy->unequip(2);
	floorguy->unequip(3);
	std::cout << "items on floor: " << items_on_floor() << std::endl;
	tmp = s->createMateria("ice");
	floorguy->equip(tmp);
	tmp = s->createMateria("ice");
	floorguy->equip(tmp);
	tmp = s->createMateria("ice");
	floorguy->equip(tmp);
	tmp = s->createMateria("ice");
	floorguy->equip(tmp);
	floorguy->unequip(0);
	floorguy->unequip(1);
	floorguy->unequip(2);
	floorguy->unequip(3);
	std::cout << "items on floor: " << items_on_floor() << std::endl;
	tmp = s->createMateria("ice");
	floorguy->equip(tmp);
	floorguy->unequip(0);
	std::cout << "items on floor: " << items_on_floor() << std::endl;

	delete s;
	delete floorguy;

	return 0;
}
