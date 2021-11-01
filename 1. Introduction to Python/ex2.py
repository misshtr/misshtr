## 1.
my_string = "Nell fed her Electric EEL!"
# begin your code here
new_string = my_string.replace("e", "o")
print(new_string.replace("E", "O"))
# end your code here

## 2. 
my_string = "Nell fed her Electric EEL eggs"
# begin your code here
my_list = my_string.split(" ")
#makes a list of strings seperated by " "
if (len(my_list)%2==0):
    for i in range(0,len(my_list),2):
        tmp = my_list[i]
        my_list[i] = my_list[i+1]
        my_list[i+1] = tmp

print(" ".join(my_list))
# end your code here

## 3.
my_list = [1, 7, 9, 15, 2, 8]
# begin your code here
print(my_list[0::2])
print(my_list[1::2])
# end your code here


## 4.
my_list = [[1,3,5], [3,2], [], [-17]]
# begin your code here
sum1 = 0
sum2 = 0
for x in my_list[0::2]:
    for y in x[0::2]:
        sum1 += y

for x in my_list[1::2]:
    for y in x[1::2]:
        sum2 += y
print(sum1 + sum2)

# end your code here

## 5.
my_list = [1, 3, 4, 23, 22, 55, 70, 400]
# begin your code here
a = 0
b = 1
for fir_num in my_list:
    fir_num = my_list[a]
    sec_num = my_list[b]
    if sec_num > fir_num and b + 1 < len(my_list):
        a = a + 1
        b = b + 1
    elif sec_num < fir_num:
        print("false")
        break
    else:
        print("true")

        break

# end your code here

## 6.
N = 30
# begin your code here
prime_num = []
i = 2
while i <= N :
    flag = 0
    divisor = 2
    while divisor*divisor <= i and flag ==0:
        if i % divisor == 0:
            flag = 1
        divisor += 1
    if flag ==0:
        prime_num.append(i)
    i+=1
print (prime_num)
# end your code here

## 7.
N = 17
# begin your code here
i = 1
odd_str = "*<*"
even_str = ":-)"
if N < 1:
    ()
else:
    while i <= N:
        if i % 2 != 0:
            print(odd_str)
            i = i + 1
            odd_str = odd_str + "," + "*<*"
        elif i % 2 == 0:
            print(even_str)
            i = 1 + i
            even_str = even_str + "]" + ":-)"
# end your code here

