//9번
import java.util.Scanner;

public class Main
{
	//커밋테스트
	public static void main(String[] args)
	{

		
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		
		
		for(int i=0; i<N; i++)
		{
			
			for(int x=0; x<i; x++)
			{
				System.out.print(' ');
			}
			for(int j=0; j<N*2-1-(i*2); j++)
			{
				System.out.print("*");
				
			}											
			System.out.println();
		}	

		for(int i=1; i<N; i++)
		{
			
			for(int x=i; x<N-1; x++)
			{
				System.out.print(' ');
			}
			for(int j=0; j<i*2+1; j++)
			{
				System.out.print("*");
				
			}
												
			System.out.println();
		}
		sc.close();
	}

}
//8번
// import java.util.Scanner;

// public class Main
// {

// 	public static void main(String[] args)
// 	{

		
// 		Scanner sc=new Scanner(System.in);
// 		int N=sc.nextInt();
		
		
// 		for(int i=1; i<=N; i++)
// 		{						
// 			for(int j=0; j<i; j++)
// 			{
// 				System.out.print("*");
// 			}
// 			for(int x=0; x<N*2-(i*2); x++)
// 			{
// 				System.out.print(' ');
// 			}	
// 			for(int y=0; y<i; y++)
// 			{
// 				System.out.print("*");
// 			}										
// 			System.out.println();
// 		}			

// 		for(int i=2; i<=N; i++)
// 		{						
// 			for(int j=i-1; j<N; j++)
// 			{
// 				System.out.print("*");
// 			}
// 			for(int x=0; x<(i-1)*2; x++)
// 			{
// 				System.out.print(' ');
// 			}	
// 			for(int y=i-1; y<N; y++)
// 			{
// 				System.out.print("*");
// 			}									
// 			System.out.println();
// 		}			
// 		sc.close();
// 	}

// }


//7번

// import java.util.Scanner;

// public class Main
// {

// 	public static void main(String[] args)
// 	{

		
// 		Scanner sc=new Scanner(System.in);
// 		int N=sc.nextInt();
		
// 		for(int i=0; i<N; i++)
// 		{
			
// 			for(int x=i; x<N-1; x++)
// 			{
// 				System.out.print(' ');
// 			}
// 			for(int j=0; j<i*2+1; j++)
// 			{
// 				System.out.print("*");
				
// 			}
												
// 			System.out.println();
// 		}
		
		
// 		for(int i=1; i<N; i++)
// 		{
			
// 			for(int x=0; x<i; x++)
// 			{
// 				System.out.print(' ');
// 			}
// 			for(int j=0; j<N*2-1-(i*2); j++)
// 			{
// 				System.out.print("*");
				
// 			}											
// 			System.out.println();
// 		}	
// 		sc.close();
// 	}

// }


//6번


// import java.util.Scanner;

// public class Main
// {

// 	public static void main(String[] args)
// 	{
// 		// TODO Auto-generated method stub
// 		Scanner sc=new Scanner(System.in);
// 		int N=sc.nextInt();
// 		for(int i=0; i<N; i++)
// 		{
			
// 			for(int x=0; x<i; x++)
// 			{
// 				System.out.print(' ');
// 			}
// 			for(int j=0; j<N*2-1-(i*2); j++)
// 			{
// 				System.out.print("*");
				
// 			}
											
// 			System.out.println();
// 		}
// 	}

// }

// 5번

// import java.util.Scanner;

// public class Main
// {

// 	public static void main(String[] args)
// 	{
// 		// TODO Auto-generated method stub
// 		Scanner sc=new Scanner(System.in);
// 		int N=sc.nextInt();
// 		for(int i=0; i<N; i++)
// 		{
			
// 			for(int x=i; x<N-1; x++)
// 			{
// 				System.out.print(' ');
// 			}
// 			for(int j=0; j<i*2+1; j++)
// 			{
// 				System.out.print("*");
				
// 			}
												
// 			System.out.println();
// 		}
// 	}

// }


// 4번

// import java.util.Scanner;

// public class Main
// {

// 	public static void main(String[] args)
// 	{
// 		// TODO Auto-generated method stub
// 		Scanner sc=new Scanner(System.in);
// 		int N=sc.nextInt();
// 		for(int i=0; i<N; i++)
// 		{
// 			for(int x=0; x<i; x++)
// 			{
// 				System.out.print(' ');
// 			}
// 			for(int j=i; j<N; j++)
// 			{
// 				System.out.print("*");
// 			}
			
// 			System.out.println();
// 		}
// 	}

// }


// 3번

// import java.util.Scanner;

// public class Main
// {

// 	public static void main(String[] args)
// 	{
// 		// TODO Auto-generated method stub
// 		Scanner sc=new Scanner(System.in);
// 		int N=sc.nextInt();
// 		for(int i=0; i<N; i++)
// 		{
			
// 			for(int j=i; j<N; j++)
// 			{
// 				System.out.print("*");
			
// 			}
// 			System.out.println();
// 		}
// 	}

// }


// 2번
// import java.util.Scanner;

// public class Main
// {

// 	public static void main(String[] args)
// 	{
// 		// TODO Auto-generated method stub
// 		Scanner sc=new Scanner(System.in);
// 		int N=sc.nextInt();
// 		for(int i=0; i<N; i++)
// 		{
// 			for(int x=i; x<N-1; x++)
// 			{
// 				System.out.print(' ');
// 			}
// 			for(int j=0; j<i+1; j++)
// 			{
// 				System.out.print("*");
			
// 			}
// 			System.out.println();
// 		}
// 	}

// }

// 1번

// import java.util.*;

// public class Main
// {

// 	public static void main(String[] args)
// 	{
// 		// TODO Auto-generated method stub
// 		Scanner sc=new Scanner(System.in);
// 		int N=sc.nextInt();
// 		for(int i=0; i<N; i++)
// 		{
// 			for(int j=0; j<i+1; j++)
// 			{
// 				System.out.print("*");
			
// 			}
// 			System.out.println();
// 		}
// 	}

// }

