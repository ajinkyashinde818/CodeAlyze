import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String[] str = sc.next().split("");

        Arrays.sort(str);
        String key = "";
        for (String s : str) {
            key += s;
        }

        String result = "No";
        if (key.contains("abc")) result = "Yes";
        System.out.println(result);
    }
}
