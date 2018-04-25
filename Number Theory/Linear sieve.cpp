inline void pre() {
	
	for(int i = 1 ; i < N ; i++) {
		if(!vis[i]) {
			prime[cnt++] = i;
			mu[i] = -1;
			phi[i] = i - 1;
		}
		for(int j = 0 ; j < cnt && i * prime[j] < N ; j++) {
			vis[i*j] = 1;
			if(i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			} else {
				mu[i * prime[j]] = -mu[i];
			    phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
	}
}
