import java.util.*;

class Main{
    static Scanner sc = new Scanner(System.in);
    public static void main(String args[]){
        String S=sc.next();
        int i=0;
        for(i=S.length();i>4;i--){
            String s5=S.substring(i-5,i);
            if(s5.equals("dream")||s5.equals("erase")){
                i-=4;
                continue;
            }
            String s6=S.substring(i-6,i);
            if(s6.equals("eraser")){
                i-=5;
                continue;
            }
            String s7=S.substring(i-7,i);
            if(s7.equals("dreamer")){
                i-=6;
                continue;
            }
            break;
        }
        System.out.println(i==0?"YES":"NO");
    }
}
