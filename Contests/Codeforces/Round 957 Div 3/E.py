for _ in range(int(input())):
    n = int(input())
    string = str(n)
    tam = len(str(n))
    ans = []
    for a in range(1, 10001):
        minB = max(1, tam * a - 6)
        maxB = tam * a
        for b in range(minB, maxB):
            x = n * a - b
            y = 0
            for i in range(tam * a - b):
                y = y * 10 + int(string[i % tam])
            if x == y:
                ans.append((a, b))
    print(len(ans))
    for a in ans:
        print(*a)