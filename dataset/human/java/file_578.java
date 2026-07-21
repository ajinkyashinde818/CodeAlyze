import java.util.Scanner;


public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int N = Integer.parseInt(sc.next());
        int R = Integer.parseInt(sc.next());
        int in_rate;

        if(N >= 10){
            in_rate = R;
        }else{
            in_rate = R+100*(10-N);
        }
        System.out.println(in_rate);
        
    }
}
