import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long i = 1;
        long j = 1;
        long s = 0;
        long t = 0;
        for (long e = 0; e < 1000000; e++) {
            if (s < t) {
                s = a * i;
                i++;
            } else {
                t = b * j;
                j++;
            }
            if (s == t) {
                break;
            }
        }
        System.out.println(s);
    }
}
