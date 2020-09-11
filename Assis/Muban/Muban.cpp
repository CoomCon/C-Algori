#include <iostream>
#include <heapapi.h>
#include <cmath>
#include <vector>
using namespace std;

//函数模板

// template <typename T>
// int compare(const T &a,const T &b)
// {
//     if(a<b)
//         return -1;
//     if(b<a)
//         return 1;
//     return 0;
// }

//模板类型参数
// template <typename T>
// T foo(const T &p)
// {
//     T tmp = p;
//     return ++tmp;
// }
// int main()
// {
//     //cout << compare("1.9", "2.1") << endl;
//     cout << foo(1) << endl;
//     cout << foo(1.0) << endl;
//     cout << foo(1.0) << endl;
//     return 0;
// }

//类模板
template <typename T>
class Pairr
{
    private:
        T n;
    public:
        Pairr() { n = 0; }
        Pairr(T k) { n = k; }
        ~Pairr(){}


        void setn(const T &k){n = k;}
        T getn() { return n; }
};
template <typename T>
class StackMy
{
    private:
        vector<T> e;
    public:
        void push_back(const T& );
        void pop_back();
        T front() { return e.back(); }
};

template <typename T>
void StackMy<T>::push_back(const T& t)
{
    e.push_back(t);
}

template <typename T>
void StackMy<T>::pop_back()
{
    if(e.empty())
        return;
    e.pop_back();
}

//

// template <typename T>
// void Pairr<T>::setn(const T &n)
// {n = k;}

int main()
{
    StackMy<int> da;
    da.push_back(1);
    cout << da.front() << endl;
    da.push_back(2);
    cout << da.front() << endl;
    da.pop_back();
    cout << da.front() << endl;


    StackMy<string> das;
    das.push_back("2312");
    cout << das.front() << endl;
    das.push_back("456654");
    cout << das.front() << endl;
    das.pop_back();
    cout << das.front() << endl;


    Pairr<int> a(2);
    cout << a.getn() << endl;
    a.setn(4);
    cout << a.getn() << endl;
    return 0;
}


/*
int dun(int a,int b)
{
    return a + b;
}
int dun(int a)
{
    return a + a;
}
int main()
{
    int mnk;
    cin>>mnk;
    int m=2, n=2, k=2;
    if(mnk==1)
        cout << 2 << endl;
    if(mnk==2)
        cout << 3 << endl;
    if(mnk==3)
        cout << 5 << endl;
    int index;
    int mo;
    for (int i = 1; i <= mnk;i++)
    {
        int tm = pow(3, i);
        if(mnk >= tm && mnk <= pow(3,i+1))
        {
            index = i;
            mo = mnk - tm;
            break;
        }
    }

    //index代表了几位数



    int a = 3, b = 7;
    cout << dun(3,5) << endl;
    cout << dun(a, b) << endl;
    return 0;

}*/

