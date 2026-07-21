import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        // str = reverse(str);
        // System.out.println(str.substring(6, 11));
        String[] divide = new String[]{"dream", "dreamer", "erase", "eraser"};
        for(int i=0;i<4;i++){
            divide[i] = reverse(divide[i]);
        }
        str = reverse(str);
        boolean can = true;
        for(int i=0;i<str.length();){
            boolean can2 = false;
            for(int j=0;j<4;j++){
                String d = divide[j];
                try {
                    if(str.substring(i, i+d.length()).equalsIgnoreCase(d)){
                        can2 = true;
                        i += d.length();
                    }
                } catch (StringIndexOutOfBoundsException e) {
                    continue;
                }
                
            }
            if(!can2){
                can = false;
                break;
            }
        }
        if(can){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }
    public static String reverse(String arg){
        char[] chStr = arg.toCharArray();
        StringBuilder builder = new StringBuilder();
        for(int i=chStr.length; i>0; i--){
            builder.append(chStr[i-1]);
        }
        return builder.toString();
    }
}
