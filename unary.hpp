    template <typename T, typename TRes>
    class IUnaryFunction
    {
      public :
        virtual ~IUnaryFunction (void) {}
        virtual TRes operator () (const T &) const noexcept = 0;
 
    }; // IUnaryFunction