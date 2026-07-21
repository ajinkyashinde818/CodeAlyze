import java.util.*;

public class Main {

    public void run() {
        Scanner sc = new Scanner(System.in);
        String orders = sc.next();
        int destX = sc.nextInt();
        int destY = sc.nextInt();

        String[] Fs = orders.split("T");

        List<Integer> horizontals = new ArrayList<>();
        List<Integer> verticals = new ArrayList<>();
        for (int i = 2; i < Fs.length; i+=2) {
            horizontals.add(Fs[i].length());
        }
        for (int i = 1; i < Fs.length; i+=2) {
            verticals.add(Fs[i].length());
        }

        int startX = 0;
        int startY = 0;
        if(Fs.length > 0) startX += Fs[0].length();

        Set<Integer> positionsX = new HashSet<>();
        Set<Integer> positionsY = new HashSet<>();

        positionsX.add(startX);
        positionsY.add(startY);

        for (int length: horizontals) {
            Set<Integer> newPositionsX = new HashSet<>();
            for (int positionX: positionsX) {
                newPositionsX.add(positionX + length);
                newPositionsX.add(positionX - length);
            }
            positionsX = newPositionsX;
        }

        for (int length: verticals) {
            Set<Integer> newPositionsX = new HashSet<>();
            for (int positionY: positionsY) {
                newPositionsX.add(positionY + length);
                newPositionsX.add(positionY - length);
            }
            positionsY = newPositionsX;
        }

        if(positionsX.contains(destX) && positionsY.contains(destY)) System.out.println("Yes");
        else System.out.println("No");
    }

    public static void main(String[] args){
        new Main().run();
    }
}
