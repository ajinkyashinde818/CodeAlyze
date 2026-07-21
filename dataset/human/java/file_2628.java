import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        String s = scanner.next().chars().mapToObj(ch -> String.valueOf((char)ch)).sorted().collect(Collectors.joining());
        String t = scanner.next().chars().mapToObj(ch -> String.valueOf((char)ch)).sorted(Comparator.reverseOrder()).collect(Collectors.joining());
        System.out.println(s.compareTo(t) < 0 ? "Yes" : "No");
    }
}
