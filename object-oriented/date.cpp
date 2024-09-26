#include "date.h"
#include <print>

void Date::change(uint8_t day, uint8_t month, uint16_t year) {
    _day = day;
    _month = month;
    _year = year;
    validate();
}

void Date::print() const {
    if (_valid) {
        std::println("{:02}/{:02}/{}", _day, _month, _year);
    } else {
        std::println("Invalid date!");
    }
}

uint8_t Date::lastDayOfMonth() const {
    return _month != FEBRUARY ?
        (30 + (_month & 1) ^ (_month > JULY)) :
        28 + isLeapYear();
}
