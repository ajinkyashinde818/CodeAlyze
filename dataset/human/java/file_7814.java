import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int townNum = scan.nextInt();
        long loveInt = scan.nextLong();
        Town[] towns = new Town[townNum + 1];
        for (int i = 1; i < townNum + 1; i++) {
            towns[i] = new Town(i);
        }

        for (int i = 1; i < townNum + 1; i++) {
            towns[i].setNextTown(towns[scan.nextInt()]);
        }

        towns[1].reach(1);
        Town endTown = towns[1].endlessGoNext();

        int startLoop=endTown.goNext().getFirstReach();
        int loop=endTown.getFirstReach()-startLoop+1;

        long minStep=loveInt;
        if (loveInt>startLoop){
            minStep=(loveInt-startLoop) % loop+startLoop;
        }

        Town end=towns[1];
        for (int i = 0; i <minStep ; i++) {
            end=end.goNext();
        }

        System.out.println(end.getId());
    }
}

class Town {
    private final int id;
    private int firstReach = 0;
    private Town nextTown;

    public Town(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public void setNextTown(Town nextTown) {
        this.nextTown = nextTown;
    }

    public boolean reach(int firstReach) {
        if (this.firstReach == 0) {
            this.firstReach = firstReach;
            return true;
        } else {
            return false;
        }
    }

    public int getFirstReach() {
        return firstReach;
    }

    Town goNext() {
        return nextTown;
    }

    Town endlessGoNext() {
        if (nextTown.reach(firstReach + 1)) {
            return nextTown.endlessGoNext();
        } else {
            return this;
        }
    }
}
