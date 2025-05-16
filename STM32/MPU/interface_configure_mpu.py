# mpu_gui.py
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QLineEdit, QComboBox, QPushButton, QTextEdit
from PyQt5.QtCore import Qt

class MPUConfigApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("MPU Config Generator")
        self.setGeometry(100, 100, 600, 400)

        # Widget chính
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # Region Config
        self.region_layout = QVBoxLayout()
        self.layout.addLayout(self.region_layout)

        # Region Number
        self.region_num_layout = QHBoxLayout()
        self.region_num_label = QLabel("Region Number (0-7):")
        self.region_num_input = QLineEdit()
        self.region_num_layout.addWidget(self.region_num_label)
        self.region_num_layout.addWidget(self.region_num_input)
        self.region_layout.addLayout(self.region_num_layout)

        # Start Address
        self.start_addr_layout = QHBoxLayout()
        self.start_addr_label = QLabel("Start Address (Hex):")
        self.start_addr_input = QLineEdit("0x40000000")
        self.start_addr_layout.addWidget(self.start_addr_label)
        self.start_addr_layout.addWidget(self.start_addr_input)
        self.region_layout.addLayout(self.start_addr_layout)

        # Region Size
        self.size_layout = QHBoxLayout()
        self.size_label = QLabel("Region Size (log2):")
        self.size_input = QComboBox()
        self.size_input.addItems([str(i) for i in range(5, 32)])  # 32B đến 4GB
        self.size_input.setCurrentText("9")  # 1KB mặc định
        self.size_layout.addWidget(self.size_label)
        self.size_layout.addWidget(self.size_input)
        self.region_layout.addLayout(self.size_layout)

        # Memory Type
        self.mem_type_layout = QHBoxLayout()
        self.mem_type_label = QLabel("Memory Type:")
        self.mem_type_input = QComboBox()
        self.mem_type_input.addItems(["Strong Order", "Normal Cacheable", "Normal Non-Cacheable"])
        self.mem_type_layout.addWidget(self.mem_type_label)
        self.mem_type_layout.addWidget(self.mem_type_input)
        self.region_layout.addLayout(self.mem_type_layout)

        # Access Right
        self.access_layout = QHBoxLayout()
        self.access_label = QLabel("Access Right:")
        self.access_input = QComboBox()
        self.access_input.addItems(["No Access", "Full Access", "Read Only"])
        self.access_layout.addWidget(self.access_label)
        self.access_layout.addWidget(self.access_input)
        self.region_layout.addLayout(self.access_layout)

        # Enable
        self.enable_layout = QHBoxLayout()
        self.enable_label = QLabel("Enable Region:")
        self.enable_input = QComboBox()
        self.enable_input.addItems(["Yes", "No"])
        self.enable_layout.addWidget(self.enable_label)
        self.enable_layout.addWidget(self.enable_input)
        self.region_layout.addLayout(self.enable_layout)

        # Nút Generate
        self.generate_btn = QPushButton("Generate Config")
        self.generate_btn.clicked.connect(self.generate_config)
        self.layout.addWidget(self.generate_btn)

        # Kết quả
        self.result_text = QTextEdit()
        self.result_text.setReadOnly(True)
        self.layout.addWidget(self.result_text)

    def generate_config(self):
        region_num = self.region_num_input.text()
        start_addr = self.start_addr_input.text()
        size = self.size_input.currentText()
        mem_type = self.mem_type_input.currentIndex()  # 0: Strong, 1: Cacheable, 2: Non-Cacheable
        access = self.access_input.currentIndex()      # 0: No Access, 1: Full, 2: Read Only
        enable = self.enable_input.currentIndex()      # 0: Yes, 1: No

        # Chuyển đổi sang định dạng MPU Driver
        mem_type_map = {0: "MPU_MEM_STRONG_ORDER", 1: "MPU_MEM_NORMAL_CACHEABLE", 2: "MPU_MEM_NORMAL_NONCACHE"}
        access_map = {0: "MPU_ACCESS_NO_ACCESS", 1: "MPU_ACCESS_FULL", 2: "MPU_ACCESS_READ_ONLY"}
        enable_map = {0: 1, 1: 0}

        config = (
            f"MPU_RegionConfig_t region_{region_num} = {{\n"
            f"    .RegionNumber = {region_num},\n"
            f"    .StartAddress = {start_addr},\n"
            f"    .Size = {size},\n"
            f"    .MemoryType = {mem_type_map[mem_type]},\n"
            f"    .AccessRight = {access_map[access]},\n"
            f"    .Enable = {enable_map[enable]}\n"
            f"}};"
        )
        self.result_text.setText(config)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MPUConfigApp()
    window.show()
    sys.exit(app.exec_())
