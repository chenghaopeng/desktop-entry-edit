# Desktop Entry 编辑器

[English Version README](README.md)

## 这是什么？

一个 GNU/Linux 的 Desktop Entry 文件 (*.desktop) 的编辑器。

暂时还很简陋，只支持很少的可编辑项。

## 解决了什么问题？

1. 有时候安装了一个应用，但没有自动建立 Desktop Entry 文件，就需要我们自己手动添加。

2. 用纯文本编辑器编辑 Desktop Entry 文件很不方便。

3. 寻找和管理 Desktop Entry 文件是件烦人的事情。

## 它在哪开发和运行？

开发系统: deepin (GNU/Linux Debian)

目标平台: GNU/Linux，尤其是 deepin，为了<span style="color: red;">***中国的自主可控的操作系统***</span> 的未来

语言: C++

框架: Qt5.12

## 我想在未来实现什么？

1. 更多项能被支持，也包括含有标签的项。
    
    > 如下

    > MimeType=text/x-tex;

    > Name[zh_cn]=名字

    > Name[en]=Name

2. Desktop Action 也能支持。

    > 如下

    > [Desktop Action new-window]

    > Name=New Window

3. 我不仅想把它做成一个编辑器，还想做成一个 *.desktop 文件的管理器，比如 `/usr/share/applications`, `~/.local/share/applications` 和 `~/Desktop` 目录下的那一些。这样就能很方便地管理桌面、启动器乃至Wine开始菜单的 *.desktop 文件。

4. 第三条的更深入发展，可以将它做成一个默认程序的管理器，因为 \*.desktop 文件中包含了 *MimeType* 项。

5. **未来可期！**

## 哪些问题是已知的？ 

1. 因为 Fcitx 和 Qt5.12 的某些缺陷，无法输入而只能粘贴中文字符。

## 我是谁？

目前是南京大学软件学院的大一学生。

这是我第一次开发 GNU/Linux 程序。