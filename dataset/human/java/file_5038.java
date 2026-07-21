import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args)throws Exception{
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        List<Character> frontList=new ArrayList<>();
        List<Character> backList=new ArrayList<>();
        int q=sc.nextInt();
        int fl=0,bl=0;
        boolean direction=true;
        int t=0,f=0;
        char c=0;
        for(int i=0;i<q;i++){
            t=sc.nextInt();
            if(t==1){
                direction=!direction;
            }else{
                f=sc.nextInt();
                c=sc.next().charAt(0);
                if(direction==(f==1)){
                    frontList.add(c);
                    fl++;
                }else{
                    backList.add(c);
                    bl++;
                }
            }
        }
        if(direction){
            for(int i=fl-1;i>=0;i--){
                System.out.print(frontList.get(i));
            }
            System.out.print(str);
            for(int i=0;i<bl;i++){
                System.out.print(backList.get(i));
            }
        }else{
            for(int i=bl-1;i>=0;i--){
                System.out.print(backList.get(i));
            }
            int l=str.length();
            for(int i=l-1;i>=0;i--){
                System.out.print(str.charAt(i));
            }
            for(int i=0;i<fl;i++){
                System.out.print(frontList.get(i));
            }
        }
        System.out.println();
    }
}
