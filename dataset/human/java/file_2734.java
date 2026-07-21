import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.next();
        String t = scanner.next();

        List<Character> sortedS = s.chars().mapToObj(c -> (char) c).sorted().collect(Collectors.toList());
        List<Character> sortedT = t.chars().mapToObj(c -> (char) c).sorted().collect(Collectors.toList());

        boolean shorter = sortedS.size() < sortedT.size();

        String result = "";

        for (int index = 0; index < sortedS.size(); index++) {
            Character cs = sortedS.get(index);
            Character largestInT = sortedT.get(sortedT.size()-1);
            if (cs == largestInT) { continue; }
            if (cs < largestInT) { result = "Yes"; break; }
            if (cs > largestInT) { result = "No"; break; }
        }

        if (result.isEmpty()) {
            if (!shorter) result = "No";
            else result = "Yes";
        }

        System.out.print(result);
    }
}
