QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cpp_/cpp_class_unit.cpp \
        cpp_/cpp_factory.cpp \
        cpp_/cpp_method_unit.cpp \
        cpp_/cpp_print_operator_unit.cpp \      
        csharp_/csharp_class_unit.cpp \
        csharp_/csharp_factory.cpp \
        csharp_/csharp_method_unit.cpp \
        csharp_/csharp_print_operator_unit.cpp \
        java_/java_class_unit.cpp \
        java_/java_factory.cpp \
        java_/java_method_unit.cpp \
        java_/java_print_operator_unit.cpp \
        main.cpp \
        unit.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cpp/cpp_class_unit.h \
    cpp/cpp_factory.h \
    cpp/cpp_method_unit.h \
    cpp/cpp_print_operator_unit.h \
    csharp/csharp_class_unit.h \
    csharp/csharp_factory.h \
    csharp/csharp_method_unit.h \
    csharp/csharp_print_operator_unit.h \
    factory.h \
    java/java_class_unit.h \
    java/java_factory.h \
    java/java_method_unit.h \
    java/java_print_operator_unit.h \
    unit.h
