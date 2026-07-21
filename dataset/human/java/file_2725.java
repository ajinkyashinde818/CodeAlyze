import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        
        String S[] = sc.next().split("");
        String T[] = sc.next().split("");
        
        Arrays.sort(S);
        Arrays.sort(T, Collections.reverseOrder());
        
        String sortedS = String.join("", S);
        String sortedT = String.join("", T);
        
        if( sortedS.equals(sortedT) ){
            System.out.println("No");
            return;
        }
        
        String judge[] = {sortedS, sortedT};
        Arrays.sort(judge);
        
        System.out.println( (judge[0] == sortedS) ? "Yes" : "No" );
        
    }
}
