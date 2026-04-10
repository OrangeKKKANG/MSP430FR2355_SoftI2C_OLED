# MSP430FR2355_SoftI2C_OLED
MSP430FR2355 软件I2C驱动0.96寸OLED(SSD1306)，基于江协科技OLED驱动和开源I2C驱动移植，CCS 20.2.0可直接编译运行

## 工程简介
- 主控芯片：MSP430FR2355（FRAM系列，低功耗）
- 通信方式：软件I2C（可自由映射GPIO引脚）
- OLED屏幕：0.96寸 I2C接口（SSD1306主控，128*64分辨率）
- 开发环境：Code Composer Studio (CCS) 20.2.0
- 核心功能：OLED初始化、清屏、显示字符/字符串，工程可直接导入编译，无需额外配置。

## 开源说明
- 软件I2C驱动源自网络开源经典实现，在此基础上修改适配MSP430FR2355的GPIO配置和延时逻辑。
- OLED驱动逻辑基于江协科技开源驱动修改，保留原作者核心代码和注释，仅适配MSP430FR2355的I2C通信方式。
- 本人核心工作：完成代码移植、调试、适配，整理完整可编译工程，供学习交流使用。
- 开源协议：MIT License，欢迎Star、Fork、提Issues交流。
- 感谢原作者的开源精神，若涉及侵权，请联系本人删除。

## 硬件接线
| OLED引脚 | MSP430FR2355引脚 | 功能说明 | 备注 |
| :------- | :--------------- | :------- | :--- |
| VCC      | 3.3V             | 供电引脚 | 切勿接5V，避免烧毁 |
| GND      | GND              | 接地引脚 | 与开发板共地 |
| SCL      | p6.0 | 时钟线     | 与代码中定义一致 |
| SDA      | p6.1 | 数据线     | 与代码中定义一致 |

## 使用方法
1.  克隆本仓库：`git clone https://github.com/OrangeKKKANG/MSP430FR2355_SoftI2C_OLED.git`
2.  打开CCS 20.2.0，导入工程（根目录下的CCS工程文件）
3.  核对硬件接线，确认与代码中GPIO引脚定义一致
4.  编译工程，下载到开发板，即可运行

## 效果展示
![8a8a78055d77f6532b753e00802b3429](https://github.com/user-attachments/assets/ebb74c35-6f4e-46c3-876b-fd4808c2bf5d)

## 作者信息
- CSDN博客：https://blog.csdn.net/qq_45788056?type=blog
- GitHub：https://github.com/OrangeKKKANG
