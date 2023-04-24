### DSA 2023 HW0 - BigInt GCD

```bash
# gen testdata

mkdir ./testdata
python3 gen.py
```

Official Solution with comment can be found [here](./sol.c)

We implement the Binary Algorithm for BigInt GCD with the following pseudo code

```pseudocode
def BigIntGCD(BigInt a, b):
    n = min(a, b), m = max(a, b), ans = 1
    while n != 0 and m != 0; do
        if n is even and m is even; then
            ans = ans * 2
            n = n / 2, m = m / 2
        elif n is even; then
            n = n / 2
        elif m is even; then
            m = m / 2
        end
        if n > m; then
            swap(n, m)
        end
        m = m - n
    done
    return n * ans
```



