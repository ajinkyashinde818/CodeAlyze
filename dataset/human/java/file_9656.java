import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;

public class Main implements Runnable 
{
    static class InputReader 
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
        private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public InputReader(InputStream stream) 
        {
            this.stream = stream;
        }
        
        public int read()
        {
            if (numChars==-1) 
                throw new InputMismatchException();
            
            if (curChar >= numChars) 
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                }
                catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                
                if(numChars <= 0)               
                    return -1;
            }
            return buf[curChar++];
        }
    
        public String nextLine()
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
        public int nextInt() 
        {
            int c = read();
            
            while(isSpaceChar(c)) 
                c = read();
        
            int sgn = 1;
        
            if (c == '-') 
            {
                sgn = -1;
                c = read();
            }
            
            int res = 0;
            do
            {
                if(c<'0'||c>'9') 
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c)); 
        
            return res * sgn;
        }
        
        public long nextLong() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            long res = 0;
            
            do 
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }    
            while (!isSpaceChar(c));
                return res * sgn;
        }
        
        public double nextDouble() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') 
            {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') 
            {
                c = read();
                double m = 1;
                while (!isSpaceChar(c))
                {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
    
        public String readString() 
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do 
            {
                res.appendCodePoint(c);
                c = read();
            } 
            while (!isSpaceChar(c));
            
            return res.toString();
        }
    
        public boolean isSpaceChar(int c) 
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    
        public String next()
        {
            return readString();
        }
        
        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
        }
    }
    public static void main(String args[]) throws Exception 
    {
        new Thread(null, new Main(),"Main",1<<27).start();
    }
    
    static class Pair{
        int nod;
        int ucn;
        
        
        Pair(int nod,int ucn){
            this.nod=nod;
            this.ucn=ucn;
            
        }
        
        public static Comparator<Pair> wc = new Comparator<Pair>(){
            public int compare(Pair e1,Pair e2){
                
                //reverse order
                if(e1.ucn < e2.ucn) 
                    return 1;  // 1 for swaping.
                else if (e1.ucn > e2.ucn) 
                    return -1; 
                else{
                    // if(e1.siz>e2.siz)
                    //     return 1;
                    // else
                    //     return -1;
                    return 0;
                } 
            }
        };	
    }

    public static long gcd(long a,long b){
        if(b==0)return a;
        else return gcd(b,a%b);
    }


    ////recursive BFS
    public static int bfsr(int s,ArrayList<Integer>[] a,boolean[] b,int[] pre){
        b[s]=true;
        int p = 1;
        int n = pre.length -1;
        int t = a[s].size();
        int max = 1;
        for(int i=0;i<t;i++){
            int x = a[s].get(i);
            if(!b[x]){
                //dist[x] = dist[s] + 1;
                int xz =  (bfsr(x,a,b,pre));
                p+=xz;
                max = Math.max(xz,max);
            }
        }
        max = Math.max(max,(n-p));
        pre[s] = max;
        return p;
    }

//// iterative BFS
    public static int bfs(int s,ArrayList<Integer>[] a,int[] dist,boolean[] b,PrintWriter w){
        b[s]=true;
        int siz = 0;
        
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        while(q.size()!=0){
            int i=q.poll();
            Iterator<Integer> it = a[i].listIterator();
            int z=0;
            while(it.hasNext()){
                z=it.next();
                if(!b[z]){
                    b[z]=true;
                    dist[z] = dist[i] + 1;
                    siz++;
                    q.add(z);
                }
            }   
        
        }
        return siz;
    }

    


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


    public void run()
    {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        int defaultValue=0;
        

        // int tc = sc.nextInt();

        // while(tc-->0){
            int n = sc.nextInt();
            int[][] a = new int[2][n];
            for(int i=0;i<n;i++){
                a[0][i] = sc.nextInt();
                a[1][i] = sc.nextInt();
            }
            boolean f = false;
            for(int i=0;i<n-2;i++){
                //w.println(i);
                if(a[0][i]==a[1][i] && a[0][i+1]==a[1][i+1] && a[0][i+2]==a[1][i+2]){
                    f = true;
                    break;
                }
                
            }
            if(f) w.println("Yes");
            else w.println("No");
            
            
        
       //}
        w.flush();
        w.close();
    }

    
}
