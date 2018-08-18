import java.math.BigInteger;
import java.math.*;

public class problem56 
{
	public static void main(String[] args)
	{
		int result = 0;
		for(int a = 1; a != 100; ++a)
			for(int b = 1; b != 100; ++b)
			{
				int sum = 0;
				BigInteger bi = (new BigInteger(""+a)).pow(b);
				String s = bi.toString();
				for(int i = 0; i != s.length(); ++i)
					sum += Integer.decode((new Character(s.charAt(i))).toString()).intValue();
				result = Math.max(result, sum);
			}
		System.out.println(result);
	}
}
