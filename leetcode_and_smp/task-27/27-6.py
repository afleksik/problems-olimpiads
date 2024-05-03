# 1) одно из чисел кратно 14
# 2) у одного есть множитель 2 у другого 7 и наоборот
# 14 = 7 * 2


# 1) mx % 14 == 0: mx 
#
#
#
#
#
max_2 = 0
max_7 = 0
max_14 = 0
mx = 0
prev = 0

# 1 2 1 2 182 196
with open("27-6A.txt") as f:
    f.readline()
    for line in f:
        a = int(line)
        if (a % 14 == 0):
            mx = max(max_14, mx)
            if max_14 != a:
                max_14 = max(max_14, a)
        elif (a % 2 == 0):
            max_2 = max(max_2, a)
        elif (a % 7 == 0):
            max_7 = max(max_7, a)    
        else:
            mx = max(a, mx)

print(max(max(mx, max_2, max_7) * max_14, max_2 * max_7))
