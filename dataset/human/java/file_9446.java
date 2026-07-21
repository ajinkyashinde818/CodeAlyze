import java.util.*;
class Main {
    static boolean isDoubletPresent(int[] A, int[] B) {
        int count = 0;
        for(int i = 0; i < A.length; i++) {
            if(A[i] == B[i]) {
                count++;
            }
            else {
                count = 0;
            }
            
            if(count >= 3) {
                return true;
            } 
        }
        
        return false;
    }
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      int N = sc.nextInt();
      int A[] = new int[N];
      int B[] = new int[N];
      
      for(int i = 0; i < N; i++) {
          A[i] = sc.nextInt();
          B[i] = sc.nextInt();
      }
      
      System.out.print(isDoubletPresent(A, B) ? "Yes" : "No");
    }
}
