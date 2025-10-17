#include <iostream>
#include <stdlib.h>
#include "Animal.h"
#include "PairsLL.h"

using namespace std;

PairsLL::PairsLL() {
    head = nullptr;
    tail = nullptr;
    curr = nullptr;
    size = 0;
}

PairsLL::PairsLL(const PairsLL &diffList) {
    head = tail = curr = nullptr;
    size = 0;
    Node* diffTemp = diffList.head;
    Node* lastInsert = nullptr;
    while (diffTemp != nullptr) {
        insertAfter(lastInsert, diffTemp->data);
        lastInsert = tail;
        diffTemp = diffTemp->next;
    }
    size = diffList.size;
}

PairsLL::~PairsLL() {
    disembark();
}

PairsLL& PairsLL::operator= (const PairsLL &diffList) {
    if (this == &diffList) return *this;
    disembark();
    Node* diffTemp = diffList.head;
    Node* lastInsert = nullptr;
    while (diffTemp != nullptr) {
        insertAfter(lastInsert, diffTemp->data);
        lastInsert = tail;
        diffTemp = diffTemp->next;
    }
    size = diffList.size;
    return *this;
}

bool PairsLL::disembark(){
    reset();
    if (head == nullptr) return true;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = tail = nullptr;
    reset();
    size = 0;
    return true;
}

bool PairsLL::board(const Animal &animal) {
    if (head == nullptr) {
        insertAfter(nullptr, animal);
        return true;
    }
    if (checkTotal(animal.get_name()) > 1) {
        return false;
    }
    int currentCount = checkTotal(animal.get_name());
    int AnimalCount = currentCount + 1;
    bool newAnimalIsSingleton = (AnimalCount == 1);
    bool newAnimalDangerousness = animal.get_dangerousness();
    Node* firstOfPair = nullptr;
    if (AnimalCount == 2) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.get_name() == animal.get_name()) {
                Node* savedCurr = curr;
                curr = temp;
                firstOfPair = pop();
                firstOfPair->next = nullptr;
                firstOfPair->prev = nullptr;
                curr = savedCurr;
                break;
            }
            temp = temp->next;
        }
    }
    reset();
    while (curr != nullptr) {
        bool currAnimalDangerousness = curr->data.get_dangerousness();
        bool currAnimalIsPair = (checkTotal(curr->data.get_name()) == 2);
        if (newAnimalDangerousness && !currAnimalDangerousness) {
            if (firstOfPair != nullptr) {
                insertNodeBefore(curr, firstOfPair);
            }
            insertBefore(curr, animal);
            return true;
        }
        if (newAnimalDangerousness == currAnimalDangerousness) {
            if (newAnimalIsSingleton && currAnimalIsPair) {
                if (firstOfPair != nullptr) {
                    insertNodeBefore(curr, firstOfPair);
                }
                insertBefore(curr, animal);
                return true;
            }
            if (newAnimalIsSingleton == !currAnimalIsPair) {
                if (animal.get_name() < curr->data.get_name()) {
                    if (firstOfPair != nullptr) {
                        insertNodeBefore(curr, firstOfPair);
                    }
                    insertBefore(curr, animal);
                    return true;
                }
            }
        }
        curr = curr->next;
    }
    if (firstOfPair != nullptr) {
        insertNodeAfter(tail, firstOfPair);
    }
    insertAfter(tail, animal);
    return true;
}

unsigned short int PairsLL::dismiss(std::string name) {
    unsigned short count = 0;
    reset();
    while (curr != nullptr) {
        if (curr->data.get_name() == name) {
            Node* toDelete = curr;
            if (curr->prev != nullptr && curr->next != nullptr) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            } else if (curr->prev != nullptr && curr->next == nullptr) {
                curr->prev->next = nullptr;
                tail = curr->prev;
            } else if (curr->prev == nullptr && curr->next != nullptr) {
                curr->next->prev = nullptr;
                head = curr->next;
            } else {
                head = tail = nullptr;
            }
            curr = curr->next;
            delete toDelete;
            count += 1;
            size -= 1;
        } else { curr = curr->next; }
    }
    return count;
}

PairsLL& PairsLL::join(PairsLL &diffList, bool copy) {
    if (this == &diffList && !copy) {
        return *this;
    }
    Node* diffTemp = diffList.head;
    while (diffTemp != nullptr) {
        Node* nextTemp = diffTemp->next;
        if (copy) {
            board(diffTemp->data);
            diffTemp = nextTemp;
        } else {
            board(diffTemp->data);
            Node* toDelete = diffTemp;
            diffTemp = diffTemp->next;
            if (toDelete->prev != nullptr && toDelete->next != nullptr) {
                toDelete->prev->next = toDelete->next;
                toDelete->next->prev = toDelete->prev;
            } else if (toDelete->prev != nullptr && toDelete->next == nullptr) {
                toDelete->prev->next = nullptr;
                diffList.tail = toDelete->prev;
            } else if (toDelete->prev == nullptr && toDelete->next != nullptr) {
                toDelete->next->prev = nullptr;
                diffList.head = toDelete->next;
            } else {
                diffList.head = diffList.tail = nullptr;
            }
            delete toDelete;
            diffList.size -= 1;
        }
    }
    return *this;
}

unsigned int PairsLL::show(bool singletons) {
    unsigned int singletonCount = 0;
    reset();
    while (!done()) {
        unsigned short type = 0;
        if (curr->prev != nullptr && curr->prev->data.get_name() == curr->data.get_name()) {
            type = 0;
        } else if (curr->next != nullptr && curr->next->data.get_name() == curr->data.get_name()) {
            type = 1;
        } else {
            type = 2;
            singletonCount++;
        }
        switch (type) {
            case 0:
                // Skip so we only print the first of a pair
                break;
            case 1:
                cout << curr->data;
                break;
            case 2:
                if (singletons) {
                    cout << curr->data;
                }
                break;
        }
        curr = curr->next;
    }
    return singletonCount;
}

bool PairsLL::reset() {
    curr = head;
    return (curr != nullptr);
}

bool PairsLL::done() {
    return (curr == nullptr);
}

Animal PairsLL::next(){
    if (done()) return Animal();
    Animal returnAnimal = curr->data;
    curr = curr->next;
    return returnAnimal;
}

bool PairsLL::isEmpty(){
    return (size > 0 ? false : true);
}

bool PairsLL::pairCheckAdjacent() {
    if (curr->next != nullptr && curr->data.get_name() == curr->next->data.get_name()) {
        return true;
    } else if (curr->prev != nullptr && curr->data.get_name() == curr->prev->data.get_name()) {
        return true;
    } else {
        return false;
    }
}

unsigned int PairsLL::checkTotal(string animalName) {
    Node* temp = head;
    unsigned short count = 0;
    while (temp != nullptr) {
        if (temp->data.get_name() == animalName) {
            count++;
        }
        temp = temp->next;
    }
    return (count);
}

void PairsLL::insertAfter(Node* oldNode, const Animal &animal) {
    Node* newNode = new Node(animal);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        curr = head;
    } else if (oldNode != nullptr) {
        newNode->next = oldNode->next;
        newNode->prev = oldNode;
        oldNode->next = newNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        } else {
            tail = newNode;
        }
    }
    size++;
}

void PairsLL::insertNodeAfter(Node* oldNode, Node* newNode) {
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        curr = head;
    } else if (oldNode != nullptr) {
        newNode->next = oldNode->next;
        newNode->prev = oldNode;
        oldNode->next = newNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        } else {
            tail = newNode;
        }
    }
    size++;
}

void PairsLL::insertBefore(Node* oldNode, const Animal &animal) {
    Node* newNode = new Node(animal);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        curr = head;
    } else if (oldNode != nullptr) {
        newNode->prev = oldNode->prev;
        newNode->next = oldNode;
        oldNode->prev = newNode;
        if (newNode->prev != nullptr) {
            newNode->prev->next = newNode;
        } else {
            head = newNode;
        }
    }
    size++;
}

void PairsLL::insertNodeBefore(Node* oldNode, Node* newNode) {
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        curr = head;
    } else if (oldNode != nullptr) {
        newNode->prev = oldNode->prev;
        newNode->next = oldNode;
        oldNode->prev = newNode;
        if (newNode->prev != nullptr) {
            newNode->prev->next = newNode;
        } else {
            head = newNode;
        }
    }
    size++;
}

PairsLL::Node* PairsLL::pop() {
    Node* temp = curr;
    if (curr != nullptr) {
        if (curr->prev != nullptr && curr->next != nullptr) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        } else if (curr->prev != nullptr && curr->next == nullptr) {
            curr->prev->next = nullptr;
            tail = curr->prev;
        } else if (curr->prev == nullptr && curr->next != nullptr) {
            curr->next->prev = nullptr;
            head = curr->next;
        } else {
            head = tail = nullptr;
        }
        curr = curr->next;
        size -= 1;
    }
    return temp;
}