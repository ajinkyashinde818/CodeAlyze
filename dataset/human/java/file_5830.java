import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(sort(sc.next()).equals("abc")?"Yes":"No");

    }

    static String sort(String input){
        String output="";
        char[] chars=new char[input.length()];
        for(int i=0;i<chars.length;i++){
            chars[i]=input.charAt(i);
        }
        Arrays.sort(chars);
        for(int i=0;i<chars.length;i++){
            output+=chars[i];
        }
        return output;
    }
}
