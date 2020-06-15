
class BinaryFilter : public PixelFilter {
  protected:
    static Pixel WHITE;
    static Pixel BLACK;

    // Protected methods - Parent class will call this
    // since it is implemented
    virtual Pixel apply_transform(const Pixel&) const;

    Pixel primary;
    Pixel secondary;

  public:
    BinaryFilter ();
    BinaryFilter (Pixel primary, Pixel secondary);
    BinaryFilter (const BinaryFilter&);
    virtual ~BinaryFilter () {}

    // to_string
    virtual ostream& print(ostream&) const;

    // Operators
    BinaryFilter& operator=(const BinaryFilter&);
    friend ostream& operator<< (ostream&, const BinaryFilter&);
};


