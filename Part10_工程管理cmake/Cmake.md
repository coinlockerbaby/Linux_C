# 1.注释

## 1.1 单行注释

```cmake
# 这是一个 CMakeLists.txt 文件
cmake_minimum_required(VERSION 3.0.0)
```

## 1.2 多行注释

CMake 使用 #[[ ]] 形式进行多行注释

```cmake
#[[ 这是一个 CMakeLists.txt 文件。
这是一个 CMakeLists.txt 文件
这是一个 CMakeLists.txt 文件]]
cmake_minimum_required(VERSION 3.0.0)
```

# 2.cmake版本

通过cmake_minumum_required来指定使用的cmake的最低版本

```cmake
cmake_minimum_required(VERSION 3.0)
project(CALC)
add_executable(app add.c div.c main.c mult.c sub.c)
```

# 3.项目信息

project：定义工程名称，并可指定工程的版本、工程描述、web 主页地址、支持的语言（默认情况支持所有语言），如果不需要这些都是可以忽略的，只需要指定出工程名字即可。

```cmake
# PROJECT 指令的语法是：
project(<PROJECT-NAME> [<language-name>...])
project(<PROJECT-NAME>
       [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
       [DESCRIPTION <project-description-string>]
       [HOMEPAGE_URL <url-string>]
       [LANGUAGES <language-name>...])
```

# 4.生成可执行程序

add_executable(可执行程序名 源文件名称)

源文件名可以是一个也可以是多个，如有多个可用空格或 ; 间隔

```cmake
# 样式1
add_executable(app add.c div.c main.c mult.c sub.c)
# 样式2
add_executable(app add.c;div.c;main.c;mult.c;sub.c)
```

# 5.执行cmake

将 CMakeLists.txt 文件编辑好之后，就可以执行 cmake 命令了。

cmake CMakeLists.txt文件所在路径

最终将生成makefile等文件

然后通过make命令即可编译

# 6.定义变量关键字set

```cmake
# SET 指令的语法是：
# [] 中的参数为可选项, 如不需要可以不写
SET(变量名 变量值)
```

定义完变量后我们如何获取变量值

```cmake
${变量名}
```

```cmake
set(SRC_LIST add.c div.c main.c mult.c sub.c)
add_executable(app  ${SRC_LIST})
```

# 7.使用set来设置c++标准

```cmake
#增加-std=c++11
set(CMAKE_CXX_STANDARD 11)
```

# 8.使用set来指定可执行文件输出路径

```cmake
set(HOME /home/robin/Linux/Sort)
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
```

# 9.实战生成可执行文件

项目在exam2_多文件

```cmake
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STRANDARD 11)
project(hello)
set(EXECUTABLE_OUTPUT_PATH ../)
set(c_files add.c sub.c mult.c div.c main.c)
add_executable(hello ${c_files})
```

# 10.搜索文件

```
file(GLOB/GLOB_RECURSE 变量名 要搜索的文件路径和文件类型)
```

* GLOB: 将指定目录下搜索到的满足条件的所有文件名生成一个列表，并将其存储到变量中。
* GLOB_RECURSE：递归搜索指定目录，将搜索到的满足条件的文件名生成一个列表，并将其存储到变量中。

```cmake
file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
```

# 11.指定头文件目录

```cmake
include_directories(headpath)
```

# 12.制作库

## 12.1制作静态库

如果你需要制作静态库文件添加

```cmake
add_library(库名称 STATIC 源文件1 [源文件2] ...) 
```

## 12.2制作动态库

如果你需要制作动态库文件添加

```cmake
add_library(库名称 SHARED 源文件1 [源文件2] ...) 
```

# 13.指定库文件输出路径

```cmake
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
```

# 14.链接库文件

## 14.1链接静态库

```cmake
link_libraries(<static lib> [<static lib>...])
```

* 参数 1：指定出要链接的静态库的名字
  可以是全名 libxxx.a
  也可以是掐头（lib）去尾（.a）之后的名字 xxx
* 参数 2-N：要链接的其它静态库的名字

如果该静态库不是系统提供的（自己制作或者使用第三方提供的静态库）可能出现静态库找不到的情况，此时可以将静态库的路径也指定出来：

```cmake
link_directories(<lib path>)
```

## 14.2链接动态库

```cmake
target_link_libraries(
    <target> 
    <PRIVATE|PUBLIC|INTERFACE> <item>... 
    [<PRIVATE|PUBLIC|INTERFACE> <item>...]...)
```

动态库链接放在CMakeLists.txt生成可执行文件的后面

target：指定要加载动态库的文件的名字

该文件可能是一个源文件
该文件可能是一个动态库文件
该文件可能是一个可执行文件
PRIVATE|PUBLIC|INTERFACE：动态库的访问权限，默认为 PUBLIC

PUBLIC：在 public 后面的库会被 Link 到前面的 target 中，并且里面的符号也会被导出，提供给第三方使用。
PRIVATE：在 private 后面的库仅被 link 到前面的 target 中，并且终结掉，第三方不能感知你调了啥库
INTERFACE：在 interface 后面引入的库不会被链接到前面的 target 中，只会导出符号。

# 15.日志

```cmake
message([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR] "message to display" ...)
```

> (无) ：重要消息
> STATUS ：非重要消息
> WARNING：CMake 警告，会继续执行
> AUTHOR_WARNING：CMake 警告 (dev), 会继续执行
> SEND_ERROR：CMake 错误，继续执行，但是会跳过生成的步骤
> FATAL_ERROR：CMake 错误，终止所有处理过程

# 16.变量操作

## 16.1追加

```cmake
list(APPEND <list> [<element> ...])
```

例如下面代码段可以将

```cmake
list(APPEND SRC_1 ${SRC_1} ${SRC_2} ${TEMP})
```

## 16.2字符串移除

```cmake
list(REMOVE_ITEM <list> <value> [<value> ...])
```
例如

```cmake
# 移除 main.cpp
list(REMOVE_ITEM SRC_1 ${PROJECT_SOURCE_DIR}/main.cpp)
```

# 17.添加宏定义

```cmake
add_definitions(-D宏名称)
```
例如
```cmake
cmake_minimum_required(VERSION 3.0)
project(TEST)
# 自定义 DEBUG 宏
add_definitions(-DDEBUG)
add_executable(app ./test.c)
```

# 18.嵌套CMakeLists.txt

如果项目很大，或者项目中有很多的源码目录，在通过 CMake 管理项目的时候如果只使用一个 CMakeLists.txt，那么这个文件相对会比较复杂，有一种化繁为简的方式就是给每个源码目录都添加一个 CMakeLists.txt 文件（头文件目录不需要），这样每个文件都不会太复杂，而且更灵活，更容易维护。

变量关系

* 根节点 CMakeLists.txt 中的变量全局有效
* 父节点 CMakeLists.txt 中的变量可以在子节点中使用
* 子节点 CMakeLists.txt 中的变量只能在当前节点中使用

## 18.1 添加子目录

```cmake
add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
```

> source_dir：指定了 CMakeLists.txt 源文件和代码文件的位置，其实就是指定子目录
> binary_dir：指定了输出文件的路径，一般不需要指定，忽略即可。
> EXCLUDE_FROM_ALL：在子路径下的目标默认不会被包含到父路径的 ALL 目标里，并且也会被排除在 IDE 工程文件之外。用户必须显式构建在子路径下的目标。
