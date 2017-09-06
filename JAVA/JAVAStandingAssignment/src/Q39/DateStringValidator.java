/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Q39;

import java.util.*;

/**
 *
 * @author harshitbudhraja
 */
public class DateStringValidator
{
    
    public static Boolean isValidDate(String date)
    {
        Boolean flag = false;
        String[] split_date = date.split("-");
        String dd = split_date[0];
        String mm = split_date[1];
        String yyyy = split_date[2];
        if(Integer.valueOf(dd) >= 1 && Integer.valueOf(dd) <= 31)
            return true;
        
        return flag;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a date stamp: ");
        String in_date = sc.nextLine();
        System.out.println(isValidDate(in_date));
    }
}
