#ifndef FINDER_HPP
#define FINDER_HPP

template <class T>
class Finder {
public:
    virtual ~Finder() {}
    virtual bool operator() (const T &) const = 0;
};

#endif // FINDER_HPP
