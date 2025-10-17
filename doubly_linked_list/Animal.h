#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Animal {
   public:
      Animal(string animalName, float animalWeight, bool animalDangerousness);

      Animal(const Animal &another_animal);

      Animal();

      friend ostream& operator<< (ostream& os, const Animal &animal);

      Animal& operator= (const Animal &another_animal);

      ~Animal();

      string get_name() const {return name;}

      float get_weight() const {return weight;}

      bool get_dangerousness() const {return dangerousness;}

   private:
      float weight;
      string name;
      bool dangerousness;
};
#endif