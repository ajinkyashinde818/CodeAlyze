import java.util.*;
         
class Main{
    public static void main(String[] args) {
        
        try(Scanner sc = new Scanner(System.in)){
 
            int around = Integer.parseInt(sc.next());
            int house = Integer.parseInt(sc.next());

            ArrayList<Integer> houseDis = new ArrayList<Integer>();
            
            for(int i = 0; i < house; i++){
                houseDis.add(Integer.parseInt(sc.next()));
            }

            int maxDis = 0;
            int startPoint = 0;

            for(int j = 0; j < house; j++){
                if(j == house - 1){
                    int dis = (around + houseDis.get(0)) - houseDis.get(j);
                    if(dis > maxDis){
                        maxDis = dis;
                        startPoint = 0;
                    }
                }else{
                    int dis = houseDis.get(j + 1) - houseDis.get(j);
                    if(dis > maxDis){
                        maxDis = dis;
                        startPoint = j;
                    }
                }
            }

            System.out.println(around - maxDis);

        }catch(Exception e){
            e.printStackTrace();
        }        
    }
}
