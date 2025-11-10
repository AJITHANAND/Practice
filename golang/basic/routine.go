package main

import "fmt"


func countToTen() {
	for i := 1; i <= 10; i++ {
		fmt.Println(i)
	}
}



func main() {
	go countToTen()
	fmt.Println("Counting to ten in a separate goroutine...")
	select {}
	
}