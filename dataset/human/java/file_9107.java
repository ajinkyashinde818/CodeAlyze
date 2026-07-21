import java.util.*;
//mport java.io.*;


public class Main{

    static int INFTY = Integer.MAX_VALUE;
    static long num=1000000007;
    public static void main (String args[]){
        //初期処理
        Scanner sc=new Scanner(System.in);
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // try{
            // int n = Integer.parseInt(br.readLine());
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        for (int i=0;i<m;i++){
            a[i] = sc.nextInt();
            if(i==0){continue;}
        //2連続で壊れてたら0で終了
            if(a[i]-a[i-1]==1){
                System.out.println(0);
                return;
            }
        }
        long[] f = new long[n+1];
        f[0]=1;
        f[1]=1;
        for(int i=2;i<=n;i++){
            f[i] = (f[i-1] + f[i-2]) % num;
        }
        //壊れてない場合は区間分けすると死亡
        if(m==0){
            System.out.println(f[n]);
            return;
        }
        //最初の区間は特別
        long ans = f[a[0]-1] % num;

        for(int i=1;i<m;i++){
            //ans = ( ans % num ) * (f[a[i]-a[i-1]-1] % num ) * (f[a[i+1]-a[i]-1] % num) % num;
            ans = ( ans % num ) * (f[a[i]-a[i-1]-2]) % num;
        }
        //最後の区間も特別
        ans = ( ans % num ) * (f[n-a[m-1]-1]) % num;
        System.out.println(ans);
    }
        

}
