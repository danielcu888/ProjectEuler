class problem36
{
    public static boolean is_pallindrome(String s)
    {
	boolean b = false;

	if(s.length() == 1) return true;

	if(s.length() != 0)
	    {
		for(int i = 0; i != s.length()/2; ++i)
		    {
			b = s.charAt(i) == s.charAt(s.length()-1-i);
			if(!b) return false;
		    }
	    }
	return b;
    }

    public static void main(String[] args)
    {
	final int MAX = 1000000; 
	int sum = 0;

	for(int i = 1; i != MAX; ++i)
	{
		String hex = Integer.toBinaryString(i);
		String dec = Integer.toString(i);

		if(is_pallindrome(hex) && is_pallindrome(dec))
		    sum += i;
	    }

	System.out.println(sum);
    }
}