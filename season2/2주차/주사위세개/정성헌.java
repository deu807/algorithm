import java.util.*;
public class Main {
    public static void main(String[] args) {

        Scanner sc=new  Scanner(System.in);

        int []arr=new int[3];
        int maxN=0;
        int answer=1;
        for(int i=0; i<3; i++)
        {
            arr[i]= sc.nextInt();
        }

        if(arr[0]==arr[1])
        {
            if(arr[1]==arr[2])
            {
                answer=10000+arr[0]*1000;
                System.out.println(answer);
            }
            else
            {
                answer=1000+arr[0]*100;
                System.out.println(answer);
            }
        }
        else
        {
           if(arr[0]==arr[2])
           {
               answer=1000+arr[0]*100;
               System.out.println(answer);
           }
           else if(arr[1]==arr[2])
           {
               answer=1000+arr[1]*100;
               System.out.println(answer);
           }
           else
           {
               for(int i=0; i<3; i++)
               {
                  maxN=Math.max(maxN,arr[i]);
               }
               answer=maxN*100;
               System.out.println(answer);
           }
        }


    }
}