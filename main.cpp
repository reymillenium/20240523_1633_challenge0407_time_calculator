/**
* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                       *
 *       Created by: Reinier Garcia Ramos                *
 *       reymillenium@gmail.com                          *
 *                                                       *
 *       https://www.linkedin.com/in/reiniergarcia       *
 *       https://github.com/reymillenium                 *
 *       https://www.reiniergarcia.dev                   *
 *                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>  // for string, to_string, etc
#include <cmath> // for sqrt, sin, pow
#include <climits>
#include <iomanip> // for setprecision
#include<array>  // for array
#include<random> // for random_device
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <sstream> // for stringstream

using namespace std;

template<typename T>
void print(const T &item) {
    std::cout << item;
}

template<typename T>
void print_n_times(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        print(item);
    }
}

template<typename T>
void printl(const T &item) {
    std::cout << item << std::endl;
}

template<typename T>
void printl_n_times(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        printl(item);
    }
}

template<typename T>
auto get_value(const std::string &message) -> T {
    std::cout << message;
    T value;
    std::cin >> value;
    cin.ignore();
    return value;
}

string get_string_from_message(const std::string &message) {
    std::cout << message;
    string value;
    std::getline(std::cin, value);
    return value;
}

string get_string() {
    string value;
    std::getline(std::cin, value);
    return value;
}

string humanize_integer(int const integer_value) {
    string integer_as_string = to_string(integer_value);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = integer_as_string.length() - 3; j > 0; j -= 3) {
        integer_as_string.insert(j, ",");
    }
    return integer_as_string;
}

string humanize_double(const double double_value, const int precision = 2) {
    const int integer_value = static_cast<int>(double_value);
    const double decimals = double_value - integer_value;
    // Extracts into a string the decimal part, rounded to two significant digits
    std::stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << std::fixed << std::setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const std::string decimals_as_string = stream.str(); // It still includeds the zero & the dot. Ex: 0.34 (the dot must be removed next)
    return humanize_integer(integer_value) + decimals_as_string.substr(1, precision + 1);
}

string monetize_integer(const double integer_value) {
    return "$ " + humanize_integer(integer_value);
}

string monetize_double(const double double_value, const int precision = 2) {
    return "$ " + humanize_double(double_value, precision);
}

double round_up(double const value, const int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}

// class MonthlyRainLog {
// public:
//     string month_name;
//     double rain_amount;
//
//     // dummy constructor
//     MonthlyRainLog() {
//     }
//
//     // Parameterized constructor
//     MonthlyRainLog(const string &a_month_name, const double &a_rain_amount) {
//         month_name = a_month_name;
//         rain_amount = a_rain_amount;
//     }
// };

int main() {
    std::cout << "Hello, World!" << std::endl;
    const auto seconds_amount = get_value<int>("Enter a number of seconds: ");

    print("Those " + to_string(seconds_amount) + " seconds are equivalent to ");

    return 0;
}
