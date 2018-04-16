CONFIG += c++14
CONFIG += console
LIBS += -L./"SFML-2.4.1 DW2"/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += ./"SFML-2.4.1 DW2"/include
DEPENDPATH += ./"SFML-2.4.1 DW2"/include

SOURCES += \
    main.cpp \
    Application.cpp \
    GameState.cpp \
    State.cpp \
    StateStack.cpp \
    TitleState.cpp \
    ResourceHolder.inl \
    Utility.cpp \
    Utility.inl \
    World.cpp \
    SceneNode.cpp \
    IOFile.cpp \
    SpriteNode.cpp \
    Button.cpp \
    Component.cpp \
    Container.cpp \
    MenuState.cpp \
    ProgressBar.cpp \
    LoadingStates.cpp \
    ParallelTask.cpp \
    Build.cpp \
    RectangleRoom.cpp \
    Tuile.cpp \
    TextureSpliter.cpp \
    DataTables.cpp \
    Command.cpp \
    CommandQueue.cpp \
    SettingsState.cpp \
    Ui.cpp \
    Animation.cpp \
    Entity.cpp \
    Sbires.cpp \
    WorkerSbire.cpp \
    SbireManager.cpp \
    Tasks.cpp \
    TaskManager.cpp \
    Position.cpp

HEADERS += \
    Application.hpp \
    GameState.hpp \
    State.hpp \
    Stateidentifiers.hpp \
    StateStack.hpp \
    TitleState.hpp \
    ResourceIdentifiers.hpp \
    ResourceHolder.hpp \
    Foreach.hpp \
    Utility.hpp \
    World.hpp \
    MapIdentifier.hpp \
    SceneNode.hpp \
    Category.hpp \
    IOFile.hpp \
    SpriteNode.hpp \
    Button.hpp \
    Component.hpp \
    Container.hpp \
    MenuState.hpp \
    ProgressBar.hpp \
    LoadingState.hpp \
    ParallelTask.hpp \
    Build.hpp \
    RectangleRoom.hpp \
    Tuile.hpp \
    TextureSpliter.hpp \
    DataTables.hpp \
    CommandQueue.hpp \
    Command.hpp \
    SettingsState.hpp \
    Ui.hpp \
    Animation.hpp \
    Entity.hpp \
    Sbires.hpp \
    WorkerSbire.hpp \
    SbireManager.hpp \
    Tasks.hpp \
    TaskManager.hpp \
    Position.hpp \
    Settings.hpp

DISTFILES += \
    Media/Textures/Title_Screen.png \
    object_script.Police.Debug \
    uml_project.qmodel \
    uml_rendering.qmodel \
    Media/Textures/Explosion.png \
    Media/Textures/police_sprites.gif \
    Media/Textures/police_sprites.png
