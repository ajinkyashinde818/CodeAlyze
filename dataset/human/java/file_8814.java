import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int A = scn.nextInt();
        int B = scn.nextInt();
        int K = scn.nextInt();
        ArrayList<Integer> hits = new ArrayList<Integer>();
        int cnt = 0;
        for(int i=1; i<=100; i++) {
            if(A%i == 0 && B%i == 0) hits.add(i);
        }
        System.out.println(hits.get(hits.size() - K));
        scn.close();
    }
}
