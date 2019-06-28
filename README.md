# Desktop Entry Edit

## What's this?

A edit for GNU/Linux Desktop Entry files (*.desktop)

Currently it's very simple, only a very limited number of items can be edited.

## What Problem to Solve?

1. Sometimes when installed a program, no desktop entry is installed at the same time. Then we need to set up one by ourself.

2. Editing a desktop entry with a plain text edit is not convenient and boring.

3. Finding out where desktop entry files are located in, and managering them, are terribly annoying.

## Where to develop and run?

Develop System: deepin (GNU/Linux Debian)

Target Platform: GNU/Linux, especially for deepin, for the future of <span style="color: red;">***Chinese Own Self-controllable Operating System***</span>

Language: C++

Framework: Qt5.12

## What I want it be in the future?

1. More items can be supported, and items with tag as well.
    
    > e.g.

    > MimeType=text/x-tex;

    > Name[zh_cn]=名字

    > Name[en]=Name

2. Desktop Action can be supported.

    > e.g.

    > [Desktop Action new-window]

    > Name=New Window

3. I want to make it not only a edit, but also a manager, for all the *.desktop files, those in, such as `/usr/share/applications`, `~/.local/share/applications` and `~/Desktop`. Thus, it can easily manager *.desktop files in Desktop, StartUp or Wine menu.

4. The further development of 3 is that, it can also be a default program manager, for it can edit all *.desktop files with item *MimeType*.

5. **The future is promising. 未来可期！**

## What issues are known? 

1. Due to the defect of Fcitx and Qt5.12, Chinese Characters can't be typed in.

## Who am I?

Currently a freshman in School of Software Engineering in NJU.

This is the first time for me to develop a GNU/Linux program.