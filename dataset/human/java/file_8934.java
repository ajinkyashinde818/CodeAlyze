import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int K = scanner.nextInt();

        ArrayList<Integer> ok = new ArrayList<>();

        for(int i=1; i<=100; i++){
            if(A%i ==0 && B%i==0){
                ok.add(i);
            }
        }

        Collections.sort(ok, Comparator.reverseOrder());

        System.out.println(ok.get(K-1));

    }
}
