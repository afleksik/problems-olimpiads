#https://inf-ege.sdamgia.ru/problem?id=27424

f = open("27-B_demo.txt")
n = int(f.readline())
s = 0
mn = 10000
for i in range(n):
    a, b = map(int, f.readline().split())
    s += max(a, b)
    if (abs(a - b) < mn) and (abs(a - b) % 3 != 0):
        mn = abs(a - b)
if s % 3 == 0:
    s -= mn
print(s)
#A = 127127
#B = 399762080
