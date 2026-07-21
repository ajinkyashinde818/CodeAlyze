import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        int n = scanner.nextInt();
        ArrayList<Integer> A = new ArrayList<>();
        for (int i=0;i<n;i++){
            A.add(scanner.nextInt());
        }
        Collections.sort(A);
        ArrayList<Integer> B = new ArrayList<>();
        B.add(k-A.get(n-1)+A.get(0));
        for (int i=1;i<A.size();i++){
            B.add(A.get(i)-A.get(i-1));
        }
        System.out.println(k-Collections.max(B));

    }

}
