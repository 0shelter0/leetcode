// 快速幂取模的应用 以及 求斐波那契数列第n项
#include<bits/stdc++.h>

using namespace std;

#define DEBUG
typedef long long ll;
const int MOD = 1e9+7;

// 快速幂算法 a^b
int qpow(int a, int b){
    int ans = 1;
    while(b>0){
        if(b&1) // b 为奇数
            ans *= a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

// 泛型的非递归快速幂
template <typename T>
T qpow(T a, ll n){
    T ans = 1; // 乘法单元
    while (n)
    {
        if(n&1)
            ans =  ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}


// 非递归 位运算 实现 快速幂算法 a^b % MOD
// 整体取模 = 步步取模
int PowerMod(int a, int b, int c = MOD){
    int ans = 1;
    a = a % c;
    while(b > 0){
        if(b&1)
            ans = ans * a % c;
        b >>= 1;
        a = a * a % c;
    }
    return ans;
}

// 求斐波那契数列第n项的模，即：F_n mod (1e9+7)
// 定义矩阵结构体
struct matrix{
    ll a1, a2, b1, b2;
    matrix(ll x1, ll x2, ll y1, ll y2) : a1(x1), a2(x2), b1(y1), b2(y2) {}
    // 重载 * 运算符
    matrix operator*(const matrix& y){
        matrix ans(
            (a1*y.a1 + a2*y.b1) % MOD,
            (a1*y.a2 + a2*y.b2) % MOD,
            (b1*y.a1 + b2*y.b1) % MOD,
            (b1*y.a2 + b2*y.b2) % MOD 
        );
        return ans;
    }
};

// 计算矩阵 a 的 n 次幂
matrix qpow(matrix a, ll n){
    matrix ans(1, 0, 0, 1); // identity matrix
    while(n){
        if(n & 1)
            ans = ans * a;
        n >>= 1;
        a = a * a;
    }
    return ans;
}

int main(){
    #ifdef DEBUG
        freopen("input.in", "r", stdin);
    #endif
    // 2^10
    int res = qpow(2, 10);
    cout << res << '\n';

    // 求斐波那契数列第n项的模，即：F_n mod (1e9+7)
    ll x;
    cin >> x;
    matrix a(0, 1, 1, 1);
    matrix ans = qpow(a, x -1);
    cout << (ans.a1 + ans.a2) % MOD << '\n';
    
    int bb = (1+2, 2+3); // , 运算符 小于 = 运算符的优先级
    cout << bb << endl;
    return 0;
}