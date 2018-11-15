#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct plan {
	int n4, n6, n9, cost;
	struct plan *next;
};

struct plan *prs, *head, *tail;

void drawer(int *max){
	int i,j,k,m; 
	int sol_num = 0;
	for(i = 1; i <= 21; i++) {
		for (j = 1; j <= (91 - 4 * i) / 6; j++) {
			k = (100 - 4 * i - 6 * j) / 9;
			if (4 * i + 6 * j + 9 * k == 100) {
				m = 20 * i + 25 * j + 30 * k;
				prs = (struct plan *)malloc(sizeof(struct plan));
				if (head == NULL) {
					prs->next = NULL;
					prs->n4 = i;
					prs->n6 = j;
					prs->n9 = k;
					prs->cost = m;
					head = tail = prs;
					sol_num++;
				}
				else {
					prs->next = NULL;
					prs->n4 = i;
					prs->n6 = j;
					prs->n9 = k;
					prs->cost = m;
					tail->next = prs;
					tail = prs;
					sol_num++;
				}

			}
		}
	}
	*max = sol_num;
	
}
int main() {
	
	prs = head = tail = NULL;
	int i,max;
	drawer(&max);
    
    for (i=0,prs = head; i < max; i++,prs = prs->next) {
		printf("%2d: 购买4屉%2d个，购买6屉%2d个，购买9屉%2d个，合计总价%2d元\n", i+1,prs->n4, prs->n6, prs->n9, prs->cost);
	}
	
	free(prs); free(head); free(tail);
	return 0;
}
