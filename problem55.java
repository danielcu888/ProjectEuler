import java.math.BigInteger;
public class problem55 
{
    public static boolean is_palindrome(String s)
    {
	if(s.length() == 1) return false;
	int beg = 0; int end = s.length()-1;
	while(beg < end && s.charAt(beg) == s.charAt(end))
	    { 
		++beg; 
		--end;
	    }
	return beg >= end ? true : false;
    }
    
    public static boolean is_lychrel(BigInteger bi, int level)
    {
	if(level > 50) return true;
	String s = bi.toString();
	char[] p = new char[s.length()];
	for(int i = 0; i != s.length(); ++i)
	    p[i] = s.charAt(s.length()-1-i);
	BigInteger bi2 = bi.add(new BigInteger(new String(p)));
	return is_palindrome(bi2.toString()) ? false : is_lychrel(bi2, ++level);
    }
    
    public static void main(String[] args) 
    {
	int count = 0;
	for(int i = 1; i != 10000; ++i)
	    if(is_lychrel(BigInteger.valueOf(i), 0))
		++count;
	System.out.println(count);
    }
}
