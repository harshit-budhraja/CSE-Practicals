package Q26;

/**
 * 
 */

/**
 * @author harshitbudhraja
 *
 */
public class month_days {

	public static int non_leap[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	public static int leap[] = {31,29,31,30,31,30,31,31,30,31,30,31};
	
	public static Boolean isleap(int year)
	{
		return ((year%4==0 && year%100!=0) || year%400==0);
	}
	
	public static int days(int dd, int mm, int yy)
	{
		int nod=0;
		if(isleap(yy))
		{
			for(int i=0;i<mm;i++)
			{
				if(i==mm-1)
				{
					nod += dd;
				}
				else
					nod += leap[i];
			}
		}
		else
		{
			for(int i=0;i<mm;i++)
			{
				if(i==mm-1)
				{
					nod += dd;
				}
				else
					nod += non_leap[i];
			}
		}
		return nod;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(days(31,12,2017));
	}

}
