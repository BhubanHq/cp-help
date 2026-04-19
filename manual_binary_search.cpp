 
 int low = l, high = n + 1, mid;
 
 while(high - low > 1){
        mid = (low + high)/2;

        int total = 0;

        for(int i = 0 ; i<32 ; i++){
          if(pre[i][mid] - pre[i][l-1] == 0) total += (1LL<<i);
        }
       
       if(total >= k) low = mid;
       else high = mid;
     }
     cout<<low<<' ';