class PixelFilter : public Filter {
  protected:
    // Protected methods
    PixelFilter ();
    PixelFilter (string);
    PixelFilter (const PixelFilter&);

    virtual Pixel apply_transform(const Pixel&) const = 0;

  public:
    virtual ~PixelFilter () {}

    // Public Interface
    virtual void apply(Image&) const;

    // to_string
    virtual ostream& print(ostream&) const;

    // Operators
    PixelFilter& operator=(const PixelFilter&);
    friend ostream& operator<< (ostream&, const PixelFilter&);
};

