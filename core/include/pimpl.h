#ifndef PIMPL_H
#define PIMPL_H

#include <algorithm>

template <class Class, class ClassPrivate>
class Pimpl
{
public:
    explicit Pimpl();
    Pimpl(const Pimpl &other);
    Pimpl &operator=(Pimpl other);

    // Used to create an exception safe assignment operator
    // (see https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom)
    friend void swap(Pimpl &first, Pimpl &second)
    {
        using std::swap;
        swap(first.d_ptr, second.d_ptr);
    }

protected:
    // Disable destruction through base class pointer
    // (see http://www.gotw.ca/publications/mill18.htm)
    ~Pimpl();

    // Fallbacks if the derived class does not implement them
    static ClassPrivate *make();
    static ClassPrivate *clone(ClassPrivate *p);
    static void unmake(ClassPrivate *p);

private:
    ClassPrivate *_make() const;
    ClassPrivate *_clone(ClassPrivate *p) const;
    void _unmake(ClassPrivate *p) const; // Prevents MSVC warning C4150

protected:
    // Should be used to ensure const-correctness while accessing d_ptr in methods of Class
    inline ClassPrivate *d_func();
    inline const ClassPrivate *d_func() const;

    ClassPrivate *d_ptr;
};

template<class Class, class ClassPrivate>
Pimpl<Class, ClassPrivate>::Pimpl()
    : d_ptr(_make())
{

}

template<class Class, class ClassPrivate>
Pimpl<Class, ClassPrivate>::Pimpl(const Pimpl &other)
    : d_ptr(_clone(other.d_ptr))
{

}

template<class Class, class ClassPrivate>
Pimpl<Class, ClassPrivate> &Pimpl<Class, ClassPrivate>::operator=(Pimpl other)
{
    swap(*this, other);

    return *this;
}

template<class Class, class ClassPrivate>
Pimpl<Class, ClassPrivate>::~Pimpl()
{
    _unmake(d_ptr);
    d_ptr = 0;
}

template<class Class, class ClassPrivate>
ClassPrivate *Pimpl<Class, ClassPrivate>::make()
{
    return new ClassPrivate;
}

template<class Class, class ClassPrivate>
ClassPrivate *Pimpl<Class, ClassPrivate>::clone(ClassPrivate *p)
{
    return new ClassPrivate(*p);
}

template<class Class, class ClassPrivate>
void Pimpl<Class, ClassPrivate>::unmake(ClassPrivate *p)
{
    delete p;
}

template<class Class, class ClassPrivate>
ClassPrivate *Pimpl<Class, ClassPrivate>::_make() const
{
    return reinterpret_cast<Class const *>(this)->make();
}

template<class Class, class ClassPrivate>
ClassPrivate *Pimpl<Class, ClassPrivate>::_clone(ClassPrivate *p) const
{
    return reinterpret_cast<Class const *>(this)->clone(p);
}

template<class Class, class ClassPrivate>
void Pimpl<Class, ClassPrivate>::_unmake(ClassPrivate *p) const
{
    reinterpret_cast<Class const *>(this)->unmake(p);
}

template<class Class, class ClassPrivate>
ClassPrivate *Pimpl<Class, ClassPrivate>::d_func()
{
    return reinterpret_cast<ClassPrivate *>(d_ptr);
}

template<class Class, class ClassPrivate>
const ClassPrivate *Pimpl<Class, ClassPrivate>::d_func() const
{
    return reinterpret_cast<const ClassPrivate *>(d_ptr);
}

#endif // PIMPL_H
