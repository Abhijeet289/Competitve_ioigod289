void spf_sieve(int n)
{
    spf[1]=1;
    for(int i=2;i<=n;i++) spf[i]=i;
    for(int i=4;i<=n;i+=2) spf[i]=2;
    for(int i=3;i*i<=n;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}
