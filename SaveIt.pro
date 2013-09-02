#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T22:53:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SaveIt
TEMPLATE = app

include(../CustomQtWidgets/CustomQtWidgets.pro)

SOURCES += main.cpp\
        mainwindow.cpp \
    backupplan.cpp \
	backupplanlistwidget.cpp \
    backupplanlist.cpp \

HEADERS  += mainwindow.h \
    backupplan.h \
	backupplanlistwidget.h \
    backupplanlist.h \
	delegates/MouseHoverDelegate.h \
	delegates/mousehovercomposite.h \
	delegates/mousehoverable.h \
	Animator.h \
	dialog.h \
	backupsrcdlg.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
