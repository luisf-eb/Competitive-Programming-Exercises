from math import ceil

for _ in range(int(input())):
    x, y, k = map(int, input().split())
    xk = ceil(x / k)
    yk = ceil(y / k)

    min_jumps = max(xk, yk) * 2

    if xk > yk:
        min_jumps -= 1
    
    print(min_jumps)
