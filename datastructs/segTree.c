#include<stdio.h>
#include<stdlib.h>

int querylazy(int *tree, int *lazy, int node, int start, int end, int l, int r);
int updatelazy(int *tree, int *lazy, int node, int start, int end, int l, int r, int val);
void build(int *a, int *tree, int node, int start, int end);

int query(int *a, int *tree, int node , int start, int end, int l, int r);
void update(int *a, int *tree, int node, int start, int end, int indx, int val);
int main(){
	int i,b;
	int a[]={1,2,10,4, 9};
	int tree[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int lazy[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	updatelazy(tree, lazy, 0, 0, 14, 1, 3, 26);
	printf("Update: ");
	for(i=0;i<15;++i){
		printf("%d, ",tree[i]);
	}
	printf("\n\n");

	updatelazy(tree, lazy, 0, 0, 14, 3, 7, 80);
	printf("Update: ");
	for(i=0;i<15;++i){
		printf("%d, ",tree[i]);
	}
	printf("\n\n");

	updatelazy(tree, lazy, 0, 0, 14, 3, 4, 20);
	printf("Update: ");
	for(i=0;i<15;++i){
		printf("%d, ",tree[i]);
	}
	printf("\n\n");


	int s = querylazy(tree, lazy, 0, 0, 14, 7, 7);
	printf("query: %d\n", s);

	return 0;
}

int querylazy(int *tree, int *lazy, int node, int start, int end, int l, int r){
	if(start > end || start > r || end < l) {
		return 0;
	}
	if(*(lazy + node)) {
		*(tree + node) += (end + start + 1) * (*(lazy + node));
		if(start != end) {
			*(lazy + (2 * node + 1)) += *(lazy + node);
			*(lazy + (2 * node + 2)) += *(lazy + node);
		}
		*(lazy + node) = 0;
	}
	if(start >= l && end <= r) {
		return *(tree + node);
	}
	int mid = (end + start) / 2;
	int p1  = querylazy(tree, lazy, 2 * node + 1, start, mid, l, r);
	int p2  = querylazy(tree, lazy, 2 * node + 2, mid + 1, end, l, r);
	return p1 + p2;
}

int updatelazy(int *tree, int *lazy, int node, int start, int end, int l, int r, int val){
	if(*(lazy + node)) {
		*(tree + node) += (end + start + 1) * (*(lazy + node));
		if(start != end) {
			*(lazy + (2 * node + 1)) += *(lazy + node);
			*(lazy + (2 * node + 2)) += *(lazy + node);
		}
		*(lazy + node) = 0;
	}
	if(start > end || start > r || end < l) {
		return;
	}
	if(start >= l && end <= r) {
		*(tree + node) += (end - start + 1) * val;
		if(start != end) {
			*(lazy + (2 * node + 1)) += val;
			*(lazy + (2 * node + 2)) += val;
		}
		return;
	}
	int mid = (start + end) / 2;
	updatelazy(tree, lazy, 2 * node + 1, start, mid, l, r, val);
	updatelazy(tree, lazy, 2 * node + 2, mid + 1, end, l, r, val);
	*(tree + node) = *(tree + (2 * node + 1)) + *(tree + (2 * node + 2));
}

void build(int *a, int *tree, int node,int start,int end){
	/* Input: a - vector with n elements
	 *        tree - vector with 2*n-1 random elements
	 * Output: tree builded
	 */

	if(start==end){
		*(tree + node) = *(a + start);
	}
	else{
		int mid=((start+end)/2);
		build(a,tree,2*node+1,start,mid);
		build(a,tree,2*node+2,mid+1,end);
		*(tree + node)=*(tree + (2*node+1))+*(tree + (2*node+2));
	}
}



int query(int *a, int *tree, int node, int start, int end, int l, int r){
	if(r<start||end <l){
		return 0;
	}
	if(l<=start && end <=r){
		return *(tree + node);
	}
	int mid=(start+end)/2;
	int p1=query(a,tree,2*node+1,start,mid,l,r);
	int p2=query(a,tree,2*node+2,mid+1,end,l,r);
	return p1+p2;
}

void update(int *a, int *tree, int node, int start, int end, int indx, int val){
	if(start == end) {
		*(a + indx) += val;
		*(tree + node) += val;
	} else {
		int mid = (start + end) / 2;
		if(start <= indx && indx <= mid) {
			update(a, tree, 2 * node + 1, start, mid, indx, val);
		} else {
			update(a, tree, 2 * node + 2, mid+1, end, indx, val);
		}
		*(tree + node) = *(tree + (2 * node + 1)) + *(tree + (2 * node + 2));
	}
}
