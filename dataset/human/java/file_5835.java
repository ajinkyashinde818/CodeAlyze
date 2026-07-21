import java.util.*;

class Main {
    public static void main(String args[]) {
        Scanner inp = new Scanner(System.in);
        char s[] = inp.next().toCharArray();
        Arrays.sort(s);
        char ans[] = {'a', 'b', 'c'};
        if (Arrays.equals(s, ans)) System.out.println("Yes");
        else System.out.println("No");
        inp.close();
    }
}
