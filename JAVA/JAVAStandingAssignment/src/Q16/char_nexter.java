package Q16;

import java.util.Scanner;

/**
 * 
 */

/**
 * @author harshitbudhraja
 *
 */
public class char_nexter {

	public static Boolean char_hai_kya(char ch)
	{
		int c = ch;
		return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
	}
	
	public static Boolean isvalidinput(char ch)
	{
		int c = ch;
		return (c >= 97 && c <= 122);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a string (all lowercase): ");
		String s = sc.nextLine();
		int len = s.length();
		StringBuilder mystring = new StringBuilder(s);
		for(int i=0;i < len;i++)
		{
			if(char_hai_kya(mystring.charAt(i)))
			{
				if(isvalidinput(mystring.charAt(i)))
				{
					mystring.setCharAt(i, (char) (mystring.charAt(i)+1));
				}
				else
				{
					System.out.println("Invalid input string detected. Exitting...");
					System.exit(1);
				}
			}
		}
		System.out.println("Output string is: " + mystring);
	}

}
