import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {
    private static final Pattern REGREX_PATTERN = Pattern.compile("(dream|dreamer|erase|eraser)*");    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        System.out.println(REGREX_PATTERN.matcher(S).matches() ? "YES" : "NO"); 
    }
}
