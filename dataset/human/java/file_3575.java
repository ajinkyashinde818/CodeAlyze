import java.util.*;

class Main {
    public static void main(String args[]) {
        Scanner inp = new Scanner(System.in);
        String x = inp.next();
        String y = inp.next();
        int xx = Integer.parseInt(x, 16);
        int yy = Integer.parseInt(y, 16);
        if (xx > yy) System.out.println(">");
        else if (xx == yy) System.out.println("=");
        else System.out.println("<");
    }
}
