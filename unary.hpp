#ifndef UNARY_HPP
#define UNARY_HPP

template <typename T, typename TResult>
class Unary {
public :
    virtual ~Unary(void) {}
    virtual TResult operator () (const T &) const = 0;
};

#endif
