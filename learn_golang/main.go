package main

import (
	"fmt"
	"log"
)


func main() {
	ans , err := networkGET()
	if err != nil {
		log.Fatal("Didn't get the data")
	}

	for _, man := range ans {
		fmt.Printf("%v\n", man.Name)
	}

	
}