#include <iostream>
#include <string>

using namespace std;

string proces(string temp);
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        string temp;
        cin >> temp;
        cout << proces(temp) << endl;
    }
    system("pause");
}

string proces(string temp)
{
    string res;
    for (int i = 0; i < temp.size();i++)
    {
        if(temp[i]==temp[i+1]&&(i+1<temp.size())) //AA
        {
            if(temp[i]==temp[i+2]&&(i+2<temp.size())) //3 AAA
            {
                res = temp.erase(i + 2, 1); //从位置i+2处删除，删除1个字
                i--;
            }
            else if(temp[i+2]==temp[i+3]&&(i+3<temp.size())) //AA BB
            {
                res = temp.erase(i + 3, 1);
                i--;
            }
           
        }
    }
    return res;
}