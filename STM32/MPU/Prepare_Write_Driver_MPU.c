/*
Plan to design main function for MPU

1. Define các Macro cần thiết
- Tổ chức Data cấu hình cho MPU, bao gồm các yếu tố
    1.1 Enable/Disable bit Default Memory Map
    1.2 Enable/Disable MPU in Exception
    1.3 Enable/Disable MemManage Handler
    1.4 Data Config bao gồm: Region Number, Start Address, 
    Region Size, Memory Type, Access Right,...

2. Viết hàm MPU_Init => Sử dụng để khởi tạo MPU với bộ Data config

3. Viết hàm MPU_DeInit => Reset tất cả các cấu hình MPU về với trạng thái mặc định

4. Viết hàm MPU_SetRegionConfig => Cấu hình cho một Region với các thuộc tính khác 
nhau khi Init

5. Viết hàm MPU_GetErrorDetails => Get lỗi khi chương trình nhảy vào Fault. 

*/