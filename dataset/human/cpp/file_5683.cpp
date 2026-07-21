#include <bits/stdc++.h>
using namespace std;

int n,i,j,len;
long long k,ans;
char s[100007];
int a[100007];

class Node {
public:
    Node(int v) {
        data = v;
        left = NULL;
        right = NULL;
    }
 
    int data;
    Node* left;
    Node* right;
};

long long nyan(long long x) {
	if (x == 0) {
		//printf("%lld\n",x);
		return 0;
	}
	long long yes = 1;
	while (x % 2 == 0) {
		yes *= 2;
		x /= 2;
	}
	//printf("%lld\n",yes);
	return yes;
}

int main() {
	Node* root = new Node(0);
	
	scanf("%d%lld",&n,&k);
	for (i=0 ; i<n ; i++) {
		scanf("%s",&s);
		len = strlen(s);
		
		Node* cur = root;
		for (j=0 ; j<len ; j++) {
			if (s[j] == '0') {
				if ((cur->left) == NULL) {
					//a[j]++;
					ans ^= nyan(k-j);
					Node* x = new Node(0);
					cur->left = x;
					cur = (cur->left);
				} else {
					cur = (cur->left);
				}
			} else {
				if ((cur->right) == NULL) {
					//a[j]++;
					ans ^= nyan(k-j);
					Node* x = new Node(0);
					cur->right = x;
					cur = (cur->right);
				} else {
					cur = (cur->right);
				}
			}
		}
	}
	
	if (ans > 0) { //for (i=0 ; i<=100000 ; i++) if (a[i] % 2 != 0) {
		printf("Alice\n");
		return 0;
	}
	printf("Bob\n");
}
