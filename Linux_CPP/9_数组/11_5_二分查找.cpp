#include <iostream>

// qsort回调函数 从小到大
int comp(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

// 二分查找算法
int find_num(int array[], int len, int aim)
{
    int low = 0;
    int high = len - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] == aim)
        {
            return array[mid];
        }
        if (mid < aim)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1; // 查找失败
}

int main()
{
    int array[] = {2, 1, 4, 3, 5, 7, 6, 8, 9};
    qsort(array, sizeof(array) / sizeof(int), sizeof(int), comp);
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
    std::cout << "find num is " << find_num(array, sizeof(array) / sizeof(int), 5) << std::endl;
    return 0;
}