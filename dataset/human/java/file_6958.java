import java.util.*;
import java.io.*;



public class Main {
    public static PrintStream out = new PrintStream(System.out);
    static LinkedList<Integer> adj[];
    static boolean[] vis;
    static final int nINF = Integer.MIN_VALUE;
    static final int INF = Integer.MAX_VALUE;
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int k = sc.nextInt(); //perimeter
        int n = sc.nextInt(); //houses
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        //find candidate start
        int mn = nINF;
        mn = Math.max((k + a[0]) - a[n - 1], mn);
        for(int i = 0; i < n - 1; i++)
            mn = Math.max(a[i + 1] - a[i], mn);
        out.println(k - mn);

    }
    
    //returns index; outputs earliest occurence; -1 if target value does not exist
    static int getUpper(int[] arr, int target)  
    {  
        int start = 0, end = arr.length - 1;  
    
        int ans = -1;  
        while (start <= end) {  
            int mid = (start + end) / 2;  
    
            // Move to right side if target is  
            // greater.  
            if (arr[mid] <= target) {  
                start = mid + 1;  
            }  
    
            // Move left side.  
            else {  
                ans = mid;  
                end = mid - 1;  
            }  
        }  
        return ans;  
    }  
    
    //returns index; outputs latest occurence; -1 if target value does not exist
    static int getLower(int[] arr, int target)  
    {  
        int start = 0, end = arr.length-1;  
    
        int ans = -1;  
        while (start <= end) {  
            int mid = (start + end) / 2;  
    
            // Move to the left side if the target is smaller  
            if (arr[mid] >= target) {  
                end = mid - 1;  
            }  
    
            // Move right side  
            else {  
                ans = mid;  
                start = mid + 1;  
            }  
        }  
        return ans;  
    }  
        
    
    static void dfs(int n){
        Iterator<Integer> i = adj[n].listIterator();
        while(i.hasNext()){
            Integer a = i.next();
            if(!vis[a]){
                vis[a] = true;
                dfs(a);
            }
        }
    }
    
    static void initAdj(int n){
        adj = new LinkedList[n + 2];
        for(int i = 0; i <= n + 1; i++)
            adj[i] = new LinkedList();
    }

    static String removeLastChar(String ss) {
        if (ss == null || ss.length() == 0) {
            return ss;
        }
        return ss.substring(0, ss.length()-1);
    }
    
    static void solveLunLun(){
        FastScanner sc = new FastScanner();
        Queue<Long> q = new ArrayDeque();
        for(int i = 1; i <= 9; i++){
            q.add((long) i);
        }
        int k = sc.nextInt();
        int cnt = 0;
        long x = 1;
        while(cnt < k){
            x = q.poll();
            cnt++;
            if(cnt >= k) break;
            
            long d = x % (long) 10;
            if(d == 0){
                q.add( (10 * x));
                q.add( (10 * x) + d + 1 );
            }
            else if (d == 9){
                q.add( (10 * x) + d - 1);
                q.add( (10 * x) + d);
            }
            else {
                q.add( (10 * x) + d - 1);
                q.add( (10 * x) + d);
                q.add( (10 * x) + d + 1 );                
            }
        }
        out.println(x);

    }
 
}


class FastScanner { 
    BufferedReader br; 
    StringTokenizer st; 

    public FastScanner() 
    { 
        br = new BufferedReader(new
                 InputStreamReader(System.in)); 
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

    int[] nextIntArray(int length) {
       int[] arr = new int[length];
       for (int i = 0; i < length; i++)
           arr[i] = nextInt();
       return arr;
   }
} 

class Node
{
    public int V;
    public Node(int v)
    {
        this.V=v;
    }
}

class Tuple{
    public int first;
    public int second;
    public int third;
    public Tuple(int a, int b, int c){
        first = a;
        second = b;
        third = c;
    }
}

class Pair{
    public int first;
    public int second;
    public Pair(int a, int b){
        first = a;
        second = b;
    }
    

}
