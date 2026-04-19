bool prime[N+5];


void seive(){
  for(int i=2;i*i<=N;i++){
    if(!prime[i]){
      for(int j=i*i;j<=N;j+=i){
        prime[j] = true;
      }
    }
  }
  prime[0]=prime[1]=true;
}