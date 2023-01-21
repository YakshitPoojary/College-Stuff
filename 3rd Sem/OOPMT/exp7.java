import java.util.*;

class TimeException extends Exception
{
    TimeException(String msg)
    {
        super(msg);
    }
    public String toString()
    {
        return "TimeOutOfRange: " + getMessage();
    }


}

public class exp7 
{
    public static void main(String[] args) throws TimeException
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Time 1 in minutes: ");
        int m1 = sc.nextInt();
        System.out.print("Enter Time 1 in seconds: ");
        int s1 = sc.nextInt();
        System.out.print("Enter Time 2 in minutes: ");
        int m2 = sc.nextInt();
        System.out.print("Enter Time 2 in seconds: ");
        int s2 = sc.nextInt();

        int m3 = m1 + m2;
        int s3 = s1 + s2;

    
        if(s3 > 59 || m3>59)
        {
            throw new TimeException("Invalid Inputs");
        }
        else
        {
            System.out.println("The final time is "+m3+" minutes and "+s3+" seconds.");
        }
        sc.close();
        
    }
}