package Q14;

import java.util.Scanner;

/**
 * 
 */

/**
 * @author harshitbudhraja
 *
 */
public class secondlargestnumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int N=0;
		System.out.println("Enter the value of n: ");
		N = s.nextInt();
		Integer arr[] = new Integer[N];
		System.out.println("Enter the values of array:");
		for(int i=0;i<N;i++)
		{
			arr[i] = s.nextInt();
		}
		Integer max = new Integer(0);
		Integer max2 = new Integer(0);
		for(int i=0;i<N;i++)
		{
			if(arr[i]>max)
				max=arr[i];
		}
		for(int i=0;i<N;i++)
		{
			if(arr[i] > max2 && arr[i] < max)
				max2=arr[i];
		}
		System.out.printf("Largest = %d\nSecond Largest = %d",max,max2);
	}

}
