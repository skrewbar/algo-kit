#include <bits/stdc++.h>
using namespace std;

struct PolynomialFunc {
    vector<double> coefficients;

    PolynomialFunc(const vector<double>& coefficient)
        : coefficients(coefficient) {}

    double operator()(double x) {
        double ret = 0;
        double powerOfX = 1;
        for (double coeff : coefficients) {
            ret += coeff * powerOfX;
            powerOfX *= x;
        }
        return ret;
    }

    double integral(int a, int b) {
        vector<double> coeffs(coefficients.size() + 1);
        for (int i = 1; i < (int)coeffs.size(); i++)
            coeffs[i] = coefficients[i - 1] / i;

        PolynomialFunc F(coeffs);
        return F(b) - F(a);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    vector<double> coeffs(k + 1);
    for (int i = (int)coeffs.size() - 1; i >= 0; i--)
        cin >> coeffs[i];

    int a, b, n;
    cin >> a >> b >> n;

    PolynomialFunc f(coeffs);

    double integral = f.integral(a, b);

    double dx = (b - a) / (double)n;
    double lo = 0;
    double hi = dx;

    auto discreteIntegral = [&](double eps) {
        double ret = 0;
        for (int k = 0; k < n; k++)
            ret += f(a + k * dx + eps) * dx;
        return ret;
    };

    if (integral < discreteIntegral(lo) or discreteIntegral(hi) < integral) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < (int)1e6; i++) {
        double eps = (lo + hi) / 2;

        if (discreteIntegral(eps) > integral)
            hi = eps;
        else
            lo = eps;
    }

    cout << (lo + hi) / 2;

    return 0;
}