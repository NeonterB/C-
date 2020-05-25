#include "fraction.h"

ostream &operator<<(ostream &output, const fraction &obj) {
    if (obj.down == 1) {
        output << obj.up;
    } else {
        output << obj.up << "/" << obj.down;
    }
    return output;
}

istream &operator>>(istream &input, fraction &obj) {
    std::string line, num;
    input >> line;
    bool _switch = false;
    obj.down = 1;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '/') {
            _switch = true;
        }

        if (!_switch) {
            num += line[i];

            if (i == line.size() - 1) {
                obj.up = stoi(num);
                break;
            }

        } else {
            obj.up = stoi(num);
            num = "";
            _switch = false;
        }



        if (i == line.size() - 1) {
            obj.down = stoi(num);
            break;
        }
    }
    return input;
}

void fraction::simplify() {
    int nod = gcd(up, down);
    up /= nod;
    down /= nod;

    if (down < 0) {
        up *= -1;
        down *= -1;
    }
}

int fraction::gcd(int a, int b) {
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    if (a == b) {
        return a;
    }
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    return gcd(a, b - a);
}

fraction::fraction() : up(0), down(1) {}

fraction::fraction(int _up) : up(_up), down(1) {}

fraction::fraction(int _up, int _down) : up(_up), down(_down) {}

fraction::fraction(const fraction &other) : up(other.up), down(other.down) {}

fraction fraction::operator+(const fraction &right) {
    fraction result(0, 0);
    result.up = this->up * right.down + right.up * this->down;
    result.down = this->down * right.down;
    if (result.up == 0) {
        result.down = 1;
    } else {
        result.simplify();
    }
    return result;
}

fraction fraction::operator-(const fraction &right) {
    fraction result(0, 0);
    result.up = this->up * right.down - right.up * this->down;
    result.down = this->down * right.down;
    if (result.up == 0) {
        result.down = 1;
    } else {
        result.simplify();
    }
    return result;
}

fraction fraction::operator*(const fraction &right) {
    fraction result(0, 0);
    result.up = this->up * right.up;
    result.down = this->down * right.down;
    if (result.up == 0) {
        result.down = 1;
    } else {
        result.simplify();
    }
    return result;
}

fraction fraction::operator/(const fraction &right) {
    fraction result(0, 0);
    result.up = this->up * right.down;
    result.down = this->down * right.up;
    if (result.up == 0) {
        result.down = 1;
    } else {
        result.simplify();
    }
    return result;
}

fraction fraction::getReverse() {
    return fraction(this->down, this->up);
}

bool fraction::operator==(const fraction &right) const {
    return (this->up / this->down == right.up / right.down);
}

bool fraction::operator!=(const fraction &right) const {
    return !(*this == right);
}
