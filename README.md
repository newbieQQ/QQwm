# 改装自己的dwm-----QQwm
首先将`QQWM_PATH=$HOME/QQwm # 可以为任意地址,只需要定义QQWM_PATH地址就好`加入/etc/environment
## 窗口渲染：pciom
```bash
# 使用该大佬修改的picom
git clone https://github.com/FT-Labs/picom.git

# 复制下面得到的uthash.h去/usr/local/include
git clone https://github.com/troydhanson/uthash.git

## 接着安装下面内容
cd picom
rm -rf build
LDFLAGS="-L/usr/local/lib" CPPFLAGS="-I/usr/local/include" meson --buildtype=release . build
ninja -C build
sudo ninja -C build install

# 开启时需要添加--experimental-backends才可以开启毛玻璃特效
picom --experimental-backends --config ~/scripts/config/picom.conf
```
## zsh
还是来自yaocccc封装的omz（oh-my-zsh精简版）
```bash
echo "source ~/.config/omz/omz.zsh" >> ~/.zshrc
# 需要安装fd
# bat (可选 更好的文本预览效果)
# exa (可选 更好的目录预览效果)
# ueberzug (可选 可在x11终端下预览图片)
# 具体用法地址 https://yaocc.cc/omz/
```

## fcitx5
### fcitx5皮肤
```bash
# gruvbox主题
git clone https://github.com/ayamir/fcitx5-gruvbox
mkdir -p ~/.local/share/fcitx5/themes/
cd fcitx5-gruvbox
cp -r Gruvbox-Light/ Gruvbox-Dark ~/.local/share/fcitx5/themes/
```
### 解决fcitx5无法在终端输入等问题
```bash
GTK_IM_MODULE=fcitx
QT_IM_MODULE=fcitx
XMODIFIERS=@im=fcitx
SDL_IM_MODULE=fcitx
```

## 需要安装工具
```bash
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
```bash
wqy-microhei
ttf-nerd-fonts-symbols-2048-em
```
