import edu.princeton.cs.algs4.StdOut;

public class DeleteSuccessor {
    private int n;
    private boolean[] isRemove;
    private UnionFindMax ufindMax;

    public DeleteSuccessor(int n) {
        this.n = n;
        ufindMax = new UnionFindMax();
        isRemove = new boolean[n];
        for (int i = 0; i < isRemove.length; i++) {
            isRemove[i] = false;
        }
    }

    public void remove(int x) {
        isRemove[x] = true;
        if (x > 0 && isRemove[x - 1]) {
            ufindMax.union(x, x - 1);
        } else if (x < n - 1 && isRemove[x + 1]) {
            ufindMax.union(x, x + 1);
        }
    }

    public int getSuccessor(int x) {
        if (x < 0 || x > n - 1) {
            return -1;
        } else if (isRemove[x]) {
            return ufindMax.find(x) + 1;
        } else {
            return x;
        }
    }

    public static void main(String[] args) {
        DeleteSuccessor dSuccessor = new DeleteSuccessor(7);
        dSuccessor.remove(1);
        dSuccessor.remove(4);
        dSuccessor.remove(9);
        StdOut.println("the successor is : " + dSuccessor.getSuccessor(3));
    }
}
