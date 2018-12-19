/*
 剑指offer面试题第三题数组中重复的数字,数组长度为n,元素只能为0～n-1之间的数字
 这是第二个循环终止的条件
 */

#include<iostream>
#include<unordered_map>
using namespace std;

/*时间复杂度o(n),空间复杂度o(n)，哈希表
 * unordered_map内部实现了一个哈希表
 *（也叫散列表，通过把关键码值映射到Hash表中一个位置来访问记录，查找的
 * 时间复杂度可达到O(1)，其在海量数据处理中有着广泛应用）。因此，其元素
 * 的排列顺序是无序的*/
bool duplicate1(int a[],int length)
{
    if(a==NULL||length<=0)return false;
    unordered_map<int,int>hash;
    for(int i=0;i!=length;i++)
    {
        hash[a[i]]++;
        if(hash[a[i]]>1)
            return true;
    }
    return false;
}
/**
 时间复杂度o（n），空间复杂度o(1)*/
bool duplicate2(int a[],int length)
{
    if(a==NULL||length<0)return false;
    for(int i=0;i!=length;i++)
    {
        while(a[i]!=i)
        {
            if(a[i]==a[a[i]])
                return true;
            int tmp=a[i];
            a[i]=a[tmp];
            a[tmp]=tmp;
        }
    }
    return false;
}
int main()
{
    int a[5]={1,2,3,4,0};
    int a1[5]={0,1,2,3,4};
    int a2[5]={0,0,1,2,3};
    cout<<duplicate1(a,5)<<endl;
    cout<<duplicate1(a1,5)<<endl;
    cout<<duplicate1(a2,5)<<endl;
    cout<<duplicate2(a,5)<<endl;
    cout<<duplicate2(a1,5)<<endl;
    cout<<duplicate2(a2,5)<<endl;
    return 0;
}