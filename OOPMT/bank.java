package Yakshit;
import java.util.Scanner;
class Customer
{
    int id,bal;
    String name;
    Customer(int id, String name, int bal)
    {
        this.id=id;
        this.name=name;
        this.bal=bal;
    }
}

public class bank 
{   
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        String nm;
        int acc_num,balance,choice;

        System.out.print("Enter number of customers: ");
        int n = sc.nextInt();

        Customer cust[] = new Customer[100];

        for(int i=0;i<n;i++)
        {
            Scanner s1 = new Scanner(System.in); 

            System.out.println("Enter Name of Customer "+(i+1)+": ");
            nm = s1.nextLine();

            System.out.println("Enter Account number of Customer "+(i+1)+": ");
            acc_num = s1.nextInt();

            System.out.println("Enter Name of Customer "+(i+1)+": ");
            nm = s1.nextLine();

            System.out.println("Enter Account Balance of Customer "+(i+1)+": ");
            balance = s1.nextInt();

            cust[i]= new Customer(acc_num, nm, balance);
        }
        
    }
}
