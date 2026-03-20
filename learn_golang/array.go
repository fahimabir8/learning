package main

func take (num ...int) int { // variadic
	sum := 0
	for _, n:= range num {
		sum += n
	}
	return sum
} 