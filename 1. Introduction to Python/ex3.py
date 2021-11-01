

import time
import random
## 0.
# begin your code here

def reverse_number(n):
    n = str(n)
    n = n[::-1]
    print (n)
n = 456
reverse_number(n)
# end your code here

## 1.
# begin your code here
def sum_list(list):
    i = 0
    sum = 0
    for list[i] in list:
        sum = sum + list[i]
        i = i +1
    print (sum)
list = [76,66]
sum_list(list)
# end your code here



## 2. 
# begin your code here
def find_strings_with_digit(string_list,d):
    i = []
    if (d<9) and (d>0):
        d = str(d)
        for string in string_list:
            if d in string:
                i.append(string)
        return(i)

a = find_strings_with_digit(['ab3','333','524','ad3'],4)
print(a)
# end your code here


## 3. 
# begin your code here
def validate_matrix(mat,m,n):
    false_counter = 0
    for i in mat:
        for x in i:
            if type(x) != int:
                false_counter = false_counter +1
                break
        if n != len(i):
            false_counter = false_counter + 1
            break
    if m != len(mat):
        false_counter = false_counter + 1
    if false_counter >0 :
        print ("false")
    else:
        print ("true")

validate_matrix([[4,3,4],[2,4,4]],2,3)
# end your code here


## 4.
# begin your code here
def transpose_matrix(mat):
#mat is a list of lists containing numbers
    new_mat = []
    for j in range(0, len(mat[0])):
        a = []
        for item in mat:
            a.append(item[j])
        new_mat.append(a)
    return(new_mat)

a = transpose_matrix([[3, 5, 7], [7, 7, 7], [4, 3, 2], [8, 9, 6]])
print(a)
# end your code here


## 5.
# begin your code here
def generate_random_list(n):

    global list
    list = []
    for x in range(n):
        list.append(random.randint(1, n+1))
    list = sorted(list)
    return

def binary_list_search (val,lst):
    low = 0
    high = len(lst) - 1
    while low <= high:        # There is a range to search
        mid = (low + high)//2 # Position of middle item
        item = lst[mid]
        if val == item:         # Found it! Return the index
            return mid
        elif val < item:        # x is in lower half of range
            high = mid - 1    #  move top marker down
        else:                 # x is in upper half of range
            low = mid + 1     #  move bottom marker up
    return -1                 # No range left to search,
                              # x is not there
generate_random_list(1000000)

print (binary_list_search(676432,list))
# end your code here



