package main

import(
	"fmt"
)

func twoSum(nums []int, target int) []int {
	idx_res:=[]int{}
	m_nums:=make(map[int]int)
	for i := 0; i < len(nums); i++ {
		item,ok := m_nums[nums[i]]
		if ok&&item != i{
			idx_res=[]int{m_nums[nums[i]], i}
			return idx_res
		}
		m_nums[target-nums[i]]=i
	}
	return idx_res
}

func main(){
	test:=[]int{2, 7, 11, 15}
	target:=9
	
	res:=twoSum(test, target);
	fmt.Println("result:",res)
}


