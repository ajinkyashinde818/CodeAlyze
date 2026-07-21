import java.util.*;

public class Main {
    static public void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int firsta = sc.nextInt();
        int prea = firsta, maxdis = 0, nowa = 0;

        for (int i = 0; i < n - 1; i++) {
            nowa = sc.nextInt();
            maxdis = Math.max(maxdis, nowa - prea);
            prea = nowa;
        }

        maxdis = Math.max(maxdis, firsta + k - nowa);

        System.out.println(k - maxdis);

    }
}
