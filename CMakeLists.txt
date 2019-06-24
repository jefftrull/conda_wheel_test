cmake_minimum_required( VERSION 3.13 )

PROJECT( conda_wheel )

# A really basic project that does almost nothing but provide a binary Python extension

find_package( Python3 COMPONENTS Interpreter Development )
set( PYTHON_COMPONENT "python${Python3_VERSION_MAJOR}${Python3_VERSION_MINOR}" )

find_package( Boost 1.67 REQUIRED
    COMPONENTS ${PYTHON_COMPONENT} )

Python3_add_library( mymod mod.cpp )
target_link_libraries( mymod PRIVATE Boost::${PYTHON_COMPONENT} )

install( TARGETS mymod DESTINATION ${Python3_SITEARCH} )
