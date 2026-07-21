import java.util.*;

class Main{
    static Scanner sc = new Scanner(System.in);
    public static void main(String args[]){
        Map<Integer,String> map=new HashMap<>();
      	map.put(0,sc.next());
        int Q=sc.nextInt(),sign=1;
        for(int i=1;i<=Q;i++){
            int T=sc.nextInt();
            if(T==1) sign*=-1;
            else{
                int F=sc.nextInt();
                if(F==1){
                    map.put(i*(-1)*sign,sc.next());
                }
                else{
                    map.put(i*sign,sc.next());
                }
            }
        }
        if(sign!=1){
            StringBuffer s=new StringBuffer(map.get(0));
            map.replace(0,s.reverse().toString());
        }
        for(int i=-Q;i<=Q;i++){
            int I=i*sign;
            if(map.containsKey(I)){
                System.out.print(map.get(I));
            }
        }
        System.out.println();
    }
}
