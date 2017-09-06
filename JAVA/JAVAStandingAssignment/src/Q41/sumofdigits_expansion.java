package Q41;

import java.math.BigInteger;

/**
 * 
 */

/**
 * @author harshitbudhraja
 *
 */
public class sumofdigits_expansion {

	public static BigInteger expand(Integer N)
	{
		BigInteger xval = new BigInteger(String.valueOf(N));
		xval = xval.pow(N);
		return xval;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Integer N = new Integer(4444);
		BigInteger xval = expand(N);
		System.out.println(xval);
		String val = xval.toString();
		int len = val.length();
		Integer sum = new Integer("0");
		int zero=0,one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0;
		for(int i=0;i<len;i++)
		{
			if(val.charAt(i)=='0')
				zero++;
			else if(val.charAt(i)=='1')
				one++;
			else if(val.charAt(i)=='2')
				two++;
			else if(val.charAt(i)=='3')
				three++;
			else if(val.charAt(i)=='4')
				four++;
			else if(val.charAt(i)=='5')
				five++;
			else if(val.charAt(i)=='6')
				six++;
			else if(val.charAt(i)=='7')
				seven++;
			else if(val.charAt(i)=='8')
				eight++;
			else if(val.charAt(i)=='9')
				nine++;
			
			sum += Integer.valueOf(val.charAt(i))-Integer.valueOf(48); // As it is returning ASCII values and not integers
		}
		System.out.printf("Zero = %d\nOne = %d\nTwo = %d\nThree = %d\nFour = %d\nFive = %d\nSix = %d\nSeven = %d\nEight = %d\nNine = %d\n",zero,one,two,three,four,five,six,seven,eight,nine);
		System.out.println("Total Number of Digits = " + String.valueOf(len) + "\nSum of Digits = " + String.valueOf(sum));
	}

}
