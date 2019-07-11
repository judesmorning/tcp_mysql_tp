QT -= gui
QT += network
QT += sql
CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    abspacket.cpp \
    mymethod.cpp \
    myrun.cpp \
    mytcp.cpp \
    parse.cpp \
    mylog.cpp \
    packet_servo_subsystem.cpp \
    mysqltool.cpp \
    packet_transmit_subsystem.cpp \
    packet_receiving_subsystem.cpp \
    packet_receive_subsystem_status_message.cpp \
    packet_power_subsystem_status_message.cpp \
    packet_antenna_feeder_subsystem_status.cpp \
    packet_ac_state.cpp \
    packet_antenna_feeder_subsystem_asks_for_wave_controller_phase_value.cpp \
    packet_external_reference_extension_status.cpp \
    packet_communication_status.cpp \
    packet_test_area_mean_value.cpp \
    packet_work_area_mean_value.cpp \
    packet_antenna_feeder_subsystem_status_2.cpp

HEADERS += \
    abspacket.h \
    includes.h \
    mymethod.h \
    myrun.h \
    mytcp.h \
    parse.h \
    mylog.h \
    packet_servo_subsystem.h \
    mysqltool.h \
    packet_transmit_subsystem.h \
    packet_receiving_subsystem.h \
    packet_receive_subsystem_status_message.h \
    packet_power_subsystem_status_message.h \
    packet_antenna_feeder_subsystem_status.h \
    packet_ac_state.h \
    packet_antenna_feeder_subsystem_asks_for_wave_controller_phase_value.h \
    packet_external_reference_extension_status.h \
    packet_communication_status.h \
    packet_test_area_mean_value.h \
    packet_work_area_mean_value.h \
    packet_antenna_feeder_subsystem_status_2.h
