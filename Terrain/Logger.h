/* 
 * File:   Log.h
 * Author: Md Imran Hasan
 *
 * Created on June 2, 2012, 3:36 AM
 */

#ifndef LOG_H
#define	LOG_H
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Logger {
public:

    Logger() {

    }

    void pr(char* str) {
        printf("%s", str);
    }

    void pr(int i) {
        printf("%d", i);
    }

    void pr(double d) {
        printf("%lf", d);
    }

    void pr(string str) {
        cout << str;
    }

    void prl() {
        printf("\n");
    }

    void prl(char* str) {
        printf("%s\n", str);
    }

    void prl(int i) {
        printf("%d\n", i);
    }

    void prl(double d) {
        printf("%lf\n", d);
    }

    void prl(string str) {
        cout << str << endl;
    }

    void prs(char* str) {
        printf("%s ", str);
    }

    void prs(int i) {
        printf("%d ", i);
    }

    void prs(double d) {
        printf("%lf ", d);
    }

    void prs(string str) {
        cout << str << " ";
    }
private:

};

#endif	/* LOG_H */

