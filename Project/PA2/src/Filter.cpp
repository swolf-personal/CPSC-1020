/*Filter is the top tier base class.  It is also an abstract class
 *it has one data member which represents the name of the the child class
 *since this is the default constructor set the name to an empty string
 you should  use initilization list here*/
Filter::Filter() {

}

/*This is the regular constructor.  Set name = to the name being passed in.
 *you should  use initilization list here*/
Filter::Filter(string name)  {

}


/*This is the copy construct.  Again the only thing that needs to be set is the
*name.  Use initializatin list and set the name to the name of f which is passed
*to the constructor.*/
Filter::Filter(const Filter& f) {

}

// one line clamp:
// if x < lo, lo is chosen by std::max
// if x > hi, hi is chosen by std::min
// if lo < x < hi, x i chosen by std::min

/*These were given to you in the documentation*/
int Filter::clamp(int lo, int hi, int x) {
  return std::max(lo, std::min(x, hi));
}

double Filter::clamp(double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}
/*Not sure that is is actually used. accept for posibly debugging or for general
*information when running the program .  Basically prints the word Filler: then
*the name of the filter. the some - under it. */
ostream& Filter::print(ostream& out) const {
  
}

/*Assignment opreator.  Simply sets name to the name from f being passed in.*/
Filter& Filter::operator=(const Filter& f) {
 
}

/*Calls the print function that belings to f. (above)*/
ostream& operator<< (ostream& out, const Filter& f) {

}
