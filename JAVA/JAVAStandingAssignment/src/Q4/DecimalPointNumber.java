/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Q4;

import java.util.*;

/**
 *
 * @author harshitbudhraja
 */
public class DecimalPointNumber
{    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the decimal nunmber: ");
        Float tmpnum = sc.nextFloat();
        String num = String.valueOf(tmpnum);
        int left=0,right=0,flap=0;  //flap=0 for left and 1 for right
        char fd = '0';
        for(int i=0;i<num.length();i++)
        {
            if(num.charAt(i)=='.')
                flap=1;
            if(flap==0)
                left++;
            else if(flap==1)
            {
                if(right==1)
                    fd = num.charAt(i);
                right++;
            }
        }
        right--;
        System.out.printf("NUMBER OF DIGITS AROUND DECIMAL POINT(.):\nLeft = %s\nRight = %s\n",left,right);
        Double frac = tmpnum - Math.floor(tmpnum);
        if(frac > 0.5)
            System.out.println("The fractional part is > 0.5");
        else if(frac < 0.5)
            System.out.println("The fractional part is < 0.5");
        else if(frac == 0.5)
            System.out.println("The fractional part is = 0.5");
    }    
}
