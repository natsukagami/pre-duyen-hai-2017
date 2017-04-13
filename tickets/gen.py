import os

MAXN = [100, 100000, 100000]
MAXX = [500, 500000, 1000000000]
TESTS = [5, 15, 30]

cur = 0
for i in range(0, len(MAXN)):
	print("Subtask %d" % (i + 1))
	for j in range(cur + 1, cur + TESTS[i] + 1):
		print("Test %d..." % j, end="")
		os.system("go run gen_test/gen.go %d %d > tests/%02d.in" % (MAXN[i], MAXX[i], j))
		print("Gen done...", end="")
		os.system("./sol < tests/%02d.in > tests/%02d.out" % (j, j))
		if MAXX[i] <= 500000:
			print("Output done...", end="")
			os.system("./xlog < tests/%02d.in > test.out" % j)
			if os.system("diff -w test.out tests/%02d.out" % j):
				print("Verify WRONG!")
			else:
				print("Verify done!")
		else:
			print("Output done.")
	cur += TESTS[i]
