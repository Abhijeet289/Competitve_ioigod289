bool dfs(int node){
    color[node] = 1;
    for(int v:adj[node]){
        if(color[v]==1)
            return true;
        else if(color[v]==0 and dfs(v))
            return true;
    }
    color[node] = 2;
    return false;
}

bool check_cycle(){
    memset(color, 0, sizeof color);
    for(int i=1;i<=ct;i++){
        if(color[i]==0 and dfs(i))
            return true;
    }
    return false;
}

