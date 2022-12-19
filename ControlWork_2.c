#include <stdio.h>

int Calc(char *exp) {
    if (exp[0] == 'x') {
        if (exp[1] == '=') {
            return (exp[3] == '+' ? (exp[2] - '0') + (exp[4] - '0') :
                    exp[3] == '-' ? (exp[2] - '0') - (exp[4] - '0') :
                    exp[3] == '*' ? (exp[2] - '0') * (exp[4] - '0') :
                    exp[3] == '/' ? (exp[2] - '0') / (exp[4] - '0') : 0);
        } else {
            return (exp[1] == '+' ? (exp[4] - '0') - (exp[2] - '0') :
                    exp[1] == '-' ? (exp[4] - '0') + (exp[2] - '0') :
                    exp[1] == '*' ? (exp[4] - '0') / (exp[2] - '0') :
                    exp[1] == '/' ? (exp[4] - '0') * (exp[2] - '0') : 0);
        }
    }
    if (exp[2] == 'x') {
        if (exp[1] == '=') {
            return (exp[3] == '+' && (exp[0] - '0') > (exp[4] - '0') ? (exp[0] - '0') - (exp[4] - '0') :
                    exp[3] == '+' && (exp[0] - '0') < (exp[4] - '0') ? (exp[4] - '0') - (exp[0] - '0') :
                    exp[3] == '-' ? (exp[0] - '0') + (exp[4] - '0') :
                    exp[3] == '*' ? (exp[0] - '0') / (exp[4] - '0') :
                    exp[3] == '/' ? (exp[0] - '0') * (exp[4] - '0') : 0);
        } else {
            return (exp[1] == '+' ? (exp[4] - '0') - (exp[0] - '0') :
                    exp[1] == '-' ? (exp[0] - '0') - (exp[4] - '0') :
                    exp[1] == '*' ? (exp[4] - '0') / (exp[0] - '0') :
                    exp[1] == '/' ? (exp[0] - '0') / (exp[4] - '0') : 0);
        }
    } else {
        if (exp[1] == '=') {
            return (exp[3] == '+' ? (exp[0] - '0') - (exp[4] - '0') :
                    exp[3] == '-' ? (exp[0] - '0') + (exp[4] - '0') :
                    exp[3] == '*' ? (exp[0] - '0') / (exp[4] - '0') :
                    exp[3] == '/' ? (exp[0] - '0') * (exp[4] - '0') : 0);
        } else {
            return (exp[1] == '+' ? (exp[0] - '0') + (exp[2] - '0') :
                    exp[1] == '-' ? (exp[0] - '0') - (exp[2] - '0') :
                    exp[1] == '*' ? (exp[0] - '0') * (exp[2] - '0') :
                    exp[1] == '/' ? (exp[0] - '0') / (exp[2] - '0') : 0);
        }
    }
}

int main() {
    char *expression[] = {"2+x=5", "x+2=5", "2/x=2", "x-5=2",
                          "5-x=2", "x=5*2", "x*5=5", "9*9=x",
                          "x=7/3", "x/2=5", "5/x=5", "6=x/3",
                          "2*x=8", "x/2=7", "9*4=x", "x-7=0",
                          "3*x=9", "x=5*2", "x*5=5", "6*3=x",
                          "x=4-4", "x/9=5", "9/x=2", "8=x/3"};
    int len = sizeof(expression) / sizeof(char *);
    for (int i = 0; i < len; i++) {
        printf("%s x=%d\n", expression[i], Calc(expression[i]));
    }
}
