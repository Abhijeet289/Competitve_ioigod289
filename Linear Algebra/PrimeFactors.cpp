vector <ll> getPrimeDiv(ll num){
    vector <ll> res;
    for(ll i=2; i*i<=num; i++){
        if(num%i==0){
            res.pb(i);
            num /= i;
            while(num%i==0)
                num /= i;
        }
    }
    if(num!=1)
        res.pb(num);
    return res;
}
