'''Дана последовательность из N целых чисел. Рассматриваются все её непрерывные подпоследовательности, такие, что сумма элементов каждой из них равна 0. Найдите среди них подпоследовательность с максимальной длиной. Если таких подпоследовательностей найдено несколько, в ответе укажите количество элементов самой длинной из них.

Входные данные: Даны два входных файла: файл A и файл B, каждый из которых содержит в первой строке количество чисел N (1 ≤ N ≤ 107) . Каждая из следующих N строк содержит целое число, по модулю не превышающее 4 10 .

Пример входного файла:

7
32
10
-18
-22
-22
20
-43

В этом наборе можно выбрать числа 32, 10,-18,-22,-22,20 которые в сумме образуют число 0. Её длина будет равна 6.

В ответе укажите два числа через пробел: сначала значение искомой длины для файла А, затем для файла B.'''

file = open("27B_10.txt")
n = int(file.readline())
prefix = {}
sum = 0
m_len = 0


for i in range(n):
    a_i = int(file.readline())
    sum += a_i
    if sum == 0:
        m_len = i
    else:
        if sum in prefix:
            m_len = max(m_len, i - prefix[sum])
        else:
            prefix[sum] = i

print(m_len)
#90 425361