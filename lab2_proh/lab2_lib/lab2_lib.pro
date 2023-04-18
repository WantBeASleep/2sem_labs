TEMPLATE = lib
CONFIG += staticlib c++17
CONFIG -= qt

HEADERS += \
    arraySequence.h \
    deque.h \
    dynamicarray.h \
    linkedList.h \
    linkedListSequence.h \
    queue.h \
    sequence.h \
    stack.h

unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
