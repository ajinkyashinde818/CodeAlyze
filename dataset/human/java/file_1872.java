import java.util.Scanner;
import java.util.ArrayList;

class Main{
    static int D;
    static int G;
    static int[] p;
    static int[] c;
    static int[] a;
    static int ans = Integer.MAX_VALUE;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        D = sc.nextInt();
        G = sc.nextInt();
        p = new int[D];
        c = new int[D];
        a = new int[D];
        for (int i=0;i<D;i++){
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        sc.close();
        dfs(0);
        System.out.println(ans);
    }

    public static void dfs(int pos){
        if (pos==D){
            func();
        } else {
            a[pos] = 0;
            dfs(pos+1);
            a[pos] = 1;
            dfs(pos+1);
        }
    }

    public static void func(){
        int point = 0;
        int cnt = 0;
        for (int i=0;i<D;i++){
            if (a[i]==1){
                point += (i+1)*100*p[i]+c[i];
                cnt += p[i];
            }
        }
        for (int i=D-1;i>=0;i--){
            if (a[i]==1){
                continue;
            }
            for (int j=0;j<p[i]-1;j++){
                if (point>=G){
                    break;
                }
                point += (i+1)*100;
                cnt++;
            }
            if (point>=G){
                break;
            }
        }
        if (point<G){
            return;
        }
        ans = Math.min(ans,cnt);
    }
}
