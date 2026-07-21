import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        char[] n = sc.next().toCharArray();
        char[] n2 = sc.next().toCharArray();

        if(n[0]<n2[0]){
        System.out.println("<");
        }
        if(n[0]==n2[0]){
            System.out.println("=");
        }
        if(n[0]>n2[0]){
            System.out.println(">");
        }
        

    }

}
