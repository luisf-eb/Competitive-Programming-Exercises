entrada = [int(i) for i in input().split()]
jogador1 = []
jogador2 = []
total1 = 0
total2 = 0

alternador = 0
for i in range(len(entrada)):
    if alternador == 0:
        if entrada[i] == -1:
            if(len(jogador2) > 0):
                x = jogador2.pop()
                total2 -= x
            alternador = 1
            continue
        jogador1.append(entrada[i])
        total1 += entrada[i]
        alternador = 1
    else:
        if entrada[i] == -1:
            if(len(jogador1) > 0):
                x = jogador1.pop()
                total1 -= x
            alternador = 0
            continue
        jogador2.append(entrada[i])
        total2 += entrada[i]
        alternador = 0

if total1 == total2: print(0)
elif total1 > total2: print(1)
else: print(2)
    