add_library(BasicMath basics.cpp basics.h)

install(TARGETS BasicMath DESTINATION lib)
install(FILES basics.h DESTINATION include)