TEMPLATE = app
TARGET = UtilisationUI
QT += core \
    gui
HEADERS += supprimergui.h \
    ajoutercamiongui.h \
    ajoutervehiculepromenadegui.h \
    ajouterpropriogui.h \
    utilisationui.h
SOURCES += supprimergui.cpp \
    ajoutercamiongui.cpp \
    ajoutervehiculepromenadegui.cpp \
    ajouterpropriogui.cpp \
    main.cpp \
    utilisationui.cpp
FORMS += supprimergui.ui \
    ajoutercamiongui.ui \
    ajoutervehiculepromenadegui.ui \
    ajouterpropriogui.ui \
    utilisationui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
