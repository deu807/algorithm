import java.util.*;
public class Main {
    public static void main(String[] args) {


        Scanner sc=new  Scanner(System.in);
        int a= sc.nextInt();
        int b= sc.nextInt();
        int c= sc.nextInt();

        if((a%2==0)&&(b%2==0)&&(c%2==0))
        {
            System.out.println(a*b*c);
        }
        else if((a%2==0)&&!(b%2==0)&&!(c%2==0))
        {
            System.out.println(b*c);
        }
        else if((a%2==0)&&!(b%2==0)&&(c%2==0))
        {
            System.out.println(b);
        }
        else if((a%2==0)&&(b%2==0)&&!(c%2==0))
        {
            System.out.println(c);
        }
        else if(!(a%2==0)&&(b%2==0)&&!(c%2==0))
        {
            System.out.println(a*c);
        }
        else if(!(a%2==0)&&!(b%2==0)&&!(c%2==0))
        {
            System.out.println(a*b*c);
        }
        else if(!(a%2==0)&&(b%2==0)&&(c%2==0))
        {
            System.out.println(a);
        }
        else if(!(a%2==0)&&!(b%2==0)&&(c%2==0))
        {
            System.out.println(a*b);
        }

    }
}
