
import java.util.*;
public class Main {
    public static void main(String[] args) {


        Scanner sc=new  Scanner(System.in);
        int []arr=new int[3];
        int answer=1;
        for(int i=0; i<3; i++)
        {
            arr[i]=sc.nextInt();
        }

        if(arr[0]%2==1||arr[1]%2==1||arr[2]%2==1)
        {
            for(int i=0; i<3; i++)
            {
                if(arr[i]%2==1)
                    answer*=arr[i];
            }
            System.out.println(answer);
        }
        else
        {
            for(int i=0; i<3; i++)
            {
                answer*=arr[i];
            }
            System.out.println(answer);
        }

    }
}
