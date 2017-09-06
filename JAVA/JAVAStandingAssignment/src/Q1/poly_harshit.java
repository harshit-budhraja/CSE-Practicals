package Q1;

/**
 * 
 */

/**
 * @author harshitbudhraja
 *
 */
public class poly_harshit {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// z=x4+x3y+x2y2+xy3+y4
		// x - [-3,4]
		// y - [-5,6]
		// Print all he values of z, and also their max and min
		
		
		double i,j,max=0,min=10000;
		double z=0;
		for(i=-3;i<=4;i+=0.1)
		{
			for(j=-5;j<=6;j+=0.2)
			{
				z=Math.pow(i, 4)+(Math.pow(i, 3)*j)+(Math.pow(i, 2)*Math.pow(j, 2))+(i*Math.pow(j, 3))+Math.pow(j, 4);
				//System.out.println("For x="+i+" and y="+j+", the value of z is "+z);
				if(z > max)
					max=z;
				if(z < min)
					min=z;
			}
		}
		System.out.println("MAX(z)="+max+" and MIN(z)="+min);
	}

}
