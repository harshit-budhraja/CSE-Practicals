package Q12;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author harshitbudhraja
 *
 */
public class twoarrays {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		Integer a1[] = new Integer[20];
		Integer a2[] = new Integer[20];
		System.out.println("Enter the numbers in the first array: ");
		for(int i=0;i<20;i++)
		{
			a1[i] = s.nextInt();
		}
		System.out.println("Enter the numbers in the second array: ");
		for(int i=0;i<20;i++)
		{
			a2[i] = s.nextInt();
		}
		
		ArrayList<Integer> num = new ArrayList();
		
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(a1[i] == a2[j])
				{
					num.add(a1[i]);
				}
			}
		}
		System.out.println(num);
		System.out.printf("Total number of shared numbers = %d\n",num.size());
	}

}
