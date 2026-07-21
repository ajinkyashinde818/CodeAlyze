import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


/*
* Problem : abc 160 - C
* Acknowledgement : None
* Author : deathnaught_
* GitHub : www.github.com/DeathNaughT-GitHub
* Complexity : O()
*/

public class Main
{

    static int N, H;
    public static void main(String[] args) 
    {
        FastReader sc = new FastReader();
        H = sc.nextInt();
        N = sc.nextInt(); 
        int arr[] = sc.nextArray(N);
        int dif = H - arr[N - 1] + arr[0];
        for (int i = 1; i < N; i++) {
            dif = Math.max(dif, arr[i] - arr[i - 1]);
        }
        System.out.println(H - dif);
        
    }

    static class FastReader 
    { 

        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 

		boolean hasNext()
		{
		    return st == null ? false : true;
		}

        char nextChar()
        {
            return next().charAt(0);
        }
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 

        int[] nextArray(int rows)
        {
            int arr[] = new int[rows];            
            for (int i = 0; i < rows; i++)
            arr[i] = nextInt();
            return arr;
        }

        long[] nextLongArray(int rows)
        {
            long arr[] = new long[rows];            
            for (int i = 0; i < rows; i++)
            arr[i] = nextLong();
            return arr;
        }

        char[] nextCharArray(int rows)
        {
            char arr[] = new char[rows];
            for (int i = 0; i < rows; i++)
            arr[i] = next().charAt(0);
            return arr;
        }

        int[][] nextMatrix(int rows, int columns)
        {
            int mat[][] = new int[rows][columns];
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    mat[i][j] = nextInt();
                }
            }
            return mat;
        }
    } 

}
