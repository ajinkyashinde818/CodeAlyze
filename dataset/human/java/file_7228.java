import java.util.Scanner;
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] a = new int[(int)(N)];
        for(int i = 0 ; i < N ; i++){
                a[i] = sc.nextInt();    
        }
        
        int L = 0;
        int H = 0;
        for(int i = 0 ; i < N - 1 ; i++){
            H = a[i + 1] - a[i];
            if(L < H){
                L = H;
            }
            //System.out.println(i + " " + H + " " + L);
        }
        
        H = (K + a[0]) - a[N - 1];
        if(L < H){
                L = H;
            }
        //System.out.println(H + " " + L);
        System.out.print(K - L);
    }
}
