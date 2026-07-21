import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());
        int s = Integer.parseInt(sc.next());
        
        StringBuilder sb = new StringBuilder();
        int s2;
        if(s == 1000000000){
            s2 = s-1;
        }else{
            s2 = s+1;
        }
        for(int i = 0; i < k; i++){
            sb.append(s).append(" ");
        }
        for(int i = k; i < n; i++){
            sb.append(s2).append(" ");
        }
        
        System.out.println(sb);
    }
}
