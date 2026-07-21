import java.util.*;
import java.io.*;

public class Main {
    
    static int n;
    static int m;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        boolean[][] n_map=new boolean[n][n];
        boolean[][] m_map=new boolean[m][m];
        String str;
        for(int i=0;i<n;i++){
            str=br.readLine();
            for(int j=0;j<n;j++){
                n_map[i][j]=(str.charAt(j)=='#');
            }
        }
        for(int i=0;i<m;i++){
            str=br.readLine();
            for(int j=0;j<m;j++){
                m_map[i][j]=(str.charAt(j)=='#');
            }
        }
        
        for(int i=0;i<=n-m;i++){
            for(int j=0;j<=n-m;j++){
                if(check(n_map,m_map,i,j)){
                    System.out.println("Yes");
                    System.exit(0);
                }
            }
        }System.out.println("No");
        
    }
    
    static boolean check(boolean[][] a,boolean[][] b,int start1,int start2){
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(a[i+start1][j+start2]!=b[i][j]){ return false; }
            }
        }
        return true;
    }
}
