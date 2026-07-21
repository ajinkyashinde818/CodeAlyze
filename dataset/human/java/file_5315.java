import java.util.*;

class Main {
    public static void main(String args[]) {
        Scanner inp = new Scanner(System.in);
        int x = inp.nextInt();
        inp.close();
        if (x < 1200) System.out.println("ABC");
        else System.out.println("ARC");
    }
}
