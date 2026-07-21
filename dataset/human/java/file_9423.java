import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args)
    {
        CP sc =new CP();
        int n = sc.nextInt();
        Pair[] p = new Pair[n];
        for(int i=0;i<n;i++){
            p[i] = new Pair(sc.nextInt(), sc.nextInt());
        }
        boolean flag = true;
        for(int i=0;i<n-2;i++){
            if(p[i].x==p[i].y && p[i+1].x==p[i+1].y && p[i+2].x==p[i+2].y){
                flag = false;
                break;
            }
        }
        if(!flag)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
    static class Pair{
        int x,y;
        Pair(int a, int b){
            x=a;
            y=b;
        }
    }
    /*****************************************************************************/
    static class CP
    {
        BufferedReader bufferedReader;
        StringTokenizer stringTokenizer;
        public CP() {
            bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        }
        int nextInt() {
            return Integer.parseInt(NNNN());
        }
        long nextLong() {
            return Long.parseLong(NNNN());
        }
        double nextDouble() {
            return Double.parseDouble(NNNN());
        }
        String NNNN() {
            while (stringTokenizer == null || !stringTokenizer.hasMoreElements()) {
                try {
                    stringTokenizer = new StringTokenizer(bufferedReader.readLine());
                }
                catch (IOException  e) {
                    e.printStackTrace();
                }
            }
            return stringTokenizer.nextToken();
        }
        String nextLine() {
            String spl = "";
            try {
                spl = bufferedReader.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return spl;
        }
    }
    /*****************************************************************************/
}
