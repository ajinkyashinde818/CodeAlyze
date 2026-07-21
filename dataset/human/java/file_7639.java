import java.util.*;

public class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        long K = sc.nextLong();

        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // position, order
        HashMap<Integer, Integer> positionOrderMap = new HashMap<Integer, Integer>();
        List<Integer> orderList = new ArrayList<Integer>();

        int order = 0;
        int currentPos = 1;
        positionOrderMap.put(currentPos, order);
        orderList.add(currentPos);
        
        int offset = 0;
        int loopCount = N;
        while (order < N) {
            order += 1;
            currentPos = A[currentPos-1];
            if (positionOrderMap.containsKey(currentPos)) {
                offset = positionOrderMap.get(currentPos);
                loopCount = order - positionOrderMap.get(currentPos);
                break;
            } else {
                positionOrderMap.put(currentPos, order);
                orderList.add(currentPos);
            }
        }

        List<Integer> offsetOrder = orderList.subList(0, offset);
        List<Integer> loopOrder = orderList.subList(offset, offset+loopCount);
        
        if (K < offset) {
            System.out.println(offsetOrder.get((int) K));
        } else {
            K = (K - offset) % loopCount;
            System.out.println((loopOrder.get((int) K)));
        }
    }
}
