import java.util.Scanner;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.LinkedList;

public class Main{

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Object[] ship = new Object[200001];
        for(int i = 0; i < 200001; i++){
            ship[i] = new LinkedList<Integer>();
        }
        boolean[] seen = new boolean[200001];
        int[] moveCount = new int[200001];
        Queue<Integer> todo = new ArrayDeque<>();

        // input
        int num = scan.nextInt();
        int shipNum = scan.nextInt();
        for(int i = 0; i < shipNum; i++){
            int a = Integer.parseInt(scan.next());
            int b = Integer.parseInt(scan.next());
            LinkedList<Integer> shipTmp = (LinkedList)ship[a];
            shipTmp.add(b);
        }

        // search
        boolean arrive = false;
        int pos = 1;
        seen[pos] = true;
        LinkedList<Integer> shipTmp = (LinkedList)ship[pos];
        while(shipTmp.size() > 0){
            moveCount[shipTmp.peek()] = 1;
            todo.add(shipTmp.poll());
        }
        while(todo.size() > 0){
            while(todo.size() > 0){
                if(seen[todo.peek()] == false){
                    pos = todo.poll();
                    seen[pos] = true;
                    break;
                } else {
                    todo.poll();
                }
            }
            if(pos == num && moveCount[pos] <= 2){
                arrive = true;
                break;
            }
            shipTmp = (LinkedList)ship[pos];
            while(shipTmp.size() > 0){
                if(moveCount[shipTmp.peek()] == 0){
                    moveCount[shipTmp.peek()] = moveCount[pos] + 1;
                }
                todo.add(shipTmp.poll());
            }
        }

        // answer
        if(arrive){
            System.out.println("POSSIBLE");
        } else {
            System.out.println("IMPOSSIBLE");
        }

    }
}
