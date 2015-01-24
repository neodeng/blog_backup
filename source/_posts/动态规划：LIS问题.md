title: 动态规划：LIS问题
date: 2015-01-23 14:51:19
tags:
	算法
---
<b>动态规划问题(DP)</b><br>类似于数学中的动力系统，物理中的微分方程，每一步的求解是由上一步的解决定的，所以类似的，解决动态问题需要知道初始状态以及递推公式，在动态问题中我们把递推公式称为<b>状态转移</b>方程。
最长递增子序列长度问题(LIS:longest increasing subsequence)是DP的一个典型例子，通过这个例子可以理解DP问题的求解思想。<br>
<b>LIS问题描述：</b><br>一个数列A[0]、A[1]...A[N-1]，求出其中非递减序列的最大长度。
举例：该序列为 {4, 2, 3, 8, 5, 7},则其非递减子序列的最大长度为 3，最长非递减子序列为{2, 3, 8}。
<!--more-->
<b>问题分析:</b><br>用l[i]表示以A[i]结尾的最长子序列的长度，则初始状态为:
``` C
	l[0]=1;
```
状态转移方程为:
``` C
	l[i]=max(1, l[j] for j<i && A[j]<=A[i]);
```
最终LIS问题的解为l[N]中的最大值。
显然该算法的时间复杂度为O(N<sup>2</sup>)。
<b>code：</b>
``` C 
/* The longest increasing subsequence of {4, 2, 3, 8, 5, 7}. */
#include "stdio.h"

int MaxSubSeq(int A[], int N);

main(){
	int A[]={4, 2, 3, 8, 5, 7};
	printf("The LIS length is:%3d.\n",MaxSubSeq(A, 5));
	return 0;
}

int MaxSubSeq(int A[], int N){
	int i, j, maxlen=0;
	int l[N];
	for (i=0;i<N;i++){
		l[i]=1;
		for (j=0;j<i;j++){
			if (A[j]<=A[i] && l[i]<l[j]+1)
				l[i]=l[j]+1;
		}
		maxlen=(l[i]>maxlen)?l[i]:maxlen;
	}
	return maxlen;
}
```  
基于该算法，可以巧妙的运用二分法将时间复杂度优化为O(NlogN)，具体算法网上已有：<a href='http://www.felix021.com/blog/read.php?1587'>O(NlogN)算法</a>。<br>
当然LIS问题只是DP类问题的初级例子，还有很多更高维度更复杂的问题也是运用DP的解法思想来解决的。<br>
接下来看另外一个例子：最大连续乘积子串问题。首先需要弄清楚的是，<b>子串(SubString)</b>与上一个例子中的<b>子序列(SubSequence)</b>是不同的，子串必须连续，而子序列并不需要连续。
<b>问题描述：</b><br>给定一个浮点序列，求出最大子串乘积，例如：A[]={-2.5，4，0，3，0.5，8，-1}，其最大子串乘积为12。
<b>问题分析：</b><br>暴力解法遍历所有的子串，时间复杂度为O(N<sup>2</sup>)。动态规划的解法时间复杂度可降为O(N)。
由于序列中含有负数，所以对于第i的状态，要同时考虑以i-1结尾的子串乘积的最大值和最小值。
由于我们这里考虑的是子串而不是子序列，所以不需要用专门的表格来记录以A[i]结尾的最大和最小值，从而减少不必要的空间调用。
初始状态：
``` C
	maxend=minend=A[0];
```
状态转移方程为：
``` C
	maxend of A[i]=max(maxend of A[i-1]*A[i],minend of A[i-1]*A[i],A[i]);
	minend of A[i]=min(maxend of A[i-1]*A[i],minend of A[i-1]*A[i],A[i]);
```
最终给出maxend的最大值，即为问题的解。
<b>code：</b>
```
/* Solution of max substring production. A[]={-2.5，4，0，3，0.5，8，-1}*/
#include "stdio.h"

double MaxSubString(double A[], int N);
double Max(double a, double b);
double Min(double a, double b);

main(){
	double A[]={-2.5, 4, 0, 3, 0.5, 8, -1};
	printf("The max production of SubString is %4f.\n ", MaxSubString(A, 7));
	return 0;
}

double MaxSubString(double A[], int N){
	double maxend=A[0];
	double minend=A[0];
	double maxpro=maxend;
	int i;
	for (i=1;i<N;i++){
		maxend=Max(Max(maxend*A[i],minend*A[i]),A[i]);
		minend=Min(Min(maxend*A[i],minend*A[i]),A[i]);
		maxpro=Max(maxpro, maxend);
	}
	return maxpro;
}

double Max(double a, double b){
	return (a>b)?a:b;
}

double Min(double a, double b){
	return (a>b)?b:a;
}
```
显然只调用一次循环，时间复杂度为O(N)。
{% blockquote July http://taop.marchtea.com/ --The Art of Programming %}
一句话理解动态规划，则是枚举所有状态，然后剪枝，寻找最优状态，同时将每一次求解子问题的结果保存在一张“表格”中，以后再遇到重叠的子问题，从表格中保存的状态中查找（俗称记忆化搜索）。
{% endblockquote %}



