/* -------------------- /
Stephen Wolf
wolf7
Lab 9
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include <iostream>
#include <vector>
#include <string>

#include "shape.h"

using namespace std;

Shape::Shape(string nameIn = "Shape", int idIn = 0) 
: name(nameIn), id(idIn) {}

Shape::~Shape() {}

void Shape::printName(ostream& out) {out << name;}

int Shape::getID() {return id;}