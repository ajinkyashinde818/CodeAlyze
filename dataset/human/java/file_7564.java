import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final String DREAM = "maerd";
        final String DREAMER = "remaerd";
        final String ERASE = "esare";
        final String ERASER = "resare";
        Scanner sc= new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        String s = sc.next();
        sb.append(s);
        sb.reverse();
        String[] dreams = {DREAM, DREAMER, ERASE, ERASER};
        boolean daydream = true;
        String ans = "NO";
        dd:while(daydream) {
            for(String dre : dreams) {
                if(sb.indexOf(dre) == 0) {
                    sb.replace(0, dre.length(), "");
                    daydream = true;
                    continue dd;
                }
                daydream = false;
            }
        }
        if(sb.length() == 0)ans = "YES";
        System.out.println(ans);
    }
}
