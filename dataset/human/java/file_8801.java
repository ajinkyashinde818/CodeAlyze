import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int k = scanner.nextInt();
        int count = 0;

        for (int i=100;i>0;i--){
            if (a%i==0&&b%i==0){
                count++;
                if (count==k){
                    System.out.println(i);
                    break;
                }
            }
        }

    }
}
