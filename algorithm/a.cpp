#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp> 
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
 typedef tree<pair<long long, long long>, null_type, less_equal<pair<long long, long long>>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    dataSet; 


long long C(long long  n,long long  k){
    if(n < k) return 0;
    return (fact[n]*pw((fact[n-k]*fact[k])%MOD,MOD-2))%MOD;
}
int main()
{
     memset(fact, 0, sizeof(fact));
    fact[0]=1;
    for(ll i=1;i<300005;i++)fact[i]=(fact[i-1]*i)%MOD;

  
      printf("%lld", C(4,2));
    return 0;
}
