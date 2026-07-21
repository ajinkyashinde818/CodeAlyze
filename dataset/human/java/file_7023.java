import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();
        int N = scanner.nextInt();
        ArrayList<Integer> A = new ArrayList<>();

        for(int i=0; i<N; i++){
            A.add(scanner.nextInt());
        }
        int maxbet = 0;
        for(int i=0; i<N-1; i++){
            int bet = A.get(i+1) - A.get(i);
            if(bet > maxbet){
                maxbet = bet;
            }
        }
        int bet0andN = A.get(0) + (K-A.get(N-1));
        if(maxbet < bet0andN){
            maxbet = bet0andN;
        }
        System.out.println(K - maxbet);
    }
}
