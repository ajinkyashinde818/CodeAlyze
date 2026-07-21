import java.util.*;

public class Main{

    Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
        new Main().run();
    }

    void run() {

        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();

        char[] copyT = new char[t.length];

        Arrays.sort(t);
        for (int i=0; i<t.length; i++) {
            copyT[t.length-1-i] = t[i];
        }

        Arrays.sort(s);
        String sortS = new String(s);
        String sortCT = new String(copyT);

//        System.out.println(sortS);
//        System.out.println(sortCT);
//        System.out.println(sortS.compareTo(sortCT));

        if (sortS.compareTo(sortCT) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

    }
}
