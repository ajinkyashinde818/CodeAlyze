import java.io.*;
import java.util.*;
public class Main {
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String line;
    static  long n,k,T,N,m,A,B;
    static StringTokenizer st;
    static Scanner in = new Scanner(System.in);
    static char [] word;
    static Deque<Character> S  = new LinkedList<>();
    public static void main(String[] args) throws IOException {
      //D - String Formation Data structure
       line=br.readLine();
       for (int i=0;i<line.length();i++)
           S.addLast(line.charAt(i));
       T = Integer.parseInt(br.readLine());
       while (T-->0){
           st = new StringTokenizer(br.readLine());
           k = Integer.parseInt(st.nextToken());
           if (k==1){
               m^=(1);
           }else{
               int F = Integer.parseInt(st.nextToken());
               if (m==0){
                   if (F==1)
                       S.addFirst(st.nextToken().charAt(0));
                   else
                       S.addLast(st.nextToken().charAt(0));
               }else{
                   if (F==1)
                       S.addLast(st.nextToken().charAt(0));
                   else
                       S.addFirst(st.nextToken().charAt(0));
               }
           }
       }
    StringBuilder sb = new StringBuilder();
       while (!S.isEmpty()&&m==0){
           sb.append(S.pollFirst());
       }
        while (!S.isEmpty()&&m==1){
            sb.append(S.pollLast());
        }
       pw.print(sb.toString());
       pw.flush();

    }
}
