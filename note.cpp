void reverse(int* A, int lo, int hi){ //数组倒置
	if (lo<hi){
		swap(A[lo], A[hi]); //交换A[lo]和A[hi]            //O(1)
		resverse(A, lo+1, hi-1); //递归倒置A(lo, hi)      //O(n)
	}
} //执行了n次循环，每次时间复杂度为O(1),所以算法时间复杂度为O(n)


void F(int n){
	for (int i = 0;i<n;i++)         //n次
		for (int j=1;j<2013;j<<=1); //常数项O(1)
} //O(n)



void F(int n){
	for (int i = 0;i<n;i++)         //n次
		for (int j=1;j<2013;j<<=1); //n次
} //O(n^2)


void F(int n){
	for (int i = 0;i<n;i++)         //n次
		for (int j=1;j<2013;j<<=1); //2^t=n => t=log n
} O(nlog n)

// 主定理 T(n) = 2T(n/2)+cn
// => O(nlogn)