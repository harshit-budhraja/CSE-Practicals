package Q5;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author harshitbudhraja
 *
 */
public class prog {

	/**
	 * 
	 */
	public prog() {
		// TODO Auto-generated constructor stub
	}
	
	public static Boolean iseven(int val)
	{
		return (val%2==0);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.println("Enter numbers: ");
		ArrayList<Integer> arr = new ArrayList();
		int i=0;
		int sumodd=0,sumeven=0;
		int numodd=0,numeven=0;
		while(true)
		{
			arr.add(i,s.nextInt());
			if(arr.get(i) < 0)
			{
				arr.remove(i);
				break;
			}
			else
			{
				if(iseven(arr.get(i)))
				{
					sumeven += arr.get(i);
					numeven++;
				}
				else
				{
					sumodd += arr.get(i);
					numodd++;
				}
				i++;
			}
		}
		System.out.println("The accepted values are: ");
		for(i=0;i<arr.size();i++)
		{
			System.out.println(arr.get(i));
		}
		System.out.println("Avg(EVEN) = " + String.valueOf(sumeven/numeven) + "\nAvg(ODD) = " + String.valueOf(sumodd/numodd));
	}

}
