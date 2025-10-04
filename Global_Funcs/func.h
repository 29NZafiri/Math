#ifndef FUNC_H
#define FUNC_H

double f(const double* coef, const int cnt, const double x);
double intf(const int* coef, const int cnt, const double x);
void promptfunc(double* coefs, const int cnt);
double* synthdiv(const double* coefs, const int cnt, const double a, const double b);

#endif //FUNC_H
