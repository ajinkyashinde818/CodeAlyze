import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String S=sc.next();
        int index=S.length();
        while(index>0){
            if(index>=7 && S.substring(index-7,index).equals("dreamer")){
                index-=7;
            }else if(index>=6 && S.substring(index-6,index).equals("eraser")){
                index-=6;
            }else if(index>=5 && (S.substring(index-5,index).equals("dream") || S.substring(index-5,index).equals("erase"))){
                index-=5;
            }else{
                System.out.println("NO");
                break;
            }
        }
        if(index == 0){
            System.out.println("YES");
        }
    }
}
