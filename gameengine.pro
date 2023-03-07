TEMPLATE = app
CONFIG += console c++17
LIBS += -L/usr/local/lib64 -lraylib
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -march=native -mtune=native -mavx2 -O3

SOURCES += \
        main.cpp

HEADERS += \
    include/default.h \
    include/draw.h \
    include/linear.h \
    include/matrix.h \
    include/point.h \
    include/vector.h \
    include/window.h
