## 0. 
my_string = "welcome to Py4Eng!"
# begin your code here
print('my_string')
# end your code here

## 1.
x = 11.25
# begin your code here
if((x-5)<0): #x has to be above 5
    print('imaginary result!')
else:
    print((x-5)**(0.5))
# end your code here

## 2. 
x = 6
# begin your code here
floor_y = (x-(x%4))/4
print('floor(',x,'/',4, ')=', int(floor_y),sep="")
# end your code here

## 3. 
x = 5
# begin your code here
if(x%4==0):
    print('ceiling(',x,'/',4, ')=',int(x/4),sep="")
else:
    ceiling_y = (x-(x%4))/4 + 1
    print('ceiling(',x,'/',4, ')=', int(ceiling_y),sep="")
# end your code here

## 4.
my_string = 'Superlative'
# begin your code here
upper_case = my_string.upper()[1::2]
lower_case = my_string.lower()[0::2]
print(upper_case, lower_case)
# end your code here


## 5. 
my_string = 'Superlative'
# begin your code here
if (len(my_string) >= 5):
    print(my_string[0:-5],my_string.upper()[-5:],sep="")
else:
    print('string too short!')
# end your code here

## 6. 
my_string = 'Soup'
# begin your code here
length = len(my_string)
if (length >= 5):
    print(my_string[0:-5],my_string.upper()[-5:],sep="")
    if (length)%2==0:
        print(my_string[2::3])
else:
    print((my_string+' ')*5)
# end your code here
