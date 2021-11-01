
## 1.
# begin your code here
def max_circle_slicing(n):  #THIS IS A KNOWN ALGORITHM IN FUNCTIONS
    if n==0:
        return 1
    if n>0:
        return max_circle_slicing(n-1) + n
a = max_circle_slicing(5)
print(a)
# end your code here


## 2.
# begin your code here
def max_rec(my_list):
    if len(my_list)==1:     #IF WE GOT TO THE LAST ITEM IN LIST IT MEANS WE CAN START FOLDING THE RECURSION
        return(my_list[0])
    x = max_rec(my_list[1:])    #CALLS REC WITHOUT FIRST ITEM
    if my_list[0]<= x:          
            return(x)
    else:
        return(my_list[0])

a = max_rec([91,7,55,64,37,89,90,81])
print(a)
# end your code here


## 3.    solving is_palindrom() in 3 different ways:
# begin your code here
def is_palindrome_slicing(s):
    # insert your code here
    return s == s[::-1]

def is_palindrome_loop(s):
    # insert your code here
    for x in range(0,len(s)):
       if s[x] != s[len(s)-1-x]:        #LEN IS +1 TO THE INDEX SO WE HAVE TO SUB
        return False
    return True

def is_palindrome_rec(s):
    # insert your code here
    if len(s)==1 or len(s) == 0:
        return True
    if s[0] == s[len(s)-1]:             #IF THE OPPOSITE INDEX MATCHES WE SEND THE LIST SHORTER BY 2 OBJECTS
        return is_palindrome_rec(s[1:len(s)-1])
    else:
        return False

a = is_palindrome_slicing('abba')
print(a)
b = is_palindrome_loop('abbsa')
print(b)
c = is_palindrome_rec('abbdbba')
print(c)
# end your code here


## 4.
# begin your code here
def write_substrings_to_file(s, filename):          #EXPERIMENTING WITH FILES
    if type(s) != str:
        raise TypeError('type(s) is not str')
    if len(filename) == 0 or len(s) == 0:
        raise ValueError('Has to recieve a value to perform')
    x = open(filename, 'a')
    text = ""
    if len(s)== 1:
        x.write(s)
        x.close()
        y = open(filename, 'r')
        z = str(y.read())
        y.close()
        return z
    for letter in s:
        text += letter
        x.write(text)
        x.write('\n')
    x.close()
    return write_substrings_to_file(s[1::], filename)

a = write_substrings_to_file('abc', 'text_1.txt')
print(a)
# end your code here

 
## 5.
# begin your code here
def escape(maze, i, j):
    if i== len(maze)-1 and j==len(maze[0])-1:       #IN CASE WE REACH THE END
        return maze[i][j]
    if maze[i][j]== False:
        return False
    if j<0 or i<0 or i==len(maze) or j==len(maze[0]):   #CHECKS IF WE ESCAPED THE MAZE BOUNDRIES
        return False

    if maze[i][j]== True:                   #AFTER BEING IN AN EMPTY SPOT WE CHANGE IT SO WE WON'T STEP THERE AGAIN
        maze[i][j]=False
        return escape(maze,i, j+1) or escape(maze, i+1, j) or escape(maze, i, j - 1) or escape(maze, i - 1, j)  #CHECKS WHICH DIRECTION WE CAN GO IN AND CALLS RECURSIVLY TO NEXT STEP

#end your code here
