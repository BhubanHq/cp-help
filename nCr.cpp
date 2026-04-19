ll ncr(ll upper, ll lower){
  if (lower == 0)
        return 1;
  if (lower > upper)
        return 0;
  ll up = fact[upper];
  ll temp = fact[lower];
  ll dif = fact[upper - lower];
  ll low = (temp * dif) % mod;
 
  ll res = (up * bigmod(low,mod-2,mod)) % mod;
  return res;
}