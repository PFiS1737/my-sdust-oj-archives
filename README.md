# my-sdust-oj-archives-cpp

我的 SDUST OJ 归档，使用 C++ 语言。

评判程序使用 Append 模式，它将会插入在你写的代码的后面。

查看 `pta` 分支，了解 Prepend 模式的使用。

## Requirements

- GNU G++
- fish
- just
- xmake
- fzf (optional)

## Usage

```sh
# 创建源文件
#   -a 启用 Append Code 模式
#   -n 仅创建文件而不询问内容
#   -y 默认确定
# 输入时直接换行即可，ctrl-c 到下一个问题
just new [-any]

# NOTE: 应该总是仅编辑 ./src/main.cpp 文件

# 评判
# 首次运行需无参数使用 `just` 进行初始化
just judge

# 归档当前工作区
# 提问 Description 为会跟在 ID 后面一起组成文件名的短描述
#      Problem 为具体题干
just archive

# 检出一个归档
# 不提供 id 则调用 fzf 进行搜索
just checkout [id]
```

# Reference

- [SDUST OJ](http://192.168.119.211/JudgeOnline/) (校内局域网访问)
