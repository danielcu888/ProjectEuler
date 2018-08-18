import java.math.BigInteger;

public class problem45
{
    final static int START = 165;
    final static int MAX = 100000;
    final static BigInteger bi0 = new BigInteger("0");
    final static BigInteger bim1 = new BigInteger("-1");
    final static BigInteger bi2 = new BigInteger("2");
    final static BigInteger bi3 = new BigInteger("3");

    //returns ith hexagonal number as a biginteger
    public static BigInteger getHex(int i)
    {
	BigInteger bii = new BigInteger(""+i);
	BigInteger tmp = bii;
	tmp = tmp.multiply(bi2);
	tmp = tmp.add(bim1);
	tmp = tmp.multiply(bii);  //i*(2*i - 1)
	return tmp;
    }

    //returns ith pentagonal number as a biginteger
    public static BigInteger getPent(int i)
    {
	BigInteger bii = new BigInteger(""+i);
        BigInteger tmp = bii;
        tmp = tmp.multiply(bi3);
        tmp = tmp.add(bim1);
        tmp = tmp.multiply(bii);
	tmp = tmp.divide(bi2);  //i*(3*i - 1)/2
	return tmp;
    }

    //returns biginteger array with first n hexagonal numbers
    public static BigInteger[] hex_nums(int n)
    {
	BigInteger[] ret = new BigInteger[MAX];
	for(int i = 0; i <= n; ++i)
	    ret[i] = getHex(i);
	for(int i = n+1; i != ret.length; ++i)
	    ret[i] = bi0;

	return ret;
    }
    
    //returns boolean as to whether biginteger bi is contained in the array hexes
    public static boolean is_hex(BigInteger bi, BigInteger[] hexes)
    {
	int i = START;
	while(!hexes[i].equals(bi0) && !hexes[i].equals(bi))
	    ++i;
	if(hexes[i].equals(bi))
	   return true;
	return false;
    }

    public static void main(String args[])
    {
	//determine first pent above 165th pentagonal number that is also a hexagonal 
	//(and hence triangular) number
	
	//generate first 165 hexagonal numbers
	BigInteger[] hexes = hex_nums(START);
	//for(int i = 0; i != START+5; ++i)
	//    System.out.println(i + " " + hexes[i].toString() + " " + getPent(i).toString());

	int n = START;
	BigInteger pent;
	do {
	    ++n; //increment counter
	    hexes[n] = getHex(n); //append next hexagonal number to array
	    pent = getPent(n); //generate nth pentagonal number
	} while(!is_hex(pent, hexes)); //check whether nth pentagonal number is a hexagonal number
	
	//return necessary value
	System.out.println("Result = " + pent);
    }
}










    