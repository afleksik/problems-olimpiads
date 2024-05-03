#https://inf-ege.sdamgia.ru/problem?id=27991

# a, b
# (a % 17)/(b % 17)
# (a % 2 and b % 2)/(a !% 2 and b !% 2)
# max sum
max_17odd = 0
max_17ev = 0
mx_odd = 0
mx_ev = 0

with open("27-7B.txt") as f:
    for line in f:
        x = int(line)
        if (x % 17 == 0):
            if x % 2 == 0:
                max_17odd = max(x, max_17odd)
            else:
                max_17ev = max(x, max_17ev)
        else:
            if x % 2 == 0:
                mx_odd = max(x, mx_odd)
            else:
                mx_ev = max(x, mx_ev)

if (mx_odd + max_17odd > mx_ev + max_17ev):
    print(mx_odd, max_17odd)
else:
    print(mx_ev, max_17ev)