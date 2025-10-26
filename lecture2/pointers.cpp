#include<iostream>

void pp(int & i)
{
    std::cout << &i << " " << i <<" " << sizeof(i)<<"\n";
}

int main(int argc, char* argv [])
{
    int a = 10;
    int b = 20;
    int *pa = &a;
    int *pb = &b;
    *(pb - 1) = 60;

    pp(a);
    pp(b);


   
    return 0;
}