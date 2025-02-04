package main

import(
	"math"
	"fmt"

)


func findMaxConsecutiveOnes(nums []int) int {
	max := 0
	count := 0
	for _,num := range nums {
		if num == 1 {
			count++
		} else {
			max = int(math.Max(float64(max), float64(count)))
			count = 0
		}
	}
	return int(math.Max(float64(max), float64(count)))
}


func main() {	
	fmt.Println(findMaxConsecutiveOnes([]int{1,1,0,1,1,1}))
}
