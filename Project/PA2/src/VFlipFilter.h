

class VFlipFilter : public SimpleFilter {
  public:
    // Derived classes need these visible
    VFlipFilter();
    VFlipFilter(const VFlipFilter&);
    virtual ~VFlipFilter () {}

    // not pure virtual!
    virtual void apply(Image&) const;

    // to_string
    virtual ostream& print(ostream& out) const;

    // Overloaded operators
    VFlipFilter& operator=(const VFlipFilter&);
    friend ostream& operator<< (ostream&, const VFlipFilter&);
};


