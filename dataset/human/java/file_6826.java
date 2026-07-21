import java.util.*;
class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        int largest = 0;
        A[0] = sc.nextInt();
        largest = A[0];
        for (int i = 1; i < A.length; i++) {
            A[i] = sc.nextInt();
        }
        largest = A[0] + K - A[N-1];
        for (int i = 1; i < A.length; i++) {
            largest = Math.max(largest,A[i] - A[i-1]);
        }
        
        System.out.println(K - largest);
        
    }
}
