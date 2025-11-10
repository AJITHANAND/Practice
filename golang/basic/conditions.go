package main


import "fmt"



func main(){



	const num int = 7
	if num%2 == 0 {
		fmt.Println(num, "is even")
	} else {
		fmt.Println(num, "is odd")
	}




	day := 5
	dayNames := map[int]string{
		1: "Sunday",
		2: "Monday",
		3: "Tuesday",
		4: "Wednesday",
		5: "Thursday",
		6: "Friday",
		7: "Saturday",
	}
	fmt.Println("Day", day, "is", dayNames[day])
}