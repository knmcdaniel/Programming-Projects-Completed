// Get 1 to 255 - Write a function that returns an array with all the numbers from 1 to 255.
var array = []
function number1(){
    for( var i=1; i<=255; i++){
        array.push(i);
    }
    return array;
}
number1();
console.log(array);


// Get even 1000 - Write a function that would get the sum of all the even numbers from 1 to 1000.  You may use a modulus operator for this exercise.
var sum =0
var num =0
function number2(num){
    for (var i=1; i<=num; i++){
        if (i % 2 == 0){
            sum = sum + i
        }
    }
}
number2(1000)
console.log(sum)

// Sum odd 5000 - Write a function that returns the sum of all the odd numbers from 1 to 5000. (e.g. 1+3+5+...+4997+4999).
var sum =0
var num =0
function number3(num){
    for (var i=1; i<=num; i++){
        if (i % 2 != 0){
            sum = sum + i
        }
    }
}
number3(5000)
console.log(sum)

// Iterate an array - Write a function that returns the sum of all the values within an array. (e.g. [1,2,5] returns 8. [-5,2,5,12] returns 14).
var array = [0,10,20,30,40,50,60,70,80,90,100]
var arraySum = 0
function number4(arraylength){
    for (var i=0; i<arraylength; i++)
        arraySum = arraySum + array[i]
}
number4(array.length)
console.log(arraySum)

// Find max - Given an array with multiple values, write a function that returns the maximum number in the array. (e.g. for [-3,3,5,7] max is 7)
var array = [-3,3,5,7]
var arrayMax = 0
function number5(arraylength){
    for (var i=0; i<arraylength; i++)
        if(array[i]> arrayMax){
            arrayMax = array[i];
        }
}
number5(array.length)
console.log(arrayMax)

// Find average - Given an array with multiple values, write a function that returns the average of the values in the array. (e.g. for [1,3,5,7,20] average is 7.2)
var array = [1,3,5,7,20]
var arrayAverage = 0
function number6(arraylength){
    for (var i=0; i<arraylength; i++){
        arrayAverage = arrayAverage + array[i]
    }
    arrayAverage = arrayAverage / arraylength
}
number6(array.length)
console.log(arrayAverage)


// Array odd - Write a function that would return an array of all the odd numbers between 1 to 50. (ex. [1,3,5, .... , 47,49]). Hint: Use 'push' method.
var array = []
function number7(num){
    for (var i=1; i<=num; i++){
        if (i % 2 != 0){
            array.push(i)
        }
    }
}
number7(50)
console.log(array)

// Greater than Y - Given value of Y, write a function that takes an array and returns the number of values that are greater than Y. For example if arr = [1, 3, 5, 7] and Y = 3, your function will return 2. (There are two values in the array greater than 3, which are 5, 7).
var array = [0,10,20,30,40,50,60,70,80,90,100]
var greaterThanCounter = 0
function number8(arraylength, greaterThan){
    for (var i=0; i<arraylength; i++){
        if (array[i] > greaterThan){
            greaterThanCounter++
        }
    }
}
number8(array.length, 66)  //You can adjust the greaterThan variable here
console.log(greaterThanCounter)


// Squares - Given an array with multiple values, write a function that replaces each value in the array with the value squared by itself. (e.g. [1,5,10,-2] will become [1,25,100,4])
var array = [1,5,10,-2]
function number9(arraylength){
    for (var i=0; i<arraylength; i++){
        array[i] = array[i] * array[i]
    }
}
number9(array.length)
console.log(array)

// Negatives - Given an array with multiple values, write a function that replaces any negative numbers within the array with the value of 0. When the program is done the array should contain no negative values. (e.g. [1,5,10,-2] will become [1,5,10,0])
var array = [1,5,10,-2]
function number10(arraylength){
    for (var i=0; i<arraylength; i++){
        if (array[i] < 0){
            array[i] = 0
        }
    }
}
number10(array.length)
console.log(array)

// Max/Min/Avg - Given an array with multiple values, write a function that returns a new array that only contains the maximum, minimum, and average values of the original array. (e.g. [1,5,10,-2] will return [10,-2,3.5])
var array = [1,5,10,-2]
var newArray = []
var max = null
var min = null
var average = 0
function number11(arraylength){
    for (var i=0; i<arraylength; i++){
        if (array[i] < min){
            newArray[1] = array[i]
            average = average + array[i]
        }
        else if (array[i] > max){
            newArray[0] = array[i]
            average = average + array[i]
        }
        else {
            average = average + array[i]
        }
    }
    newArray[2] = average / arraylength
}
number11(array.length)
console.log(newArray)

// Swap Values - Write a function that will swap the first and last values of any given array. The default minimum length of the array is 2. (e.g. [1,5,10,-2] will become [-2,5,10,1]).

var array = [1,5,10,-2]
function number12(arraylength){
    [array[0], array[arraylength-1]] = [array[arraylength-1], array[0]]
}
number12(array.length)
console.log(array)

// Number to String - Write a function that takes an array of numbers and replaces any negative values within the array with the string 'Dojo'. For example if array = [-1,-3,2], your function will return ['Dojo','Dojo',2].

var array = [-1,-3, 0,2]
function number13(arraylength){
    for (var i=0; i<arraylength; i++){
        if (array[i] < 0){
            array[i] = "Dojo"
        }
    }
}
number13(array.length)
console.log(array)

