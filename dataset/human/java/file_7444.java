import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
        String s = sc.next();
        int tail = s.length();
        String ans = "NO";
        while(tail > 0){
            if(tail >= 5 && s.substring(tail - 5, tail).equals("dream")){
                tail -= 5;
            }else if(tail >= 7 && s.substring(tail - 7, tail).equals("dreamer")){
                tail -= 7;
            }else if(tail >= 5 && s.substring(tail - 5, tail).equals("erase")){
                tail -= 5;
            }else if(tail >= 6 && s.substring(tail - 6, tail).equals("eraser")){
                tail -= 6;
            }else{
                System.out.println("NO");
                return;
            }
        }

        if(tail == 0) ans = "YES";
        System.out.println(ans);
    }
}
