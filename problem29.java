import java.math.BigInteger;
public class problem29
{
    static final int MAX = 100;
    static final int MIN = 2;

    static int find(String[] nums, String s)
	throws Exception
    {
	for(int i = 0; i != nums.length; ++i)
	    {
		if(nums[i].compareTo(s) == 0)
		    return -1;
		else if (nums[i].equals("0")) 
		    return i;
	    }
	throw new Exception("Array full!");
    }
    
    static void display(String[] nums)
	throws Exception
    {
	for(int i = 0; i != find(nums, ""); ++i)
	    System.out.print(nums[i] + " ");
	System.out.println();
    }

    public static void main(String[] args)
	throws Exception
    {
	String[] nums = new String[(MAX-1)*(MAX-1)];
	for(int i = 0; i != nums.length; ++i)
	    nums[i] = "0";

	for(int a = MIN; a <= MAX; ++a)
	    {
		for(int b = MIN; b <= MAX; ++b)
		    {
			BigInteger bi = new BigInteger(""+a).pow(b);
			String sTmp = bi.toString();
			int tmp = find(nums, sTmp);
			if(tmp != -1 && tmp != -2)
			    nums[tmp] = sTmp;
			//display(nums);
		    }
	    }

	System.out.println(find(nums,""));
    }
}