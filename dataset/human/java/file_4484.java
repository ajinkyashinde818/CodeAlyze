import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int g = sc.nextInt();
        int gd = sc.nextInt();
        int pd = sc.nextInt();
        
        System.out.println(gd + Math.min(gd+g+1, pd));
    }
}
