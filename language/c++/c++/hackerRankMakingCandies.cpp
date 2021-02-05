#include <iostream>

using namespace std;

long minimumPasses(long m, long w, long p, long n) {
    long result = m*w;
    long count = 1;
    
    while(result < n) {
        count++;
        long limit = result/p;
        long max = m*w, idx1=0, idx2=0;
        for (long i = 0; i<= limit; i++) {
            if (max < (m+i)*(w+(limit-i))) {
                idx1 = i;
                idx2 = limit-i;
                max = (m+i)*(w+(limit-i));
            }
        }
        m = m+idx1;
        w = w+idx2;
        result = result + max;
        result = result - (p*(idx1+idx2));
        cout << result << endl;
    }
    return count;
}

int main()
{
    cout << minimumPasses(1,1,6,45);
    return 1;
}

/*
 * working for other corner cases
 */
static boolean  check(long m , long w , long p , long target , long rounds)
{
    // even long cant store 10^24
    if(m >= (target + w-1)/w)
    return true;

    long curr = m*w;
    rounds--;

    if(rounds == 0)
    return false;

    while(true)
    {

        long rem = target - curr;

        // if i go with the no change in m and w 

        // to get the upper range
        // Math.ceil(a/b) = (a+b-1)/b
        long required = (rem + m*w -1) /( m*w);

        if(rounds >= required)
        return true;

        // unable to buy machines or workers
        if(curr < p)
        {
            // here i must be able to know
            // how many rounds to go till i
            // can make curr >= p

            rem = p-curr;

            required = (rem  + m*w -1 )/(m*w);

            rounds = rounds - required;

            // as unable to buy anything
            if(rounds < 1)
            return false;

            curr += required*m*w;
        }

        // if we can buy we increment which in minimum 
        curr = curr-p;
        if( m > w)
        w++;
        else
        m++;

    }


}

// Complete the minimumPasses function below.
static long minimumPasses(long m, long w, long p, long n) 
{

    long min = 1;
    long max = 10000000000000L; 

    while(min< max)
    {
        long mid = (min+max)/2;

        if(check(m , w , p , n ,mid))
        {
            max = mid;
        }
        else
        {
            min = mid+1;
        }
    }

    return min;
}