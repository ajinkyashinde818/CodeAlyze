import java.util.*;
 
public class Main{
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        Map<Integer, Integer> toN = new HashMap<>();
        int[][] a = new int[2][M];
        for(int i = 0; i < M; i++){
            a[0][i] = sc.nextInt();
            a[1][i] = sc.nextInt();
            if(a[1][i] == N){
                toN.put(a[0][i], N);
            }
        }
        sc.close();

        for(int i = 0; i < M; i++){
            if(a[0][i] == 1){
                if(toN.containsKey(a[1][i])){
                    System.out.println("POSSIBLE");
                    return;
                }
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
