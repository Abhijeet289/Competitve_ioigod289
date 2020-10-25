ll find_root(ll i){
    while(rt[i]!=i){
        rt[i]=rt[rt[i]];
        i=rt[i];
    }
    return i;
}

void uni(ll a, ll b){
    ll r1=find_root(a);
    ll r2=find_root(b);
    if(trsz[r1]<trsz[r2]){
        rt[r1]=rt[r2];
        trsz[r2]+=trsz[r1];
    }
    else{
        rt[r2]=rt[r1];
        trsz[r1]+=trsz[r2];
    }
}

ll kruskal(){
    sort(all(edges));
    ll res = 0;
    for(int i=0;i<sz(edges);i++){
        ll w = edges[i].F;
        ll u = edges[i].S.F;
        ll v = edges[i].S.S;
        ll r1 = find_root(u);
        ll r2 = find_root(v);
        // cout<<w<<"    ";
        // cout<<r1<<" "<<r2<<"\n";
        if(r1==r2)
            continue;
        res += w;
        uni(u, v);
    }
    return res;
}
