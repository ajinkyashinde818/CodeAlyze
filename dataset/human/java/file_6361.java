import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        int sum = 0;
        for(int i=0;i<=K;i++)
        {
            for(int j=0;j<=K;j++)
            {
                int z = S - i - j;
                if(0 <= z && z <= K)
                {
                    sum++;
                }
            }
        }
        System.out.println(sum);
    }
}
