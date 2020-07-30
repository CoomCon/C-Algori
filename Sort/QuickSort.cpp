#include <iostream>
#include <vector>
using namespace std;
// void quickSort(int s[], int l, int r);
void swapd(int &a,int &b) //拷贝和指针 引用
{
	int temp= a;
	a = b;
	b = temp;
}
void quickSort(int arr[], int low, int high); //访问数组都是访问 不是拷贝
void quickSortv(vector<int> &ss, int low, int high)
{
	if (high <= low) return;
    int i = low;
    int j = high+1 ;
    int key = ss[low];//基准为low
    while (true)
    {
        /*从左向右找比key大的值*/
        while (ss[++i] < key)
        {
            if (i == high){
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (ss[--j] > key)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
		int temp = ss[i];
		ss[i] = ss[j];
		ss[j] = temp;
		//swapd(ss[i], ss[j]);
	}
    /*中枢值与j对应值交换*/
	//swapd(ss[low], ss[j]);
	int temp = ss[low];
	ss[low] = ss[j];
	ss[j] = temp;

    quickSortv(ss, low, j - 1);
    quickSortv(ss, j + 1, high);
}

int main()
{
	int s[] = {1, 23, 4, 5, 67, 8, 9, 32134, 13, 2, 312, 24};
	vector<int> ss = {1, 23, 4, 5, 67, 8, 9, 32134, 13, 2, 312, 24};
	quickSort(s, 0, 11);
    quickSortv(ss, 0, 11);
	for (int i = 0; i < 12;i++)
	{
		cout << s[i]<<" ";
	}
	cout << endl;
}
void quickSort(int arr[], int low, int high)
{
	if (high <= low) return;
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[++i] < key)
        {
            if (i == high){
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[--j] > key)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    quickSort(arr, low, j - 1);
    quickSort(arr, j + 1, high);
	// if (l< r)
	// {      
	// 	int i = l, j = r, x = s[l];
	// 	while (i < j)
	// 	{
	// 		while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
	// 			j--; 
	// 		if(i < j)
	// 			s[i++] = s[j];
	// 		while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
	// 			i++; 
	// 		if(i < j)
	// 			s[j--] = s[i];
	// 	}
	// 	s[i] = x;
	// 	quickSort(s, l, i - 1); // 递归调用
	// 	quickSort(s, i + 1, r);
	// }
}