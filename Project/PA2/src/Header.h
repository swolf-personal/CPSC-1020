class Header {
private:
    string MAGIC;
    int W, H, MC;

  public:
    Header ();
    Header (const Header& HDR);
    Header (string m, int w, int h, int mc);
    ~Header ();

    // Value getter, use only these for immutable headers
    string magic() const;
    int width() const;
    int height() const;
    int max_color() const;

    /*I am not sure what this is for but you may want to add setters if you 
     *need them. This returns a reference to a variable allowing you to change
     *a value of the data member using the reference.  You may or may not use
     *this.  There are no setter you may want to create setters rather than 
     * use a reference.  */
    // Ref getter 
    string& magic();
    int& width();
    int& height();
    int& max_color();

    // Assignment
    Header& operator= (const Header&);
    // Output
    friend ostream& operator<< (ostream&, const Header&);
};


