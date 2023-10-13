#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

int main(void) 
{
	// subject
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* took = new Character("Fool of a Took");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	took->equip(tmp);
	tmp = src->createMateria("cure");
	took->equip(tmp);

	ICharacter* gundalf = new Character("GunDalf");
	took->use(0, *gundalf);
	took->use(1, *gundalf);

	// deep copy MateriaSource
	MateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	MateriaSource* src_copy = new MateriaSource(*src2);
	delete src2;

	// full inventory and unequip
	tmp = src_copy->createMateria("ice");
	took->equip(tmp);

	AMateria *last_item = src_copy->createMateria("cure");
	took->equip(last_item);

	took->equip(tmp);

	took->unequip(3);

	delete last_item;

	// deep copy Character
	Character* took_copy = new Character(*took);
	delete took;

	took_copy->use(0, *gundalf);
	took_copy->use(1, *gundalf);
	// empty
	took_copy->use(3, *gundalf);

	// materia that does not exist
	tmp = src->createMateria("does_not_exist");
	tmp = src->createMateria("ice");

	took_copy->equip(tmp);
	took_copy->use(3, *gundalf);

	// delete objects
	delete gundalf;
	delete took_copy;
	delete src;
	delete src_copy;
	return (0);
}