import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        char[] res = S.toCharArray();
        Arrays.sort(res);
        String ans = "No";
        if(res[0]=='a'&&res[1]=='b'&&res[2]=='c') ans = "Yes";
        System.out.println(ans);
    }
}
