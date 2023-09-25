import java.util.*;


public class Main
{

    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int []arr=new int[9];
        ArrayList list = new ArrayList();
        int indexToRemove = 0;
        int indexToRemove1 = 0;
        int sum=0;

        for(int i=0; i<9; i++)
        {
            arr[i]=sc.nextInt();
            sum+=arr[i];
        }
        Arrays.sort(arr);


        for(int i=0; i<9; i++)
        {
            for(int j=i+1; j<9; j++)
            {
                int temp=arr[i]+arr[j]; 

                if(sum-temp==100)
                {
                    indexToRemove=arr[i];
                    indexToRemove1=arr[j];
                }
            }
        }

        for(int i=0; i<9; i++)
        {
            if(indexToRemove!=arr[i]&&indexToRemove1!=arr[i])
            {
                list.add(arr[i]);
            }
        }
        for(int i=0; i< list.size(); i++)
        {
            System.out.println(list.get(i));
        }
        sc.close();

    }
}