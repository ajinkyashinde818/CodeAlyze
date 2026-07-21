import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        String[] t = {"eraser","erase","dreamer","dream"};
        for(int i=0;i<4;i++)s=s.replace(t[i],"");
        System.out.println(s.equals("")?"YES":"NO");
        
    }
}
