import java.util.*;


public class Main {
    public static void main(String[] args) {
        // 自分の得意な言語で
        // Let's チャレンジ！！
    String[]str={"a","b","c"};
    boolean[]b={false,false,false};
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String []s=line.split("");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(str[i].equals(s[j])){
                    b[i]=true;
                }
            }
        }
        if(b[0]&&b[1]&&b[2])
        System.out.println("Yes");
        else
        System.out.println("No");
        
    }
}
