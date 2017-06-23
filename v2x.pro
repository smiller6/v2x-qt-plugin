
TEMPLATE = lib
TARGET = v2x
QT    += qml quick
CONFIG += qt plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.genivi.v2x

SOURCES += \
    v2xcontrol.cpp \
    plugin.cpp \
    v2xcommand.cpp

HEADERS += \
    v2xcontrol.h \
    v2xcommand.h

DISTFILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}
#unix {
qmldir.files = qmldir
installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
#installPath = /usr/lib/qt5/lib/qml/$$replace(uri, \\., /)
target.path = /usr/lib/qt5/qml/$$replace(uri, \\., /)
qmldir.path = $$target.path
INSTALLS += target qmldir
#}
