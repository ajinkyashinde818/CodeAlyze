import java.util.*;

class Main {
    public static void main(String args[]) {
        Scanner inp = new Scanner(System.in);
        do_(inp);
        inp.close();
    }
    public static void do_(Scanner inp) {
        int a = inp.nextInt();
        int b = inp.nextInt();
        if (a < 10) System.out.println(b + 100 * (10 - a));
        else System.out.println(b);
    }
}
