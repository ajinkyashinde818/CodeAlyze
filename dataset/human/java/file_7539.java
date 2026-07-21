import java.util.Scanner;

public class Main {

    static String DRM = "dream";
    static String DRMR = "dreamer";
    static String ERS = "erase";
    static String ERSR = "eraser";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String N = sc.nextLine();

        String n1 = N.replace(ERSR, "");
        String n2 = n1.replace(ERS, "");
        String n3 = n2.replace(DRMR, "");
        String n4 = n3.replace(DRM, "");
        System.out.println(n4.equals("") ? "YES" : "NO");
    }

}
