import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        String t=sc.next();
        char[] schar=new char[s.length()];
        char[] tchar=new char[t.length()];
        for(int i=0;i<s.length();i++){
            schar[i]=s.charAt(i);
        }
        for(int i=0;i<t.length();i++){
            tchar[i]=t.charAt(i);
        }
        Arrays.sort(schar);
        Arrays.sort(tchar);
        for(int i=0;i<Math.min(s.length(),t.length());i++){
            if(schar[i]<tchar[t.length()-i-1]){
                System.out.println("Yes");
                return;
            }else if(schar[i]>tchar[t.length()-i-1]){
                System.out.println("No");
                return;
            }
        }
        if(s.length()<t.length()){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
