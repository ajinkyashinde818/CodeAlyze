import java.util.Scanner;

public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) throws java.io.IOException {
        // TODO 自動生成されたメソッド・スタブ
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n != 0) {
            char[] cs = sc.next().toCharArray();
            char[] ds = sc.next().toCharArray();
            int a = decode(cs);
            int b = decode(ds);
            System.out.println(encode(a+b));
            n--;
        }

    }

    public static int decode(char[] cs) {
        char buf = '0';
        int ans = 0;
        for (int i = 0; i < cs.length; i++) {
            switch (cs[i]) {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                buf = cs[i];
                break;
            case 'm':
                switch (buf) {
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    ans += 1000 * (buf - '0');
                    buf = '0';
                    break;
                case '0':
                    ans += 1000;
                    break;

                }
                break;
            case 'c':
                switch (buf) {
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    ans += 100 * (buf - '0');
                    buf = '0';
                    break;
                case '0':
                    ans += 100;
                    break;

                }
                break;
            case 'x':
                switch (buf) {
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    ans += 10 * (buf - '0');
                    buf = '0';
                    break;
                case '0':
                    ans += 10;
                    break;

                }
                break;
            case 'i':
                switch (buf) {
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    ans += (buf - '0');
                    buf = '0';
                    break;
                case '0':
                    ans += 1;
                    break;

                }
                break;

            }

        }
        return ans;
    }
    public static String encode(int n){
        char tmp ;
        StringBuilder sb= new StringBuilder();
        for(int i=3;i>=0;i--){
            tmp = (char) (n/Math.pow(10,i)+'0');
            //System.out.println(tmp);
            n%=Math.pow(10,i);
           switch(tmp){
           case '2':
           case '3':
           case '4':
           case '5':
           case '6':
           case '7':
           case '8':
           case '9':
               sb.append(tmp-'0');
               switch((int)Math.pow(10,i)){
               case 1000:
                   sb.append("m");
                   break;
               case 100:
                   sb.append("c");
                   break;
               case 10:
                   sb.append("x");
                   break;
               case 1:
                   sb.append("i");
                   break;
               }
               break;
           case '1' :
               switch((int)Math.pow(10,i)){
               case 1000:
                   sb.append("m");
                   break;
               case 100:
                   sb.append("c");
                   break;
               case 10:
                   sb.append("x");
                   break;
               case 1:
                   sb.append("i");
                   break;
               }
               break;
            }
                
        }
        return sb.toString();
    }
}
