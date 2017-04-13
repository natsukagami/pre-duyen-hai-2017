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
	maxX, err := strconv.ParseInt(args[1], 10, 64)
	if err != nil {
		panic(err)
	}
	N := rand.Intn(maxN) + 1
	X := rand.Int63n(maxX) + 1
	fmt.Println(N, X)
	for i := 0; i < N; i++ {
		fmt.Printf("%d ", rand.Intn(100)+1)
	}
	fmt.Println("")
}
