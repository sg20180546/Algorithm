#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>

typedef long long ll;
ll ans[10];

void cal(ll num, ll ten) {
	while (num) {
		ans[num % 10] += ten;
		num /= 10;
	}
}

void sol(ll start, ll end, ll ten) {
	while (start % 10 != 0 && start <= end) {
		cal(start, ten);
		start++;
	}
	if (start > end) {
		return;
	}

	while (end % 10 != 9 && start <= end) {
		cal(end, ten);
		end--;
	}

	ll diff = (end / 10 - start / 10 + 1);
	
	int i;
	for (i = 0; i < 10; i++) {
		ans[i] += diff * ten;
	}
	sol(start / 10, end / 10, ten * 10);
}

int main() {

	ll N;
	scanf("%d", &N);

	sol(1, N, 1);
	int i;
	for (i = 0; i < 10; i++) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
}