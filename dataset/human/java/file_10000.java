import java.util.*;

class Main{
    static int minc = 100000000;
    static int n;
    static int m;
    static int x;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        x = sc.nextInt();
        int[][] nm = new int[n][m];
        int[] c = new int[n];
        for(int i=0;i<n;i++){
            c[i] = sc.nextInt();
            for(int j=0;j<m;j++){
                nm[i][j] = sc.nextInt();
            }
        }

        int[] list = new int[n];
        search(nm, c, list, 0);

        if(minc==100000000){
            System.out.println(-1);
        }
        else{
            System.out.println(minc);
        }

    }

    private static void search(int[][] nm, int[] c, int[] list, int now) {
        if(now!=n){
            list[now] = 1;
            search(nm, c, list, now+1);
            list[now] = 0;
            search(nm, c, list, now+1);
        }
        else{
            int sumc = 0;
            int[] check = new int[m];
            for(int i=0;i<n;i++){
                if(list[i]==0)continue;
                sumc += c[i];
                for(int j=0;j<m;j++){
                    check[j] += nm[i][j];
                }
            }
            boolean flag = true;
            for(int i=0;i<m;i++){
                if(check[i]<x)flag=false;
            }
            if(flag)minc = Math.min(minc, sumc);
        }
        
    }
}
