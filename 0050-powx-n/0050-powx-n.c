double myPow(double x, int n) {

    double ans = 1;
    long long N = n;

    if(n < 0)
    {
        x = 1/x;
        N = -N;
    }

    while(N > 0){

        if(N%2 == 1)
            ans = ans * x;
        
        x = x*x;
        N = N /2;
    }

    return ans;
}