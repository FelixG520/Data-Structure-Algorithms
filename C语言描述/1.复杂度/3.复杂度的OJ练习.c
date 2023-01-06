#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//1.
//leetcode 面试题 17.04. 消失的数字

/*
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那
个确实的整数。你有办法在O(n)时间内完成吗？
示例1：
输入：[3,0,1]
输出：2

示例2：
输入：[9,6,4,2,3,5,7,0,1]
输出：8
*/

/*
思路1：排序->快速排序->时间复杂度O（n* log2N）
思路2：(0+1+2+3+...+n)-(a[0]+a[1]+a[2]+...+a[n-1]) -> 时间复杂度O(N) 空间复杂度O(1)
思路3：数组中是几就在第几个位置写一下这个值 -> 空间复杂度O(N) 时间复杂度O(N)
思路4：给一个值x=0，x先跟[0,n]的所有值异或，x再跟数组中每个值异或，最后x就是缺的那个数字
       时间复杂度O(N)  空间复杂度O(1)
*/

//int missingNumber(int* nums, int numsSize) {
//    //异或
//    int ret = 0;
//    //先异或0-n的所有数  
//    for (int i = 0; i <= numsSize; ++i) {
//        ret ^= i;//0^1^2^3^4^5^6^7^8^9
//    }
//    //再将ret与数组所有数异或
//    for (int i = 0; i < numsSize; ++i) {
//        ret ^= nums[i];//(0^1^2^3^4^5^6^7^8^9)^0^1^2^3^4^5^6^7^9=8
//    }
//    return ret;
//}

//1.
//leetcode 189.旋转数组
/*给定一个数组将数组中的元素向右移动K个位置其中K是非负数
尽可能想出更多的解决方案至少有3种不同的方案可以解决这个问题
你可以使用空间复杂度为O(1)的圆的算法 解决这个问题吗?
*/

/*示例1：
输入：nums = [1,2,3,4,5,6,7],k = 3
输出：[5,6,7,1,2,3,4]
解释：
向右旋转1步：[7,1,2,3,4,5,6]
向右旋转2步：[6,7,1,2,3,4,5]
向右旋转3步：[5,6,7,1,2,3,4]
*/

/*
思路1：暴力求解，旋转k次，时间复杂度：O(n*k)     空间复杂度：O(1)
思路2：开辟额外空间，以空间换时间，把后k个元素放进临时数组，再把剩下的n-k个数追加到临时数组
       最后把元素拷贝到原数组。时间复杂度：O(n)   空间复杂度：O(n)
思路3：前n-k个逆置，后k个逆置，整体逆置  时间复杂度：O(2n)     空间复杂度：O(1)
*/

//void Reverse(int* nums, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp=nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        ++left;
//        --right;
//
//    }
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k >= numsSize)
//        k %= numsSize;//k=numsSize时，k%numsSize=0，不旋转
//    //前n-k个数逆置
//    Reverse(nums, 0, numsSize - k - 1);
//    //后k个逆置
//    Reverse(nums, numsSize - k,numsSize - 1);
//    //整体逆置
//    Reverse(nums, 0, numsSize - 1);
//}