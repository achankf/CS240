#include "a04q2c.h"

std::string set_color(Color foreground, Color background) {
    char num_s[3];
    std::string s = "\033[";
    if (!foreground && ! background) s += "0"; // reset colors if no params
    if (foreground) {
				sprintf(num_s, "%d", 29+foreground);
        s += num_s;
        if (background) s += ";";
    }
    if (background) {
				sprintf(num_s, "%d", 39+background);
        s += num_s;
    }
    return s + "m";
}
