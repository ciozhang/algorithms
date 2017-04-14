template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi){ //[lo,hi)
	if(hi-lo<2)return; //单元素区间自然有序，否则。。。
	int mi=(lo+hi)>>1; //以中心为界
	mergesort(lo,mi); //对前半段排序
	mergesort(mi,hi); //对后半段排序
	merge(lo,mi,hi); //归并
}

template<typename T> void Vector<T>::mergeSort(Rank lo, Rank mi, Rank hi){
	T*A=_elem + lo; //合并后的向量A[0,hi-l)=_elem[lo,mi)
	int lb=mi-lo;T*B=new T[lb]; //前子向量B[0,lb)=_elem[lo,mi)
	for (Rank i=0; i<lb; B[i]=A[i++]); //复制前子向量B
	int lc = hi - mi; T*C = _elem + mi; //后子向量C[o,lc) = _elem[mi,hi)
	for (Rank i =0, j = 0, k=0;(j < lb)||(k<lc);){
		if((j < lb) && (lc <= k || (B[j] <= C[k]))) A[i++] = B[j++]; //C[k]已无或不小
		if((k < lc) && (lb <= j || (C[k] < B[j]))) A[i++] = C[k++]; //B[j]已无或更大
	} //该循环实现紧凑；但就效率而言，不如拆分处理
	delete [] B; //释放临时空间B
}