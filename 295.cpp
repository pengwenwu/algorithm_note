#include <cstdio>
struct node{
	typename data;
	node* lchild;
	node* rchild;
};
//先序序列[preL, preR] , //中序序列[inL, inR] 
node* create(int preL,int preR ,int inL, int inR){
	if(preL > preR) return NULL;
	node* root=new node;
	root->data = pre[preL];
	int k;
	for(k=inL; k<=inR; k++){
		if(pre[preL] == in[k]) break;
	}
	int numberLeft = k-inL;
	
	//此时， 左子树的先序区间是[preL+1, preL+numberLeft];中序区间[inL, k-1]
	root->lchild = create(preL+1, preL+numberLeft,inL, k-1);
	root->rchild = create(preL+numberLeft+1,preR, k+1,inR);
	return root;
	 
}

 