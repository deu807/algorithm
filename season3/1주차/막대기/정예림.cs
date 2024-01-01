using System;

namespace algorithm
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int cnt = 0;
            int temp = 0;

            int n = int.Parse(Console.ReadLine());
            int[] num = new int[n];

            for (int i = 0; i < n; i++)
            {
                num[i] = int.Parse(Console.ReadLine());
            }

            for (int i = n-1; i >= 0; i--)
            {
                if (num[i]>temp)
                {
                    temp = num[i];
                    cnt++;
                }

                //if (num[n - 1] < num[i])
                //{
                //    cnt++;
                //}
            }

            Console.WriteLine(cnt);       //맨 오른쪽에 있는 자기자신 +1
        }
    }
}