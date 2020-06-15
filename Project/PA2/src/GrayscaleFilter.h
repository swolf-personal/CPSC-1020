

class GrayscaleFilter : public PixelFilter {
  protected:
    // Protected methods - Parent class will call this
    // since it is implemented
    virtual Pixel apply_transform(const Pixel&) const;

  public:
    GrayscaleFilter ();
    GrayscaleFilter (const GrayscaleFilter&);
    virtual ~GrayscaleFilter () {}

    // to_string
    virtual ostream& print(ostream&) const;

    // Operators
    GrayscaleFilter& operator=(const GrayscaleFilter&);
    friend ostream& operator<< (ostream&, const GrayscaleFilter&);
};

