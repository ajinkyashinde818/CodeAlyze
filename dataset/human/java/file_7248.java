import java.util.*;

public class Main {
  public static void main(String[] args ) throws Exception {
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    ArrayList<Integer> A = new ArrayList<Integer>();
    while(sc.hasNext()){
        A.add(sc.nextInt());
    }
    int[] right = new int[N];
    int max = 0;
    for(int i = 0;i < N-1;i++){
        if(i == N-2){
            right[i+1] = ((K - A.get(i+1)) + A.get(0)) ;
            // System.out.println("right[i+1]" + right[i+1]);
        }
        right[i] = A.get(i+1) - A.get(i);
        // System.out.println(A.get(i+1));
        // System.out.println(A.get(i));
    }   
    for(int i = 0;i < N-1;i++){
                if(max < Math.max(right[i+1],right[i]))
        max = Math.max(right[i+1],right[i]);
        // System.out.println("max" + max);
    }
    System.out.println(K - max);
  }
  
}
