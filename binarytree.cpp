//BinNote类
#define BinNodePosi(T) BinNode<T>* //节点位置
template <tupename T> struct BinNode{
	BinNodePosi(T) parent, lChild, rChild; //父亲，孩子
	T data; int height; int size(); //高度、子树规模
	BinNodePosi(T) insertAsLC( T const & ); //作为左孩子插入新节点
	BinNodePosi(T) insertAsRC( T const & ); //作为右孩子插入新节点
	BinNodePosi(T) succ(); //(中序遍历意义下)当前节点的直接后继
	template <typename VST> void traveLevel( VST & ); //子树层次遍历
	template <typename VST> void travePre( VST & ); //子树先序遍历
	template <typename VST> void traveIn( VST & ); //子树中序遍历
	template <typename VST> void travePost( VST & ); //子树后序遍历
}

//BinNote接口
template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const & e)
	{ return lChild = new BinNode( e, this); }
template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const & e)
	{ return rChild = new BinNode( e, this); }
template <typename T>
int BinNode<T>::size() { //后代总数，亦即以其为根的子树规模
	int s = 1; //计入本身
	if (lChild) s += lChild->size(); //递归计入左子树规模
	if (rChild) s += rChild->size(); //递归计入右子树规模

	return s;
} //O(n = |size|)

//BinTree类
template<template T> class BinTree{
protected:
	int _size; //规模
	BinNodePosi(T) _root; //根节点
	virtual int updateHeight( BinNodePosi(T) x ); //更新节点x的高度
	void updateHeightAbove( BinNodePosi(T) x); //更新x及祖先的高度
public:
	int size() const { return _size; } //规模
	bool empty() const {return !_root; } //判空
	BinNodePosi(T) root() const {return _root;} //树根
	/*...子树接入、删除和分离接口...*/
	/*...遍历接口...*/
}

//高度更新
#define stature(p) ( (p) ? (p)->height:-1) //节点高度————约定空树高度为-1
template<typename T> //更新节点x高度，具体规则因树不同而异
int BinTree<T>::updateHeight(BinNodePosi(T) x){
	return x->height=1+
	max(stature(x->lChild), stature(x->rChild));
} //此处采用常规二叉树规则， O(1)
template <typename T> //更新V及其历代祖先的高度
void BinTree<T>::updateHeightAbove( BinNodePosi(T) x){
	while (x) //可视化：一旦高度未变，即可终止
		{updateHeight(x);x=x->parent;}
} //O( n= depth(x) )

template<typename T> BinNodePosi(T)
BinTree<T>::insertAsRC(BinNodePosi(T) x, T const & e){ //insertAsLC(对称)
	_size++; x->insertAsRC(e); //x祖先的高度可能增加，其余节点比如不变
	updateHeightAbove(x);
}