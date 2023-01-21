import java.util.Random;

class random extends Thread
{
    int a;
    public void run()
    {
        Random r = new Random();
        for(int i =0; i<3;i++)
        {
            a = r.nextInt(10);
            try
            {
                Thread.sleep(0);
            }
            catch(Exception e)
            {
                System.out.println("exception handled");
            }
            Square sq = new Square(a);
            Cube cb = new Cube(a);
            if(a%2==0)
            {
                sq.start();
            }
            else
            {
                cb.start();
            }
        }
    }
}

class Square extends Thread
{
    int x;
    Square(int x)
    {
        this.x =x;
    }
    public void run()
    {
    System.out.println("the square of the number " + x+ " is: " + x*x);
    }
}

class Cube extends Thread
{
    int x;
    Cube(int x)
    {
        this.x =x;
    }
    public void run()
    {
        System.out.println("the cube of the number " + x+ " is: " + x*x*x);
    }
}

class multi
{
    public static void main(String args[])
    {
        random ob = new random();
        ob.start();
    }
}

