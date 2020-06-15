

class HFlipFilter : public SimpleFilter {
  public:
    // Derived classes need these visible
    HFlipFilter();
    HFlipFilter(const HFlipFilter&);
    virtual ~HFlipFilter () {}

    // not pure virtual!
    virtual void apply(Image&) const;

    // to_string
    virtual ostream& print(ostream&) const;

    // Overloaded operators
    HFlipFilter& operator=(const HFlipFilter&);
    friend ostream& operator<< (ostream&, const HFlipFilter&);
};


