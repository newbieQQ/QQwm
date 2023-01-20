# QQwm

## 窗口渲染：pciom
```bash
# 使用该大佬修改的picom
git clone https://github.com/FT-Labs/picom

# 复制下面得到的uthash.h去/usr/local/include
git clone https://github.com/troydhanson/uthash

## 接着安装下面内容
cd picom
rm -rf build
LDFLAGS="-L/usr/local/lib" CPPFLAGS="-I/usr/local/include" meson --buildtype=release . build
ninja -C build
sudo ninja -C build install
```

## fcitx5皮肤
```bash
# gruvbox主题
git clone https://github.com/ayamir/fcitx5-gruvbox
mkdir -p ~/.local/share/fcitx5/themes/
cd fcitx5-gruvbox
cp -r Gruvbox-Light/ Gruvbox-Dark ~/.local/share/fcitx5/themes/
```

## 需要安装工具
```
w3m 
ranger
nodejs
npm
neovim
lazygit
alsa-utils
fcitx5-im
```

## 需要安装字体
```
wqy-microhei
ttf-nerd-fonts-symbols-2048-em
```
## neovim配置

