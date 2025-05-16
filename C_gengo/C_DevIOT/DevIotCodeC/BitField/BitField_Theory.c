/*
Bit fields là một kỹ thuật nhằm tối đa bộ nhớ trong Struct, trong một số
trường hợp khi ta khai báo biến nhưng không sử dụng tối đa phạm vi
giá trị đó.

Example:
1. Khi khai báo biến "bool" để thể hiện "True" or "False". Nó chiếm
1 byte tương đương 8 bit nhưng ta chỉ dùng 1 bit để biểu diễn 0 or 1.
Do đó đã lãng phí 7 bit còn lại.

2. Khai báo 1 biến "int age" nhưng ta không bao giờ sử dụng cả 4 bytes 
đó để biểu diễn tuổi.

--> Những trường hợp trên ta có thể sử dụng "Bit Field" để tối ưu hóa bộ nhớ.
*/