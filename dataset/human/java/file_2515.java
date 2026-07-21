import java.util.*;

class Main{

    void solve(){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        while(n-->0){
            String s1 = sc.next(), s2 = sc.next();
            int num = getNumber(s1) + getNumber(s2);
            System.out.println(toMCXI(num));
        }
    }

    String toMCXI(int num){
        String[] ss = {"m","c","x","i"};
        int n = 1000;
        String res = "";
        for(int i=0; i<4; i++){
            if(num/n>=1){
                if(num/n>=2) res += num/n + "";
                res += ss[i];
            }
            num %= n;
            n /= 10;
        }
        return res;
    }

    int getNumber(String s){
        int num = 0;
        char[] c = s.toCharArray();
        for(int i=0; i<c.length; i++){
            if(Character.isDigit(c[i])){
                if(c[i+1]=='m') num += (c[i]-'0') * 1000;
                if(c[i+1]=='c') num += (c[i]-'0') * 100;
                if(c[i+1]=='x') num += (c[i]-'0') * 10;
                if(c[i+1]=='i') num += (c[i]-'0') * 1;
                i++;
            }else{
                if(c[i]=='m') num += 1000;
                if(c[i]=='c') num += 100;
                if(c[i]=='x') num += 10;
                if(c[i]=='i') num += 1;
            }
        }   
        return num;
    }

    public static void main(String[] args){
        new Main().solve();
    }
}
