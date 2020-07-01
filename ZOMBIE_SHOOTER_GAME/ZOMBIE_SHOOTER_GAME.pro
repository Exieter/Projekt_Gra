TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "E:/SFML-2.5.1/include"
LIBS += -L"E:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}
SOURCES += \
    bullet.cpp \
    graj.cpp \
    main_ZOMBIE_SHOOTER_GAME.cpp \
    otoczenie.cpp \
    player.cpp \
    zombie.cpp \
    zombieclasses.cpp

HEADERS += \
    bullet.h \
    graj.h \
    otoczenie.h \
    player.h \
    zombie.h \
    zombieclasses.h
