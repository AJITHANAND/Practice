package main

import "fmt"

func main() {
    // Using make() to create a slice with a specified length and capacity
    s := make([]int, 10, 15)

    // Initializing the elements
    for i := 0; i < 10; i++ {
		fmt.Printf("Before initializing: %d\n : %d\n", i, s[i])
        s[i] = i + 1
    }

    fmt.Println(s)
	// fmt.Printf("Non initializing variable for s[11]: %d\n", s[11]) // this will cause a runtime panic: index out of range

	fmt.Printf("Array allocated length %d\n", len(s))
	fmt.Printf("Array allocated capacity %d\n", cap(s))

	s = append(s, 11, 12, 13)
	fmt.Println(s)
	fmt.Printf("Array allocated length after append %d\n", len(s))
	fmt.Printf("Array allocated capacity after append %d\n", cap(s))
}