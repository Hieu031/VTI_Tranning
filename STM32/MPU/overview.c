/*
MPU - Memory protection Unit

1. MPU có thể coi là một cơ chế để giúp quản lý các vùng nhớ quan trọng, cần được bảo vệ 
trong hệ thống nhúng cho Vi điều khiển.

2. MPU là một ngoại vi có thể lập trình được (Thường là ngoại vi Core, giống như System Tick hay NVIC)
sử dụng để phân vùng và xác định quyền truy cập bộ nhớ.
    - Nó có thể giám sát các công việc như tìm nạp lệnh, truy cập dữ liệu từ processor, và có thể trigger
    một Fault Exception khi có truy cập không hợp lệ.
    Example: Setup bảo vệ không cho đọc/ghi vùng nhớ Flash, nếu người dùng cố tình làm điều đó thì sẽ
    dẫn đến 1 fault (ví dụ HardFault)

3. Một số đặc điểm cơ bản của MPU
- Cung cấp tối đa 8/16 Region tùy dòng, có thể cấu hình được
- Kích thước nhỏ nhất có thể lập trình mỗi Region là 32 bytes.
- Kích thước tối đa của mỗi Region là 4GB, phải là bội số của 32 bytes.
- Tất cả các Region phải bắt đầu với địa chỉ Aligned 32 bytes.
- Các Region độc lập với nhau về quyền đọc/ghi cho cả chế độ Privilegend và Un-Privileged.
- Thuộc tính XN - Excute Never cho phép phân tách vùng code và vùng data.
- Các Region có thể Overlap và các địa chỉ trong vùng Overlap sẽ có thuộc tính của Region có mức ưu tiên
cao hơn.

4. Đặc điểm chung của MPU trong Cortex M4
- Setup thuộc tính từng vùng một cách độc lập
- Các Region có thể Overlap lên nhau
- Có 8 Region riêng biệt (0 - 7). Region 7 có độ ưu tiên cao nhất và giảm dần về 0.
- Một Background Region là Region 0.

5. Các thanh ghi cấu hình MPU
5.1. Thanh ghi MPU_CTRL: Thanh ghi điều khiển các hoạt động quan trọng của MPU
    Bit 2 - PRIVDEFENA: Cho phép truy cập vào vùng nhớ deafault memory map 
    (Là vùng nhớ không được cấu hình bởi MPU) ở chế độ Privileged.

    Bit 1 - HFNMIENA: Cho phép MPU hoạt động trong Hardfault hay Memfault.
    1 = Enable MPU in Fault
    0 = Disable MPU in Fault.
    
    Bit 0 - ENABLE: Enable MPU (=1).

5.2. Thanh ghi MPU_RBAR - Region Base Address Register
- Định nghĩa địa chỉ base của Region chứa trong thanh ghi MPU_RNR. Nó có thể update lại giá trị của 
thanh ghi MPU_RNR

    Bit[31:N] - ADDR: Chứa Base Region của Region
    N = Log2(Region Size in Bytes)

    Bit 4 - VALID: Bit này xác định thanh ghi chứa Region Number
    0 = Xác định Region bằng thanh ghi MPU_RNR
    1 = Updae thanh ghi RNR bằng rường Region trong thanh ghi RBAR

    Bit[3:0] - REGION: Trường này chứa giá trị Region Number để Update cho thanh  ghi RNR nếu
    bit VALID = 1.

5.3. Thanh ghi MPU_RASR - Region Attribute & Size Register
- Có công dụng define region size & memory attributes của Region chứa trong thanh ghi MPU_RNR, enable region 
và subregion.

    Bit 28 - XN: Bit disable Íntruction Access.
    0 = Instruction fetch enabled
    1 = Instruction fetch disabled
    
    Bit[26-24] - AP: Access Permission Feild, cho biết quyền truy cập vào Region.

    Bit[21:19, 17, 16] - TEX, C, B: Memory Access Attribute, chứa các thuộc tính khác của Region 
    như Memory Type, Shareability,...

    Bit 18 - S: Shareable Bit, là bit cho phép share vùng nhớ trong các ứng dụng Multicore.

    Bit[5:1] - SIZE: Kích thước của Region, min = 0b00010 = 3
    Region size in bytes = 2 ^ (SIZE + 1)

    Bit 0 - ENABLE: Bit Enable Region

5.3.1. Subregion trong MPU_RASR
- MPU_RASR có hỗ trợ tính năng Subregion, cho phép chia nhỏ mỗi Region thành 8 phần bằng nhau để quản
lý chi tiết hơn.

- Tính năng này được điều khiển bởi các bit SRD - Subregion Disable (Bit [15:8]) trong thanh ghi MPU_RASR.

    Bit [15:8] - SRD: Subregion Disable, mỗi bit tương ứng vơi một Subregion (0 - 7)
    0 = Subregion được bật (enable)
    1 = Subregion bị tắt (disable)

- Cách hoạt động: Mỗi Region được chia thành 8 Subregion có kích thước bằng nhau, bắt đầu từ địa chỉ base
Kích thước mỗi Subregion là Region Size / 8. Nếu một Subregion bị disable, bất kì truy cập nào vào Subregion đó
sẽ gây ra MemManage Fault.

- Ứng dụng: Được dùng khi cần bảo vệ một vùng nhỏ trong Region mà không muốn cấu hình thêm Region mới.

- Lưu ý: Subregion chỉ hoạt động khi Region Enable và kích thước tối thiểu 25 bytes để có thể chia 8 phần bằng nhau (mỗi phần >= 32 bytes)


6. Sử dụng MPU cho Microcontroller
- Để tránh các lỗi không muốn trong quá trình cấu hình thì ta nên disable các ngắt trước khi udate các thuộc tính của MPU.

- Đối với vi điều khiển, ARM cung cấp một số ví dụ điển hình để giúp cấu hình MPU đảm bảo 
họat động đúng mong muốn, đặc biệt là bộ nhớ Flash trong các ứng dụng chạy dài ngày, cần ngăn
việc truy cập bộ nhớ trái phép.

*/