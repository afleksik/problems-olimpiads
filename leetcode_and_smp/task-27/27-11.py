f = open("27B_11.txt")
n = int(f.readline())
mas = [0] * 1000
count = 0
sums = 0
for i in range(1, n + 1):
    num = int(f.readline())
    sums += num
    if sums % 999 == 0:
        count += 1
    count += mas[sums % 999]
    mas[sums % 999] += 1

print(count)