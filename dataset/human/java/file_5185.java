import java.util.*;
import java.io.*;
public class Main
{
    public static void main(String []args) throws IOException {
    	FastScanner in  = new FastScanner(System.in);
    	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), false);
    	solve(in, out);
    	in.close();
    	out.close();
    }
    static long gcd(long a, long b){ return (b==0) ? a : gcd(b, a%b); }
    static int gcd(int a, int b){ return (b==0) ? a : gcd(b, a%b); }
    static class FastScanner{
	BufferedReader reader;
	StringTokenizer st;
	FastScanner(InputStream stream){reader=new BufferedReader(new InputStreamReader(stream));st=null;}
	String next(){while(st == null || !st.hasMoreTokens()){try{String line = reader.readLine();if(line == null){return null;}
	     st = new StringTokenizer(line);}catch (Exception e){throw new RuntimeException();}}return st.nextToken();}
	String nextLine()  {String s=null;try{s=reader.readLine();}catch(IOException e){e.printStackTrace();}return s;}
	int    nextInt()   {return Integer.parseInt(next());}
	long   nextLong()  {return Long.parseLong(next());}
	double nextDouble(){return Double.parseDouble(next());}
	char   nextChar()  {return next().charAt(0);}
	int[]  nextIntArray(int n)         {int[] arr= new int[n];   int i=0;while(i<n){arr[i++]=nextInt();}  return arr;}
	long[] nextLongArray(int n)        {long[]arr= new long[n];  int i=0;while(i<n){arr[i++]=nextLong();} return arr;}
	int[]  nextIntArrayOneBased(int n) {int[] arr= new int[n+1]; int i=1;while(i<=n){arr[i++]=nextInt();} return arr;}
	long[] nextLongArrayOneBased(int n){long[]arr= new long[n+1];int i=1;while(i<=n){arr[i++]=nextLong();}return arr;}
	void   close(){try{reader.close();}catch(IOException e){e.printStackTrace();}}
    }
    
    /********* SOLUTION STARTS HERE ************/
    
    private static void solve(FastScanner in, PrintWriter out){
        String s = in.next().trim();
        int q = in.nextInt();
        int f = 0,t = 0, tmp;
        char c='.';
        StringBuilder head = new StringBuilder();
        StringBuilder tail = new StringBuilder();
        while(q-->0){
            t = in.nextInt();
            if(t==1){
                f++;
            }else{
                tmp = in.nextInt();
                c = in.nextChar();
                if(f%2==0){// NOT REVERSED
                    if(tmp==1){
                        head.append(c);
                    }else{
                        tail.append(c);
                    }
                }else{// REVERSED
                    if(tmp==1){
                        tail.append(c);
                    }else{
                        head.append(c);
                    }
                }
            }
        }
        StringBuilder ans = new StringBuilder();
        if (f%2==1) {
            tail.reverse();
            ans.append(tail)
               .append(new StringBuilder(s).reverse())
               .append(head);
        } else {
            head.reverse();
            ans.append(head).append(s).append(tail);
        }
        out.println(ans.toString());
    }
    
    /************* SOLUTION ENDS HERE **********/
}
