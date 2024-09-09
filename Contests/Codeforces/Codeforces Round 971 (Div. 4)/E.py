def getVals(mid):
    val1 = (k+k+mid-1)*(mid)//2
    val2 = (k+mid+k+n-1)*(n-mid)//2

    return val1, val2

for _ in range(int(input())):
    n, k = map(int, input().split())

    l = 1
    r = n
    curr = 1
    while(l <= r):
        mid = (l + r)//2
        a, b = getVals(mid)
        if(a >= b):
            curr = mid
            r = mid - 1 
        else:
            l = mid + 1

    a1,b1 = getVals(curr)
    a2,b2 = getVals(curr-1)

    print(min(a1-b1, b2-a2))