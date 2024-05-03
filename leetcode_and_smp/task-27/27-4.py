#макс сумма не кратна 5

f = open("27-B_demo.txt")
n = int(f.readline())
s = 0
mn = 10000
for i in range(n):
    a, b = map(int, f.readline().split())
    s += max(a, b)
    if (abs(a - b) < mn) and (abs(a - b) % 5 != 0):
        mn = abs(a - b)
if s % 5 != 0:
    print(s)
else:
    print(s - mn)