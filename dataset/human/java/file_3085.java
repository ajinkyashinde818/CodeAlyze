import java.util.*;

class Main{
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] a = new int[M];
        int[] b = new int[M];
        int[] c = new int[N + 1];

        for(int i=0; i<M; i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            if(a[i]==1){
                c[b[i]]++;
            }
            if(b[i]==N){
                c[a[i]]++;
            }
        }

        for(int i=1; i<N; i++){
            if(c[i]>1){
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
