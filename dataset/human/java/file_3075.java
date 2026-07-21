import java.util.*;
 
public class Main {
    static final long MOD=1000000007;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int tmpa;
        int tmpb;
        List<Integer> list1=new ArrayList<>();
        List<Integer> listn=new ArrayList<>();
        for(int i=0;i<m;i++){
            tmpa=sc.nextInt();
            tmpb=sc.nextInt();
            if(tmpa==1){
                list1.add(tmpb);
            }else if(tmpa==n){
                listn.add(tmpb);
            }else if(tmpb==1){
                list1.add(tmpa);
            }else if(tmpb==n){
                listn.add(tmpa);
            }
        }
        Collections.sort(list1);
        Collections.sort(listn);
        int i=0;
        int j=0;
        int tmp1;
        int tmpn;
        while(i<list1.size()&&j<listn.size()){
            tmp1=list1.get(i);
            tmpn=listn.get(j);
            if(tmp1==tmpn){
                System.out.println("POSSIBLE");
                return;
            }else if(tmp1<tmpn){
                i++;
            }else{
                j++;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
