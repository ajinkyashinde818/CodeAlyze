import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int ac = 0;
        int bc = 0;
        int cc = 0;

        for(int i = 0; i<s.length();i++){
            if(s.charAt(i)=='a'){
                ac++;
            }else if(s.charAt(i)=='b'){
                bc++;
            }else{
                cc++;
            }
        }

        if(ac ==1 && bc == 1 && cc == 1){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

    }

}
