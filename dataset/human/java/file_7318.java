import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {
    private static final Pattern PATTERN = Pattern.compile("^(dreamer|dream|eraser|erase)+$");
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();
                
        boolean canMake = PATTERN.matcher(s).matches();
        System.out.println(canMake ? "YES" : "NO");
    }
    
}
