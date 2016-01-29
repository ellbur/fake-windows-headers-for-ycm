
# For all of you developing for Windows on Linux using [Vim](http://www.vim.org/)+[YCM](https://github.com/Valloric/YouCompleteMe) (I know you're out there!)

YCM uses [Clang](http://clang.llvm.org/), which doesn't handle Boost on Windows very well. You end up getting lots of red code.

It turns out to be easier to point YCM towards Boost for Linux, and then fake the Windows API with some function prototypes.

This is a start of some prototypes that can be used. It's very incomplete, so feel free to add to it as you need more functions to suit your needs!

