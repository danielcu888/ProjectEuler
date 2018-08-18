import java.math.BigInteger;
public class problem48
{
    public static void main(String[] args) 
    {
	BigInteger n = new BigInteger("0");
	for(int i = 1; i <= 1000; i++)
	    {      
		n = n.add(new BigInteger(""+i).pow(i));
	    }
	System.out.println(n.toString().substring(n.toString().length() - 10));
    }
}