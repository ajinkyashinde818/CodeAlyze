import java.util.Scanner;
class Main{
    public static void main(String arg[]){
        Scanner scn=new Scanner(System.in);
        String s = scn.next();
        String answer = "No";
        if(s.charAt(0)!=s.charAt(1)&&s.charAt(0)!=s.charAt(2)&&s.charAt(1)!=s.charAt(2)) answer = "Yes";
        System.out.println(answer);
    }
}
