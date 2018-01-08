CONFIG += c++14
CONFIG += console
LIBS += -L../Police/"SFML-2.4.1 DW2"/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += ../Police/"SFML-2.4.1 DW2"/include
DEPENDPATH += ../Police/"SFML-2.4.1 DW2"/include

SOURCES += \
    main.cpp \
    object.cpp \
    stack.inl \
    object_one.cpp \
    object_two.cpp \
    SceneNodeStack.cpp \
    SceneNode.cpp

HEADERS += \
    stack.hpp \
    object.hpp \
    object_one.hpp \
    object_two.hpp \
    SceneNodeStack.hpp \
    SceneNode.hpp
