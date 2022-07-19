struct KMP {
    int nextt[50066];

    // 字符串x下标从0开始, 返回的nextt下标从1开始
    void kmp_pre(int x[], int m, int nextt[]) {
        int i = 0, j = -1;
        nextt[0] = -1;
        while (i < m) {
            while (j != -1 && x[i] != x[j]) j = nextt[j];
            nextt[++i] = ++j;
        }
    }

    //x 是模式串，y 是主串, 0开始
    void KMP_Count(int x[], int m, int y[], int n) {
        int i = 0, j = 0;
        int ans = 0;
        kmp_pre(x, m, nextt);
        while(i < n) {
            while(j != -1 && y[i] != x[j]) j = nextt[j];
            i++; j++;
            if (j >= m) {
                ans++;
                j = nextt[j];
            }
        }
    }
}kmp;
