import java.util.*;

public class Main {
	
	public static long fac(int num)
	{
		return num==0?1:num*fac(num-1); 
	}
	
	public static void main(String[] args)
  {
	  
	 
    Scanner sc=new Scanner(System.in);
    
    
    int N=sc.nextInt();
    System.out.println(fac(N));
    
 }
 
}