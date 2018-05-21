    template <typename T>
    class ILessThanAbstrGen
    {
      public :
        virtual ~ILessThanGen (void) {}
        virtual bool operator () (const T &, const T &) const = 0;
 
    }; // ILessThanGen