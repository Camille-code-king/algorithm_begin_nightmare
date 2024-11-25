#include<iostream>
#include<limits>
using namespace std;
//加法运算
int sum(int a, int b) {
    while (b) {
        int carry = a & b;
        a = a ^ b;
        b = (carry << 1);
    }
    return a;
}
//取相反数
int anti(int num) {
    return sum(~num, 1);
}
//减法（在加法的基础上完成）
int diff(int a, int b) {
    return sum(a, anti(b));
}
//基础版除法运算（不包括整数最小值）
int divs(int a, int b) {
    int x = a > 0 ? a : anti(a);
    int y = b > 0 ? b : anti(b);
    int ans = 0;
    for (int i = 30; i >= 0; i = diff(i, 1)) {
        if ((x >> i) >= y) {
            x = diff(x, (y << i));
            ans |= (1 << i);
        }
    }
    return (a ^ b) < 0 ? anti(ans) : ans;
}
//乘法运算
int timev(int a, int b) {
    int ans = 0;
    while (b) {
        if (b & 1) {
            ans = sum(ans, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return ans;
}
//包括最小整数的出发运算（完整版除法）
int divide(int a, int b) {
    if (a == INT_MIN && b == INT_MIN)return 1;
    if (b == INT_MIN)return 0;
    if (a == INT_MIN) {
        if (b == -1)return INT_MAX;
        return b > 0 ? diff(divs(sum(a, b), b), 1) : sum(divs(diff(a, b), b), 1);
    }
    return divs(a, b);
}
int main() {
    int a = 10;
    int b = 3;
    cout << timev(a, b) << endl;//乘法；
    cout << divide(a, b) << endl;//除法
    cout << sum(a, b) << endl;//加法
    cout << diff(a, b) << endl;//减法
    return 0;
}
