/**
 * @file TimeHandler.h
 * @brief Definition of the TimeHandler class.
 *
 * The TimeHandler class provides a representation of time in hours, minutes, and seconds.
 * It includes functionalities to manipulate time values and perform arithmetic and comparison operations.
 * This class ensures that all time values remain within valid ranges and normalizes any out-of-range
 * inputs. It's implemented using `uint16_t` for storing hours, minutes, and seconds to maintain a compact
 * and efficient representation.
 *
 * @example Usage:
 *      TimeHandler t1(10u, 20u, 30u); // Initializes a TimeHandler object to 10:20:30
 *      t1++;                          // Increments time by one second
 *      std::cout << t1;               // Prints the time
 *
 * @note This class is designed to handle time in a 24-hour format. However it is possible to print time also in 12h
 * format.
 * @note It was decided to use unsigned data type to store all the time values. Class instance won't be created with
 * different data type (unsigned, float, double) - it will lead to compilation error.
 *
 * @author DWI
 * @date 2021-12-12
 */
#ifndef SAAB_LIBRARY_TIME
#define SAAB_LIBRARY_TIME

#include <cstdint>
#include <string>
#include <tuple>
#include <type_traits>

namespace saab
{
namespace library
{

class TimeHandler
{
  public:
    /**
     * @brief Constructor for the TimeHandler class.
     *
     * @param hours The initial number of hours. Must be an integral type and non-negative.
     *              Values exceeding 23 are wrapped around to fit in a 24-hour format.
     * @param minutes The initial number of minutes. Must be an integral type and non-negative.
     *                Values exceeding 59 are added to hours.
     * @param seconds The initial number of seconds. Must be an integral type and non-negative.
     *                Values exceeding 59 are added to minutes.
     *
     * @note The construction of object will fail if negative value is added. If you initialize data
     * by raw values please add `u` so compiler will consider these as unsized, instead of signed.
     */
    template <typename T>
    TimeHandler(T hours, T minutes, T seconds)
        : hours_{static_cast<uint16_t>(hours)},
          minutes_{static_cast<uint16_t>(minutes)},
          seconds_{static_cast<uint16_t>(seconds)}
    {
        // compile time check for negative values
        static_assert(std::is_unsigned<T>::value && std::is_unsigned<T>::value,
                      "\nTime can be stored only as unsigned integer. Consider adding `u` to the variable.");
    }
    TimeHandler() : TimeHandler(0u, 0u, 0u){};

    /**
     * @brief Check if stored time is valid.
     *
     * Checks if hours are between [0,23],
     * minutes and seconds are between [0,59].
     *
     * @return `true` if time is valid, `false` otherwise.
     */
    bool is_valid();

    /**
     * @brief Return time as string in 12h or 24h format.
     *
     * Get time as string with `am` or `pm` (12h format)
     * or without any formatting (24h format).
     *
     * @param format_24h `true` for 24h format in output, `false` for 12h format in output.
     *
     * @return Time as string formatted to 12h or 24h style.
     */
    std::string to_string(const bool format_24h) const;

    /**
     * @brief Check if stored time is before or after midnight (am or pm).
     *
     * @return `true` if stored time is before noon (am), `false` otherwise.
     */
    bool is_am() const;

    /**
     * @brief Overloads the << operator for formatted output of TimeHandler objects.
     *
     * This function overloads the insertion (<<) operator to provide a convenient
     * way of outputting the state of a TimeHandler object in a formatted string representation.
     * It is typically used for printing the object's state to the console or writing it
     * to an output stream like a file.
     *
     * @param os The output stream (e.g., std::cout) to which the formatted time is to be sent.
     * @param obj The TimeHandler object whose state is to be output.
     *
     * @return A reference to the updated output stream (`std::ostream&`). This allows for chaining
     * of << operator calls.
     *
     * @note This function is declared as a friend of the TimeHandler class to allow it direct
     * access to the class's private members. This is necessary for it to read the state
     * of the object (hours, minutes, seconds) and format it appropriately for output.
     */
    friend std::ostream& operator<<(std::ostream& os, const TimeHandler& obj);

    /**
     * @brief Overloads the >> operator for formatted input into a TimeHandler object.
     *
     * This function overloads the extraction (>>) operator to provide a convenient way
     * of reading the state of a TimeHandler object from an input stream. It is typically
     * used for inputting the object's state from the console or reading it from an
     * input stream like a file.
     *
     * @param is The input stream (e.g., std::cin) from which the time data is to be read.
     * @param obj The TimeHandler object into which the read state is to be stored.
     *
     * @return A reference to the updated input stream (`std::istream&`). This allows for
     *         chaining of >> operator calls.
     *
     * @note This function is declared as a friend of the TimeHandler class to allow it direct
     *       access to the class's private members. This is necessary for it to write the read
     *       state (hours, minutes, seconds) into the object.
     */
    friend std::istream& operator>>(std::istream& is, TimeHandler& obj);

    /**
     * @brief Adds seconds to a TimeHandler object.
     *
     * @param seconds The number of seconds to add.
     * @return A new TimeHandler object representing the time after the addition.
     */
    TimeHandler operator+(const uint64_t seconds);

    /**
     * @brief Subtracts seconds from a TimeHandler object.
     *
     * @param seconds The number of seconds to subtract.
     * @return A new TimeHandler object representing the time after the subtraction.
     */
    TimeHandler operator-(const uint64_t seconds);

    /**
     * @brief Prefix increment operator.
     *
     * Increments the time of the TimeHandler object by one second.
     *
     * @return A reference to the incremented object.
     */
    TimeHandler& operator++();

    /**
     * @brief Postfix increment operator.
     *
     * Increments the time of the TimeHandler object by one second.
     *
     * @param Unused parameter to distinguish from the prefix increment operator.
     * @return A TimeHandler object representing the time before the increment.
     */
    TimeHandler operator++(int);

    /**
     * @brief Prefix decrement operator.
     *
     * Decrements the time of the TimeHandler object by one second.
     *
     * @return A reference to the decremented object.
     */
    TimeHandler& operator--();

    /**
     * @brief Postfix decrement operator.
     *
     * Decrements the time of the TimeHandler object by one second.
     *
     * @param Unused parameter to distinguish from the prefix decrement operator.
     * @return A TimeHandler object representing the time before the decrement.
     */
    TimeHandler operator--(int);

    /**
     * @brief Compares two TimeHandler objects for less-than relationship.
     *
     * Determines if the time represented by `left_obj` is earlier than the time
     * represented by `right_obj`.
     *
     * @param left_obj The TimeHandler object on the left-hand side of the operator.
     * @param right_obj The TimeHandler object on the right-hand side of the operator.
     * @return `true` if `left_obj` is earlier than `right_obj`, `false` otherwise.
     */
    friend bool operator<(const TimeHandler& left_obj, const TimeHandler& right_obj);

    /**
     * @brief Compares two TimeHandler objects for greater-than relationship.
     *
     * Determines if the time represented by `left_obj` is later than the time
     * represented by `right_obj`.
     *
     * @param left_obj The TimeHandler object on the left-hand side of the operator.
     * @param right_obj The TimeHandler object on the right-hand side of the operator.
     * @return `true` if `left_obj` is later than `right_obj`, `false` otherwise.
     */
    friend bool operator>(const TimeHandler& left_obj, const TimeHandler& right_obj);

    /**
     * @brief Compares two TimeHandler objects for less-than-or-equal-to relationship.
     *
     * Determines if the time represented by `left_obj` is earlier than or equal to
     * the time represented by `right_obj`.
     *
     * @param left_obj The TimeHandler object on the left-hand side of the operator.
     * @param right_obj The TimeHandler object on the right-hand side of the operator.
     * @return `true` if `left_obj` is earlier than or equal to `right_obj`, `false` otherwise.
     */
    friend bool operator<=(const TimeHandler& left_obj, const TimeHandler& right_obj);

    /**
     * @brief Compares two TimeHandler objects for greater-than-or-equal-to relationship.
     *
     * Determines if the time represented by `left_obj` is later than or equal to
     * the time represented by `right_obj`.
     *
     * @param left_obj The TimeHandler object on the left-hand side of the operator.
     * @param right_obj The TimeHandler object on the right-hand side of the operator.
     * @return `true` if `left_obj` is greater than or equal to `right_obj`, `false` otherwise.
     */
    friend bool operator>=(const TimeHandler& left_obj, const TimeHandler& right_obj);

    /**
     * @brief Checks if two TimeHandler objects represent the same time.
     *
     * Determines if the time represented by `left_obj` is exactly the same as the time
     * represented by `right_obj`.
     *
     * @param left_obj The TimeHandler object on the left-hand side of the operator.
     * @param right_obj The TimeHandler object on the right-hand side of the operator.
     * @return `true` if both objects represent the same time, `false` otherwise.
     */
    friend bool operator==(const TimeHandler& left_obj, const TimeHandler& right_obj);

    /**
     * @brief Checks if two TimeHandler objects represent different times.
     *
     * Determines if the time represented by `left_obj` is different from the time
     * represented by `right_obj`.
     *
     * @param left_obj The TimeHandler object on the left-hand side of the operator.
     * @param right_obj The TimeHandler object on the right-hand side of the operator.
     * @return `true` if the objects represent different times, `false` otherwise.
     */
    friend bool operator!=(const TimeHandler& left_obj, const TimeHandler& right_obj);

  private:  // Data members
    uint16_t hours_;
    uint16_t minutes_;
    uint16_t seconds_;

  private:  // Methods
    std::string format_time(const uint16_t time_val) const;
    TimeHandler subtract_seconds(const uint64_t seconds_to_subtract) const;
    TimeHandler add_seconds(const uint64_t seconds_to_add) const;
    TimeHandler convert_seconds_to_time(const uint64_t seconds_to_format) const;
};

}  // namespace library

}  // namespace saab

#endif  // SAAB_LIBRARY_TIME