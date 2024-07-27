# POINTER
<details><summary>More</summary>
<p>

## Definition
A pointer is a variable to store the address of the other variable.It is easier to handle the memory by using pointer.

## Pointer size
**The pointer size depend on the architecture of microcontroller.**

**Example:**
32-bit MCU -> Pointer size = 4 bytes

```cpp
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[]){
    printf("%d bytes\n", sizeof(int *));
    printf("%d bytes\n", sizeof(char *));
    printf("%d bytes\n", sizeof(float *));
    printf("%d bytes\n", sizeof(double *));
    printf("%d bytes\n", sizeof(long *));
    printf("%d bytes\n", sizeof(short *));
    printf("%d bytes\n", sizeof(long long *));
    printf("%d bytes\n", sizeof(bool *));
    return 0;
}
```
```cpp
4 bytes
4 bytes
4 bytes
4 bytes
4 bytes
4 bytes
4 bytes
4 bytes
```



## Pointer classification
### 1.Void pointer
**Void pointer** is used to point to the address of variable under any data-type (ex: int, char, double, etc).
If we want to use the **Void pointer** , we need to assign its datatype the same as the variable pointed.

****Syntax**:** ``` void *ptr_void; ```

**Example:**
```cpp
#include <stdio.h>

void sum(int a, int b){
    printf("%d + %d = %d\n", a, b, a+b);
}

int main(int argc, char const *argv[]){
    void *ptr_void;
    ptr_void = (void*)sum;
    ((void (*)(int,int))ptr_void)(9,3);

    int var_int = 10;
    ptr_void = &var_int;
    printf("Dia chi: %p, int: %d\n", ptr_void, *(int*)ptr_void);

    double var_double = 3.14;
    ptr_void = &var_double;
    printf("Dia chi: %p, double: %.3f\n", ptr_void, *(double*)ptr_void);

    char var_char = 'B';
    ptr_void = &var_char;
    printf("Dia chi: %p, char: %c\n", ptr_void, *(char*)ptr_void);

    return 0;
}
```
```cpp
9 + 3 = 12
Dia chi: 00000000005FFE94, int: 10
Dia chi: 00000000005FFE88, double: 3.140
Dia chi: 00000000005FFE87, char: B
```
### 2.Function pointer
**Function pointer** is to store the address of function


A function pointer is a variable that contains the address of a function. Since it is a pointer variable though with some restricted properties, you can use it pretty much like you would any other pointer variable in data structures. We need to declare the return value and argument datatype of this pointer.

NOTE: We can not allocate memory for the **Function pointer**.


****Syntax**:** 
```cpp
<return_type> (* func_pointer)(input_1_data type, input_2_data type,....);

int (*ptr)(int,double);
void (*array[])(int,int);

```

**Example**
```cpp
#include <stdio.h>

void tong(int a, int b){
    printf("%d + %d = %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("%d - %d = %d\n", a, b, a-b);
}

void tich(int a, int b){
    printf("%d x %d = %d\n", a, b, a*b);
}

void thuong(int a, int b){
    printf("%d/%d = %0.3f\n", a, b, a/(double)b);
}

int main(int argc, char const *argv[]){
    // khai báo con trỏ ptr có kiểu trả về là void
    // tham số truyền vào là 2 tham số kiểu integer
    void (*pheptoan[])(int,int) = {&tong, &hieu, &tich, &thuong};
    pheptoan[0](7,10);
    pheptoan[1](7,10);
    pheptoan[2](7,7);
    pheptoan[3](6,5);
    return 0;
}
```

### 3.Pointer to constant


**Pointer to Constant** means that the pointer point to a varible, however, it can not change value of variable


**Syntax**:
```cpp
<data_type> const *ptr_const;
const <data_type> *ptr_const;
```



### 4.Constant pointer
**Constant pointer** is the pointer which only point to **a fix address**. That mean, we can not point to other address.

**Syntax**:
```cpp
int *const const_ptr = &value;
```



### 5.NULL pointer 
In case we declare a pointer and do not assign to any variable. We need to assign it to **NULL*.
```cpp
int *ptr_null = NULL;
//  ptr_null = 0x00: initalize address value
// *ptr_null = 0   : initalize value
```
### 6.Pointer to pointer
The first pointer is used to store the address of the variable. And the second pointer is used to store the address of the first pointer. That is why they are also known as double-pointers. We can use a pointer to a pointer to change the values of normal pointers or create a variable-sized 2-D array. A double pointer occupies the same amount of space in the memory stack as a normal pointer.

## Example of Pointer 
```cpp
#include <stdio.h>
#include <string.h>

typedef struct{
    char  ten[50];
    float diemTrungBinh;
    int   id;
}SinhVien_t;

int stringCompare(const char *str1,const char *str2){ // Why const???, if not const???
    while (*str1 && (*str1 == *str2)){    // so sánh từng ký tự của mỗi chuỗi
        str1++;  // tăng địa chỉ để truy cập vào ký tự tiếp theo khi 2 ký tự giống nhau
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2; // lấy mã Ascii để so sánh   // Why unsigned char???
}

// Hàm so sánh theo tên
int compareByName(const void *a,const void *b){	// why void pointer???
    SinhVien_t *sv1 = (SinhVien_t *)a;
    SinhVien_t *sv2 = (SinhVien_t *)b;
    return stringCompare(sv1->ten, sv2->ten);
}

// Hàm so sánh theo điểm trung bình
int compareByDiemTrungBinh(const void *a, const void *b) {
   SinhVien_t *sv1 = (SinhVien_t *)a;
   SinhVien_t *sv2 = (SinhVien_t *)b;
   if (sv1->diemTrungBinh > sv2->diemTrungBinh)
   {
       return 1;
   }
  
   return 0;
}

// Hàm so sánh theo ID
int compareByID(const void *a, const void *b) {
   SinhVien_t *sv1 = (SinhVien_t *)a;
   SinhVien_t *sv2 = (SinhVien_t *)b;
   return sv1->id - sv2->id;
}

// Hàm hoán vị
void swapSV(SinhVien_t *a, SinhVien_t *b){
    SinhVien_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp sinh viên dựa theo tiêu chí (tên hoặc điểm hoặc ID)
void sort(SinhVien_t array[], size_t size, int (*compareFunc)(const void *, const void *)){
    int i,j;
    for (i=0; i<size-1; i++){
        for (j=i+1; j<size; j++){
            if (compareFunc(array+i,array+j) > 0){
                swapSV(array+i,array+j);
            }
        }
    }
}



void display(SinhVien_t *array, size_t size){
    for (size_t i = 0; i < size; i++){
        printf("ID: %d,  Ten: %s,   Diem tb: %.2f\n", array[i].id, array[i].ten, array[i].diemTrungBinh);
    }
    printf("\n");
}

int main(int argc, char const *argv[]){
    SinhVien_t danhsanhSV[] = {
        {
            .ten = "Hoang",
            .diemTrungBinh = 7.5,
            .id = 100
        },
        {
            .ten = "Tuan",
            .diemTrungBinh = 6.5,
            .id = 101
        },
        {
            .ten = "Vy",
            .diemTrungBinh = 5.5,
            .id = 102
        }
    };
    size_t size = sizeof(danhsanhSV) / sizeof(danhsanhSV[0]);
    
    // Sắp xếp theo tên
    sort(danhsanhSV, size, compareByName);
    display(danhsanhSV, size);

    // Sắp xếp theo điểm trung bình
    sort(danhsanhSV, size, compareByDiemTrungBinh);
    display(danhsanhSV, size);

    // Sắp xếp theo ID
    sort(danhsanhSV, size, compareByID);
    display(danhsanhSV, size);

    return 0;
}
```
```cpp
ID: 100,  Ten: Hoang,   Diem tb: 7.50
ID: 101,  Ten: Tuan,   Diem tb: 6.50
ID: 102,  Ten: Vy,   Diem tb: 5.50

ID: 102,  Ten: Vy,   Diem tb: 5.50
ID: 101,  Ten: Tuan,   Diem tb: 6.50
ID: 100,  Ten: Hoang,   Diem tb: 7.50

ID: 100,  Ten: Hoang,   Diem tb: 7.50
ID: 101,  Ten: Tuan,   Diem tb: 6.50
ID: 102,  Ten: Vy,   Diem tb: 5.50
```

</p>
</details>

# Goto - setjmp.h
<details><summary>More</summary>
<p>

## Goto statement
### Definition



**goto** tells the compiler to go to or jump to the statement marked as a label.

NOTE: The use of the **goto** statement is highly discouraged as it makes the program logic very complex and is hard to follow the program flow.

**Example:**
```cpp
    int i=0;
    
    // đặt label start
    start:
        if (i >= 5){
            goto end;       // move to label "end"
        }
        printf("%d\n",i);
        i++;
        goto start;

    // đặt label end
    end:
        printf("The end\n");// move to label "start"
    return 0;
}
```


### Goto application
#### Exit the **loop in loop**
In case, we need to exit from multiple loop that is very complicated to exit one by one. So, **goto** will be useful in this case.

```cpp
int main(int argc, char const *argv[]){
    int count=0;

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (i==5 && j==5) goto exit_loops;
            else{
                printf("i=%d  j=%d\n", i, j);
            }
        }
    }
    
    exit_loops:
    return 0;
}
```

#### Error handling & release memory
We can use **goto** to release the allocated memory before exit the function.
```cpp
void process_data() {
    int *data = malloc(sizeof(int) * 100);
    if (data == NULL) {
        goto cleanup;
    }

    // TODO

    cleanup:
    free(data);
}
```

#### Finite State Machines (FSM)

```cpp
switch (current_state) {
    case STATE_A:
        // Xử lý State A
        if (condition) {
            goto STATE_B;
        }
        break;

    case STATE_B:
        // Xử lý State B
        break;
}
```

## setjmp library
### Definition
There are 2 main function in this librayry: **setjmp** and **longjmp**.

```cpp
setjmp(jmp_buf buf);
```
```cpp
void longjmp(SETJMP_FLOAT128 *_Buf, int _Value);
```

**How does it work?**

**Example:**
```cpp
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;

double thuong(int a, int b){
	if (!b){
		longjmp(buf,1);
	}
	return a/(double)b;
}

int checkArray(int *arr, int size){
    	if (size <= 0){
        	longjmp(buf,2);
	}
    	return 1;
}

int main(int argc, char const *argv[]){
	// khi bắt đầu thì setjmp(buf) luôn bằng 0

	if ((exception_code = setjmp(buf)) == 0){
		int array[0];
		double ketqua = thuong(8,0);
		printf("Ket qua: %0.3f\n", ketqua);
		checkArray(array,0);
	}
	else if (exception_code == 1){
		printf("ERROR! Mau bang 0\n");
	}
	else if (exception_code == 2){
		printf("ERROR! Array bang 0\n");
	}
	return 0;
}
```

### Exception handling
Use **setjmp** & **longjmp** for exception handling in programming C by macro define: **TRY**, **CATCH**, **THROW**.

```cpp
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x)
#define THROW(x) longjmp(buf,x)
```

**Example:**
```cpp
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x)
#define THROW(x) longjmp(buf,x)

double thuong(int a, int b){
    if (b == 0){
        THROW(1);
    }
    return a/(double)b;
}

int checkArray(int *arr, int size){
    if (size <= 0){
        THROW(2);
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    
    TRY{
        int array[0];
        double ketqua = thuong(8,1);
        printf("Ket qua = %0.3f\n",ketqua);
        checkArray(array,0);
    }
    CATCH(1){
        printf("Error\n");
    }
    CATCH(2){
        printf("Error! Array = 0\n");
    }

    return 0;
}
```

</p>
</details>

# Static - Extern - Register - Volatile
<details><summary>More</summary>
<p>

## Static
**Syntax**:
```cpp
static <data_type> <name_variable>;
static <data_type> <name_function>;
```

### static local variables
A local variable in a function is declared with static remaining the value of variable when call function within this function.


**Example:**
```cpp
#include <stdio.h>

int *ptr = NULL;

void Func(){
    static int a=0;
    ptr = &a;
    a++;
    printf("a = %d\n",a);
}

int main(int argc, char const *argv[]){
    Func();     // in ra "a = 1"
    Func();     // in ra "a = 2"
    *ptr = 20;  // a = 20
    Func();     // in ra "a = 21"
    return 0;
}
```

### static global variables
A local variable in a file is declared with static remaining the value within this function.

**Example:**

File Ex1.c
```cpp
#include <stdio.h>

extern void display();
extern int value1;
extern int value2;

int main(int argc, char const *argv[]){
    value1 = 10;
    value2 = 20;
    display();
    return 0;
}
```
File Ex2.c
```cpp
#include <stdio.h>

static int value1 = 5;
int value2 = 5;

void display(){
    printf("value1=%d\n",value1);
    printf("value2=%d\n",value2);
}
```
```cpp
undefined reference to `value1'
```
Running file Ex1.c cause error due to attempting to use an extern variable when it is declared as static in other file.


## Extern
### Definition

It allows different files in the same folders can access and use the same varible without repeated declaration.

NOTE: **extern** only allows declare, not for assigning.

**Syntax**:
```cpp
extern <data_type> <name_variable>;
```

**Example: **

File main.c
```cpp
#include <stdio.h>

extern int var_global;
extern void Func();

int main(int argc, char const *argv[]){
    var_global = 3;
    Func();
    return 0;
}
```
File File1.c
```cpp
#include <stdio.h>
int var_global = 1;
void Func(){
    printf("%d\n",var_global);
}
```

### Application
**Program pregmantation**: a big program is divided into many smaller files, it is easier for debug and design.

**Sharing variable from library**

**Calculation result sharing between files**





## Volatile
### Definition
The volatile keyword is intended to prevent the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler. 

**Syntax**:
```cpp
volatile <data_type> <name_variable>;
```

Example:
```cpp
volatile int flag;

void interrupt_handler(){
    flag = 1; // flag value can be change
}
```

## Register
### Definition

//![image](https://github.com/user-attachments/assets/5325937f-1104-4845-9bda-7f1e7c1589b9)

**register** is to store a global variable within **register** instead of RAM.
**register** help increasing performance of program.
**register** is prioritized for a few varible for calculation purpose in program.

NOTE: **register** is used in restricted due to the limitation of register size.

**Syntax**:
```cpp
register <data_type> <name_variable>;
```

**Example:**
```cpp
#include <stdio.h>
#include <time.h>

int main() {
    // Start point
    clock_t start_time = clock();
    int i;
    //register int i;

    
    for (i = 0; i < 2000000; ++i) {
        // TODO
    }

    // End point
    clock_t end_time = clock();

    // Process time
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("running time: %f giay\n", time_taken);
    return 0;
}
```

Without register ```running time: 0.002 giay```

With register ```running time: 0.001 giay```

</p>
</details>

# Bitmask
<details><summary>More</summary>
<p>

## Definition

A binary digit is used as a flag in bitmasking to denote the status or existence of a feature or trait. To accomplish this, certain bits within a binary number are set or reset to reflect a particular state or value.

Common bitwise operations in bitmasking are:

OR (|) – sets a bit to 1 if either of the corresponding bits in the operands is 1.

AND (&) – sets a bit to 1 if both the corresponding bits in the operands are 1.

XOR (^) – sets a bit to 1 if the corresponding bits in the operands are different.

NOT (~) – flips the bits in the operand, i.e., sets 0 bits to 1 and 1 bits to 0.

## Bitwise operator



![image](https://media.geeksforgeeks.org/wp-content/uploads/20220922145839/BItwiseoperatortruthtable-300x197.png)


![image](https://embeddedwala.com/uploads/images/202206/img_temp_62af09c374d866-36338888-48712239.gif)


</p>
</details>

## Test 
<details>
<summary><b>Hidden markdown text on GitHub</b></summary>

Any folded content here. It requires an empty line just above it.

</details>
