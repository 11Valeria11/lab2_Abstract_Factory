QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cpp_class_unit.cpp \
        cpp_factory.cpp \
        cpp_method_unit.cpp \
        cpp_print_operator_unit.cpp \
        csharp_class_unit.cpp \
        csharp_factory.cpp \
        csharp_method_unit.cpp \
        csharp_print_operator_unit.cpp \
        java_class_unit.cpp \
        java_factory.cpp \
        java_method_unit.cpp \
        java_print_operator_unit.cpp \
        main.cpp \
        unit.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cpp_class_unit.h \
    cpp_factory.h \
    cpp_method_unit.h \
    cpp_print_operator_unit.h \
    csharp_class_unit.h \
    csharp_factory.h \
    csharp_method_unit.h \
    csharp_print_operator_unit.h \
    factory.h \
    java_class_unit.h \
    java_factory.h \
    java_method_unit.h \
    java_print_operator_unit.h \
    unit.h
