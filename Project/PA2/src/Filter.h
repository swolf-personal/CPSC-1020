class Filter {
  protected:
    // Data - Shows that abstract classes can still do things
    string name;

    // Derived classes need these visible
    Filter();
    Filter(string);
    Filter(const Filter&);

    // Static helpers - in real software, this would be
    // a template function so we can support many different numeric types
    static int clamp(int, int, int);
    static double clamp(double, double, double);

  public:
    virtual ~Filter () {}

    // Public Interface - every derived class must implement
    //                  - or be abstract itself
    virtual void apply(Image&) const = 0;

    // to_string
    virtual ostream& print(ostream&) const;

    // Overloaded operators
    Filter& operator=(const Filter&);
    friend ostream& operator<< (ostream&, const Filter&);
};


