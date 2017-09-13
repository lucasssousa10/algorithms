#include <stdio.h>

long long querylazy(long long *tree, long long *lazy, int node, int start, int end, int l, int r);
void updatelazy(long long *tree, long long *lazy, int node, int start, int end, int l, int r, int val);

int main() {
	int t, n, c, p, q, v;
	int opcode, i;
	
	scanf("%d", &t);

	for(;t > 0; t--) {
		scanf("%d %d", &n, &c);

		
		long long tree[2 * n - 1];
		long long lazy[2 * n - 1];

		for(i = 0; i < n * 2 - 1; lazy[i] = tree[i++] = 0);

		for(i = 0; i < c; i++) {
			scanf("%d", &opcode);
			switch(opcode) {
				case 0:
					scanf("%d %d %d", &p, &q, &v);
					updatelazy(tree, lazy, 0, 0, n-1, p-1, q-1, v);
					break;
				case 1:
					scanf("%d %d", &p, &q);
					printf("%lld\n", 
						querylazy(tree, lazy, 0, 0, n - 1, p-1, q-1)
					);
					break;
			}
		}
	}


	return 0;
}


long long querylazy(long long *tree, long long *lazy, int node, int start, int end, int l, int r){
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
	long long p1  = querylazy(tree, lazy, 2 * node + 1, start, mid, l, r);
	long long p2  = querylazy(tree, lazy, 2 * node + 2, mid + 1, end, l, r);
	return p1 + p2;
}

void updatelazy(long long *tree, long long *lazy, int node, int start, int end, int l, int r, int val){
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