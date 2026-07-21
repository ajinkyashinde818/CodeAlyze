import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pair {
    public int first;
    public int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Queue<Pair> q = new LinkedList<Pair>();

        int n = scanner.nextInt();

        boolean doublet = false;

        for (int i = 0 ; i < n ; i++) {
            int d1 = scanner.nextInt();
            int d2 = scanner.nextInt();

            q.add(new Pair(d1,d2));
            if (q.size() >= 3) {
                int countDoublet = 0;
                for (Pair item: q) {
                    if (item.first == item.second) {
                        countDoublet++;
                    }
                }
                if (countDoublet == 3) {
                    doublet = true;
                    break;
                }
                q.remove();
            }
        }

        if (doublet) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
