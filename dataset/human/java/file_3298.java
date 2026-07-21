import java.util.Scanner;
class Main{
    public static void main(String[] args) {
        Scanner scn= new Scanner(System.in);
        String n = scn.next();
        String answer="Yes";
        if(n.charAt(0)!='9'&&n.charAt(1)!='9') answer="No";
        System.out.println(answer);
    }
}
