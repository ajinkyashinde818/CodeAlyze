using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace ConsoleApplication
{
    public class main
    {
        static void Main()
        {
            string [] vals = Console.ReadLine().Split(' ');
            int N = int.Parse(vals[0]);
            int M = int.Parse(vals[1]);
            string [] A = new string [N];
            string [] B = new string [M];

            for (int i =0; i< N ; i++) 
                A [i] = Console.ReadLine();
            for (int i = 0; i < M; i++) 
                B[i] = Console.ReadLine();
            for (int y = 0; y<= N-M; y++)
            {
                for (int x = 0; x<= N-M; x++)
                {
                    bool match = true;
                    for (int j = 0; j < M; j++)
                    {
                        for (int i = 0; i < M; i++)
                        {
                            if ( A[y + j][x + i] != B[j][i])
                            {
                                match = false;
                            }
                        }
                    
                    }
                    if (match)
                    {
                        Console.WriteLine("Yes");
                        return;
                    }
                }
            }
            Console.WriteLine("No");
        }

    }
}
