#include <iostream>
#include <stdlib.h>
#include "Animal.h"

using namespace std;

Animal::Animal(string animalName, float animalWeight, bool animalDangerousness) {
  name = animalName;
  weight = animalWeight;
  dangerousness = animalDangerousness;
  
}
Animal::Animal(const Animal &another_animal) {
  name = another_animal.name;
  weight = another_animal.weight;
  dangerousness = another_animal.dangerousness;
}

Animal::Animal() {
  name = "";
  weight = 0;
  dangerousness = false;
}

ostream& operator<< (ostream& os, const Animal &animal) {
  os << animal.name << ", " << animal.weight << " lbs. " << (animal.dangerousness ? "Be Careful!" : "") << endl;
  return os;
}

Animal& Animal::operator= (const Animal &another_animal) {
  name = another_animal.name;
  weight = another_animal.weight;
  dangerousness = another_animal.dangerousness;
  return *this;
}

Animal::~Animal() {
}
