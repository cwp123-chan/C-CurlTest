# C-CurlTest

### 1. 使用原理

* 循环对任务地址进行curl请求，不考虑间隔，实现小量并发
* 请求参数为病历号
* 1.txt 格式固定以空格隔开
* 最大上限1000次请求（远程服务器允许情况下可加大）
* 院方网络允许情况下使用（数据库查询，http请求速度影响）

### 2. 命令行(参数1为固定)

```
curlTest.exe [1] [FilePath]
```

### 3. 响应

* success： 返回内容
* false： Failed to connect to 127.0.0.1 port 6776: Connection refused