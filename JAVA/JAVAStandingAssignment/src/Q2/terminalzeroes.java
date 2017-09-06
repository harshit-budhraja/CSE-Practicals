package Q2;

/**
 * 
 */

import java.math.*;
import java.util.*;

/**
 * @author harshitbudhraja
 *
 */
public class terminalzeroes {

	/**
	 * 
	 */
	public terminalzeroes() {
		// TODO Auto-generated constructor stub
	}
	
	public static BigInteger factorial(Integer N)
	{
		BigInteger fac = new BigInteger(String.valueOf(1));
		for(int i=1;i<=N;i++)
		{
			fac=fac.multiply(BigInteger.valueOf(i));
		}
		return fac;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		final Scanner s = new Scanner(System.in);
		System.out.println("Enter the integer: ");
		int inputnum = s.nextInt();
		Integer N = new Integer(inputnum);
		BigInteger factval = factorial(N);
		String f = factval.toString();
		System.out.println(N.toString()+"! = "+f);
		int len = f.length();
		int count=0;
		for(int i=len-1;i>=0;i--)
		{
			if(f.charAt(i)=='0')
				count++;
			else
				break;
		}
		System.out.println("No. of digits in this factorial = " + String.valueOf(len));
		System.out.println("No. of terminal zeroes = " + String.valueOf(count));
	}

}
