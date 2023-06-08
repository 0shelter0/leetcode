/**
 * ref: https://shentuzhigang.blog.csdn.net/article/details/90726422
 * ACM/OI中C++常用优化(实用/调试/技巧)代码(语法)
 * date: 9.26
*/

#include<bits/stdc++.h> //1.万能头文件
#include<ctime>
// #include<iostream>
using namespace std;

#define DEBUG //2.条件编译：替换、选择性编译

typedef long long ll;
// 宏编译
// #define long long ll

//快速输入输出函数 减少输入输出的时间
template <class T>
inline void scan_d(T &ret) 
{
    char c; 
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    { 
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

// 常量
const int N=1000+10;
const int M=100000+10;
const int MOD=1e9+7;
const double PI = acos(-1.0);
const double EXP = 1E-8;
const int INF = 0x3f3f3f3f;

int main(){
    // 第一句话是解除ios与stdio之间的同步关系。第二句话是解除cin与cout之间的绑定
    /**
     * cin、cout运作速度缓慢的原因有一部分是因为需要和stdin、stdout数据流进行同步。
     * 但是如果cin、cout和scanf、printf混用，会造成不可预知的后果。cin和cout原本是绑定在一起，解除绑定后可以提速。
    */
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    #ifdef DEBUG
	    // 3.输入输出重定向：减少DEBUG中繁琐的复制/粘贴/输入操作
        // echo "2222" > input.in 
        freopen("input.in", "r", stdin);
	    //freopen("output.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    cout << n << endl;

    // 4. 计算程序运行时间 clock 输出程序启动到调用clock()之间的时间，CLOCKS_PER_SEC 它用来表示一秒钟会有多少个时钟计时单元
    // ref: https://www.cnblogs.com/didiaodidiao/p/9194702.html
    #ifdef DEBUG
	    printf("Time cost : %lf s\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
    //对于一些频繁使用的变量，可以声明时加上该关键字，运行时可能会把该变量放到CPU寄存器中，
    // 只是可能，因为寄存器的空间是有限的，不保证有效。特别是你变量多的时候，一般还是丢到内存里面的。
    clock_t start, end;
    start = clock();
    register int a = 0;
    for(register int i = 0; i < 9999999; i ++) a++;
    end = clock();
    cout << "runtime is: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    // 5. lowbit 函数用来取一个二进制最低位的1与后边的0组成的数
    int y = 8;
    int z = y&(-y);
    cout << z << '\n';

    //6. 2 的幂判断
    int x = 16;
    bool is2Power = x > 0 ? (x & (x - 1)) == 0 : false;
    cout << is2Power << endl;

    //7. memset和memcpy以及memmove 函数效率都非常高，比循环的速度快很多
    int arr[100];
    int arr2[100] = {2};
    int l = 0, r = 99;
    memset(arr+l,0,(r-l+1)*sizeof(arr[0])); //or: memset(arr+l, 0, (r-l+1)<<2);
    memcpy(arr+l,arr2+l,(r-l+1)*sizeof(arr[0]));
    
    for(int i=l;l<=r;++i) arr[i]=arr2[i],arr2[i]=0; //等价于 memmove
    memmove(arr+l, arr2+l, r-l+1<<2); // 算术大于移位优先级

    // 8. "yes" 和 "no" 的输出
    bool ans = true;
    cout << (ans ? "yes" : "no") << '/n';
   
   // 9. 输出空格分隔、末尾无空格的数组
    n = 100;
    for(int i=0;i<n;i++){
        printf("%d%c",arr[i]," \n"[i == n-1]); // 字符数组[下标] 
    }


    cout << "Hello world!" << endl;
    return 0;
 
}