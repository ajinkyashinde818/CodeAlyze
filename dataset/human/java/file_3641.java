import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String x = sc.next();
        String y = sc.next();

        if(x.charAt(0) < y.charAt(0)){
            System.out.println('<');
        }else if(x.charAt(0) > y.charAt(0)){
            System.out.println('>');
        }else{
            System.out.println('=');
        }

    }
}
