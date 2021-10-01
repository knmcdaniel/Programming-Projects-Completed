function a(){
    return 35;
}
console.log(a())

// This function Returns 35.


function a(){
    return 4;
}
console.log(a()+a());

// This function returns 4
//The function is called twice in the console.log and it adds them
//Thus the output of this code snippet is 8

function a(b){
    return b;
}
console.log(a(2)+a(4));

// This function returns b
//The function is called twice in the console.log and it adds them
//The first run through inserts 2 into the function, thus returning 2.
//The second run through inserts 4 into the function, thus returning 4.
//Since the console.log calling to add them.
//The output of this code snippet is 6

function a(b){
    console.log(b);
    return b*3;
}
console.log(a(3));

//This function returns b * 3
// The function is called with a value of 3
//The first line of the function simply prints the input which is 3.
//The function then returns the value of b*3 which, in this case, is 3*3.
//The values returned from this code snippet are below
//3
//9

function a(b){
    return b*4;
    console.log(b);
 }
 console.log(a(10));

//This function returns b * 4
//The function is called with the value of 10 being inserted.
//The function then returns b * 4 or 10*4
//The function ignores the console.log(b) within itself because it is located after the return.
//The results of this code snippet are below.
//40

function a(b){
    if(b<10) {
        return 2;
    }
    else     {
        return 4;
    }
    console.log(b);
}
console.log(a(15));

//This function accepts an input and puts that value to b
//Once the function is called the if statement within it is evaluated.
//within the if statement if b is less than 10 it will force the function to exit and return the value of 2
//if b is not less than 10 it will jump to the else statement and force the function to exit and return the value of 4
//The console.log(b); after the if else statement is ignored because it will never be utilized since the function exits from within the if statement
//The function is called with console.log(a(15)).
// this sets the value of b to 15.
//The if statement checks to see if b is less than 10, since it is not it continues to the else statement
//within the else statement the function returns the value of 4.
//Thus the result of the code snippet is 4.


function a(b,c){
    return b*c;
}
console.log(10,3);
console.log( a(3,10) );

//This function returns the value of b*c. It also accepts to inputs labeled b and c.
//the first console.log does not call the function, this simply prints 10, 3 to the console. 
//The second console.log does call the function and b = 3 and c = 10.

// |__Var__|___Value___|
//     b   |    3
//     c   |    10
//         |
//         |
//         |
//         |
//         |

//The output of this code snippet is 
//10 3
//30

function a(b){
    for(var i=0; i<10; i++){
        console.log(i);
    }
    return i;
}
console.log(3);
console.log(4);

//This function receives one input and sets it to the variable of b.
//The for loop simply iterates until i is no longer less than 10.
//The function then returns i
//the two consoles outside of the function does not actually call the function.
//thus the function is never called and the for loop is never ran.
//The output of this code snippet is below.
//3
//4

function a(){
    for(var i=0; i<10; i++){
        i = i +2;
        console.log(i);
    }
}
a();

//This function does not have an input
//This function has a for loop that simply iterates until i is no longer less than 10.
//each loop of the for loop i has 2 added to it then the console prints the value of i and then i is added 1 more to it.


// |__Var__|___Value___|
//     i   |    0 -> 2 -> 3 -> 5 -> 6 -> 8 -> 9 -> 11
//         |    
//         |
//         |
//         |
//         |
//         |

//The function's output is below
//2
//5
//8
//11


function a(b,c){
    for(var i=b; i<c; i++) {
        console.log(i);
    }
    return b*c;
}
a(0,10);
console.log(a(0,10));

//This function has 2 inputs, b and c
//the for loop within the function sets the var i to the value of b
//this loop will iterate while i is less than c
//within the for loop it will print the value of i to the console
//after the for loop is over the function will return b * c
//the function is called twice, once without writing the return values to the console, the second time it will write the return values to the console. 
//both function calls will print the for loop iterations.

// |__Var__|___Value___|
//     b   |    0 -> 0
//     c   |    10 -> 10
//     i   |    b  -> 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 0(b) -> 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
//         |
//         |
//         |
//         |

//The output is below.
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 0


function a(){
    for(var i=0; i<10; i++){
        for(var j=0; j<10; j++){
            console.log(j);
        }
        console.log(i);
    }
}

//This function has no input and is not called. 
//The T diagram for this will be very long because it is a nested for loop.
//In short, the main for loop will go once, so i will = 0.
//While i = 0 it will go into the other for loop and loop 10 times.
//j starts at 0 and loops up to 10 breaking the that for loop and causing the i value to iterate up to 1.
//when i = 1 it will loop through the second for loop again taking j from 0 to 10 again.
//This will loop 10 times until i is 10 and it will break out of the nested for loop. 
//This means, j will go from 0 to 10, 10 different times while i is iterated from 0 to 10 one time.
//The output will also be very large, it will output i once then j ten times per loop and it will loop 10 times. 
//The output will technically never be used in this specific code snippet because nothing is calling the function.

function a(){
    for(var i=0; i<10; i++){
        for(var j=0; j<10; j++){
            console.log(i,j);
        }
        console.log(j,i);
    }
}
//This function is very similar to the previous function, the only difference is that it will print both i and j on every loop. 
//But this function is also not being called and will produce no output

var z = 10;
function a(){
    var z = 15;
    console.log(z);
}
console.log(z);

//The output of this code snippet is 10
//The function is not being called.


var z = 10;
function a(){
    var z = 15;
    console.log(z);
}
a();
console.log(z);

//This function is being called and the output is below.
//15
//10

// |__Var__|___Value___|
//     z   |    10 -> 15 -> 10
//         |    
//         |    
//         |
//         |
//         |
//         |


var z = 10;
function a(){
    var z = 15;
    console.log(z);
    return z;
}
z = a();
console.log(z);

//This function is being called and the output is below.
//15
//15

// |__Var__|___Value___|
//     z   |    10 -> 15
//         |    
//         |    
//         |
//         |
//         |
//         |
