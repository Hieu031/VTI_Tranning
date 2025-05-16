/*
Phân mảnh bộ nhớ 
1. Data alignment là khi data được load lên memory sẽ được CPU sắp xếp lại
để tiện cho việc truy xuất nhất có thể.
2. Các ô nhớ được sắp xếp liên tiếp và có kích thước là 1 byte.
3. Trong các vi xử lý hiện đại thì chúng không truy xuất từng ô một mà
chúng sẽ truy xuất theo nhóm các ô nhớ gồm 2, 4 hoặc 8 bytes nhằm tăng năng suất
đọc ghi của hệ thống.
4. Để làm được việc đó thì cần có:
    - Data alignment: Sắp xếp data sao cho địa chỉ của chúng luôn là số chẵn
    và phù hợp với hệ thống.
    - Data padding: Để làm được alignment như trên thì cần padding (đệm)
    một số byte vào để thỏa mãn.
*/
/*
Tính kích thước của Struct
- Tìm biến có kích thước lớn nhất trong Struct, Sau đó sẽ cấp phát một block có kích thước
tương ứng với member lớn nhất đó.
- Tiếp đến, bắt đầu điền các vùng nhớ của member theo thứ tự khai báo vào block đó.
- Khi nào hết một block sẽ khai báo một block mới đến khi điền đủ các biến.
*/

/*
Example:
1. 
struct A{
    int x; //4 bytes
    double y; //8 bytes
    short int z; //2 bytes
};

Block = 8 bytes. 
1. cấp 4 ô nhớ cho x => còn 4 ô không đủ cho y => cấp block mới => đủ block mới
=> cấp thêm 1 block mới nữa => tổng cộng có 3 block 8 bytes được cấp
==> kích thước của struct ở đây là 24 bytes.
*/

/*
Ngoài ra để tính kích thước của struct có thể dùng 
    sizeof(struct_name);
*/