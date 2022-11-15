package Yakshit;
import java.util.Scanner;

public class MyMath
{

    static void factorial(int a)
    {
        int fact=1;
        for(int i=a;i>0;i--)
        {
            fact= fact*i;
        }
        System.out.println("The factorial of this number is: "+fact);
    }

    static void power(int a, int b)
    {
        int result=1;
        for(int i=b;i>0;i--)
        {
            result= a*result;
        }
        System.out.println("The result of this is: "+result);
    }

    public static void main(String[] args) 
    {
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter a number: ");
        int a = sc.nextInt();
        factorial(a);
        System.out.print("Enter its power: ");
        int b = sc.nextInt();
        sc.close();
        power(a,b);
    }

}
