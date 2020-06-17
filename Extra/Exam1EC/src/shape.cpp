/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

#include <iostream>
#include <vector>
#include <string>

#include "shape.h"

using namespace std;

Shape::Shape() : name("Shape"), id(0) {}

Shape::Shape(string nameIn, int idIn) 
: name(nameIn), id(idIn) {}

Shape::~Shape() {}

void Shape::printName(ostream& out) {out << name;}

int Shape::getID() {return id;}

int& Shape::getR() {return r;}
int& Shape::getG() {return g;}
int& Shape::getB() {return b;}