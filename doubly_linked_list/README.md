# Doubly linked list
## according to the following criterion:

build a Doubly Linked List (DLL) implementation,
where the list supports operations to organize the list in a particular way,
ensuring that no more than 2 animals of a certain type are contained in the list at
any given time. You will need to implement the Rule of Three functions for the
class, so that we can pass lists by value, copy assign one list onto another, and not
leak memory.
Write a doubly-linked list C++ class, called PairsLL, with head and tail pointers (or
first and last if you prefer), that stores Animals, and which supports the following
public interface:
bool isEmpty()
Returns true if the PairsLL is empty (i.e. contains no animals), false if it is not
empty.
bool disembark()
Empties out the PairsLL by deleting all of its elements. Basically does what the
destructor should do, but allows it to be called from the public interface.
bool board(const Animal &)
Adds a copy of the animal passed as a parameter to the list, if and only if there
are fewer than two of that animal type in the list already. Returns true if the
animal is added successfully, false if there were already two such animals in the
list.
unsigned short int dismiss(std::string name)
Removes all animals whose name matches name, from the PairsLL. Returns a
count of how many such animals were removed. The return value should be 0, 1,
or 2 in all cases.
PairsLL &join(PairsLL &other, bool copy=true)
If copy is true, this operation adds copies of the values of the PairsLL passed (by
reference) as a parameter, to the list, leaving other intact. However, the operation
must maintain the invariant that at most two animals of some given name are
stored in the list at any given time. If copy is false, this operation subsumes the
other list, leaving it empty. If a third animal of a certain name is in the "other" list,
and adding that animal would result in 3 such animals in the list, then that animal
should not join the list, it should instead be deleted (if copy==false) or should just
remain in the "other" list and not copied in.
If the user tries to prepend a list to itself with copy set to false, the list should
remain unchanged. If the user prepends a list to itself with copy set to true, the
result should be that there are no singleton animals in the list.
unsigned int show(bool singletons=true)
Shows all animals in the ark, in the order they are stored, by calling the <<
operator on Animal, to match the output specified for an Animal, in CP1. If two
animals with the same name are stored, they should be shown twice. If singletons
is set to true, then all animals are shown, if singletons is set to false, then only
animals in pairs are shown. Returns the number of singleton animals in the list.
Organization
Across all the operations above, dangerous animals should all be stored together
at the front of the list, and not dangerous animals should be stored at the back of
the list. Thus at most one dangerous animal is stored right next to a not
dangerous animal. Within the dangerous animals, the singletons should be stored
together first, followed by the pairs. Same with the not dangerous animals...
singletons first, followed by pairs. Each of these four parts of the list (dangerous
singletons, dangerous pairs, safe singletons, safe pairs), should be stored in
alphabetical order. You may assume that all animals of the same name are either
dangerous or not (in other words, you will not encounter both a dangerous tiger
and a not dangerous one).
Rule of Three
Implement the Rule of Three functions to perform deep copies on assignment
and copy construction, and to delete the nodes of the list when the list object's
lifetime ends.
Your PairsLL should support the concept (but only the concept) of an "iterator",
via the following operations.
bool reset()
Sets a "pointer" within the object to the first node of the linked list. This
operation returns true if the list is non-empty, and false otherwise.
bool done()
Returns true if there are "no more" items to go through in the list, false if there
are more items.
Animal next()
Returns a copy of the "next" animal from the linked list. So a call to reset()
followed by a call to next() returns a copy of the first element of a (non-empty)
PairsLL. Subsequent calls to next() return the subsequent items in the list. When
it becomes true that the last item was returned on the previous call to next(), and
no subsequent reset() is performed, then next() should return an item created
with the Animal default constructor.
Thus, the following loop allows a PairsLL user to print the items in the PairsLL,
assuming << is overloaded on Animal:
PairsLL ark;
// populate with some values
ark.reset();
Animal a;
while (!ark.done()) {
a = ark.next())
cout << "[" << a << "]";
}
The internal pointer to values should be maintained across all of the operations
above, and should always be made to point to the next value.
Animal Class
The default constructor should set name to the empty string, weight to 0, and
dangerousness to false. Overload the << operator to print out the animal name,
weight and dangerousness such that Animal a{"Aardvark", 100, false}; cout << a
<< endl; prints out "Aardvark, 100 lbs". The string output is the same as what is
specified in CP1, so if the animal is dangerous, a "be careful" is tacked on the
end.