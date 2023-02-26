from random import randint, seed
from math import gcd

subtask0 = 2
subtask1 = 20 + subtask0
subtask2 = 20 + subtask1
subtask3 = 30 + subtask2
seed(0xdeadbeef)

a, b = 20230228, 82203202
with open(f'./testdata/0.in', 'w') as f:
    f.write(f'{a} {b}\n')
with open(f'./testdata/0.out', 'w') as f:
    f.write(f'{gcd(a, b)}\n')
a, b = 987654321987654321987654321, 123456789123456789123456789
with open(f'./testdata/1.in', 'w') as f:
    f.write(f'{a} {b}\n')
with open(f'./testdata/1.out', 'w') as f:
    f.write(f'{gcd(a, b)}\n')

for i in range(subtask0, subtask1):
    a, b = randint(1, 10**6), randint(1, 10**6)

    with open(f'./testdata/{i}.in', 'w') as f:
        f.write(f'{a} {b}\n')

    with open(f'./testdata/{i}.out', 'w') as f:
        f.write(f'{gcd(a,b)}\n')

for i in range(subtask1, subtask2-5):
    b = randint(3, 10**6)
    a = b * randint(10**4, 10**256)
    while a >= 10**256:
        b = randint(3, 10**6)
        a = b * randint(10**4, 10**256)
    with open(f'./testdata/{i}.in', 'w') as f:
        f.write(f'{a} {b}\n')

    with open(f'./testdata/{i}.out', 'w') as f:
        f.write(f'{gcd(a,b)}\n')

for i in range(subtask2-5, subtask2):
    a, b = randint(10**5, 10**256), randint(1, 10**6)

    with open(f'./testdata/{i}.in', 'w') as f:
        f.write(f'{a} {b}\n')

    with open(f'./testdata/{i}.out', 'w') as f:
        f.write(f'{gcd(a,b)}\n')

for i in range(subtask2, subtask3-5):
    a, b = randint(10**4, 10**256), randint(10**4, 10**256)

    with open(f'./testdata/{i}.in', 'w') as f:
        f.write(f'{a} {b}\n')

    with open(f'./testdata/{i}.out', 'w') as f:
        f.write(f'{gcd(a,b)}\n')

for i in range(subtask3-5, subtask3):
    a = randint(10**20, 10**64)
    b = a * randint(10**4, 10**192)
    while b >= 10**256:
        a = randint(10**20, 10**64)
        b = a * randint(10**4, 10**192)

    with open(f'./testdata/{i}.in', 'w') as f:
        f.write(f'{a} {b}\n')

    with open(f'./testdata/{i}.out', 'w') as f:
        f.write(f'{gcd(a,b)}\n')

