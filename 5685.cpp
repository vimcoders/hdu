/* 
 * File Name: main.cpp
 * Descript: 
 * 
 * Version: 1.0 
 * Created Time: 07/28/17 13:16:08
 * Compiler: 
 * Editor: vim 
 * Author: Jimbo 
 * Mail: jimboo.lu@gmail.com 
 *
 * Company: 
 */
 
#include<stdio.h>
#define max 100010
#define mod 9973

char str[max];
int sum[max];
int inv[mod];

int pow(int a, int b) {
	if (a == 0 || b == 0) {
		return 1;
	}
	int r = 1, base = a;
	while (b) {
		if (b&1) {
			r = (r * base) % mod;
		}
		base *= base;
		b >>= 1;
	}

	return r;
}

int main(void) {
	for (int i = 0; i < mod; i++) {
		inv[i] = pow(i, 9971);
	}
	int n, start, end;
	while(scanf("%d", &n) != EOF) {
		scanf("%s", str);
		sum[0] = 1;
		for (int i = 0; str[i] != '\n'; i++) {
			sum[i + 1] = (sum[i] * (str[i] - 28)) % mod;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &start, &end);
			printf("%d\n", (sum[end] * inv[start - 1]) % mod);
		}
	}
}
