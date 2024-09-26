#ifndef DATE_H
#define DATE_H

#include <compare>
#include <cstdint>

class Date {
public:
    enum { YEAR_MIN = 1900, YEAR_MAX = 3000 };
    enum { FEBRUARY = 2, JULY = 7 };

    Date() = default;

    Date(uint8_t day, uint8_t month, uint16_t year) {
        change(day, month, year);
    }

    void change(uint8_t day, uint8_t month, uint16_t year);

    void validate() {
        _valid = ((_day >= 1 && _day <= lastDayOfMonth()) &&
                  (_month >= 1 && _month <= 12) &&
                  (_year >= YEAR_MIN && _year <= YEAR_MAX));
    }

    void print() const;

    uint8_t lastDayOfMonth() const;

    /**
     * An year is leap when:
     * - Is divisible by 400
     * - Is divisible by 4, but not by 100
     *
     * It's possible to check a remainder of a number using an and of bits (&).
     * This works only when the number being checked is a power of 2,
     * so we can use it only for the divisible by 4 verification.
     * The rule is to apply the & on n-1, so {_year & 3}.
     *
     * 1 [0001] & 3 [0011] -> 0001 -> 1
     * 2 [0010] & 3 [0011] -> 0010 -> 2
     * 3 [0011] & 3 [0011] -> 0011 -> 3
     * 4 [0100] & 3 [0011] -> 0000 -> 0
     *
     * Putting the divisible by 4 and bot by 100 first is more efficient,
     * because this happens more frequentely than the other clause.
     *
     * Checking directly against the int value from the expressions is more efficient,
     * because temp variables doesn't need to be created to do the comparison against 0.
     */
    uint16_t isLeapYear() const {
        return (!(_year & 3) && (_year % 100)) || !(_year % 400);
    }

    uint8_t day() const {
        return _day;
    }

    uint8_t month() const {
        return _month;
    }

    uint16_t year() const {
        return _year;
    }

    auto operator<=>(const Date &other) const {
        if (const auto cmp = _year <=> other._year; cmp != 0) return cmp;
        if (const auto cmp = _month <=> other._month; cmp != 0) return cmp;
        return _day <=> other._day;
    }

    bool operator==(const Date &other) const {
        return (*this <=> other) == 0;
    }

    bool operator!=(const Date &other) const {
        return (*this <=> other) != 0;
    }
private:
    bool _valid : 1 {false};
    uint8_t _day : 7;
    uint8_t _month;
    uint16_t _year;
};

#endif // DATE_H
