n, m = [int (i) for i in input().split()]
barra = [int (i) for i in input().split()]
pos = [int (i) for i in input().split()]
diff = [0]*(n+2)
diff[pos[0]-1] = 1
diff[pos[0]] = -1

for i in range(m-1):
    a = pos[i]-1
    b = pos[i+1]-1
    if a < b:
        diff[a+1] += 1
        diff[b+1] -= 1
    else:
        diff[a] -= 1
        diff[b] += 1

s = [0]*10
acumulado = 0

for i in range(n):
    acumulado += diff[i]
    numero = barra[i]
    s[numero] += acumulado

print(*s)
