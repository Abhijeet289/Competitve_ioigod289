struct seg_tree{
    vector <int> stre;
    int n;
    seg_tree(int n){
        this->n = n;
        stre.assign(4*n+1, 0);
    }

    void build(int node, int start, int end){
        if(start==end){
            stre[node] = start;
            return;
        }
        int mid = (start + end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        if(leaves[stre[2*node]].size()>=leaves[stre[2*node+1]].size())
            stre[node] = stre[2*node];
        else
            stre[node] = stre[2*node+1];
        return;
    }

    void update(int node, int start, int end, int pos){
        if(start>pos or end<pos)
            return;
        if(start==end){
            stre[node] = start;
            return;
        }
        int mid = (start + end)/2;
        update(2*node, start, mid, pos);
        update(2*node+1, mid+1, end, pos);
        if(leaves[stre[2*node]].size()>=leaves[stre[2*node+1]].size())
            stre[node] = stre[2*node];
        else
            stre[node] = stre[2*node+1];
        return;
    }
};
