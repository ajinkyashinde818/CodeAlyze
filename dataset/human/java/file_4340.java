import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<Integer> A = new ArrayList<>();
        List<Integer> B = new ArrayList<>();
        List<Integer> C = new ArrayList<>();
        for(int i=0; i<N; i++){
            A.add(scanner.nextInt());
        }
        for(int i=0; i<N; i++){
            B.add(scanner.nextInt());
        }
        for(int i=0; i<N-1; i++){
            C.add(scanner.nextInt());
        }
        
        int score = 0;
        for(int i=0; i<N; i++){
            score += B.get(i);
        }
        for(int i=0; i<N-1; i++){
            if(A.get(i)+1 == A.get(i+1)){
                score += C.get(A.get(i)-1);
            }
        }

        System.out.println(score);

    }
}
