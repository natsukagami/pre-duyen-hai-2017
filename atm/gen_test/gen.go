package main

import (
	crand "crypto/rand"
	"fmt"
	"math/big"
	"math/rand"
	"os"
	"strconv"
)

func main() {
	sd, err := crand.Int(crand.Reader, big.NewInt(1<<60))
	if err != nil {
		panic(err)
	}
	rand.Seed(sd.Int64())
	args := os.Args[1:]
	maxN, err := strconv.Atoi(args[0])
	if err != nil {
		panic(err)
	}
	N := rand.Intn(maxN) + 1
	X := rand.Intn(N)
	fmt.Println(N, X)
	b := make([]byte, N)
	for i := 0; i < N; i++ {
		if i == 0 && rand.Intn(2) == 0 && N > 1 {
			b[i] = '-'
		} else {
			b[i] = byte(rand.Intn(10)) + '0'
		}
	}
	fmt.Println(string(b))
}
