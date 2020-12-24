Useful resources-----
https://www.geeksforgeeks.org/determinant-of-a-matrix/

Implementation------
int finding_the_determinant(){
    int res = 1, total = 1;
    int tmp[n+5]; // temporary array
    for(int i=1;i<=n;i++){
        int idx = i;
        while(matrix[idx][i]==0 and idx<=n)
            idx++;
        if(idx==n+1)
            continue;
        if(idx!=i){
            for(int j=1;j<=n;j++){
                swap(matrix[idx][j], matrix[i][j]);
                swap(arr[idx], arr[i]);
            }
            if((idx-i)%2==1)
                res = -1*res;
        }
        for(int j=1;j<=n;j++)
            tmp[j] = matrix[i][j];
        for(int j=i+1;j<=n;j++){
            int pivot = tmp[i];
            int lower = matrix[j][i];
            arr[j] = ((pivot * arr[j]) - (lower * arr[i]));
            for(int k=1;k<=n;k++){
                matrix[j][k] = ((pivot * matrix[j][k]) - (lower * tmp[k]))%2;
            }
            total *= pivot;
        }
    } 
    for(int i=1;i<=n;i++)
        res *= matrix[i][i];
    return res/total;
}
