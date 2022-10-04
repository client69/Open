class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int[] source = new int[]{0, 0};
        for (int[] ghost: ghosts)
            if (taxi(ghost, target) <= taxi(source, target))
                return false;
        return true;
    }

    public int taxi(int[] P, int[] Q) {
        return Math.abs(P[0] - Q[0]) + Math.abs(P[1] - Q[1]);
    }
}