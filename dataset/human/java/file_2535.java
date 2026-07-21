import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();

        List<Character> sList = new ArrayList<>();
        List<Character> tList = new ArrayList<>();
        for (char c : s.toCharArray()) { sList.add(c); }
        for (char c : t.toCharArray()) { tList.add(c); }
        Collections.sort(sList);
        Collections.sort(tList, Collections.reverseOrder());

        StringBuilder sSorted = new StringBuilder();
        StringBuilder tReverseSorted = new StringBuilder();
        for (char c : sList) { sSorted.append(c); }
        for (char c : tList) { tReverseSorted.append(c); }

        System.out.println(sSorted.toString().compareTo(tReverseSorted.toString()) < 0 ? "Yes" : "No");
    }
}
