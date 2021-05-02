# 安装

UTM能在iOS11+并且已越狱的设备上运行。 UTM也能通过 [Xcode][9] 运行在未越狱的设备上但这只建议高级用户(大佬)使用。 UTM在非越狱设备上运行时兼容性有限，具体取决于iOS版本和设备处理器。请参阅下面的列表了解更多详细信息。

## 未越狱设备

**iOS11/12/13**: UTM不需要越狱来使用，但您必须将其通过侧载安装。如果你是新的侧载设备(每个设备有单独的UDID，如果你的UDID没有在开发人员提供的ipa包内签名，则视为新的侧载设备)，则需要使用开发人员的证书加载未经批准的应用程序在非越狱的iOS设备上。侧载有一些限制：

* 免费开发者账号必须每7天重新签名一次
* 付费开发者账号必须每1年重新签名一次

对于非越狱用户，建议使用自动管理重新签名的[AltStore App][4]。

**iOS14.2/14.3**: 如果您的设备有Apple A12+芯片，UTM可用于侧载（无需越狱）。否则，你就得越狱。

**iOS14.0/14.1/14.4+**: UTM只会在越狱之后工作。

### AltStore 源

提示: 此时，第三方回购需要AltStore的beta版本，该版本仅对开发者的Patreon支持者可用。从源安装时，可以从AltStore接收更新提示。

1. 安装 [AltStore App][4]
2. 添加源: [https://alt.getutm.app][5]
3. 从Altstore下载安装UTM

### AltStore 侧载

对于非beta测试人员来说，AltStore的公共版本缺乏添加存储库和检查更新的能力，但仍然可以自动管理重新签名。

1. 安装 [AltStore App][4]
2. 下载 [最新版本的IPA][1] 到你的设备
3. 使用Altstore打开下载的IPA

### 其他方法

有许多云签名服务，包括AppCake，由于使用了错误的签名证书，**无法**让UTM工作。如果您在尝试启动VM时遇到崩溃或黑屏，很可能是您的签名证书无效。

你可以通过 `设置 -> 通用 -> 设备&描述文件管理` 检查你的签名。 如果用于对UTM进行签名的证书列在“开发者应用程序”下，则它是有效的。如果它列在“企业应用程序”等其他项下，则它是无效的证书。

## 越狱设备

UTM需要AppSync Unified，可以在[Karen's Repo][8]上找到。您需要将这两个存储库添加到包管理器（Cydia、Sileo、Zebra等）以安装UTM。

1. 为 AppSync Unified 添加 [https://cydia.akemi.ai/][8]。
2. 为 UTM 添加 [https://cydia.getutm.app/][7]。

# 快速开始

最简单的方法是使用其中的任意一个 [预构虚拟机](https://mac.getutm.app/gallery/)。只需从您的设备下载、解压并打开“.utm”文件。

# 设置

## 后台

如果您启用在后台运行VM，那么UTM将每隔几秒钟查询一次您的位置，以防止iOS终止应用程序进程。除非启用了调试日志记录（它显示在调试日志中），否则UTM不会存储此信息。UTM不会将此数据发送到任何地方，除非您手动导出并发送它。请注意，如果后台应用程序使用了太多资源，iOS可能仍然会强制停止它。

后台自动设置允许UTM在进入后台时对正在运行的VM进行快照。然后，如果iOS出于任何原因决定终止它，它将从快照恢复。不建议使用在后台运行选项启用此选项，因为在恢复快照时，在后台完成的任何工作都将丢失。

在内存不足时自动保存也会这样，除非iOS警告应用程序内存不足，可能很快就会终止。请注意，这可能并不总是有效，因为iOS可能会在保存快照时终止应用程序。

## 手势和输入

手势和输入选项在所有虚拟机之间共享，并在设置应用程序中配置。这些不适用于控制台模式。

手势可以用来模拟右键单击、单击并拖动或鼠标滚轮。你也可以禁用一些手势。有关手势列表，请参见下面的部分。

对于光标模式，您可以选择每个输入设备如何模拟鼠标光标。“触摸模式”或“平板电脑模式”模拟USB平板电脑设备并模拟触摸板，您可以在其中拖动光标。要使用不同的光标模式，您的虚拟机需要支持USB HID设备（特别是USB鼠标和USB平板电脑），并且不能使用“传统模式”输入。

对于尝试隐藏光标的选项，只有在安装[SPICE guest agent tools](https://www.spice-space.org/download.html)后才能隐藏光标。

## 游戏手柄

您可以使用任何iOS支持的游戏手柄，并将游戏手柄键映射到键盘键。右指杆映射到鼠标，左指杆映射到滚轮。

# 主屏幕

## 退出

由于iOS的Bug，您**无法**强制退出应用程序（例如，通过在应用程序切换器中向上滑动）。退出UTM的唯一好方法是屏幕左上角的X按钮（或者使用VM中的Power/quit按钮）。如果您不使用指定的退出按钮退出应用程序，则在重新启动设备之前，应用程序将不再启动。

提示：屏幕左上角的X按钮仅在UTM1.0及以下版本中适用

## 创建新的虚拟机

使用屏幕右上角的+按钮创建一个新的虚拟机。

## 启动虚拟机

UTM的文档目录中的每个有效的“.utm”包都将显示。要启动虚拟机，请按中心的大按钮。如果当前有挂起映像，那么启动虚拟机将自动恢复它。每次启动UTM只能启动一个虚拟机。如果关闭或退出UTM，则可以再次启动UTM以进入主屏幕。

## 修改现有虚拟机

对于每个虚拟机，都有一个“i”按钮，您可以按它来修改虚拟机设置。

# 新建虚拟机设置

当使用+按钮创建新的虚拟机时，您将看到一组简化的选项。

## 系统

有关详细信息，请阅读下面关于**系统**设置的部分。

## 驱动器

有关更多信息，请阅读下面关于**驱动器/镜像**的部分。

## 高级

选中“创建后打开配置”以显示所有配置选项。

# 修改虚拟机设置

## 名称

此VM的唯一名称，它也是`.utm`包的文件名。

## 调试

选中`Debug Log`以捕获详细的调试日志，该日志将存储在此虚拟机的`.utm`包中的`Debug.Log`中。请注意，此日志中可能会捕获敏感数据，包括击键和位置数据（如果启用了后台）。`导出日志…`选项允许您快速访问`Debug.Log`，以便将其发送到其他地方。UTM的当前版本也显示在本节中。

## 系统

### 架构

QEMU可以模拟的受支持的CPU体系结构之一。最常见的选项是**x86_64**，它模拟64位PC。

### 系统

QEMU不仅仅模拟CPU，它还模拟整个系统。这允许您选择一个QEMU支持的系统。在大多数情况下，您不需要更改所选体系结构的默认系统。当您选择架构时，它将自动高亮显示。

### 内存

要分配给VM的主机内存量。请注意，iOS不允许单个应用程序使用超过设备40%的内存（在某些设备上甚至更少）。由于JIT和其他因素，这里指定的内存量不是VM将使用的内存总量。在系统页面底部附近，您可以找到估计的RAM使用量以及系统上的RAM数量。

如果您不知道要使用多少RAM，请谨慎猜测，如果RAM太多，VM将拒绝启动，或者您将收到内存使用警告。

### CPU核心数

**在大多数情况下，你应该填入“1”**即使您的设备有多个内核，除非体系结构支持，否则QEMU也不会在单独的内核上模拟多个CPU。最常见的架构是x86_64（和i386）不**支持ARM上的多核仿真。只有具有弱内存模型的体系结构（如ARM和ARM64）才支持多核仿真（在ARM上）。

### 启动

仅适用于**pc**。它指定要从第一个启动的设备。在其他目标上，此选项将被忽略。即使您没有cd驱动器，将其设置为**cd**通常也是安全的。

### JIT缓存

见上文**内存**。这使您可以微调JIT缓存大小。默认情况下，JIT缓存设置为主机内存的1/4。例如，如果您将主机内存设置为512MB，那么JIT缓存将为128MB，总计640MB。然而，由于iOS对JIT内存的处理方式不同，它将JIT内存视为实际使用大小的两倍。所以iOS认为这个应用程序使用了768MB的内存。记住，iOS会强制结束任何使用超过总内存40%的应用程序。

靠近底部的**估计使用量**将为您自动计算。

### 强制多核

仅限高级用户。这将强制在不同的物理内核上模拟多个CPU。请注意，这就是不支持的原因。仿真在大多数情况下都是不正确的，这应该只用于开发或非常简单的BIOS应用程序。

### QEMU属性

一些目标支持其他属性。您可以在`property=value`格式的逗号分隔列表中指定它们。例如：`via=pmu,vmport=off`。这是一个高级选项，大多数人不需要触摸。有关要使用的有效属性，可以参考QEMU文档。

### 其他QEMU参数

可以指定要传递给QEMU的其他参数。请注意，如果这些选项与自动生成的参数冲突，则不会选中它们。您可以启用调试日志来查看传递给QEMU的选项。每个附加参数之间用空格隔开。也可以在参数中使用空格，例如`-option value`。如果要转义空格，请确保使用引号：`-option "value with space"`。

## 驱动器/镜像

要添加新驱动器，请按右上角的+按钮。要更改现有驱动器的映像文件，请在列表中选择驱动器。要删除现有驱动器，可以向左滑动一行或使用右上角的“编辑”按钮，然后单击该行左侧的-按钮。

请注意，删除驱动器时，系统将提示您删除文件。如果您选择不删除该文件，它将继续使用您的存储，磁盘映像将存储在`.utm`包中。您可以添加新驱动器并将其重新链接到映像。

### 选择驱动器

您可以通过驱动器图标进入选择器。

您可以在列表中选择现有图像或导入/创建新映像。此处仅列出当前`.utm`包中的驱动器。您可以通过向左滑动或使用“编辑”按钮删除任何图像。请注意，如果在此处删除，则该文件将被永久删除。

按右上角的+按钮可导入或创建驱动器。如果选择导入驱动器，则会显示一个文件选择屏幕，您可以在其中从任何位置选择磁盘（例如ISO文件）。该文件的一个副本将放入`.utm`包中。导入完成后，可以安全地删除原始文件。

如果您选择创建一个新驱动器，您可以给它一个文件名（可以是任何东西，扩展名不重要）和一个大小。注意：创建的磁盘映像将是一个QCOW2格式的文件，它将自动增长到指定的大小。当前的UTM限制使您无法在每次启动时创建多个磁盘映像。

### 驱动器格式

* **磁盘镜像**: 最常见的类型。通常使用QCOW2映像作为虚拟机的主磁盘。但是，这里可以使用QEMU支持的任何驱动器。请注意，只有QCOW2映像支持挂起/恢复功能。
* **CD/DVD 镜像**: 通常是只读映像（如ISO）用于引导到安装程序中。
* **BIOS**: 高级用法。允许您指定自定义BIOS映像。
* **Linux内核**: 高级用法。直接引导到Linux内核。
* **Linux RAM 磁盘**: 高级用法。Linux初始化。
* **Linux设备树二进制文件**: 高级用法。Linux DTB。Linux引导不需要。

### 驱动器位置

指定磁盘和CD的硬件位置。最常见的选项是用于PC仿真的**ide**。对于ARM Virt仿真，请使用**virtio**。其他选项仅适用于高级用户。

## 显示

### 方式

全图形将模拟图形界面的VGA连接。控制台模式速度更快，但只能将模拟设备的字符端口直接输出到UTM的内置终端仿真器。

### 解决方式

[SPICE来宾代理工具](https://www.spice-space.org/download.html)要安装在虚拟机上。目前仅在Windows和少数Linux发行版上受支持。

**适应屏幕** 没有**视网膜模式**将使用设备的“有效”分辨率。这通常是显示器像素数的1/2或1/3。您需要使用“缩放”功能放大显示，这应该是正确的纵横比。

**适应屏幕** 在**视网膜模式下**将使用设备的分辨率。如果操作系统没有HiDPI模式，那么显示的对象将太小。对于大屏幕设备（如iPad），这也需要大量的主机RAM，因此如果您启用此选项而它不起作用，则可能没有足够的RAM。

**视网膜模式** 在没有**适合屏幕**的情况下启用后没有作用。

### 缩放比例

您可以选择降尺度和升尺度。线性将使文本看起来模糊，但图像看起来平滑。会使文本看起来很清晰，但图像看起来很像块状。

### 控制台设置

目前只能选择字体和字号。字体可以是系统上安装的任何单间距字体。如果你想让光标闪烁，你也可以选择在这里启用它。

### 调整控制台大小命令

当您在虚拟机中按下重新设置大小按钮时，它会将这个文本字符串发送到终端。将对字符串进行以下替换：

* `$ROWS` 将替换为当前在屏幕上可以看到的行数。
* `$COLS` 将替换为当前在屏幕上可以看到的列数。
* `\n` 将替换为新行（回车键）。

您可以使用它向虚拟机发送命令。默认使用`stty`，这在大多数Linux上都适用。

## Input

### Legacy Mode

When enabled, a PS/2 mouse and keyboard will be used. Otherwise a USB mouse and keyboard will be used. Legacy mode does not support emulated USB tablet device (used by "touch mode" or "tablet mode").

### Invert Mouse Scroll

When enabled, an external mouse or trackpad scroll event will be inverted.

### Gesture and Cursor Settings

Goes to the Settings screen.

## Networking

You can enable/disable networking and select the network card to emulate.

### Isolate Guest

This option makes it so the guest cannot see the host network at all.

### Advanced Configuration

These options let you configure the virtual guest network. UTM uses QEMU's slirp usermode networking driver.

### Port Forwarding

You can forward guest ports to host ports. For example, if you have an HTTP server running on the VM's port 80 and you forward host TCP port 8080 to guest TCP port 80 then you can access "http://localhost:8080/" from Safari to communicate with the HTTP server. If host/guest addresses are not specified, then all host interfaces will be binded to and all guests will be forwarded.

## Sound

You can enable/disable sound and select the sound card to emulate. Does not work in Console mode.

## Sharing

### Clipboard Sharing

Requires [SPICE guest agent tools](https://www.spice-space.org/download.html). This will synchronize the VM's clipboard with the device's clipboard. The synchronization happens whenever you copy something inside the VM or if you task switch (UTM to the foreground) on the host.

### Shared Directory

Requires [SPICE WebDAV service](https://www.spice-space.org/download.html). Note that Windows XP support by SPICE is not perfect and Windows 7 is recommended for working WebDAV. You can share any directory inside UTM's `Documents` directory except any `.utm` package.

# Virtual Machine

## Toolbar options

From left to right:

* **Power**: sends a power button event to the VM. Once this is pressed, the button changes to an X which allows you to force quit UTM. Note the power and X button are the only safe way of exiting UTM. If you quit UTM any other way (including swiping up from the app switcher), an iOS bug will prevent you from launching UTM again until you reboot.
* **Pause**: suspends the VM and makes a snapshot (if supported). This button becomes a Play button after Pause completes and can resume the VM (and delete the snapshot).
* **Restart**: sends a reset button event to the VM.
* **Zoom**: first press will attempt to zoom the display to fit. Second press will reset the display state (zoom out and centered).
* **Keyboard**: shows or hides the keyboard. In console mode, the keyboard must be shown to type anything in the console.
* **Settings**: not implemented
* **Hide**: Hides the toolbar. To show again, use a **three finger downwards** gesture. If the keyboard is visible, you need to make the gesture twice.

## Gestures

In Console mode, the only gestures available is Three Finger Swipe Up/Down.

### Long press

Configurable in Settings:

* Disabled
* Click & Hold (default)
* Right Click

### Two Finger Tap

Configurable in Settings:

* Disabled
* Right Click (default)

### Two Finger Pan

Configurable in Settings:

* Disabled
* Move Screen (default)
* Click & Hold (move cursor while clicking)
* Mouse Wheel (only up and down)

### Two Finger Pinch

If Move Screen is selected for Two Finger Pan: zoom the screen.

Otherwise: does nothing.

### Two Finger Swipe

Configurable in Settings:

* Disabled (default)
* Mouse Wheel (each swipe up or down is one event)

### Three Finger Pan

Configurable in Settings:

* Disabled (default)
* Move Screen
* Click & Hold (move cursor while clicking)
* Mouse Wheel (only up and down)

### Three Finger Swipe Up

If toolbar is visible: hide the toolbar

If toolbar is not visible: show the keyboard

### Three Finger Swipe Down

If toolbar is visible: hide the keyboard

If toolbar is not visible: show the toolbar

  [1]: https://github.com/utmapp/UTM/releases/latest
  [2]: https://dantheman827.github.io/ios-app-signer/
  [3]: https://discord.gg/UV2RUgD
  [4]: https://altstore.io
  [5]: altstore://source?url=https://alt.getutm.app
  [6]: https://repo.dynastic.co/package/altdaemon
  [7]: cydia://url/https://cydia.saurik.com/api/share#?source=https://cydia.getutm.app/
  [8]: cydia://url/https://cydia.saurik.com/api/share#?source=https://cydia.akemi.ai/
  [9]: https://github.com/utmapp/UTM/blob/master/Documentation/TetheredLaunch.md
