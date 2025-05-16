/*
Để khắc phục phân mảnh bộ nhớ (Dư thừa bộ nhớ)
1. Sử dụng từ khóa #pragma pack(n) để cho complier biết cần cấp phát 
cho các phần tử trong struct theo n bytes một.
example:

#pragma pack(1)

struct test {
    int x; 
    char b;
    double z;
};

#pragma pack() //end
 
=> struct sex được cấp phát theo 1 bytes một.
*/