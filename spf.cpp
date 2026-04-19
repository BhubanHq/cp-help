int spf[1000005];
void sieve(int n) {
	for(int i = 2; i <= n; i++) {
		if(spf[i] > 0) continue;
		for(int j = i; j <= n; j += i) {
			if(spf[j] == 0) {
				spf[j] = i;
			}
		}
	}
	spf[0] = -1;
}