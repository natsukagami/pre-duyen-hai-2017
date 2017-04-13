import os

MAXN = [18, 1000, 100000, 1000000]
TESTS = [5, 10, 10, 25]

cur = 0
for i in range(0, len(MAXN)):
	print("Subtask %d" % (i + 1))
	for j in range(cur + 1, cur + TESTS[i] + 1):
		print("Test %d..." % j, end="")
		os.system("go run gen_test/gen.go %d > tests/%02d.in" % (MAXN[i], j))
		print("Gen done...", end="")
		os.system("./sol < tests/%02d.in > tests/%02d.out" % (j, j))
		print("Output done.")
	cur += TESTS[i]
