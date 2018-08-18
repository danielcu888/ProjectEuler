import java.math.BigDecimal;

public class problem26 
{
    public static void main(String args[]) 
    {
	int max_sz = 0;
	int d = 2;

	for(int den = 1; den != 999; ++den)
	    {
		BigDecimal a = new BigDecimal(1);
		BigDecimal b = new BigDecimal(den);
		BigDecimal c = a.divide(b, 2000, BigDecimal.ROUND_FLOOR);
		String s = c.toString();
		
		int beginIdx = 0;
		while(s.charAt(beginIdx) != '.')
		    ++beginIdx;
		s = s.substring(beginIdx+1);
		
		int half = s.length()/2;
		String f = s.substring(0, half);
		String l = s.substring(half);

		int sz = 0;
		for(int i = 1; i != f.length(); ++i)
		    {
			String test = f.substring(f.length()-i, f.length());
			int firstIdx = s.indexOf(test);
			int secondIdx = s.indexOf(test, firstIdx + test.length());
			if(secondIdx == firstIdx + test.length())
			    {
				sz = test.length();
				break;
			    }
		    }

		if(sz > max_sz)
		    {
			max_sz = sz;
			d = den;
		    }
	    }
	
	System.out.println("Result = " + d);
    }
}