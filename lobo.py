from collections import deque

r, c = [int (i) for i in input().split()]

fazenda = [[0]*(c+2)]
for _ in range(r):
    ca = input()
    ca = list(ca)
    fazenda.append([0]+ca+[0])
fazenda += [[0]*(c+2)]

fila = deque()
visitados = [[False]*(c+2) for _ in range(r+2)]

s = [0, 0]

for i in range(1, r+1):
    for j in range(1, c+1):

        if visitados[i][j] == False and fazenda[i][j] != '#' and fazenda[i][j] != 0:
            visitados[i][j] = True
            fila.append((i, j))
            ovelhas = 0
            lobos = 0
            aberto = False
            while fila:
                x, y = fila.popleft()

                if fazenda[x][y] == 'k':
                    ovelhas += 1
                
                elif fazenda[x][y] == 'v':
                    lobos += 1
                
                elif x == 1 or x == r or y == 1 or y == c:
                    aberto = True
                
                direcoes = [(0, -1), (0, 1), (-1, 0), (1, 0)]

                for dl, dc in direcoes:
                    nl = x+dl
                    nc = y+dc
                    if fazenda[nl][nc] != '#' and visitados[nl][nc] == False and fazenda[nl][nc] != 0:
                        visitados[nl][nc] = True
                        fila.append((nl, nc))
                
            if aberto:
                s[0] += ovelhas
                s[1] += lobos
            elif ovelhas > lobos:
                s[0] += ovelhas
            else:
                s[1] += lobos

print(*s, sep=' ')
