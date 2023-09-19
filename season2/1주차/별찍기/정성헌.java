//6번


import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
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
	}

}

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

