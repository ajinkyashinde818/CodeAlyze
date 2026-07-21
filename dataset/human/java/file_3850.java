import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter pw = new PrintWriter(System.out);
    public static String line;
    public static StringTokenizer st;
    public static ArrayList<ArrayList<Integer>> adjList;
    public static int[] dx = {-1, 0, 1, 0, -1, 1, 1, -1};
    public static int[] dy = {0, 1, 0, -1, 1, 1, -1, -1};
    public static int INF = 0x3f3f3f3f;
    public static int MOD = 1000000007;

    public static void main(String[] args) throws Exception{
        String s = br.readLine();
        int xCount = 0;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'x'){
                xCount++;
            } else{
                sb.append(s.charAt(i));
            }
        }

        // System.out.println(sb.reverse().toString() + " " + sb.toString());
        if(sb.toString().equals(sb.reverse().toString())){
            int i = 0;
            int j = s.length() - 1;
            int ans = 0;
            while(i < j){
                char a = s.charAt(i);
                char b = s.charAt(j);

                if(a == b){
                    i++;
                    j--;
                } else if(a == 'x'){
                    i++;
                    ans++;
                } else{
                    j--;
                    ans++;
                }
            }
            pw.print(ans + "\n");
        } else{
            pw.print("-1\n");
        }

        pw.close(); 
        br.close();
    }
}

class Pair{
    public long x, y;

    Pair(long _x, long _y){
        x = _x;
        y = _y;
    }
}
class Point implements Comparable<Point>{
    public double x, y;

    Point(double x, double y){
        this.x = x;
        this.y = y;
    }

    public int compareTo(Point p){
        if(x != p.x) return x < p.x ? -1 : 1;
        else if(y != p.y) return y < p.y ? -1 : 1;
        return 0;
    }
}
