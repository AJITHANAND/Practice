# Sample Input
# 9 27

# Sample Output

# ------------.|.------------
# ---------.|..|..|.---------
# ------.|..|..|..|..|.------
# ---.|..|..|..|..|..|..|.---
# ----------WELCOME----------
# ---.|..|..|..|..|..|..|.---
# ------.|..|..|..|..|.------
# ---------.|..|..|.---------
# ------------.|.------------



n, m = map(int, input().split())
dash = (m - 3) // 2
after = False

for i in range(1, n):
    if (n + 1) // 2 == i:
        print('-'*((m-7)//2),end='')
        print('WELCOME',end='')
        print('-'*((m-7)//2))
        after = True
        dash += 3 
    if after:
        print('-' * dash, end='')
        print('.|.' * (2 * (n - i) - 1), end='')
        print('-' * dash)
        dash += 3
    else:
        print('-' * dash, end='')
        print('.|.' * (2 * i - 1), end='')
        print('-' * dash)
        dash -= 3
    