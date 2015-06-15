TEMPLATE =app
QT+=widgets
QT+=gui \
printsupport
SOURCES += \
main.cpp \
ui/mainwindow.cpp \
    ui/option.cpp \
    leu/parcer.cpp \
    leu/plotwindow.cpp \
    leu/qcustomplot.cpp
HEADERS += \
ui/mainwindow.h \
    ui/option.h \
    leu/parcer.h \
    leu/plotwindow.h \
    leu/qcustomplot.h
