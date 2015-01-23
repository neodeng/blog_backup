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
当然LIS问题只是DP类问题的初级例子，还有很多更高维度更复杂的问题也是运用DP的解法思想来解决的。
