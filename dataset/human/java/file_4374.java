import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        final int N = scan.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N];
        for(int i = 0; i < N; i++){
            A[i] = scan.nextInt();
        }
        for(int i = 0; i < N; i++){
            B[i] = scan.nextInt();
        }
        for(int i = 0; i < N - 1; i++){
            C[i] = scan.nextInt();
        }
        scan.close();
        int result = 0;
        for(int i = 0; i < N; i++){
            result += B[A[i] - 1];
            if(i != 0 && A[i - 1] + 1 == A[i] ){
                result += C[A[i - 1] - 1];
            }
        }

        System.out.println(result);
        
    }
    
}
