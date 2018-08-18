import java.math.BigInteger;
import java.io.*;

public class problem53
{
    public static BigInteger factorial(int i)
	throws Exception
    {
	if(i < 0) throw new Exception("negative argument");
	else if(i == 0 || i == 1) return new BigInteger(""+1);
	else
	    {
		BigInteger result = new BigInteger(""+i);
		while(i > 1)
		    {
			--i;
			result = result.multiply(new BigInteger(""+i));
		    }
		return result;
	    }
    }

    public static BigInteger nCr(int n, int r)
	throws Exception
    { 
	if(n < 1 || r < 0) throw new Exception("negative argument");
	if(r > n) throw new Exception("r > n");
	if(r == 0) return new BigInteger(""+1);

	BigInteger num = factorial(n);
	BigInteger den = factorial(n-r).multiply(factorial(r));

	return num.divide(den);
    }

    public static void main(String[] args)
	throws Exception
    {
	BigInteger comp = new BigInteger(""+1000000);
	int count = 0;
	for(int n = 1; n <= 100; ++n)
	    for(int r = 1; r <= n; ++r)
		if(nCr(n,r).compareTo(comp) == 1)
		    ++count;
	System.out.println("count = " + count);
    }
}