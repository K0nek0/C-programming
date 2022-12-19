#include <stdio.h>
#include <math.h>
#include <string.h>

double polynom(const char* expr, double x) {
    double y = 0;
    int j = 0, flag = 0, flag_minus = 0, buffer = 0, arg = 1;
    int len = strlen(expr);
    for (int i = 0; expr[i] != 0; i++) {
        flag_minus += (expr[i] == '-') ? 1 : 0;
        if ((((expr[i] != ' ') && (expr[i] != '-') && (expr[i] != '+')) &&
             ((expr[i - 1] == ' ') || (expr[i - 1] == '-') || (expr[i - 1] == '+')))) {
            j = i, flag = 1;
        }
        if ((flag == 1) && (((expr[i + 1] == ' ') || (expr[i + 1] == '-') || (expr[i + 1] == '+')) || (i + 1 == len))) {
            flag = 0;
            while (j <= i) {
                double x1 = x;
                if (expr[j] == '*') {
                    arg = buffer;
                }
                if (expr[j] == 'x') {
                    if (expr[j + 1] == '^') {
                        x1 = pow(x, expr[j + 2] - '0');
                    }
                    y += flag_minus ? x1 * arg * -1 : x1 * arg;
                    flag_minus = 0, buffer = 0, arg = 1;
                    break;
                }
                else {
                    int num = expr[j] - '0';
                    buffer = buffer * 10 + num;
                }
                j++;
            }
            y += flag_minus ? buffer * -1 : buffer;
            flag_minus = 0, buffer = 0;
        }
    }
    return y;
}


int main() {
    char* test0 = "     -x^8 -x^3+ 14";
    char* test1 = " x^5 + 15*x^4 - 3*x^3 + x^2 - 2*x + 1";
    char* test2 = "x^4 + 15*x^3 - 3*x^2 + x - 2";
    char* test3 = " -22+5*x^3 + x   ";
    char* test4 = "  -x^4 + 50";
    const char* expr = test0;
    double x = 3.14;
    printf("y(%f)=%s returns %f", x, expr, polynom(expr, x));
}