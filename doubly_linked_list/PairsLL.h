#ifndef PAIRSLL_H
#define PAIRSLL_H
#include <iostream>
#include <stdlib.h>
#include "Animal.h"

using namespace std;

class PairsLL {

    private:

        struct Node {
            Animal data;
            Node* next;
            Node* prev;
            Node(const Animal &animal) : data(animal), next(nullptr), prev(nullptr) {};
        };
        Node* head;
        Node* tail;
        Node* curr;
        unsigned int size;

    public:

        PairsLL();

        PairsLL(const PairsLL &diffList);

        ~PairsLL();

        PairsLL& operator= (const PairsLL &diffList);

        bool disembark();

        bool board(const Animal &animal);

        unsigned short int dismiss(std::string name);

        PairsLL& join(PairsLL &diffList, bool copy = true);

        unsigned int show(bool singletons = true);

        bool reset();

        bool done();

        Animal next();

        bool isEmpty();

        bool pairCheckAdjacent();

        unsigned int checkTotal(string animalName);

        void insertAfter(Node* oldNode, const Animal &animal);

        void insertNodeAfter(Node* oldNode, Node* newNode);

        void insertBefore(Node* oldNode, const Animal &animal);

        void insertNodeBefore(Node* oldNode, Node* newNode);

        Node* pop();
};
#endif