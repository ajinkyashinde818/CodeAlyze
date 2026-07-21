import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.PI;
import static java.lang.System.in;
import static java.lang.System.out;

public class Main
{
    public static void main(String[] args) throws Exception
    {   
        Foster sc = new Foster();
        PrintWriter p = new PrintWriter(out);
        int count = 0;
        boolean poss = false;
        int n = sc.nextInt();
        for(int i = 0; i < n; i++)
        {
            int u = sc.nextInt(), v = sc.nextInt();
            if(u==v)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if(count>=3)    poss = true;
        }
        p.println(poss ? "Yes" : "No");
        p.close();
    }
/*
*/    
/*
1. Check overflow in pow function or in general
2. Check indices of read array function
3. Think of an easier solution because the problems you solve are always easy
4. Check iterator of loop
5. If still doesn't work, then jump from the 729th floor 'coz "beta tumse na ho paayega"

    Move to top!!
*/

    static int[] sort(int[] a)
    {
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i : a)
        {
            arr.add(i);
        }
        Collections.sort(arr);
        for(int i = 0 ; i < arr.size(); i++)
        {
            a[i] = arr.get(i);
        }
        return a;
    }
    
    static class Foster 
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        StringTokenizer st = new StringTokenizer("");
        String next() 
        {
            while (!st.hasMoreTokens())
                try 
                {
                    st = new StringTokenizer(br.readLine());
                } 
                catch (IOException e) 
                {
                    e.printStackTrace();
                }
            return st.nextToken();
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
        int[] intArray(int n)                   // Check indices
        {
            int arr[] = new int[n];
            for(int i = 0; i < n; i++)
            {
                arr[i] = nextInt();
            }
            return arr;
        }
        long[] longArray(int n)                 // Check indices
        {
            long arr[] = new long[n];
            for(int i = 0; i < n; i++)
            {
                arr[i] = nextLong();
            }
            return arr;
        }
        int[] getBits(int n)                    //in Reverse Order
        {
            int a[] = new int[31];
            for(int i = 0; i < 31; i++)
            {
                if(((1<<i) & n) != 0)
                    a[i] = 1;
            }
            return a;
        }
        static long pow(long... a)
        {
            long mod = Long.MAX_VALUE;
            if(a.length == 3)   mod = a[2];
            long res = 1;
            while(a[1] > 0)
            {
                if((a[1] & 1) == 1)
                    res = (res * a[0]) % mod;
                a[1] /= 2;
                a[0] = (a[0] * a[0]) % mod;
            }
            return res;
        }
        void print(Object... o) 
        {
            for(Object next : o)
            {
                System.err.print(next + " ");
            }
        }
        void println(Object... o) 
        {
            for(Object next : o)
            {
                System.err.print(next + " ");
            }
            System.err.println();
        }
        void watch(Object...a) throws Exception 
        {
            int i = 1;
            for (Object o: a) 
            {
                boolean found = false;
                if (o.getClass().isArray()) 
                {
                    String type = o.getClass().getName().toString();
                    switch (type) 
                    {
                        case "[I":
                        {
                            int[] test = (int[]) o;
                            println(i + " : " + Arrays.toString(test));
                            break;
                        }
                        case "[[I":
                        {
                            int[][] obj = (int[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        case "[J":
                        {
                            long[] obj = (long[]) o;
                            println(i + " : " + Arrays.toString(obj));
                            break;
                        }
                        case "[[J":
                        {
                            long[][] obj = (long[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        case "[D":
                        {
                            double[] obj = (double[]) o;
                            println(i + " : " + Arrays.toString(obj));
                            break;
                        }
                        case "[[D":
                        {
                            double[][] obj = (double[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        case "[Ljava.lang.String":
                        {
                            String[] obj = (String[]) o;
                            println(i + " : " + Arrays.toString(obj));
                            break;
                        }
                        case "[[Ljava.lang.String":
                        {
                            String[][] obj = (String[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        case "[C":
                        {
                            char[] obj = (char[]) o;
                            println(i + " : " + Arrays.toString(obj));
                            break;
                        }
                        case "[[C":
                        {
                            char[][] obj = (char[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        default:
                        {
                            println(i + " : type not identified");
                            break;
                        }
                    }
                    found = true;
                }
                if (o.getClass() == ArrayList.class) 
                {
                    println(i + " : LIST = " + o);
                    found = true;
                }
                if (o.getClass() == TreeSet.class) 
                {
                    println(i + " : SET = " + o);
                    found = true;
                }
                if (o.getClass() == TreeMap.class) 
                {
                    println(i + " : MAP = " + o);
                    found = true;
                }
                if (o.getClass() == HashMap.class) 
                {
                    println(i + " : MAP = " + o);
                    found = true;
                }
                if (o.getClass() == LinkedList.class) 
                {
                    println(i + " : LIST = " + o);
                    found = true;
                }
                if (o.getClass() == PriorityQueue.class) 
                {
                    println(i + " : PQ = " + o);
                    found = true;
                }
                if (!found) 
                {
                    println(i + " = " + o);
                }
                i++;
            }
        }
    }
}
