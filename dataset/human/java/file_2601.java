import java.util.Scanner;
import java.util.ArrayList;
class Main{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        String s=scn.next();
        String t=scn.next();
        String answer="Yes";
        int limit=Math.min(s.length(),t.length());
        ArrayList<Character> sList=new ArrayList<Character>();
        ArrayList<Character> tList=new ArrayList<Character>();
        for(int i=0;i<s.length();i++){
            char buf=s.charAt(i);
            for(int j=i+1;j<s.length();j++){
                char bufj=s.charAt(j);
                if(buf>bufj){
                    String front=s.substring(0,i);
                   String mid= s.substring(i,j+1);
                   StringBuffer bf=new StringBuffer(mid);
                   String end=s.substring(j+1,s.length());
                   s=front+bf.reverse()+end;
                    buf=bufj;
                }
            }
            sList.add(buf);
        }
        for(int i=0;i<t.length();i++){
            char buf=t.charAt(i);
            for(int j=i+1;j<t.length();j++){
                char bufj=t.charAt(j);
                if(buf<bufj){
                     String front=t.substring(0,i);
                    String mid= t.substring(i,j+1);
                    StringBuffer bf=new StringBuffer(mid);
                    String end=t.substring(j+1,t.length());
                    t=front+bf.reverse()+end;
                    buf=bufj;
                }
            }   
            tList.add(buf);
        }

        int i=0;
        for(;i<limit;i++){
            if(sList.get(i)<tList.get(i)){
                i=limit+1;
                break;
            }else if(sList.get(i)>tList.get(i)){
                i=limit+1;
                answer="No";
                break;
            }
        }
        if(i==limit&&t.length()<=s.length()){  
            answer="No";
        }
        System.out.println(answer);
     }
}
