package Q13;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author harshitbudhraja
 *
 */
public class alternatearrays {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		Integer a1[] = new Integer[10];
		Integer a2[] = new Integer[10];
		System.out.println("Enter the numbers in the first array: ");
		for(int i=0;i<10;i++)
		{
			a1[i] = s.nextInt();
		}
		System.out.println("Enter the numbers in the second array: ");
		for(int i=0;i<10;i++)
		{
			a2[i] = s.nextInt();
		}
		
		int i=0,j=0,k=0;
		ArrayList<Integer> afinal = new ArrayList();
		while(i<10 || j<10)
		{
			afinal.add(a1[i++]);
			afinal.add(a2[j++]);
		}
		System.out.println(afinal);
	}

}
