package main
 
import (
  "sort"
  "container/heap"
  "fmt"
)
 
type HeapHelper struct {
    container sort.Interface
    length    int
}
 
func (self HeapHelper) Len() int { return self.length }
func (self HeapHelper) Less(i, j int) bool { return self.container.Less(j, i) }
func (self HeapHelper) Swap(i, j int) { self.container.Swap(i, j) }
func (self *HeapHelper) Push(x interface{}) { panic("impossible") }
func (self *HeapHelper) Pop() interface{} {
    self.length--
    return nil
}
 
func heapSort(a sort.Interface) {
    helper := HeapHelper{ a, a.Len() }
    heap.Init(&helper)
    for helper.length > 0 {
        heap.Pop(&helper)
    }
}
 
func main() {
    // test :
    a := []int{170, 45, 75, -90, -802, 24, 2, 66}
    heapSort(sort.IntSlice(a))
    fmt.Println("after: ", a)
}
