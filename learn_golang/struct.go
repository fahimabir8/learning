package main

type car struct {
	brand string
	model string
}

type truck struct {
	car 
	pupil int
}

// func main() {
// 	myTruck := truck {
// 		pupil: 20,
// 		car: car {
// 			brand: "Axis",
// 			model: "301-B",
// 		},
		
// 	}
// 	fmt.Println(myTruck)
	
// 	circ := circle {
// 		radius: 5,
// 	}
// 	printShapeData(circ)
// }