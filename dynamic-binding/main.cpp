#include <iostream>
#include <cstring>

using namespace std;

class Animal {
protected:
    int legs;
    char* name;
  public:
    Animal();
    Animal(const int, const char*);
    Animal(const Animal&);
    virtual ~Animal();

    virtual void display() const = 0;
};

Animal::Animal() : legs(0), name(NULL) {}

Animal::Animal(const int legs, const char* name) : legs(legs) {
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

Animal::Animal(const Animal& src) : legs(src.legs) {
  if(this == &src) return;

  if(name) delete name;
  name = new char[strlen(src.name) + 1];
  strcpy(name, src.name);
}

Animal::~Animal() {
  if(name) delete name;
}

class Dog : public Animal {
  private:
    char* tail;
  public:
    Dog();
    Dog(const int, const char*, const char*);
    Dog(const Dog&);
    ~Dog();

    void display() const;
};

Dog::Dog() : tail(NULL) {}

Dog::Dog(const int legs, const char* name, const char* tail) : Animal(legs, name) {
  this->tail = new char[strlen(tail) + 1];
  strcpy(this->tail, tail);
}

Dog::Dog(const Dog& src) : Animal(src) {
  if(this == &src) return;

  if(tail) delete tail;
  tail = new char[strlen(src.tail) + 1];
  strcpy(this->tail, src.tail);
}

Dog::~Dog() {
  if(tail) delete tail;
}

void Dog::display() const {
  cout << "Dog(" << name << ", " << tail << ", " << legs << ")" << endl;
}

class Fish : public Animal {
  private:
    int fins;
  public:
    Fish();
    Fish(const char*, const int);
    Fish(const Fish&);
    ~Fish();

    void display() const;
};

Fish::Fish() : fins(0) {}

Fish::Fish(const char* name, const int fins) : Animal(0, name), fins(fins) {}

Fish::Fish(const Fish& src) : Animal(src) {
  if(this == &src) return;
  fins = src.fins;
}

Fish::~Fish() {}

void Fish::display() const {
  cout << "Fish(" << name << ", " << fins << ")" << endl;
}

Animal** build_list(const int size) {
  Animal** list = new Animal*[size];
  for(int i = 0; i < size; ++i) list[i] = NULL;
  return list;
}

void display_list(const int size, Animal** list) {
  if(!list) return;
  for(int i = 0; i < size; ++i)
    if(list[i]) list[i]->display();
}

void bad_copy_list(const int size, Animal** src, Animal**& dest) {
  if(!src) return;

  dest = new Animal*[size];
  for(int i = 0; i < size; ++i){
    dest[i] = src[i];
  }
}

void good_copy_list(const int size, Animal** src, Animal**& dest) {
  if(!src) return;

  dest = new Animal*[size];
  for(int i = 0; i < size; ++i){
    Dog* t1 = dynamic_cast<Dog*>(src[i]);
    if(t1) {
        dest[i] = new Dog(*t1);
        continue;
    }

    Fish* t2 = dynamic_cast<Fish*>(src[i]);
    if(t2) {
      dest[i] = new Fish(*t2);
      continue;
    }
  }
}

void delete_list(const int size, Animal**& src) {
  if(!src) return;

  for(int i = 0; i < size; ++i)
    if(src[i]) delete src[i];
  delete [] src;
  src = NULL;
}

int main() {
  // Instantiate things
  const int size = 3;
  Animal** src_animals = build_list(size);
  Animal** dest_animals = NULL;

  // Populate the first list
  src_animals[0] = new Fish("Nemo", 1);
  src_animals[1] = new Dog(4, "Walter", "Stubbed");
  src_animals[2] = new Fish("Marlin", 2);

  // Copy the list
  // bad_copy_list(size, src_animals, dest_animals); // The shallow (bad) copy
  good_copy_list(size, src_animals, dest_animals); // The deep (good) copy

  // Display things
  cout << "Source:" << endl;
  display_list(size, src_animals);
  cout << "Copy:" << endl;
  display_list(size, dest_animals);

  // Destroy things
  delete_list(size, src_animals);
  delete_list(size, dest_animals);
}
