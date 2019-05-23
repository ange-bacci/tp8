#ifndef COMPARATOR_H
#define COMPARATOR_H

template <typename T>
class Comparator
{
  public :
    virtual ~Comparator (void) {}
    virtual bool operator () (const T &, const T &) const = 0;

};

#endif // COMPARATOR_H
