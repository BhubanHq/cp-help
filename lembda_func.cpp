 auto check = [&]() -> bool {
         for(int i=0 ; i<n ; i++){
           ll need = mid;
           ll ops = 0;
                
           for(int j = i ; j<n ; j++){
              ll more = need - v[j];
                
              if(more < 1){
                 if(ops <= k)
                     return 1;
              else
                 break;
            }
                    
         ops += need - v[j];
         --need;
         need = max(need, 1LL);
       }
      }
      return 0;
     };
