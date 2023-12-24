/**
 * @file TimeHandler.cpp
 * @brief Implementation of the TimeHandler class.
 *
 * For detailed description and usage check TimeHandler.h
 *
 * @author DWI
 * @date 2021-12-12
 */

#include <iomanip>
#include <sstream>
#include <string>
#include "TimeHandler.h"

namespace saab
{
namespace library
{

// operators overloading
TimeHandler TimeHandler::operator+(const uint64_t seconds)
{
    return add_seconds(seconds);
}

TimeHandler TimeHandler::operator-(const uint64_t seconds)
{
    return subtract_seconds(seconds);
}

TimeHandler& TimeHandler::operator++()
{
    *this = add_seconds(1u);
    return *this;
}

TimeHandler TimeHandler::operator++(int)
{
    TimeHandler tmp = *this;
    operator++();
    return tmp;
}

TimeHandler& TimeHandler::operator--()
{
    *this = subtract_seconds(1u);
    return *this;
}

TimeHandler TimeHandler::operator--(int)
{
    TimeHandler tmp = *this;
    operator--();
    return tmp;
}

bool operator<(const TimeHandler& left_obj, const TimeHandler& right_obj)
{
    return std::tie(left_obj.hours_, left_obj.minutes_, left_obj.seconds_) <
           std::tie(right_obj.hours_, right_obj.minutes_, right_obj.seconds_);
}

bool operator>(const TimeHandler& left_obj, const TimeHandler& right_obj)
{
    return right_obj < left_obj;
}

bool operator<=(const TimeHandler& left_obj, const TimeHandler& right_obj)
{
    return !(left_obj > right_obj);
}

bool operator>=(const TimeHandler& left_obj, const TimeHandler& right_obj)
{
    return !(left_obj < right_obj);
}

bool operator==(const TimeHandler& left_obj, const TimeHandler& right_obj)
{
    return std::tie(left_obj.hours_, left_obj.minutes_, left_obj.seconds_) ==
           std::tie(right_obj.hours_, right_obj.minutes_, right_obj.seconds_);
}

bool operator!=(const TimeHandler& left_obj, const TimeHandler& right_obj)
{
    return !(left_obj == right_obj);
}

std::ostream& operator<<(std::ostream& os, const TimeHandler& obj)
{
    const bool format_24h{true};  // by default always use 24h format
    os << obj.to_string(format_24h);
    return os;
}

std::istream& operator>>(std::istream& is, TimeHandler& obj)
{
    char delimiter1 = '0';
    char delimiter2 = '0';
    is >> obj.hours_ >> delimiter1 >> obj.minutes_ >> delimiter2 >> obj.seconds_;

    if (!is || delimiter1 != ':' || delimiter2 != ':' || !obj.is_valid())
    {
        is.setstate(std::ios::failbit);
    }
    return is;
}

bool TimeHandler::is_valid()
{
    // We are using unsigned integers which are always greater than 0
    return (hours_ <= 23u && minutes_ <= 59u && seconds_ <= 59u);
}

bool TimeHandler::is_am() const
{
    // We are using unsigned integers which are always greater than 0
    return (hours_ <= 12u);
}

std::string TimeHandler::to_string(const bool format_24h) const
{
    std::stringstream ss{};
    uint16_t hours_format{hours_};
    std::string time_format{};

    if (!format_24h)
    {
        if (!is_am())
        {
            hours_format -= 12u;  // reformat for `pm`
            time_format = " pm";
        }
        else
        {
            time_format = " am";
        }
    }
    ss << format_time(hours_format) << ":" << format_time(minutes_) << ":" << format_time(seconds_) << time_format;
    return ss.str();
}
// Private:
std::string TimeHandler::format_time(const uint16_t time_val) const
{
    std::stringstream ss{};
    ss << std::setfill('0') << std::setw(2) << time_val;
    return ss.str();
}

// Function to add seconds and handle overflow
TimeHandler TimeHandler::add_seconds(const uint64_t seconds_to_add) const
{
    const uint64_t total_seconds = hours_ * 3600u + minutes_ * 60u + seconds_ + seconds_to_add;
    return convert_seconds_to_time(total_seconds);
}

TimeHandler TimeHandler::subtract_seconds(const uint64_t seconds_to_subtract) const
{
    int64_t total_seconds = hours_ * 3600u + minutes_ * 60u + seconds_ - seconds_to_subtract;
    while (total_seconds < 0)
    {
        total_seconds += 24u * 3600u;  // Add a day's worth of seconds
    }

    return convert_seconds_to_time(static_cast<uint64_t>(total_seconds));
}

TimeHandler TimeHandler::convert_seconds_to_time(const uint64_t seconds_to_format) const
{
    const uint16_t new_hours = (seconds_to_format / 3600u) % 24u;  // wrap around if exceeds 24 hours
    const uint16_t new_minutes = (seconds_to_format % 3600u) / 60u;
    const uint16_t new_seconds = seconds_to_format % 60u;

    return TimeHandler(new_hours, new_minutes, new_seconds);
}

}  // namespace library
}  // namespace saab