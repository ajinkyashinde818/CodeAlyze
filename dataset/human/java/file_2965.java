import java.util.*;
import java.io.*;

class Main{
    boolean ans = false;
    public void check(Map<Integer, List<Integer>> maps, int now, int goal, int count){
        if(count > 2)
            ans = ans || false;
        else if(now == goal - 1) // goal
            ans = ans || true;
        else{
            if(maps.containsKey(now)){
                for(int s: maps.get(now)){
                    check(maps, s, goal, count + 1);
                }
            }
        }
    }

    public List<Integer> getAddElement(List<Integer> list, int num){
        list.add(num);
        return list;
    }

    public void run(){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            String[] nm = br.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);
            Map<Integer, List<Integer>> maps = new HashMap<>();
            br.lines().map(j -> j.split(" "))
                .forEach(j -> maps.put(Integer.parseInt(j[0]) - 1, getAddElement(maps.getOrDefault(Integer.parseInt(j[0]) - 1, new ArrayList<Integer>()), Integer.parseInt(j[1]) - 1) ));
            check(maps, 0, n, 0);

            if(ans)
                System.out.println("POSSIBLE");
            else
                System.out.println("IMPOSSIBLE");
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    public static void main(String... args){
        new Main().run();
    }
}
