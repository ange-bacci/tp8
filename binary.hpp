#ifndef BINARY_HPP
#define BINARY_HPP

template <class T1, class T2, class R>
class Binary {
public:
    virtual ~Binary() {}
    virtual R operator() (const T1 &, const T2 &) const = 0;
};

#endif // BINARY_HPP
