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
#include <string>
#include <vector>

using namespace std;

template<typename T>
void printl(const T &item) {
    std::cout << item << std::endl;
}

template<typename T>
auto get_value(const std::string &message) -> T {
    std::cout << message;
    T value;
    std::cin >> value;
    cin.ignore();
    return value;
}

string humanize_integer(const unsigned long int integer_value) {
    string integer_as_string = to_string(integer_value);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = integer_as_string.length() - 3; j > 0; j -= 3) {
        integer_as_string.insert(j, ",");
    }
    return integer_as_string;
}

int main() {
    constexpr int SECONDS_PER_DAY = 86400;
    constexpr int SECONDS_PER_HOUR = 3600;
    constexpr int SECONDS_PER_MINUTE = 60;

beginning:
    const auto input_in_seconds = get_value<unsigned long int>("Enter a number of seconds: ");
    if (input_in_seconds <= 0) {
        printl("You must enter a number greater than zero. Try again please.");
        goto beginning;
    }

    // Improved Main Core Calculations, after refactoring:
    const unsigned long int days_amount = input_in_seconds / SECONDS_PER_DAY;
    const int hours_amount = (input_in_seconds % SECONDS_PER_DAY) / SECONDS_PER_HOUR;
    const int minutes_amount = ((input_in_seconds % SECONDS_PER_DAY) % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
    const int seconds_amount = ((input_in_seconds % SECONDS_PER_DAY) % SECONDS_PER_HOUR) % SECONDS_PER_MINUTE;

    // Now we store the values as English composed strings, into a vector (if needed) while pluralizing (also if needed):
    std::vector<string> composed_values;
    if (days_amount != 0)
        composed_values.push_back(humanize_integer(days_amount) + " day" + (days_amount == 1 ? "" : "s"));
    if (hours_amount != 0)
        composed_values.push_back(to_string(hours_amount) + " hour" + (hours_amount == 1 ? "" : "s"));
    if (minutes_amount != 0)
        composed_values.push_back(to_string(minutes_amount) + " minute" + (minutes_amount == 1 ? "" : "s"));
    if (seconds_amount != 0)
        composed_values.push_back(to_string(seconds_amount) + " second" + (seconds_amount == 1 ? "" : "s"));

    string composed_conversion;
    for (int i = 0; i < composed_values.size(); i += 1) {
        const string composed_value = composed_values[i];
        if (composed_values.size() == 1) {
            // The vector has only 1 item
            composed_conversion += composed_value + ".";
        } else {
            // The vector has more than 1 item
            if (i == 0) {
                // First item of the vector
                composed_conversion += composed_value;
            } else {
                // Not the first item of the vector
                if (i == composed_values.size() - 1) {
                    // The last item of the vector
                    composed_conversion += ", and " + composed_value + ".";
                } else {
                    // Not the last item, nor the first one either (it's an item in between)
                    composed_conversion += ", " + composed_value;
                }
            }
        }
    }

    const string composed_answer = (input_in_seconds == 1 ? "That second is " : "Those " + humanize_integer(input_in_seconds) + " seconds are ") + "equivalent to: " + composed_conversion;
    printl(composed_answer);

    return 0;
}
