import sys

sys.setrecursionlimit(200000)

def find(x):
    global pais
    if pais[x] != x:
        pais[x] = find(pais[x])
    return pais[x]

def union(x, y):
    global pais
    pais[find(x)] = find(y)

n, k = [int (i) for i in input().split()]

pais = [i for i in range(n)]

saida = []

for _ in range(k):
    c, b1, b2 = [(i) for i in input().split()]
    if c == 'C':
        if find(int(b1)-1) == find(int(b2)-1):
            saida.append('S')
        else:
            saida.append('N')
    else:
        union(int(b1)-1, int(b2)-1)

for i in saida:
    print(i)
