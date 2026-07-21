import java.util.*;
public class Main{
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();
        int cnt = 0;

        for(int a=0; a<=k; a++){
            for(int b=0; b<=k; b++){
                int c = s - a - b;
                if( 0<=c && c<=k){
                    cnt++;
                }        
            }
        }
        System.out.println(cnt);
    }
}
