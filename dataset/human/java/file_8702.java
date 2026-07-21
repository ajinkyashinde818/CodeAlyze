import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numA = sc.nextInt();
        int numB = sc.nextInt();
        int numC = sc.nextInt();
        List<Integer> numAList = getNums(numA);
        List<Integer> numBList = getNums(numB);

        List<Integer> commonList = new ArrayList<>();
        for (int num : numAList) {
            if (numBList.contains(num)) {
                commonList.add(num);
            }
        }
        commonList.sort(Comparator.reverseOrder());
        System.out.println(commonList.get(numC- 1));
    }

    public static List<Integer> getNums(int num) {
        List<Integer> numList = new LinkedList<>();
        for (int n = 1; n <= num; n++) {
            if (num % n == 0) {
                numList.add(n);
            }
        }
        return numList;
    }
}
