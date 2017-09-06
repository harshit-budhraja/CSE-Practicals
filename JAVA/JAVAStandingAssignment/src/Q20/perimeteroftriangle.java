package Q20;

import java.util.Scanner;

/**
 * 
 */

/**
 * @author harshitbudhraja
 *
 */
class Triangle
{
	double AB,BC,AC;
	
	public Triangle(double x1,double y1,double x2,double y2,double x3, double y3)
	{
		this.AB = Math.sqrt(Math.pow(Math.abs((x1-x2)), 2) + Math.pow(Math.abs((y1-y2)), 2));
		this.BC = Math.sqrt(Math.pow(Math.abs((x2-x3)), 2) + Math.pow(Math.abs((y2-y3)), 2));
		this.AC = Math.sqrt(Math.pow(Math.abs((x3-x1)), 2) + Math.pow(Math.abs((y3-y1)), 2));
	}
	public double getperimeter()
	{
		return this.AB+this.BC+this.AC;
	}
}

public class perimeteroftriangle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double x1,y1,x2,y2,x3,y3;
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the coordinates of A: (x1,y1)");
		x1=s.nextDouble();
		y1=s.nextDouble();
		System.out.println("Enter the coordinates of B: (x2,y2)");
		x2=s.nextDouble();
		y2=s.nextDouble();
		System.out.println("Enter the coordinates of C: (x3,y3)");
		x3=s.nextDouble();
		y3=s.nextDouble();
		
		Triangle T = new Triangle(x1,y1,x2,y2,x3,y3);
		System.out.printf("The perimeter of triangle T is = %f",T.getperimeter());
	}

}
