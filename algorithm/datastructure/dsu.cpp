int dsuGet(int x) {
    if (dsu[x] == x) {
        return x;
    }
    dsu[x] = dsuGet(dsu[x]);
    return dsu[x];
}

void dsuComb(int x, int y) {
    dsu[dsuGet(x)] = dsuGet(y);
}