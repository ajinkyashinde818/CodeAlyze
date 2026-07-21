import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String devider[] = {"maerd","remaerd","esare","resare"};
        String str = new StringBuffer(sc.nextLine()).reverse().toString();
        boolean flag1 = true;
        for(int i=0;i<str.length();){
            boolean flag2 = false;
            for(int j=0;j<4;j++){
                String d = devider[j];
                String d2 = str.substring(i,i);
                if((i+d.length())<=str.length()){
                    d2 = str.substring(i,i+d.length());
                }
                if(d2.equals(d)){
                    flag2 = true;
                    i += d.length();
                }
            }
            if(!flag2){
                flag1 = false;
                break;
            }
        }
        System.out.println(flag1 ? "YES":"NO");
    }
}
