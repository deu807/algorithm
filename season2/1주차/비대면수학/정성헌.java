import java.util.*;

public class Main {
  public static void main(String[] args)
  {
    Scanner sc=new Scanner(System.in);
    
    int x=0,y=0;
    int a=sc.nextInt();
    int b=sc.nextInt();
    int c=sc.nextInt();
    int d=sc.nextInt();
    int e=sc.nextInt();
    int f=sc.nextInt();
    
    x=(e*c-b*f)/(a*e-b*d);
    y=(d*c-a*f)/(b*d-a*e);
    
    System.out.print(x);
    System.out.print(' ');
    System.out.print(y);
  }
}
