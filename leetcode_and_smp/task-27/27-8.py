# ....        a               b                                 c   ....
# ...   S_with_last       S_with_last
# ...  S_without_last    S_without_last + b
#
# Smax

# S2 ? S2 - a + b

# S1  S2  S3  X

S_with_l = 0
S_without_l = 0
S_max = 0
with open("27-8B.txt") as f:
    n = int(f.readline())
    a = int(f.readline())
    b = int(f.readline())
    S_with_l += a + b
    S_without_l = a
    for line in f:
        amount = int(line)
        S_with_l += amount
        S_max = max(S_with_l, S_without_l)
        t = S_with_l
        S_with_l = S_without_l
        S_without_l = t

print(max(S_max, S_with_l, S_without_l))
