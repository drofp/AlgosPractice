# Right heavy descending MergeSort algorithm

def mergeSortRecurse(arr):
    if len(arr) == 1 or len(arr) == 0:
        return arr
    else:
        left  = arr[ : len(arr) // 2]
        right = arr[len(arr) // 2 : len(arr)]
        sortedArr = merge(mergeSortRecurse(left), mergeSortRecurse(right))

    return sortedArr

def merge(left, right):
    leftPosition = 0
    rightPosition = 0
    sortedArr = []

    while ( (leftPosition != len(left)) or (rightPosition != len(right)) ):
        if (len(left) > leftPosition) and (len(right) > rightPosition) and (left[leftPosition] > right[rightPosition]):
            sortedArr.append(left[leftPosition])
            leftPosition += 1
        elif (len(left) > leftPosition) and (len(right) > rightPosition) and left[leftPosition] < right[rightPosition]:
            sortedArr.append(right[rightPosition])
            rightPosition += 1
        elif len(left) == leftPosition and (len(right) > rightPosition):
            sortedArr.append(right[rightPosition])
            rightPosition += 1
        elif len(right) == rightPosition and (len(left) > leftPosition):
            sortedArr.append(left[leftPosition])
            leftPosition += 1
    
    return sortedArr
            
if __name__ == '__main__':
    print(mergeSortRecurse([1, 2, 3, 5, 999 , 4, 0, -5, -1])) # input test case
