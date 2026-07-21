import java.util.*;

public class Main{

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int S = sc.nextInt();
        sc.close();
        
        long count = 0;
        for(int i = 0; i <= K; i++){
            for(int j = 0; j <= K; j++){
                int z = S - i - j;
                if(z >= 0 && z <= K)
                    count++;
            }
        }
        System.out.println(count);
    }
}
