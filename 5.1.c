n = int(input())
logs = []

for _ in range(n):
    name, time = input().split()
    h, m = map(int, time.split(':'))
    logs.append((h, m, name, time))

logs.sort()

for _, _, name, time in logs:
    print(name, time)
