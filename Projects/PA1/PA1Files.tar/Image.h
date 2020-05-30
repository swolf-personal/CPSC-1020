class Image
{
    private:
      Header hdr;
      vector<vector<Pixel> > pixels;

    public:
      Image();
      Image(string, int, int);
      Image(ifstream&);
      void writeImage(ofstream&);
      Header& getHeader();
      vector<vector<Pixel> >& getPixel();
      void readPixels(const Header&, ifstream&);
      void resizeImage(Image& oldImage, Image& newImage);
      void printP6Image(ofstream&, Image);
      void printP3Image(ofstream&, Image);

};

