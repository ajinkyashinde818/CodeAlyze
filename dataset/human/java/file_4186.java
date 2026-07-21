import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        List<Integer> numsListA = new ArrayList<Integer>();
        List<Integer> numsListB = new ArrayList<Integer>();
        List<Integer> numsListC = new ArrayList<Integer>();
        int score = 0;

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();                     //N品の料理を食べる
        for(int i = 0; i < n; i++) {                //N回scanします ListA
            numsListA.add(scan.nextInt());
        }
        for(int i = 0; i < n; i++) {                //N回scanします ListB
            numsListB.add(scan.nextInt());
        }
        for(int i = 0; i < n - 1; i++) {            //N-1回scanします ListC
            numsListC.add(scan.nextInt());
        }

        for (int i = 0; i < n; i++) {               //ListB満足度をscoreにSUM
            score += numsListB.get(numsListA.get(i) - 1);
        }

        for (int i = 0; i < n - 1; i++) {           //ListCボーナスをscoreにSUM
            if(numsListA.get(i + 1) - numsListA.get(i) == 1) {
                score += numsListC.get(numsListA.get(i)- 1);
            }
        }

        System.out.println(score);
    }
}
