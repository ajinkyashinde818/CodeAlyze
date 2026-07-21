import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int c = a > b ? b : a;
        List<Integer> d = new ArrayList<>();
        for(int i=1; i<=c; i++) {
            if(a%i == 0 && b%i ==0) {
                d.add(i);
            }
        }
        System.out.println(d.get(d.size()-k));
    }
}
