import java.util.*;
import java.io.*;
import static java.lang.System.in;

public class Main {
    public static void main(String[] args)throws IOException {
        //BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt(), k = sc.nextInt();
        ArrayList<Integer> res = new ArrayList<>();
        for(int i=1;i<=Math.min(a,b);i++){
            if(a%i==0&&b%i==0) res.add(i);
        }
        Collections.sort(res,Collections.reverseOrder());
        System.out.println(res.get(k-1));
    }
}
