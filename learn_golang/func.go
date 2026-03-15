package main

import "fmt"

// defer executes just before returning func
// for multiple defer, it follows LIFO

func verisium (a,b int) int {

	fmt.Println("Entered verisium...") // 1st

	defer add(a,b) // 3rd

	fmt.Println("after defer") // 2nd

	return a * b + b * a // 4th
}

func add (a,b int) {
	fmt.Println(a+b)
}

func sub (a,b int) {
	fmt.Println(a-b)
}

func marwin (g, m int)  {
	fmt.Println("entering now..") // 1st

	defer add (g,m) // 4th
	defer sub (g,m) // 3rd

	fmt.Println("wow, 2 defers, non executing") // 2nd
}