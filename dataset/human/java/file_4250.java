import java.util.Scanner;
import java.io.*;

// public class Main {
//     public static void main(String[] args){
//         Scanner sc = new Scanner(System.in);
//     }
// }

public class Main {
    //B Buffet
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum = 0;
        int[] A = new int[n]; 
        int[] B = new int[n]; 
        int[] C = new int[n-1]; 
        for(int i = 0; i < n; i++) A[i] = Integer.parseInt(sc.next());
        for(int i = 0; i < n; i++) sum += Integer.parseInt(sc.next());
        for(int i = 0; i < n-1; i++) C[i] = Integer.parseInt(sc.next());

        int a1 = A[0];
        for(int i = 1; i < n; i++){
            if(a1 + 1 == A[i]) sum += C[a1 - 1];
            a1 = A[i];
        }

        System.out.print(sum);
    }
}
