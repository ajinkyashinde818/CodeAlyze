import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        int count = 0;
        //String str = sc.next();
        //char[] c = str.toCharArray();
        //a[0] = Character.getNumericValue(str.charAt(0));
        //boolean test = false;
        
        for(int i=0; i<=K; i++){
            for(int j=0; j<=K; j++){
                if((S-i-j) >= 0 && (S-i-j) <= K){
                    count++;
                }
            }
            //System.out.println(a[i]);
        }
        System.out.println(count);
    }
}
