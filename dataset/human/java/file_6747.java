import java.util.Scanner;
import java.util.LinkedList;
import java.lang.Math;
import java.util.Arrays;
import java.util.Collections;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] A = new int[n];

        for(int i=0;i <n;i++){
            A[i]=sc.nextInt();
        }
        sc.close();

        Arrays.sort(A);

        int[] B = new int[n];
        
        for(int i=0;i<n-1;i++){
            B[i]=A[i+1]-A[i];
        }
        B[n-1] = A[0]+k-A[n-1];

        int max = B[0];

        for(int i=0;i<B.length;i++){
            if(max<B[i]){
                max = B[i];
            }
        }
        k=k-max;
        System.out.print(k);
        
    //     for(int i=0;i<A.length;i++){
    //         System.out.println(A[i]);
    //     }
    //     for(int i=0;i<B.length;i++){
    //         System.out.println(B[i]);
    //     }
    }
}
