import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        int X = 0, Y = 0, Z = 0;
        int count = 0;
        for(int i = 0; i <= K; i++) {
            for(int j = 0; j <= K; j++) {
                    X = i;
                    Y = j;
                    Z = S - X - Y;
                    int total = X + Y + Z;
                    if(total == S && Z >= 0 && Z <= K){
                        count++;
                    }
            }
        }
        System.out.println(count);
    }
}
