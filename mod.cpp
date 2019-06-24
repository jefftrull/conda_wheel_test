#include <iostream>

#include <boost/python.hpp>

void foo()
{
    std::cout << "hello from foo\n";
}

BOOST_PYTHON_MODULE(mymod)
{
    boost::python::def("foo", foo);
}
