k, n, m = [int (i) for i in input().split()]

posicoes = [0 for _ in range(n)]
treinfo = [[0, 0, i+1] for i in range(n)]

for i in range(m):
    x, y = [int (i) for i in input().split()]
    if y - posicoes[x-1] == 1 or (posicoes[x-1] == k and y == 1):
        posicoes[x-1] = y
        treinfo[x-1][0] += 1
        treinfo[x-1][1] = -i

treinfo.sort(reverse=True)

for i in treinfo:
    print(i[2], end=' ')
