import java.util.*;
class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n+1];
        int[] b = new int[n+1];
        int[] c = new int[n];
        int ret = 0;
        for(int i = 1; i <= n ;i++){
            a[i] = sc.nextInt();
        }
        for(int x = 1; x <= n ;x++){
            b[x] = sc.nextInt();
        }
        for(int y = 1; y <= n-1 ;y++){
            c[y] = sc.nextInt();
        }
        for(int z = 1; z <= n;z++ ){
            if(z != n && a[z] + 1 == a[z+1]){
                ret += c[a[z]];
            }
            ret += b[a[z]];
            
        }

        System.out.println(ret);
        sc.close();
    }
}
